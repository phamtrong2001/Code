#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 30
#define maxc 1000000007

using namespace std;

int n, dd[N], dem[N];
string s;

bool check(int k)
{
    memset(dem, 0, sizeof dem);
    memset(dd, 0, sizeof dd);
    for (int i = 1; i <= k; i++) dd[s[i]-'a']++;
    for (int i = 0; i < 26; i++) dem[i] = (dd[i] > 0);
    for (int i = k+1; i <= n; i++)
    {
        dd[s[i] - 'a']++;
        dd[s[i-k] - 'a']--;
        for (int i = 0; i < 26; i++) dem[i] += (dd[i] > 0);
    }
    for (int i = 0; i < 26; i++)
        if (dem[i] == n-k+1) return 1;
    return 0;
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> s;
    n = s.size(); s = "%" + s;
    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout <<r;
}
