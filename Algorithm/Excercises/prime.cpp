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
#define task "prime"
#define maxc 1000000007
#define maxn 100005

using namespace std;

int n, f[maxn];

bool dd[maxn];

void chuanbi()
{
    memset(dd, 1, sizeof (dd));
    memset(f, 0, sizeof (f));
    for (int i = 2; i <= 1000; i++)
        for (int j = i+i; j <= 100005; j+=i)
            dd[j] = 0;
    f[1] = f[0] = 0;
    for (int i = 2; i <= 100005; i++)
        f[i] = f[i-1] + dd[i];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    chuanbi();
    cin >> n;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        cout << f[r] - f[l-1] << '\n';
    }
    return 0;
}
