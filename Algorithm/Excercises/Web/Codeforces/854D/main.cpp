#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1200005
#define maxc 1000000007

using namespace std;

int n, m, k, dem1[N], dem2[N];
long long res1[N], res2[N];
int dd[N];
long long res = 1ll*1000000000000000007;
struct flight
{
    int u, v, w;
    flight(int u=0, int v=0, int w=0) : u(u), v(v), w(w) {}
};
vector<flight> allFlight[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int d, u, v, w;
        cin >> d >> u >> v >> w;
        allFlight[d].PB(flight(u, v, w));
    }

    for (int i = 1; i < N-1; i++)
    {
        dem1[i] = dem1[i-1];
        res1[i] = res1[i-1];
        for (auto z : allFlight[i])
        {
            if (z.u == 0) continue;
            else
            {
                if (z.w >= dd[z.u] && dd[z.u]) continue;

                if (!dd[z.u])
                {
                    dem1[i]++;
                    res1[i] += 1ll*z.w;
                }
                else res1[i] -= 1ll*(dd[z.u] - z.w);
                dd[z.u] = z.w;
            }
        }
    }
    memset(dd, 0, sizeof dd);
    for (int i = N-2; i >= 1; i--)
    {
        dem2[i] = dem2[i+1];
        res2[i] = res2[i+1];
        for (auto z : allFlight[i])
        {
            if (z.v == 0) continue;
            else
            {
                if (z.w >= dd[z.v] && dd[z.v]) continue;

                if (!dd[z.v])
                {
                    dem2[i]++;
                    res2[i] += 1ll*z.w;
                }
                else res2[i] -= 1ll*(dd[z.v] - z.w);
                dd[z.v] = z.w;
            }
        }
    }
    for (int i = 1; i < N - 2*k; i++)
    {
        int j = i + k - 1;
        if (dem1[i-1] == n && dem2[j+1] == n)
            res = min(res, res1[i-1] + res2[j+1]);
    }
    if (res == 1ll*1000000000000000007) cout <<-1;
    else cout <<res;
}
