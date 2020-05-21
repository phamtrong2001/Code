#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
int main()
{
    freopen("REMEMBER.INP", "r", stdin);
    freopen("REMEMBER.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
        {
            int cpmax = 0;
            for (int k = 1; k <= n; k++)
                if (s[i][j] == s[k][j])
                {
                    mask[i][j] |= (1 << (k-1));
                    cpmax = max(cpmax, a[k][j]);
                    c[i][j] += a[k][j];
                }
                c[i][j] -= cpmax;
        }
    for (int i = 1; i < (1 << n); i++)
    {

    }
}
