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

const int N = 100000;

void MAIN() {
    int n = rand() % N + 1;
    printf("%d\n", n);
    vector<int> p(n);
    REP(i, n) p[i] = i+1; random_shuffle(p.begin(), p.end());
    REP(i, n) printf("%d%c", p[i], " \n"[i+1==n]);
    REP(i, n) printf("%d%c", rand()%20000+1, " \n"[i+1==n]);
}

