/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "expression"
#define maxn

using namespace std;

stack <int> st;
string s, t = "";

bool dd;

void xuli()
{
    if (t == "") return;
    if (t == "MUS")
    {
        int cur = st.top();
        st.pop();
        cur += st.top();
        st.pop();
        st.push(cur);
    }
    if (t == "FID")
    {
        int cur = st.top();
        st.pop();
        cur -= st.top();
        st.pop();
        st.push(cur);
    }
    if (t == "XAM")
    {
        int cur = st.top();
        st.pop();
        cur = max(cur, st.top());
        st.pop();
        st.push(cur);
    }
    if (t == "NIM")
    {
        int cur = st.top();
        st.pop();
        cur = min (cur, st.top());
        st.pop();
        st.push(cur);
    }
    if (t == "DCG")
    {
        int cur = st.top();
        st.pop();
        cur = __gcd(abs(cur), abs(st.top()));
        st.pop();
        st.push(cur);
    }
    if (dd == 1)
    {
        int cur = 0;
        for (int i = t.length()-1; i >= 0; i--)
            cur = cur*10 + (t[i] - '0');
        st.push(cur);
    }
    t = "";
    dd = 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    getline(cin, s);
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] == '(' || s[i] == ')' || s[i] == ',') s[i] = ' ';
    for (int i = n-1; i >= 0; i--)
        {
            if (s[i] == ' ') xuli();
                else
                {
                    if (s[i] - '0' <= 9 && s[i] - '0' >= 0) dd = 1;
                    t = t + s[i];
                }
        }
    xuli();
    cout << st.top();
    return 0;
}




