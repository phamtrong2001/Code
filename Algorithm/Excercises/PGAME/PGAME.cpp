#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 10000005
#define maxc 1000000007

using namespace std;

long long n, k, a, dd[N];
vector<long long> allPrime;
int main()
{
    freopen("PGAME.INP", "r", stdin);
    freopen("PGAME.OUT", "w", stdout);
    cin >> n >> k >> a;
    dd[0] = dd[1] = 1;
    long long i = 1;
    while (allPrime.size() <= 500000)
    {
        i++;
        if (dd[i]) continue;
        allPrime.PB(i);
        for (long long j = i*2; j < N; j += i) dd[j] = 1;
    }
    cin >> n >> k >> a;

    long long pos = a;
    for (long long i = 0; i < k; i++)
    {
        long long x = allPrime[i];
        if (pos == 1) pos = x % n + 1;
        else
        {
            if (x % (n-1) >= pos-1) pos--;
            pos = ((pos % n) + n) % n;
            if (pos == 0) pos = n;

            pos -= x / (n-1);
            pos = ((pos % n) + n) % n;
            if (pos == 0) pos = n;
        }
    }
    long long possau = pos;
    pos = possau + 1;
    pos = ((pos % n) + n) % n;
    if (pos == 0) pos = n;

    for (long long i = k-1; i >= 0; i--)
    {
        long long x = allPrime[i];
        if (pos == x % n + 1) pos = 1;
        else
        {
            pos += x / (n-1);
            pos = ((pos % n) + n) % n;
            if (pos == 0) pos = n;

            if (x % (n-1) >= pos) pos++;
            pos = ((pos % n) + n) % n;
            if (pos == 0) pos = n;
        }
    }
    cout <<pos<<" ";

    pos = possau - 1;
    pos = ((pos % n) + n) % n;
    if (pos == 0) pos = n;
    for (long long i = k-1; i >= 0; i--)
    {
        long long x = allPrime[i];
        if (pos == x % n + 1) pos = 1;
        else
        {
            pos += x / (n-1);
            pos = ((pos % n) + n) % n;
            if (pos == 0) pos = n;

            if (x % (n-1) >= pos) pos++;
            pos = ((pos % n) + n) % n;
            if (pos == 0) pos = n;
        }
    }

    cout <<pos;
}
