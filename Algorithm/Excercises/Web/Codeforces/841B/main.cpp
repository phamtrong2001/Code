#include <bits/stdc++.h>
#define maxn 100005


using namespace std;

int n, a[maxn], s[maxn];
int main()
{
    cin >> n;
    bool res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; a[i] %= 2;
        s[i] = s[i-1] + a[i];
    }
    if (s[n] % 2 == 1) res = 1;
    else
    {
        if (s[n-1] % 2 == 1 || (s[n] - s[1]) % 2 == 1) res = 1;
    }

    if (res) cout<<"First";
    else cout<<"Second";
}
