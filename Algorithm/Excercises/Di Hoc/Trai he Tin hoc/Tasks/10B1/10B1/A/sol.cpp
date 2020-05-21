#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int) (n); i++)

const int N = 1<<17;

int n, m;

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

main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  T.init();
  while (m--) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      int l, r; cin >> l >> r; l--; r--;
      cout << T.get(l, r+1) << "\n";
    } else {
      int l, r, v; cin >> l >> r >> v; l--; r--;
      T.update(l, r+1, v);
    }
  }
}

