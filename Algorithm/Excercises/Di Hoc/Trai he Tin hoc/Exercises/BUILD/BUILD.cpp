#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, p, d[N];
vector<pii> a[N];
void nhap()
{
    cin >> n >> m >> p;
    for (long long i = 1; i <= m; i++)
    {
        long long u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, w));
    }
    for (long long i = 1; i <= p; i++)
    {
        long long u, v, w; cin >> u >> v >> w;
        a[v].PB(mp(u, -w));
    }
}
void Bell()
{
    for (long long i = 1; i <= n; i++) d[i] = 1ll*maxc*maxc;
    d[1] = 0;
    for (long long i = 1; i <= n; i++)
    {
        bool flag = 0;
        for (long long u = 1; u <= n; u++)
            for (int j = 0; j < a[u].size(); j++)
            {
                long long v = a[u][j].F;
                long long w = a[u][j].S;
                if (d[u] + w < d[v])
                {
                    flag = 1;
                    d[v] = d[u] + w;
                }
            }
        if (i == n && flag) {cout <<-1; exit(0);}
    }
    if (d[n] == 1ll*maxc*maxc) {cout <<-2; exit(0);}
    cout <<d[n];
}

int main()
{
    freopen("BUILD.INP", "r", stdin);
    freopen("BUILD.OUT", "w", stdout);
    nhap();
    Bell();

}
