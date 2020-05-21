/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define maxn 100005
#define task "camera"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, h[maxn], l[maxn], r[maxn];

stack <int> st;

string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> h[i];
    cin >> s;
    s = "#" + s;
    FOR(i, 1, n)
    {
        l[i] = st.size();
        while (!st.empty() && h[st.top()] < h[i]) st.pop();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    FORD(i, n, 1)
    {
        r[i] = st.size();
        while (!st.empty() && h[st.top()] < h[i]) st.pop();
        st.push(i);
    }
    FOR(i, 1, n)
    {
        if (s[i] == 'W') cout << l[i] << ' ';
            else cout << r[i] << ' ';
    }
    return 0;
}
