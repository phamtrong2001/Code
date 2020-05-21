#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, a[N], h[N], ans[N], lef[N], rig[N];
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CAMERA.INP", "r", stdin);
    freopen("CAMERA.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s; s = "%" + s;
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();
        st.push(i);
        lef[i] = st.size();
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();
        st.push(i);
        rig[i] = st.size();
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == 'W') ans[i] = lef[i-1];
        else ans[i] = rig[i+1];
    for (int i = 1; i <= n; i++) cout <<ans[i]<<' ';
}
