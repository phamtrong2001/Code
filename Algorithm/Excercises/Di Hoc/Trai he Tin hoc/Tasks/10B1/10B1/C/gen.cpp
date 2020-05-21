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
int main(int argc, char* argv[]) {
//    freopen("input.txt", "r", stdin);

    srand(atoi(argv[1]));
    MAIN();
    return 0;
}

const int N = 998;

void MAIN() {
    int n = rand() % N; if (n % 2 == 0) n++;
    int m = rand() % N + 1;
    printf("%d %d\n", n, m);

    vector<int> a(n);
    REP(i, n) a[i] = i+1; random_shuffle(a.begin(), a.end());
    REP(i, n) printf("%d%c", a[i], " \n"[i+1==n]);

    REP(i, m) {
        int l = rand() % n + 1, r = rand() % n + 1;
        printf("%d %d\n", l, r);
    }
}

