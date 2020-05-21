#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200
#define mod 1000001
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long c[N][N], p[N], n, m, k;
void prepare()
{
    c[0][0] = 1;
    for (long long i = 1; i < N; i++)
        for (long long j = 0; j <= i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    p[0] = 1;
    for (long long i = 1; i < N; i++) p[i] = (p[i-1]*i) % mod;
}

int main()
{
    prepare();
    long long t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        if (k > n || k > m) {cout <<0<<'\n'; continue;}
        long long res = c[n][k];
        res = (res * c[m][k]) % mod;
        res = (res * p[k]) % mod;
        cout <<res<<'\n';
    }
}
