#include <bits/stdc++.h>

using namespace std;

int n, a[8];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < 7; i++) a[i] = 0;
    a[5] = a[6] = 1;

    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[i % 7];
    cout <<res<<" ";

    for (int i = 0; i < 7; i++) a[i] = 0;
    a[0] = a[1] = 1;
    res = 0;
    for (int i = 0; i < n; i++)
        res += a[i % 7];
    cout <<res;
}
