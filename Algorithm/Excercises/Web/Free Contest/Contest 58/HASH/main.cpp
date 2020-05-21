#include <bits/stdc++.h>
#define BASE 97
#define maxc 1000000007
#define N 300005
using namespace std;

string s;
int n, q;
long long h[N], b[N];
int get(int u, int v)
{
    return ((h[v] - (1ll*h[u-1]*b[v-u+1]) % maxc) + maxc) % maxc;
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> s;
    n = s.size();
    s = "#" + s;
    h[0] = 0;
    b[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        h[i] = (h[i-1]*BASE + s[i]) % maxc;
        b[i] = (b[i-1]*BASE) % maxc;
    }
    scanf("%d", &q);
    while (q--)
    {
        int u, v; scanf("%d %d", &u, &v);
        printf("%d\n", get(u, v));
    }
}
