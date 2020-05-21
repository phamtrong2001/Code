/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define task "financial"

using namespace std;

int n, k, a[maxn], z, c[maxn], tr[maxn], t[maxn*4];

vector <int> b;

int cmax(int i, int j)
{
    return (c[i] > c[j]) ? i : j;
}

void update(int l, int r, int id ,int u, int v)
{
    t[id] = cmax(t[id], v);
    if (l == r) return;
    int mid = (l+r) >> 1;
    if (mid >= u) update(l, mid, id*2, u, v);
        else update(mid+1, r, id*2+1, u, v);
}

int get_max(int l, int r, int id, int u, int v)
{
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return t[id];
    int mid = (l+r) >> 1;
    int m1 = get_max(l, mid, id*2, u, v);
    int m2 = get_max(mid+1, r, id*2+1, u, v);
    return cmax(m1, m2);
}

void write(int i)
{
    if (tr[i]) write(tr[i]);
    cout << a[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    b.assign(a+1, a+n+1);
    b.PB(-maxc);
    b.PB(maxc);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    z = b.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        int p = lower_bound(b.begin(), b.end(), a[i]-k+1) - b.begin() - 1;
        int q = lower_bound(b.begin(), b.end(), a[i]+k) - b.begin();
        int j = cmax(get_max(0, z, 1, 0, p), get_max(0, z, 1, q, z));
        c[i] = c[j] + 1;
        tr[i] = j;
        int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        update(0, z, 1, x, i);
    }
    cout << c[t[1]] << endl;
    write(t[1]);
    return 0;
}
