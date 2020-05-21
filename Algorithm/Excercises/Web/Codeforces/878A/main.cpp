#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 500005
#define maxc 1000000007

using namespace std;

int n;
pair<char, int> q[N];

int apply(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (q[i].F == '|') x |= q[i].S;
        else if (q[i].F == '&') x &= q[i].S;
        else x ^= q[i].S;
    }
    return x;
}
bool bit(int x, int i)
{
    return (x >> i) & 1;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> q[i].F >> q[i].S;
    int ans1, ans2, ans3; ans1 = ans2 = 0;  ans3 = 1023;
    for (int i = 0; i <= 9; i++)
    {
        int x = (1 << i);
        int p = apply(x);
        int q = apply(0);
        int u = bit(p, i);
        int v = bit(q, i);
        if (u == 0 && v == 0) ans3 ^= x;
        else if (u == 1 && v == 1) ans1 |= x;
        else if (u == 0 && v == 1) ans2 |= x;
    }
    cout <<3<<endl;
    cout <<'&'<<" "<<ans3<<endl;
    cout <<'^'<<" "<<ans2<<endl;
    cout <<'|'<<" "<<ans1<<endl;
}
