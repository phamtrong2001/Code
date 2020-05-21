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
#define task "os"
#define maxc 1000000007
#define maxn 200005

using namespace std;

int m, n, res;
pii t[maxn << 2];

bool dd[maxn];

pii a[maxn];

vector <int> v;

void nhap()
{
    cin >> m >> n;
    if (!n)
    {
        cout << 0;
        exit(0);
    }
    res = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].F >> a[i].S;
        v.PB(a[i].F);
        v.PB(a[i].S);
    }
}

void upgrade(int id)
{
    if (!t[id].S) return;
    t[id*2] = t[id*2+1] = t[id];
    t[id].S = 0;
}

void update(int l, int r, int id, int u, int v)
{
    if (r < u || l > v) return;
    if (u <= l && v >= r)
    {
        t[id] = MP(1, 1);
        return;
    }
    upgrade(id);
    int mid = (l + r) >> 1;
    update(l, mid, id*2, u, v);
    update(mid+1, r, id*2+1, u, v);
    t[id].F = t[id*2].F + t[id*2+1].F;
}

void chuanbi()
{
    v.PB(m);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++)
    {
        a[i].F = lower_bound(v.begin(), v.end(), a[i].F) - v.begin() + 1;
        a[i].S = lower_bound(v.begin(), v.end(), a[i].S) - v.begin() + 1;
    }
    m = lower_bound(v.begin(), v.end(), m) - v.begin() + 1;
}

ll get_sum(int l, int r, int id, int u, int v)
{
    if (r < u || l > v) return 0;
    if (u <= l && v >= r) return t[id].F;
    upgrade(id);
    int mid = (l + r) >> 1;
    ll m1 = get_sum(l, mid, id*2, u, v);
    ll m2 = get_sum(mid+1, r, id*2+1, u, v);
    return m1+m2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    chuanbi();
    for (int i = n; i >= 1; i--)
    {
        ll s = get_sum(1, m, 1, a[i].F, a[i].S);
        if (s) res--;
        update(1, m, 1, a[i].F, a[i].S);
    }
    cout << res;
    return 0;
}
