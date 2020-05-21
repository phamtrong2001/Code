/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 40004
#define task "dct"

using namespace std;

int n, a[maxn], res = -maxc, t[maxn], f[maxn], tr[maxn], b[maxn];

vector <int> v;

int fmax(int i, int j)
{
    return (f[i] < f[j]) ? j : i;
}

void update(int x, int val)
{
    while (x < maxn)
    {
        t[x] = fmax(t[x], val);
        x += x & (-x);
    }
}

int get(int x)
{
    int cur = 0;
    while (x > 0)
    {
        cur = fmax(cur, t[x]);
        x -= x & (-x);
    }
    return cur;
}

void ghi(int i)
{
    if (tr[i]) ghi(tr[i]);
    cout << b[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memcpy(b, a, sizeof (a));
    v.assign(a+1, a+n+1);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[get(a[i]-1)] + 1;
        tr[i] = get(a[i]-1);
        update(a[i], i);
    }
    cout << *max_element(f+1, f+n+1) << endl;
    int x = max_element(f+1, f+n+1) - f;
    ghi(x);
    return 0;
}
