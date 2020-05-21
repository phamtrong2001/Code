#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
using namespace std;

ll n, x[N], d[N];
int cur, m, k;
vector<pii> a[N];
map<ll, ll> ma;
void nhap()
{
    cin >> n >> k;
    x[++cur] = n; x[++cur] = 1;
    for (int i = 1; i <= k; i++)
    {
        ll u; cin >> u;
        x[++cur] = u;
        ll step = sqrt(u-1) + 1;
        ll start = (step-1)*(step-1);
        ll len = step*step - start;
        ll number = (step*2-2)*2-1;
        if (u - start <= len/2) number -= 2;
        x[++cur] = u - number;
        ma[u] = u - number;
    }
    sort(x+1, x+cur+1);
    m = unique(x+1, x+cur+1) - x - 1;
    for (int i = 2; i <= m; i++)
    {
        a[i-1].PB(mp(i, x[i] - x[i-1]));
        a[i].PB(mp(i-1, x[i] - x[i-1]));
        if (!ma[x[i]]) continue;
        int pos = lower_bound(x+1, x+m+1, ma[x[i]]) - x;
        a[pos].PB(mp(i, 1));
        a[i].PB(mp(pos, 1));
    }
}

void IJK()
{
    priority_queue<pii> q;
    memset(d, 60, sizeof d);
    d[1] = 0;
    q.push(mp(0, 1));
    while (!q.empty())
    {
        int u = q.top().S;
        ll l = -q.top().F;
        q.pop();
        if (d[u] < l) continue;
        for (auto z : a[u])
        {
            int v = z.F;
            ll w = z.S;
            if (d[v] > w + l)
            {
                d[v] = w + l;
                q.push(mp(-d[v], v));
            }
        }
    }
    int pos = lower_bound(x+1, x+m+1, n) - x;
    cout <<d[pos];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    nhap();
    IJK();
}
