/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pii pair <int, int>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
#define maxn 1003
#define maxc 1000000007
#define MOD 1000000007
#define task "seq"

using namespace std;

int z[maxn], dd, luu;
ll vt;

string s;

string chuyen(int pos)
{
    string res = "";
    while (pos)
    {
        res += ((pos%10) + '0');
        pos /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

void Z_Function(int pos)
{
    int l = 0, r = 0;
    z[0] = 0;
    FOR(k, 1, 1000)
    {
        int x = pos;
        if (k <= r) x = min(r-k+1, z[k-l]);
        while (k+x <= 1000 && s[x] == s[k+x]) x++;
        z[k] = x-pos;
        if (k+x-1 > r) l = k, r = k+x-1;
    }
}

void chuanbi(int pos)
{
    Z_Function(pos);
    FOR(i, 0, 1000)
        if (z[i] >= 4)
        {
            dd = i;
            luu = pos;
            break;
        }
}

void xuli(int k)
{
    int x = (1ll*k - luu) % dd;
    if (x == 0) x = dd;
    cout << s[x+luu-1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> s;
    int n = 2;
    while (n <= 1005)
    {
        int pos = s[n] - '0' + s[n-1] - '0' + s[n-2] - '0';
        string t = chuyen(pos);
        s += t;
        n += t.length();
    }
    //cout << s << '\n';
    FOR(i, 0, 1000)
        {
            memset(z, 0, sizeof (z));
            chuanbi(i);
            if (dd) break;
        }
    while (cin >> vt)
    {
        xuli(vt);
    }
    return 0;
}
