#include <bits/stdc++.h>
#define N 500
using namespace std;

int n, a[N];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i < N; i++) a[i] = i*(i-1)/2;
    int dem = 0;
    if (n == 0)
    {
        cout <<'a';
        return 0;
    }
    while (n > 0)
    {
        dem++;
        int pos = upper_bound(a+1, a+N, n) - a - 1;
        n -= a[pos];
        for (int i = 1; i <= pos; i++)
        {
            char c = 'a' + dem - 1;
            cout <<c;
        }
    }
}
