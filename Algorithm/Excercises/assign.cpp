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
#define task "assign"
#define maxc 1000000007
#define maxn 100005

using namespace std;

int m, n, old, res, match[maxn], l[maxn];

vector <int> a[maxn];

bool dd[maxn], found;

void nhap()
{
//    int c;
//    cin >> m >> n >> c;
    cin >> m >> n;
    int u, v;
    while (cin >> u >> v)
        a[u].PB(v);
}

void DFS(int u)
{
    for (int &v : a[u])
        if (!dd[v])
        {
            dd[v] = 1;
            if (!match[v]) found = 1;
                else DFS(match[v]);
            if (found)
            {
                match[v] = u;
                return;
            }
        }
}

void xuli()
{
    int nlist = m;
    for (int i = 1; i <= m; i++) l[i] = i;
    while (old != nlist)
    {
        old = nlist;
        memset(dd, 0, sizeof (dd));
        for (int i = nlist; i >= 1; i--)
        {
            found = 0;
            DFS(l[i]);
            if (found)
            {
                l[i] = l[nlist];
                nlist--;
            }
        }
    }
}

void ghi()
{
    for (int i = 1; i <= n; i++)
        if (match[i]) res++;
    cout << res << '\n';
    for (int i = 1; i <= n; i++)
        cout << match[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    xuli();
    ghi();
    return 0;
}
