#include <bits/stdc++.h>

using namespace std;

int n, a[105][105];

int main()
{
    cin >> n;

    int res = 1000000007; int sum;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            sum += x;
        }
        res = min(res, sum);
    }
    cout <<res;
}
