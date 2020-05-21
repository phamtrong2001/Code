#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
pii a[N], b[N];
string s;

void solve(int ap, int ba, int x, int y)
{
    n = ap + ba;
    bool flag = 0;
    int u = (ap-1)/x + 1;
    int v = (ba-1)/y + 1;
    if (u == v)
    {
        for (int i = 1; i < u; i++)
        {
            for (int j = 1; j <= x; j++) cout <<'a';
            for (int j = 1; j <= y; j++) cout <<'b';
        }
        for (int i = 1; i <= ap - (u-1)*x; i++) cout <<'a';
        for (int i = 1; i <= ba - (v-1)*y; i++) cout <<'b';
        cout <<'\n';
        return;
    }
    if (v <= u)
    {
        swap(u, v); swap(ap, ba); swap(x, y);
        flag = 1;
    }
    int div = ap / (v-1);
    int rem = ap % (v-1);
   // if (rem == 0) {rem = v-1; div--;}
    for (int i = 1; i < v; i++) b[i] = mp(1, y);
    b[v] = mp(1, ba % y);
    if (b[v].S == 0) b[v].S = y;
    a[v] = mp(0, 0);
    for (int i = 1; i <= v - 1 - rem; i++)
    {
        if (div == 0) a[i] = mp(3, 1);
        else a[i] = mp(2, div);
    }
    for (int i = v - rem; i < v; i++) a[i] = mp(2, div + 1);

    string rr = " ba*"; if (flag) swap(rr[1], rr[2]);
    //cerr<<rr<<endl;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= b[i].S; j++) cout <<rr[b[i].F];
        for (int j = 1; j <= a[i].S; j++) cout <<rr[a[i].F];
    }
    cout <<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    int tests; cin >> tests;
    while (tests--)
    {
        int ap = 0, ba = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'a') ap++; else ba++;
        int x, y; cin >> x >> y;
        solve(ap, ba, x, y);
    }
    return 0;
}
