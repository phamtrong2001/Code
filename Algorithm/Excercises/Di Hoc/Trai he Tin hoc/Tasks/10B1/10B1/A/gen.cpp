#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int) (n); i++)
void MAIN();
int main(int argc, char* argv[]) {
//    freopen("input.txt", "r", stdin);

    if (argc < 2) srand(time(0));
    else srand(atoi(argv[1]));
    MAIN();
    return 0;
}

int N = 100000;

void MAIN() {
  ios::sync_with_stdio(false);

  int n = rand() % N + 1, m = rand() % N + 1;
  cout << n << " " << m << "\n";
  while (m--) {
    int l = rand() % n + 1, r = rand() % n + 1;
    if (l > r) swap(l, r);
    if (rand() % 2) {
      cout << "1 " << l << " " << r << "\n";
    } else {
      int v = rand() % N;
      cout << "2 " << l << " " << r << " " << v << "\n";
    }
  }
}

