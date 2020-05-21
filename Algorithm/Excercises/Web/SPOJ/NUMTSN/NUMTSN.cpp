#include <bits/stdc++.h>
#define FOR(i, aa, bb) for (int i = (aa); i <= (bb); i++)
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007
#define ZZ posDigit][cnt3][cnt6][cnt9
#define ZZ3 posDigit-1][cnt3-1][cnt6][cnt9
#define ZZ6 posDigit-1][cnt3][cnt6-1][cnt9
#define ZZ9 posDigit-1][cnt3][cnt6][cnt9-1

using namespace std;

string a, b;
ll dp[51][21][21][21][2];

int solve(string s)
{
    dp[0][0][0][0][0] = 1;
    int n = s.size(); s = "%" + s;
    FOR(posDigit, 1, n)
    {
        int num = s[posDigit] - '0';
        FOR(cnt3, 0, 20)
            FOR(cnt6, 0, 20)
                FOR(cnt9, 0, 20)
                {
                    if (cnt3)
                    {
                        dp[ZZ][1] = dp[ZZ3][1];
                        if (num == 3) dp[ZZ][0] = dp[ZZ3][0];
                        else if (num > 3) dp[ZZ][1] += dp[ZZ3][0];
                    }
                    if (cnt6)
                    {
                        dp[ZZ][1] = dp[ZZ6][1] + dp[ZZ6][0];
                        if (num == 6) dp[ZZ][0] = dp[ZZ6][0];
                        else if (num > 6) dp[ZZ][1] += dp[ZZ6][0];
                    }
                    if (cnt9)
                    {
                        dp[ZZ][1] = dp[ZZ9][1];
                        if (num == 9) dp[ZZ][0] = dp[ZZ3][0];
                    }
                    if (num != 3 && num != 6 && num != 9) dp[ZZ][0] = dp[posDigit-1][cnt3][cnt6][cnt9][0];
                    int mul = num+1;
                    if (num >= 3) mul--;
                    if (num >= 6) mul--;
                    if (num >= 9) mul--;
                    dp[ZZ][1] = (dp[ZZ][1] + dp[posDigit-1][cnt3][cnt6][cnt9][0]*mul + dp[posDigit-1][cnt3][cnt6][cnt9][1]*7) % mod;
                }
    }
    ll res = 0;
    for (int i = 0; i <= 20; i++)
        res = (res + dp[n][i][i][i][0] + dp[n][i][i][i][1]) % mod;
    return res;
}
string rem(string s)
{
    for (int i = s.size()-1; i >= 0; i--)
        if (s[i] == '0') s[i] = '9';
        else
        {
            s[i]--;
            break;
        }
    return s;
}
int main()
{
    freopen("NUMTSN.INP", "r", stdin);
    int Tests; cin >> Tests;
    while (Tests--)
    {
        cin >> a >> b;
        a = rem(a);
        cout <<solve(b) - solve(a)<<endl;
    }
}
