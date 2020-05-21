#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, xx[10], a[N], calced[N], f[N], dp[N];
vector<int> all[1005][7];

string convert(int x)
{
    string ans;
    stringstream ss;
    ss << x;
    ss >> ans;
    return ans;
}
void tinh(string s, int id)
{
    string w = "";
    int cur = 0;
    int dem = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (xx[i] == 0) {dem++; continue;}
        w = w + s[i];
        cur = cur*10 + s[i] - '0';
    }
    if (dem == s.size() || (w.size() > 1 && w[0] == '0')) return;
    all[id][dem].PB(cur);
}
void duyet(string s, int pos, int id)
{
    if (pos >= s.size())
    {
        tinh(s, id);
        return;
    }
    xx[pos] = 0;
    duyet(s, pos+1, id);
    xx[pos] = 1;
    duyet(s, pos+1, id);
}
void prepare(int id, int x)
{
    string s = convert(x);
    duyet(s, 0, id);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("RECOVERY.INP", "r", stdin);
    freopen("RECOVERY.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prepare(i, a[i]);
    }
    for (int i = 0; i < N; i++) dp[i] = maxc;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 6; j >= 0; j--)
            for (auto x : all[i][j])
                dp[x] = min(dp[x], j + f[x]);
        f[0] = dp[0]; dp[0] = maxc;
        for (int j = 1; j < N; j++)
        {
            f[j] = min(f[j-1], dp[j]);
            dp[j] = maxc;
        }
    }
    if (f[N-1] == maxc) f[N-1] = -1;
    cout <<f[N-1];
}
