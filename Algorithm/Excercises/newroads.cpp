/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "newroads"
#define maxn 100005

using namespace std;

int n, m, index[maxn], low[maxn], s[maxn], top, cnt, dem, tr[maxn];

long long res[maxn], tong;

bool dd[maxn] ;

vector <int> ke[2*maxn];

map <pair <int, int>, bool> ma;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (ma[MP(a, b)]) continue;
        ke[a].PB(b);
        ma[MP(a, b)] = 1;
    }
}

void DFS(int u)
{
    index[u] = ++cnt;
    low[u] = cnt;
    dd[u] = 1;
    s[++top] = u;
    for (int i = 0; i < ke[u].size(); i++)
    {
        int v = ke[u][i];
        if (!index[v])
            {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        else if (dd[v]) low[u] = min(low[u], index[v]);
    }
    if (index[u] == low[u])
    {
        dem++;
        while (s[top] != u)
        {
            res[dem]++;
            int v = s[top--];
            dd[v] = 0;
            tr[v] = u;
        }
        tr[u] = u;
        res[dem]++;
        dd[u] = 0;
        top--;
        res[dem] = 1ll*res[dem]*(res[dem]-1);
    }
}

void xuli()
{
    for (int i = 1; i <= n; i++)
        if (!index[i]) DFS(i);
    tong = accumulate(res+1, res+dem+1, 0ll);
    for (int u = 1; u <= n; u++)
        for (int &v : ke[u])
            if (tr[v] == tr[u]) tong--;
    cout << tong;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    xuli();
    return 0;
}
