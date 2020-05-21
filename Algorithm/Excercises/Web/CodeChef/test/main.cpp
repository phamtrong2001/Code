#include <bits/stdc++.h>
#define mid (l + r)/2
#define mod 1000000007
#define N 100005
#define ll long long

using namespace std;

int n, k;
ll f[N];
struct IT
{
    ll t[N << 3];
    int lazy[N << 3];
    ll pre[N << 3];

    void push(int id)
    {
        if (lazy[id] == 0) return;
        int z = lazy[id];
        ll u = t[id];
        ll v = pre[id];
        t[id] = ((f[z+1]*u) % mod + (f[z]*v) % mod) % mod;
        pre[id] = ((f[z]*u) % mod + (f[z-1]*v) % mod) % mod;
        lazy[id*2] += z;
        lazy[id*2+1] += z;
        lazy[id] = 0;
    }
    void build(int l, int r, int id)
    {
        if (l == r)
        {
            pre[id] = 1;
            return;
        }
        build(l, mid, id*2);
        build(mid+1, r, id*2+1);
        pre[id] = pre[id*2] + pre[id*2+1];
    }
    void update(int l, int r, int id, int x, int y)
    {
        push(id);
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            lazy[id] = 1;
            push(id);
            return;
        }
        update(l, mid, id*2, x, y);
        update(mid+1, r, id*2+1, x, y);
        t[id] = (t[id*2] + t[id*2+1]) % mod;
        push(id*2); push(id*2+1);
        pre[id] = (pre[id*2] + pre[id*2+1]) % mod;
    }
    ll get_ans(int l, int r, int id, int x, int y)
    {
        push(id);
        //pre[id] = (pre[id*2] + pre[id*2+1]) % mod;
        if (l > y || r < x) return 0;
        if (l >= x && r <= y) return t[id];
        ll a = get_ans(l, mid, id*2, x, y);
        ll b = get_ans(mid+1, r, id*2+1, x, y);
        //pre[id] = (pre[id*2] + pre[id*2+1]) % mod;
        return (a + b) % mod;
    }
}t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("INP.TXT", "r", stdin);
    cin >> n >> k;
    f[0] = 0; f[1] = 1;
    for (int i = 2; i < N; i++) f[i] = (f[i-1] + f[i-2]) % mod;
    t.build(1, n, 1);
    for (int i = 1; i <= k; i++)
    {
        char c; int u, v;
        cin >> c >> u >> v;
        if (c == 'D') t.update(1, n, 1, u, v);
        else cout <<t.get_ans(1, n, 1, u, v)<<endl;
    }
}
