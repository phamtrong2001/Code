#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n, m, ok[N], tt, ans[N];
string s[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        s[n+i] = s[u] + s[v];
        if (s[n+i].size() >= 1000000)
        {
            ans[n+i] =  max(ans[u], ans[v]);
            cout <<ans[n+i]<<'\n';
            continue;
        }
        int res = 0;
        while (1)
        {
            tt++;
            for (int j = 0; j < s[n+i].size(); j++)
            {
                int sum = 0;
                if (j+res >= s[n+i].size()) break;
                for (int k = j; k <= j+res; k++) sum += (s[n+i][k]-'0')*(1 << (k-j));
                ok[sum] = tt;
            }
            bool flag = 0;
            for (int j = 0; j < (1 << (res+1)); j++)
                if (ok[j] != tt) flag = 1;
            if (flag) break;
            else res++;
        }
        ans[n+i] = res;
        cout <<ans[n+i]<<'\n';
    }

}
