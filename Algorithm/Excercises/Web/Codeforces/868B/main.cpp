#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, t1, t2;
double h, m, s, a[5];
int main()
{
    freopen("INP.TXT", "r", stdin);

    cin >> h >> m >> s >> t1 >> t2;
    h = h + (m/60) + (s/3600);
    m = m/5 + (s/(60*5));
    s = s/5;
    a[1] = h; a[2] = m; a[3] = s;
    sort(a+1, a+4);
    bool flag = 0;
    int z = t2;
    if (t1 > t2) z += 12;
    for (int i = t1; i < z; i++)
    {
        int x = i; if (x > 12) x -= 12;
        int y = i+1; if (y > 12) y -= 12;
        if (lower_bound(a+1, a+4, x) != lower_bound(a+1, a+4, y))
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout <<"YES";
        return 0;
    }
    z = t1;
    if (t2 > t1) z += 12;
    flag = 0;
    for (int i = t2; i < z; i++)
    {
        int x = i; if (x > 12) x -= 12;
        int y = i+1; if (y > 12) y -= 12;
        if (lower_bound(a+1, a+4, x) != lower_bound(a+1, a+4, y))
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout <<"YES";
        return 0;
    }
    cout <<"NO";
}
