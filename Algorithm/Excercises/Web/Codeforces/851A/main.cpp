#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, k, t, res;
int main()
{
    cin >> n >> k >> t;
    if (t <= k) res = t;
    else if (t > n) res = k - (t - n);
    else res = k;
    cout <<res;
}
