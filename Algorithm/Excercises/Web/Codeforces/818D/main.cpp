#include <bits/stdc++.h>
#define N 1000006

using namespace std;

int n, A, a[N], res[N], dem[N];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> n >> A;
    for (int i = 1; i <= n; i++) cin >> a[i];

    res[A] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == A)
        {
            dem[A]++;
            continue;
        }
        if (res[a[i]]) continue;
        if (dem[a[i]] < dem[A]) res[a[i]] = 1;
        dem[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != A && res[a[i]] == 0 && dem[a[i]] >= dem[A])
        {
            cout <<a[i];
            return 0;
        }
    cout <<-1;
}
