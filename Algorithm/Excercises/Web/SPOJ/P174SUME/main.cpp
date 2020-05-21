#include <bits/stdc++.h>

using namespace std;

int n, k, cur;
char s[1000006];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &k);
    if (k > n || (n > 1 && k == 1))
    {
        cout <<-1;
        return 0;
    }
    for (int i = 1; i <= n-k+2; i++)
        if (i % 2) s[++cur] = 'a';
        else s[++cur] = 'b';
    for (int i = 3; i <= k; i++) s[++cur] = 'a'+i-1;
    for (int i = 1; i <= n; i++) cout <<s[i];
}
