#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2100005
#define maxc 1000000007

using namespace std;

int n, k, s[N], dp[N];
string str;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VOCARD.INP", "r", stdin);
    cin >> n >> k >> str;
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + (str[i-1] == '1');

    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && q.back() < i-k) q.pop_back();
        dp[i] = s[i] - dp[q.back()];
        while (!q.empty() && dp[q.front()] >= dp[i]) q.pop_front();
        q.push_front(i);
    }
    if (dp[n]*2 == s[n]) cout <<"NO";
    else
        cout <<"YES"<<endl<<min(dp[n], s[n]-dp[n]);
}
