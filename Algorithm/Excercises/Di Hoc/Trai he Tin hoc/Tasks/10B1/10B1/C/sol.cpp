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

const int N = 100032;
int n, m, a[N], l[N], r[N];

struct ST{
    int s[N<<2], lz[N<<2];
    void init(int k = 0, int l = 0, int r = n) {
        if (l >= r) return;
        s[k] = 0;
        lz[k] = -1;
        if (l+1 == r) return;
        init(k*2 + 1, l, l+r>>1);
        init(k*2 + 2, l+r>>1, r);
    }

    void pass(int k, int l, int r) {
        if (lz[k] == -1) return;
        int md = l + r >> 1;
        update(2*k+1, l, md, l, md, lz[k]);
        update(2*k+2, md, r, md, r, lz[k]);
        lz[k] = -1;
    }

    void update(int k, int l, int r, int p, int q, int v) {
        if (l >= r || l >= q || r - 1 < p || p >= q) return;
        if (l >= p && r <= q) {
            s[k] = v * (r - l);
            lz[k] = v;
            return;
        }
        pass(k, l, r);
        update(2*k+1, l, l+r>>1, p, q, v);
        update(2*k+2, l+r>>1, r, p, q, v);
        s[k] = s[2*k+1] + s[2*k+2];
    }

    int get(int k, int l, int r, int p, int q) {
        if (l >= r || l >= q || r-1 < p || p >= q) return 0;
        if (l >= p && r <= q) return s[k];
        pass(k, l, r);
        return get(2*k+1, l, l+r>>1, p, q) +
               get(2*k+2, l+r>>1, r, p, q);
    }
    void update(int p, int q, int v) { update(0, 0, n, p, q, v); }
    int get(int p, int q) { return get(0, 0, n, p, q); }
} T;


void MAIN() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", &a[i]), a[i]--;
    REP(i, m) scanf("%d%d", &l[i], &r[i]), l[i]--, r[i]--;
    
    int target = n/2, base = 0;
    for (int i = 16; i >= 0; i--) if (base + (1<<i) < n) {
        int lim = base + (1<<i);
        T.init();
        REP(j, n) if (a[j] >= lim) {
            T.update(j, j+1, 1);
        }
        REP(j, m) {
            int p = min(l[j], r[j]), q = max(l[j], r[j]);
            int one = T.get(p, q+1), zero = q-p+1 - one;

            if (l[j] < r[j]) {
                T.update(p, q+1, 1);
                T.update(p, p+zero, 0);
            } else {
                T.update(p, q+1, 0);
                T.update(p, p+one, 1);
            }
        }
        int val = T.get(target, target+1);
        if (val) base = lim;
    }
    cout << base + 1 << endl;
}
