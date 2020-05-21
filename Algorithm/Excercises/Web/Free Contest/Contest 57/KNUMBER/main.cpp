#include <bits/stdc++.h>

using namespace std;

int n, k, a[100005];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    cout <<a[k];
}
