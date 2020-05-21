#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007
#define add(x, y) {x += y; if (x >= mod) x -= mod;}

using namespace std;

int n;
ll a[N], M[N][25], res;
ll getGCD(int u, int v)
{
    int k = log2(v-u+1);
    return __gcd(M[u][k], M[v-(1<<k)+1][k]);
}

ll trau()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll curGCD = a[i];
        for (int j = i; j <= n; j++)
        {
            curGCD = __gcd(curGCD, a[j]);
            res = (res + curGCD) % mod;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VOGCDSUM.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) M[i][0] = a[i];
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            M[j][i] = __gcd(M[j][i-1], M[j+(1<<(i-1))][i-1]);
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (j <= n)
        {
            ll val = getGCD(i, j);
            int l = j, r = n+1;
            while (r - l > 1)
            {
                int mid = (r + l)/2;
                if (getGCD(i, mid) != val) r = mid;
                else l = mid;
            }
            res = (res + val*(r - j)) % mod;
            j = r;
        }
    }
    cout <<res<<" "<<trau();
}
