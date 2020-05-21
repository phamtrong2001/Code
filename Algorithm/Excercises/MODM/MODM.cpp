#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, m, a[N], dem[N], res;
int ok[N], dd[N], tt;

void tinh()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = ((a[i] % m) + m) % m;
        if (dd[i] == 0) continue;
        else
        {
            if (ok[(m-x) % m] == tt) return;
            ok[x] = tt;
            cnt++;
        }
    }
    res = max(res, cnt);
}
void Try(int pos)
{
    if (pos > n)
    {
        tt++;
        tinh();
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        dd[pos] = i;
        Try(pos+1);
    }
}
int main()
{
    freopen("MODM.INP", "r", stdin);
    freopen("MODM.OUT", "w", stdout);
    scanf("%d %d", &n, &m);
    //if (m > 20) return 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        int x = ((a[i] % m) + m) % m;
        dem[x]++;
    }
    if (n <= 20) Try(1);
    else
    {
        res = (dem[0] > 0);
        for (int i = 1; i <= (m-1)/2; i++) res += max(dem[i], dem[m-i]);
        if (m % 2 == 0 && dem[m/2] > 0) res++;
    }
    printf("%d", res);
}
