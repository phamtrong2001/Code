#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, dd[N];
int main()
{
    cin >> n;
    for (int i = (n-1)/2; i >= 1; i--)
        if (__gcd(i, n-i) == 1)
    {
        cout <<i<<" "<<n-i;
        return 0;
    }
}
