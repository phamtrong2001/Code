#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;

int getL(int u, int v)
{
    if (v < u) v += n;
    return s[v] - s[u] - dem[v]*(dist[v] - dist[u]);
}
int getR(int u, int v)
{
    if (u < v) u += n;
    return rig[v] - rig[u] - dem[u]*(dist[u] - dist[v]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        a[i+n] = a[i]; b[i+n] = b[i];
    }

    for (int i = 1; i <= 2*n; i++)
    {
        dist[i] = dist[i-1] + a[i-1];
        lef[i] = lef[i-1] + dem[i-1]*b[i-1];
        dem[i] = dem[i-1] + a[i];
    }
    dem[2*n+1] = 0;
    for (int i = 2*n; i >= 1; i--)
    {
        rig[i] = rig[i+1] + dem[i+1]*b[i];
        dem[i] = dem[i+1] + a[i];
    }

    int lmax = dist[n+1];
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(dist+1, dist+2*n+1, dist[i] + lmax/2);
        int curAns = getL(pos, i) + getR(pos, i)
    }
}
