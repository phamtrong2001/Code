#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 3005
#define maxn 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long t;
long long n, k, m;
long long c[N][N];
bool isprime[maxn];
vector <long long> all;
long long dd[3][maxn];



void prepare()
{
    isprime[1] = isprime[0] = 1;
    for (long long i = 2; i < maxn; i++)
        if (!isprime[i])
        {
            all.PB(i);
            for (long long j = i*2; j < maxn; j += i) isprime[j] = 1;
        }
}
long long get(long long a, long long b)
{
    if (b == 0) return 1;
    long long x = get(a, b/2);
    x = (x * x) % m;
    if (b % 2) return (x * a) % m;
    return x;
}
long long C(long long n, long long k)
{
    long long h = n - k;
    for (long long i = 1; i <= n; i++)
    {
        long long x = i;
        for (long long j = 0; j < all.size(); j++)
        {
            long long v = all[j];
            if (v > n) break;
            while (x % v == 0) {x /= v; dd[1][j]++;}
        }
    }
    for (long long i = 1; i <= k; i++)
    {
        long long x = i;
        for (long long j = 0; j < all.size(); j++)
        {
            long long v = all[j];
            if (v > n) break;
            while (x % v == 0) {x /= v; dd[2][j]++;}
        }
    }
    for (long long i = 1; i <= h; i++)
    {
        long long x = i;
        for (long long j = 0; j < all.size(); j++)
        {
            long long v = all[j];
            if (v > n) break;
            while (x % v == 0) {x /= v; dd[2][j]++;}
        }
    }
    long long res = 1;
    for (long long i = 0; i < all.size(); i++)
    {
        long long v = all[i];
        long long dem = dd[1][i] - dd[2][i];
        long long gg = get(v, dem);
        res = (res * gg) % m;
    }
    return res;
}
void sub2()
{
    c[0][0] = 1;
    for (long long i = 1; i < N; i++)
        for (long long j = 0; j <= i; j++) c[i][j] = (c[i-1][j-1] + c[i-1][j]) % m;
    long long block = (n-1)/k+1;
    long long z = block*k - n;
    cout <<block <<" "<<c[block+z-1][z]<<endl;
}
int main()
{
    freopen("TPCNINJA.INP", "r", stdin);
    freopen("TPCNINJA.OUT", "w", stdout);
    long long t; cin >> t;
    prepare();
    while (t--)
    {
        cin >> n >> k >> m;
        if (n <= 1000)
        {
            sub2();
            continue;
        }
        else
        {
            memset(dd, 0, sizeof dd);
            long long block = (n-1)/k+1;
            long long z = block*k - n;
            cout <<block <<" "<<C(block+z-1,z)<<endl;
        }
    }
    return 0;

}
