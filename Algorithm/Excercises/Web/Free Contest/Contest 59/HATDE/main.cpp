#include <bits/stdc++.h>

using namespace std;

int n, m;
int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    if (m == 1)
    {
        int res = 0; int turn = 0;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                if (turn == 1) res += n/2;
                else turn = 0;
                n /= 2;
            }
            else
            {
                if (turn == 0)
                {
                    res += n/2 + 1;
                    turn = 1;
                }
                n /= 2;
            }
        }
        cout <<res;
        return 0;
    }
    cout <<max(n-m, m);
}
