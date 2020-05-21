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
#define task "binary"
#define maxc 1000000007
#define maxn 10004

using namespace std;

int n, c[maxn];

bool dd[maxn];

ll res;

vector <pii> ke[maxn];

void AddEdge(int u, int v, int color)
{
    ke[u].PB(MP(v, color));
    ke[v].PB(MP(u, color));
}

void DFS(int u)
{
    dd[u] = 1;
    for (auto p : ke[u])
    {
        int v = p.F;
        int color = p.S;
        if (!dd[v])
        {
            c[v] = c[u]^color;
            DFS(v);
        }
            else
            {
                if (c[v] != c[u]^color)
                {
                    cout << 0;
                    exit(0);
                }
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int z;
        cin >> z;
        if (i == 1 && z != 0 && z != -1)
        {
            cout << 0;
            return 0;
        }
        if (i == 1) continue;
        if (z == -1) continue;
        if (z > (n - i + 1))
        {
            cout << 0;
            return 0;
        }
        for (int j = 1; j <= z; j++)
            AddEdge(j, i+j-1, 0);
        if (i+z <= n) AddEdge(z+1, i+z, 1);
    }
    int tplt = 0;
    res = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dd[i]) continue;
        res = (res * 2) % maxc;
        DFS(i);
    }
    cout << res%maxc;
    return 0;
}
