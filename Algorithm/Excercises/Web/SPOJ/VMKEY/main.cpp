#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
using namespace std;

string s;
int d[11][11], dis[11][11], p[11];
pii key[11];
vector<pii> all;

int calc()
{
    int ans = 0;
    for (auto z : all)
    {
        int i = z.F;
        int j = z.S;
        int u = p[i];
        int v = p[j];
        ans += d[i][j] * dis[u][v];
        //if (ans > res) return 1e9+7;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 1; i < s.size(); i++)
        d[s[i-1] - '0' + 1][s[i] - '0' + 1]++;
    for (int i = 1; i <= 10; i++)
    {
        int u = (i-1)/3 + 1;
        int v = i % 3; if (v == 0) v = 3;
        key[i] = mp(u, v);
    }
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            dis[i][j] = abs(key[i].F - key[j].F) + abs(key[i].S - key[j].S);
            if (d[i][j] > 0) all.PB(mp(i, j));
        }
    for (int i = 1; i <= 10; i++) p[i] = i;

    int res = calc();
    while (next_permutation(p+1, p+11))
    {
        res = min(res, calc());
    }
    cout <<res;
}
