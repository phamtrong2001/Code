#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int res = 1e9; int pos;
        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            if (x < res)
            {
                res = x;
                pos = i;
            }
        }
        cout <<pos<<endl;
    }
}
