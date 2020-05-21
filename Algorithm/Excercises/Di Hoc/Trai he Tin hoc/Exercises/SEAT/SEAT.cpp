#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 100000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


void duyet()
{
    if (full())
    {
        res++;
        if (res == mod) res = 0;
        return;
    }
    for (int i = 2; i < n; i++)
        if (!x[i-1] && !x[i+1])
        {
            x[i] = 1;
            duyet();
            x[i] = 0;
        }
    for (int i = 1; i <= n; i++)
        if (x[i] == )
}
int main()
{
    freopen("SEAT.INP", "r", stdin);
    while (cin >> n)
    {
        if (n == 1) cout <<1 <<endl;
        if (n == 2) cout <<2<<endl;
        else
        {
            for (int i = 2; i < n; i++)
            {
                memset(x, 0, sizeof x);

                x[i] = 1;
                duyet();
            }
        }
    }
}
