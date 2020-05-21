#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<= b; ++i)
#define FORD(i, a, b) for (int i = a; i>=b; --i)
#define REP(i, a) for (int i = 0; i<a; ++i)
#define N 21
#define pp pair<int, int>
#define bit(S, i) (((S) >> i) & 1)
#define IO cin.tie(NULL);cout.tie(NULL);
#define taskname "FAFLOWER"
using namespace std;

int mark[1 << N];
long long d[1 << N];
int n;
long long t;
char s[N][N];

void Solve() {
    int status = 0;
    REP(i, n) {
        if (s[0][i] == '1') {
            status += 1 << i;
            d[0]++;
        }
    }
    int step = 0;
    long long total = d[0];
    while (true) {
        REP(i, n) cerr<<bit(status, i);
        cerr<<':'<<step<<' '<<total<<endl;
        if (mark[status]) {
            long long ans = (d[step] - d[mark[status]]) * ((t - mark[status] - 1) / (step - mark[status])) + d[mark[status] + (t - mark[status] - 1) % (step - mark[status])];
            printf("%lld", ans);
            return;
        }
        mark[status] = step;
        step++;
        if (step == t) {
            printf("%lld", total);
            return;
        }
        int newStatus = 0;
        REP(i, n) {
            if (bit(status, i)) {
                REP(j, n) if (s[i][j] == '1') {
                    total++;
                    newStatus ^= 1 << j;
                }
            }
            else {
                REP(j, n) if (s[i][j] == '1') {
                    total += 2;
                }
            }
        }
        status = newStatus;
        d[step] = total;
    }
}
int main() {
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    IO;
    scanf("%d %lld", &n, &t);
    REP(i, n) scanf("%s", &s[i]);
    Solve();
}
