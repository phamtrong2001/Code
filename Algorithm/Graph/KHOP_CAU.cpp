#include <bits/stdc++.h>
#define MAX(x, y) if (x < y) x = y;
#define MIN(x, y) if (x > y) x = y;
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define MOD 1000000007
#define BASE 97
#define maxn 1000006

using namespace std;

vector <int> a[maxn];

vector <pii> vcau;

int cau = 0;

bool khop[maxn];

int n, m, index[maxn], low[maxn], Time=0;

void visit(int u, int p)
{
    int snc = 0;
    low[u] = index[u] = ++Time;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if (v != p)
        {
            if (index[v] != 0) low[u] = min(low[u], index[v]);
            else
            {
                visit(v, u);
                snc++;
                low[u] = min(low[u], low[v]);
                if (low[v] >= index[v]) cau++, vcau.PB(mp(u, v));
                if (u == p)
                {
                    if (snc >= 2) khop[u] = 1;
                }
                else
                {
                    if (low[v] >= index[u]) khop[u] = 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    for (int i = 1; i <= n; i++) if (!index[i]) visit(i, i);
    int dem = 0;
    for (int i = 1; i <= n; i++) if (khop[i]) dem++;
    cout << dem <<" "<< cau;
}
