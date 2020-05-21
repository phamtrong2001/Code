#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, k, res1, res2;
int main()
{
    cin >> n >> k;
    if (k == 0)
    {
        cout <<0<<" "<<0;
        return 0;
    }
    if (k == n) res1 = 0; else res1 = 1;
    if (n/2 <= k) res2 = n-k;
    else res2 = min(2*k, n-k);
    cout <<res1<<" "<<res2;
}
