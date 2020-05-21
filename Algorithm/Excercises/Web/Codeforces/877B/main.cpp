#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, sa[N], sb[N], res;
string s;

int main()
{
    cin >> s; n = s.size(); s = "%" + s;
    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i-1] + (s[i] == 'a');
        sb[i] = sb[i-1] + (s[i] == 'b');
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int ans = sa[i-1] - sa[0] + sa[n] - sa[j-1] + sb[j] - sb[i-1];
            res = max(res, ans);
        }
    cout <<res;
}
