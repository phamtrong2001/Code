#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, a, b;

int main()
{
    cin >> n >> a >> b;
    for (int i = min(a, b); i >= 0; i--)
    {
        int x = a/i + b/i;
        if (x >= n)
        {
            cout <<i;
            return 0;
        }
    }
}
