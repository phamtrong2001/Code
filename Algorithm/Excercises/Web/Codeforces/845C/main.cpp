#include <bits/stdc++.h>
#define N 400005
#define mp make_pair
#define F first
#define S second
using namespace std;

int n, tt;
pair<int, int> e[N];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        e[++tt] = mp(u, 0);
        e[++tt] = mp(v, 1);
    }
    sort(e+1, e+tt+1);
    int cur = 0;
    for (int i = 1; i <= tt; i++)
    {
        if (e[i].S == 1) cur--;
        else cur++;
        if (cur > 2)
        {
            cout <<"NO";
            return 0;
        }
    }
    cout <<"YES";
}
