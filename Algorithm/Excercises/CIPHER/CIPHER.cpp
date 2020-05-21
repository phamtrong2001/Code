#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define BASE 97
#define maxc 1000000007

using namespace std;

int n, m, A, B, cnt, cnt1, cnt2;
string s[N];
ll b1[N][N], b2[N][N], h[N*N], all1[N*N], all2[N*N], a[N][N];
map<ll, int> dd, dem;

ll get1(int u, int v)
{
    int v1 = v + B - 1;
    return b1[u][v1] - b1[u][v-1]*h[v1-v+1];
}
ll get2(int u, int v)
{
    int u1 = u + A - 1;
    return b2[u1][v] - b2[u-1][v]*h[u1-u+1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CIPHER.INP", "r", stdin);
    freopen("CIPHER.OUT", "w", stdout);
    cin >> n >> m;
    getline(cin, s[1]);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s[i]);
        s[i] = "#" + s[i];
    }
    cin >> A >> B; cout <<A<<" "<<B<<endl;
    h[0] = 1;
    for (int i = 1; i < N*N; i++) h[i] = h[i-1]*BASE;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b1[i][j] = (b1[i][j-1]*BASE + s[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m-B+1; j++)
        {
            ll x = get1(i, j);
            a[i][j] = x;
            all1[++cnt1] = x;
        }
    sort(all1+1, all1+cnt1+1);
    cnt1 = unique(all1+1, all1+cnt1+1) - all1 - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m-B+1; j++)
            a[i][j] = lower_bound(all1+1, all1+cnt1+1, a[i][j]) - all1;

    for (int j = 1; j <= m-B+1; j++)
        for (int i = 1; i <= n; i++)
            b2[i][j] = (b2[i-1][j]*BASE + a[i][j]);

    ll res = 0, ans = 0;
    for (int i = 1; i <= n-A+1; i++)
        for (int j = 1; j <= m-B+1; j++)
        {
            ll x = get2(i, j);
            all2[++cnt2] = x;
        }
    sort(all2+1, all2+cnt2+1);
    int cur = 0;
    for (int i = 1; i <= cnt2; i++)
    {
        if (all2[i] != all2[cur])
        {
            cur++;
            all2[cur] = all2[i];
            dem[cur] = 1;
        }
        else dem[cur]++;
    }
    for (int i = 1; i <= cur; i++)
        if (dem[i] > dem[res]) res = i;

    bool flag = 0;
    for (int i = 1; i <= n-A+1; i++)
        for (int j = 1; j <= m-B+1; j++)
        {
            ll x = get2(i, j);
            if (x == all2[res] && !flag)
            {
                for (int h = i; h <= i+A-1; h++)
                {
                    for (int k = j; k <= j+B-1; k++) cout <<s[h][k];
                    cout <<'\n';
                }
                flag = 1;
            }
        }
    cout <<dem[res]<<'\n';
    for (int i = 1; i <= n-A+1; i++)
        for (int j = 1; j <= m-B+1; j++)
        {
            ll x = get2(i, j);
            if (x == all2[res]) cout <<i<<" "<<j<<'\n';
        }
}
