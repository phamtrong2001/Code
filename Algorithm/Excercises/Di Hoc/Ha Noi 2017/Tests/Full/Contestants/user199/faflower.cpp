#include <bits/stdc++.h>
#define maxn 21

using namespace std;
int n, dd[maxn], ddd[maxn], dddd[maxn];
char c[maxn][maxn];
long long t;
vector <int> g[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("faflower.inp","r",stdin);
    freopen("faflower.out","w",stdout);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '1') g[i].push_back(j);
        }
    int dem = 0;
    for (auto v : g[1])
    {
        dd[v] += 1;
        dem ++;
    }
    t--;
    long long t1 = t;
    while (t--)
    {
        for (int i = 1; i <= n; i++) ddd[i] = dd[i];
        memset(dd, 0, sizeof(dd));
        for (int i = 1; i <= n; i++)
        {
            if (ddd[i] % 2 == 0)
            {
                for (auto v : g[i])
                {
                    dem += 2;
                    dd[v] += 2;
                }
            }
            else {
                for (auto v : g[i])
                {
                    dem += 1;
                    dd[v] += 1;
                }
            }
        }
    }
    cout << dem;
}
