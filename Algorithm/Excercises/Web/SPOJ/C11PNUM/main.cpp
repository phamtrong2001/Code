#include <bits/stdc++.h>
#define N 3000006
#define ll unsigned long long
#define PB push_back
using namespace std;

bool dd[N];
vector<ll> all;
ll n;
int k, t;
void prepare()
{
    dd[0] = dd[1] = 1;
    for (int i = 2; i < N; i++)
        if (!dd[i])
        {
            all.PB(i);
            for (int j = 2*i; j < N; j+=i) dd[j] = 1;
        }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    prepare();
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll res = 0;
        for (int i = 0; i < all.size() - k; i++)
        {
            ll cur = 1;
            bool flag = 0;
            for (int j = i; j < i + k; j++)
            {
                if (cur > n/all[j]) {flag = 1; break;}
                cur = cur*all[j];
            }
            if (flag == 1) continue;
            if (cur <= n) res = cur;
        }
        if (res == 0) cout <<-1<<'\n';
        else cout <<res<<'\n';
    }
}
