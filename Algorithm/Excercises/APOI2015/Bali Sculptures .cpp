#include <cstdio>
#include <algorithm>
using namespace std;

int n, a, b;
int y[2000];
long long sum[2001];
bool dp1[101][101];

bool ok1(long long mask) {
    dp1[0][0] = 1;
    for(int i = 1; i <= b; i++)
        dp1[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        dp1[i][0] = 0;
        for(int j = 1; j <= b; j++) {
            dp1[i][j] = 0;
            for(int k = 0; k < i; k++)
                if(dp1[k][j - 1] && ((sum[i] - sum[k]) & ~mask) == 0) {
                    dp1[i][j] = 1;
                    break;
                }
        }
    }
    for(int i = a; i <= b; i++)
        if(dp1[n][i])
            return 1;
    return 0;
}

int dp2[2001];

bool ok2(long long mask) {
    dp2[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp2[i] = b + 1;
        for(int j = 0; j < i; j++)
            if(((sum[i] - sum[j]) & ~mask) == 0)
                dp2[i] = min(dp2[i], dp2[j] + 1);
    }
    return dp2[n] <= b;
}

bool ok(long long mask) {
    return a == 1 ? ok2(mask) : ok1(mask);
}

int main() {
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++) {
        scanf("%d", y + i);
        sum[i + 1] = sum[i] + y[i];
    }
    long long mask = 0x1FFFFFFFFFFLL;
    for(long long high = 0x10000000000LL; high; high >>= 1)
        if(ok(mask & ~high))
            mask &= ~high;
    printf("%lld\n", mask);
}