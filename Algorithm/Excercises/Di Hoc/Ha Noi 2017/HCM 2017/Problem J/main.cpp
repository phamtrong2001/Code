#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*3000000000000000007

using namespace std;

int n, m, sz[3][N], pointer;
long long sum1[3][N], sum2[3][N], sumSquare1[3][N], sumSquare2[3][N];
vector<int> a[3][N];
vector<ll> U, V;
pii val[N], all[N];

void DFS1(int u, int p, int id)
{
    sz[id][u] = 1;
    for (auto v : a[id][u])
    {
        if (v == p) continue;
        DFS1(v, u, id);
        sum1[id][u] += sz[id][v] + sum1[id][v];
        sumSquare1[id][u] += sumSquare1[id][v] + 2ll*sum1[id][v] + sz[id][v];
        sz[id][u] += sz[id][v];
    }
}
void DFS2(int u, int p, int id, int nn)
{
    if (p != -1)
    {
        sum2[id][u] = (sum1[id][p] + sum2[id][p]) - (sum1[id][u] + sz[id][u]) + nn - sz[id][u];
        sumSquare2[id][u] = (sumSquare1[id][p] + sumSquare2[id][p]) - (sumSquare1[id][u] + 2ll*sum1[id][u] + sz[id][u]) + 2ll*(sum1[id][p] + sum2[id][p] - sum1[id][u] - sz[id][u]) + nn - sz[id][u];
    }
    for (auto v : a[id][u])
    {
        if (v == p) continue;
        DFS2(v, u, id, nn);
    }
}

bool bad(int l1, int l2, int l3)
{
    return 1.*(V[l3]-V[l1])/(U[l1] - U[l3]) < 1.*(V[l2]-V[l1])/(U[l1]-U[l2]);
}
void add(ll u, ll v)
{
    U.PB(u); V.PB(v);
    while (U.size() >= 3 && bad(U.size()-3, U.size()-2, U.size()-1))
    {
        U.erase(U.end()-2);
        V.erase(V.end()-2);
    }
}

ll get(ll x)
{
    //if (pointer >= U.size()) pointer = U.size()-1;
    while (pointer < U.size()-1 && U[pointer]*x + V[pointer] > U[pointer+1]*x + V[pointer+1])
        pointer++;
    return U[pointer]*x + V[pointer];
}

bool cmp(pii p, pii q)
{
    if (p.F != q.F) return p.F > q.F;
    return p.S < q.S;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        a[1][u].PB(v);
        a[1][v].PB(u);
    }
    cin >> m;
    for (int i = 1; i < m; i++)
    {
        int u, v; cin >> u >> v;
        a[2][u].PB(v);
        a[2][v].PB(u);
    }
    DFS1(1, -1, 1);
    DFS2(1, -1, 1, n);
    DFS1(1, -1, 2);
    DFS2(1, -1, 2, m);

    for (int i = 1; i <= m; i++)
        val[i] = mp((sum1[2][i] + sum2[2][i]), 1ll*n*(sumSquare1[2][i] + sumSquare2[2][i]) + 2ll*n*(sum1[2][i] + sum2[2][i]));
    sort(val+1, val+m+1, cmp);
    add(val[1].F, val[1].S);
    for (int i = 2; i <= m; i++)
         if (val[i].F != val[i-1].F) add(val[i].F, val[i].S);
    for (int i = 1; i <= n; i++)
        all[i] = mp(2ll*(sum1[1][i] + sum2[1][i]), 1ll*m*n + 1ll*m*(sumSquare1[1][i] + sumSquare2[1][i]) + 2ll*m*(sum1[1][i] + sum2[1][i]));
    sort(all+1, all+n+1);
    ll res = maxc, ans = 0;
    for (int i = 1; i <= n; i++)
        res = min(res, get(all[i].F) + all[i].S);

    for (int i = 1; i <= n; i++) ans += sumSquare1[1][i] + sumSquare2[1][i];
    for (int i = 1; i <= m; i++) ans += sumSquare1[2][i] + sumSquare2[2][i];
    cout <<res + ans/2<<endl;
}
