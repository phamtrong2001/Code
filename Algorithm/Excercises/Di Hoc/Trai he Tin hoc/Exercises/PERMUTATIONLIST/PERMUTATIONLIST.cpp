#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int n, k, p[N], dd[N], luu[N], zz;
int main()
{
    cin >> n >> k;
    if (n > 15)
    {
        for (int i = 1; i <= n-15; i++) cout <<i<<" ";

        zz = n-15;
        n = 15;
    }

    p[0] = 1;
    for (int i = 1; i <= 15; i++) p[i] = p[i-1]*i;
    int pos = n;
    while (pos > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dd[i]) continue;
            if (k > p[pos-1]) k -= p[pos-1];
            else
            {
                luu[pos--] = i;
                dd[i] = 1;
                break;
            }
        }
    }
    for (int i = n; i >= 1; i--) cout <<zz+luu[i]<<" ";
}
