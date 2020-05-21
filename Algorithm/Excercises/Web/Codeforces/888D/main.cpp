#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

long long n, k;
long long res, ans;
long long s[5] = {0, 0, 1, 2, 9};
long long gt[5] = {1, 1, 2, 6, 24};
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> k;

    for (long long j = k; j > 0; j--)
    {
        res = s[j];
        for (long long i = 0; i < j; i++) res = res*(n-i);
        ans += res/gt[j];
    }
    cout <<ans+1;
}
