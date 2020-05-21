#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 4000005
#define maxc 1000000007

using namespace std;

long long x, y, m, q, st, en, len, a[N], dd[N];
string s;

long long xuli(string s)
{
    long long x = 0; long long i = 0;
    while (i < s.size())
    {
        x = (x*10 + s[i] - '0') % len;
        i++;
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("QSEQ.INP", "r", stdin);
    freopen("QSEQ.OUT", "w", stdout);
    cin >> a[0] >> x >> y >> m >> q;
    for (long long i = 1; i <= 2*m; i++)
    {
        a[i] = (a[i-1]*x + y) % m;
        if (dd[a[i]])
        {
            st = dd[a[i]];
            en = i-1;
            len = en - st + 1;
            break;
        }
        dd[a[i]] = i;
    }
    while (q--)
    {
        cin >> s;
        if (s.size() <= 7)
        {
            long long x = 0;
            for (long long i = 0; i < s.size(); i++) x = x*10 + s[i]-'0';
            if (x < st) {cout <<a[x]<<' '; continue;}
        }
        long long d = xuli(s);
        d = ((d - st) % len + len) % len;
        cout <<a[d+st]<<' ';
    }

}
