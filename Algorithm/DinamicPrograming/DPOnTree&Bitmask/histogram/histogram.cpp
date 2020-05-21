#include <bits/stdc++.h>
#define F first
#define S second
#define maxC 1000000000
#define MOD 1000000007
#define pil pair <int, long long>
#define mp make_pair
#define PB push_back
#define Task "histogram"
#define ll long long
using namespace std;
const int maxbit = 20;
const int MaxM = 65540;
int dp[MaxM][maxbit], nho[MaxM][maxbit];
ll num[MaxM][maxbit];
int n, h[maxbit];

pil calc(int y, int j) {
    if(y == (1 << (j-1))) {
        num[1 << (j-1)][j] = 1;
        return {(2 + h[j] * 2), 1};
    }
    if(nho[y][j]) return {dp[y][j], num[y][j]};
    nho[y][j] = 1; dp[y][j] = -maxC;
    int x = y ^ (1 << (j-1));
    for(int i=1 ; i<=n ; ++i)
        if((x >> (i-1)) & 1) {
                ll t = calc(x, i).F + 1ll* (h[j] - h[i]) + 1ll * abs(h[j] - h[i]) + 1ll * 2;
                if(dp[y][j] < t) {
                    dp[y][j] = t;
                    num[y][j] = num[x][i];
                }
                else if(dp[y][j] == t) num[y][j] += num[x][i];
        }
    return {dp[y][j], num[y][j]};
}

int main() {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    while(scanf("%d", &n)) {
        if(!n) return 0;
        memset(nho, 0, sizeof nho);
        for(int i=1 ; i<=n ; ++i) scanf("%d", &h[i]);
        int ans = 0;
        ll hv = 0;
        for(int i=1 ; i<=n ; ++i) {
            if(ans < calc((1 << n) - 1, i).F) {
                hv = calc((1 << n) - 1, i).S;
                ans = calc((1 << n) - 1, i).F;
            } else if(ans == calc((1 << n) - 1, i).F) {
                hv += calc((1 << n) - 1, i).S;
            }
        }
        printf("%d %lld\n", ans, hv);
    }
    return 0;
}
