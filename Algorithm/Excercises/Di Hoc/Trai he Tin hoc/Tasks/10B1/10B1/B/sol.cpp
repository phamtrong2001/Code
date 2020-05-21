#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int) (n); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maximize(a, b) ((a)<(b)?(a)=(b),1:0)
#define minimize(a, b) ((a)>(b)?(a)=(b),1:0)
void MAIN();
int main() {
    MAIN();
    return 0;
}

const int N = 1<<17, INF = (int) 2e9;

struct Value{
    int maxX, minF;
    Value(int x = 0, int y = INF):
        maxX(x), minF(y) {}

    void combine(const Value &x) {
        maxX = max(maxX, x.maxX);
        minF = min(minF, x.minF);
    }
} W[N*2], H[N*2];

int n, p[N], v[N], f[N];

#define md ((l+r)>>1)
void get(int k, int l, int r, int y, Value &x) {
    if (W[k].maxX < x.maxX) return;
    if (l + 1 == r) {
        x.combine(W[k]);
        return;
    }
    if (y < md) {
        get(2*k+1, l, md, y, x);
        return;
    }
    get(2*k+2, md, r, y, x);
    if (x.maxX == W[2*k+2].maxX) x.combine(H[k]);
    else get(2*k+1, l, md, y, x);

}

void add(int k, int l, int r, int y, int x) {
    if (l + 1 == r) {
        W[k] = H[k] = Value(x, f[x]);
        return;
    }
    if (y < md) add(2*k+1, l, md, y, x);
    else        add(2*k+2, md, r, y, x);

    H[k] = Value(W[2*k+2].maxX); get(2*k+1, l, md, n, H[k]);
    W[k] = W[2*k+2]; W[k].combine(H[k]);
}



void MAIN() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    p[n+1] = n+1;
    n += 2;
    
    add(0, 0, n, p[0], 0);
    for (int i = 1; i < n; i++) {
        Value x;
        get(0, 0, n, p[i], x);
        f[i] = x.minF + v[i];
        add(0, 0, n, p[i], i);
    }
    printf("%d\n", f[n-1]);
}

