/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "foods"
#define maxc 1000000007
#define maxn 200005

using namespace std;

int m, n, k, old, res, match[maxn], l[maxn], cnt = 0;

vector <int> a[maxn];

int dd[maxn];
bool choose[maxn];

void nhap()
{
    cin >> m >> n >> k;
    int x, y;
    while (k--)
    {
        cin >> x >> y;
        a[x].PB(maxn-y);
        a[maxn-y].PB(x);
    }
}

bool visit(int u, int Key)
{
    if (match[u] == Key) return false;
    match[u] = Key;
    for (int i = 0; int v = a[u][i]; i++)
        if (!dd[v] || visit(dd[v], Key))
        {
            dd[u] = v;
            dd[v] = u;
            return true;
        }
    return false;
}

void chuanbi()
{
    for (int i = 1; i <= m; i++) a[i].PB(0);
    for (int i = 1; i <= n; i++) a[maxn-i].PB(0);
    for (int i = 1; i <= m; i++)
        if (!dd[i]) visit(i, ++cnt);
}

void xuli()
{
    queue <int> q;
    for (int i = 1; i <= m; i++) if (!dd[i]) q.push(i);
    for (int i = 1; i <= n; i++) if (!dd[maxn-i]) q.push(maxn-i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int &v : a[u])
            if (!(choose[v]++)) q.push(dd[v]);
    }
    for (int i = 1; i <= m; i++)
        if (dd[i] && !choose[i] && !choose[dd[i]])
            choose[i] = 1;
    int dem1 = 0, dem2 = 0;
    for (int i = 1; i <= m; i++)
        if (choose[i]) dem1++;
    for (int i = 1; i <= n; i++)
        if (choose[maxn-i]) dem2++;
    cout << m - dem1 << " " << n - dem2 << '\n';
    for (int i = 1; i <= m; i++)
        if (!choose[i]) cout << i << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++)
        if (!choose[maxn-i]) cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    chuanbi();
    xuli();
    return 0;
}
