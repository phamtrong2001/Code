#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define MM 333
#define maxc 1000000007

using namespace std;

int n, m, a[MM][N], pos[MM][N], res[N], add[N];
int trc[N], sau[N], distPre[N], valx[N], valy[N], allPos[3*N];
struct Query
{
    int type, l, r, x, y;
    Query(int type = 0, int l = 0, int r = 0, int x = 0, int y = 0) : type(type), l(l), r(r), x(x), y(y) {}
}query[N];

int getPos(int x)
{
    int pos = 0, cur = 0;
    while (pos != n+1)
    {
        pos = sau[pos];
        cur += distPre[pos];
        if (cur > x) return trc[pos];
    }
    return n+1;
}
int getVal(int x)
{
    int pos = 0, cur = 0;
    while (pos != n+1)
    {
        if (pos == x) return cur;
        pos = sau[pos];
        cur += distPre[pos];
    }
    return n+1;
}
void rotateBlock(int lef, int mid, int rig)
{
    sau[trc[lef]] = mid;
    sau[trc[mid]] = rig;
    sau[trc[rig]] = lef;

    int temp = trc[lef];
    trc[lef] = trc[rig];
    trc[rig] = trc[mid];
    trc[mid] = temp;

    temp = distPre[lef];
    distPre[lef] = distPre[rig];
    distPre[rig] = distPre[mid];
    distPre[mid] = temp;
}
void createConnect(int lef, int mid, int rig, int pos)
{
    sau[lef] = mid;
    sau[mid] = rig;
    trc[rig] = mid;
    trc[mid] = lef;
    distPre[mid] = pos - getVal(lef);
    distPre[rig] = distPre[rig] - distPre[mid];
}
void updateBlock(int u, int v, int x, int y)
{
    valx[u] += x; add[u] = x;
    valy[u] += y;
    while (u != v)
    {
        int w = sau[u];
        add[w] = add[u] + distPre[w]*y;
        valx[w] += add[w];
        valy[w] += y;
        u = w;
    }
}

void modifyBlockQuery(int blockId, int leftId, int rightId)
{
    for (int i = 1; i <= n+1; i++) trc[i] = 0, sau[i] = n+1, distPre[i] = i, valx[i] = valy[i] = 0;
    createConnect(0, 1, n+1, 1);

    for (int id = leftId; id <= rightId; id++)
    {
        int l = query[id].l; int r = query[id].r; int x = query[id].x;
        int u = getPos(l);
        if (getVal(u) != l) createConnect(u, u+l-getVal(u), sau[u], l), u = u+l-getVal(u);
        int v = getPos(r+1);
        if (getVal(v) != r+1) createConnect(v, v+r-getVal(v)+1, sau[v], r+1), v = v+r-getVal(v)+1;
        if (query[id].type == 1)
        {
            int w = getPos(r-x+1);
            if (getVal(w) != r-x+1) createConnect(w, w+r-x+1 - getVal(w), sau[w], r-x+1), w = w+r-x+1 - getVal(w);
            if (l != r && x) rotateBlock(u, w, v);
        }
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) if (trc[i] || sau[i] != n+1) allPos[++cur] = i;
    allPos[++cur] = n+1; sau[0] = 1;
    for (int i = 1; i <= cur; i++) trc[allPos[i]] = allPos[i-1], sau[allPos[i]] = allPos[i+1], distPre[allPos[i]] = allPos[i] - allPos[i-1];

    for (int id = leftId; id <= rightId; id++)
    {
        int l = query[id].l; int r = query[id].r; int x = query[id].x;
        int u = getPos(l);
        int v = getPos(r+1);
        if (query[id].type == 1)
        {
            int w = getPos(r-x+1);
            if (l != r && x) rotateBlock(u, w, v);
        }
        else
        {
            int y = query[id].y;
            updateBlock(u, trc[v], x, y);
        }
    }
    int poss = 0, dem = 0;
    while (poss != n+1)
    {
        poss = sau[poss];
        if (poss == n+1) break;
        int zz = lower_bound(allPos, allPos + cur + 1, poss) - allPos;
        for (int i = allPos[zz]; i < allPos[zz+1]; i++)
        {
            pos[blockId][i] = ++dem;
            a[blockId][dem] = a[blockId-1][i] - valx[i];
            if (i == allPos[zz+1]-1) break;
            valx[i+1] = valx[i] + valy[i];
            valy[i+1] = valy[i];

        }
    }
}

void calcElement(int x)
{
    int value, posBlock = 0;
    for (int blockId = 1; blockId <= m/MM+1; blockId++)
    {
        int z = pos[blockId][x];
        if (a[blockId][z] < 0) {posBlock = blockId; value = a[blockId-1][x]; break;}
        x = z;
    }
    if (!posBlock) return;
    for (int id = (posBlock-1)*MM+1; id <= min(m, posBlock*MM); id++)
    {
        int l = query[id].l; int r = query[id].r;
        if (x < l || x > r) continue;
        if (query[id].type == 1)
            x = l + (x - l + query[id].x) % (r - l + 1);
        else
            value -= (query[id].x + (x - l)*query[id].y);
        if (value < 0) {res[id]++; break;}
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ANT.INP", "r", stdin);
    freopen("ANT.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[0][i];
    for (int i = 1; i <= m; i++)
    {
        int type, l, r, x, y; cin >> type >> l >> r >> x;
        if (type == 1) query[i] = Query(1, l, r, (r-l+1-x) % (r-l+1), 0);
        else
        {
            cin >> y;
            query[i] = Query(2, l, r, x, y);
        }
    }
    for (int i = 0; i < m/MM; i++)
        modifyBlockQuery(i+1, i*MM+1, (i+1)*MM);
    modifyBlockQuery(m/MM+1, m/MM*MM+1, m);
    for (int i = 1; i <= n; i++) calcElement(i);
    for (int i = 1; i <= m; i++)
        if (query[i].type == 2) cout <<res[i]<<'\n';
}
