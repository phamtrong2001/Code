#include <bits/stdc++.h>
#define llint long long
#define fi first
#define se second
#define db(x) cout << #x << " = " << x << endl;
using namespace std;

void openFile() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
#ifdef Tr___
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("visitors.inp", "r", stdin);
    freopen("visitors.out", "w", stdout);
#endif
}

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const llint inf = 1e9 + 7;

int N;
int a[maxn];
vector<int> allPosition;

void enter() {
    cin >> N;
    allPosition.push_back(0);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        allPosition.push_back(a[i]);
    }
}

inline void mini(llint &a, llint b) {
    a = min(a, b);
}

class SegmentTree {
public:
    llint it[maxn * 4], lz[maxn * 4];
    int L[maxn * 4], R[maxn * 4], leaf[maxn];
    llint defaultValue = inf * inf;

    inline llint combine(llint lef, llint rig) {
        return min(lef, rig);
    }

    inline void pushDown(int x) {
        it[x] += lz[x];
        if (L[x] != R[x]) {
            lz[x<<1] += lz[x];
            lz[x<<1|1] += lz[x];
        }
        lz[x] = 0;
    }

    void buildTree(int x, int low, int high) {
        L[x] = low; R[x] = high;
        if (low == high) {
            leaf[low] = x;
            it[x] = defaultValue;
            return;
        }
        int mid = (low + high) / 2;
        buildTree(x<<1, low, mid);
        buildTree(x<<1|1, mid + 1, high);
        it[x] = combine(it[x<<1], it[x<<1|1]);
    }

    void update(int x, int low, int high, llint val) {
        pushDown(x);
        if (L[x] > high || R[x] < low) return;
        if (low <= L[x] && R[x] <= high) {
            lz[x] = val;
            pushDown(x);
            return;
        }
        update(x<<1, low, high, val);
        update(x<<1|1, low, high, val);
        it[x] = combine(it[x<<1], it[x<<1|1]);
    }

    void update(int pos, llint val) {
        int x = leaf[pos];
        vector<int> gg;
        while (x) {
            gg.push_back(x);
            x /= 2;
        }
        reverse(gg.begin(), gg.end());
        for (int i : gg) {
            pushDown(i);
            if (L[i] != R[i]) {
                pushDown(i<<1);
                pushDown(i<<1|1);
            }
        }

        reverse(gg.begin(), gg.end());

        for (int i = 0; i < gg.size(); ++i) {
            if (i == 0) {
                it[gg[i]] = val;
            }
            else {
                it[gg[i]] = combine(it[gg[i]<<1], it[gg[i]<<1|1]);
            }
        }
    }

    llint query(int x, int low, int high) {
        pushDown(x);
        if (L[x] > high || R[x] < low) return defaultValue;
        if (low <= L[x] && R[x] <= high) {
            return it[x];
        }
        return combine(query(x<<1, low, high), query(x<<1|1, low, high));
    }
};
SegmentTree treeLef, treeRig;

inline int getPosition(int x) {
    return upper_bound(allPosition.begin(), allPosition.end(), x) - allPosition.begin();
}

void solve() {
    treeLef.buildTree(1, 1, N + 1);
    treeRig.buildTree(1, 1, N + 1);

    sort(allPosition.begin(), allPosition.end());
    int school = getPosition(0);

    treeLef.update(school, 0);
    treeRig.update(school, 0);

    int p;
    llint f;
    llint res;
    for (int i = 1; i <= N; ++i) {

        //for (int j = 0; j <= i; ++j) {
        //    mini(f[i + 1][j], f[i][j] + abs(a[i + 1] - a[i]));
        //    mini(f[i + 1][i], f[i][j] + abs(a[i + 1] - a[j]));
        //}
        //(j < i) f[j] = f[j] + abs(a[i] - a[i - 1]);
        //f[i] = min(f[j] + abs(a[i] - a[j]));
        
        p = getPosition(a[i]);
        llint flef = a[i] + treeLef.query(1, 1, p - 1);
        llint frig = treeRig.query(1, p + 1, N + 1) - a[i];
        f = min(flef, frig);
        if (i == N) res = f;

        treeLef.update(1, 1, N + 1, abs(a[i] - a[i - 1]));
        treeRig.update(1, 1, N + 1, abs(a[i] - a[i - 1]));

        treeLef.update(getPosition(a[i - 1]), f - a[i]);
        treeRig.update(getPosition(a[i - 1]), f + a[i]);
    }

    cout << res << endl;
}

int main() {
    openFile();
    enter();
    solve();
    return 0;
}
