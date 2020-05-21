#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s, w;
int l, r;
int convert(string gg)
{
    int ans;
    stringstream ss;
    ss << gg;
    ss >> ans;
    return ans;
}
bool check(int x)
{
    vector<int> v;
    while (x)
    {
        int y = x%10;
        v.PB(y);
        x /= 10;
    }
    int del = (v[1] - v[0] + 10) % 10;
    for (int i = 1; i < v.size()-1; i++)
        if ((v[i+1] - v[i] + 10) % 10 != del) return 0;
    return 1;
}
void sub1()
{
    l = convert(s);
    r = convert(w);
    int res = 0;
    for (int i = l; i <= r; i++)
    {
        if (check(i)) res++;
    }
    cout <<res<<endl;
}
void sub()
{
    int del = (s[1] - s[0] + 10) % 10;
    int res = 0;
    string s1 = s;
    for (int i = 2; i < s.size(); i++) s1[i] = (del + s1[i-1]) % 10;
    if (s1 >= s && s1 <= w) res++;

    del = (w[1] - w[0] + 10) % 10;
    s1 = w;
    for (int i = 2; i < w.size(); i++) s1[i] = (del + s1[i-1]) % 10;
    if (s1 >= s && s1 <= w) res++;

    for (int i = 1; i <= 9; i++)
    {
        if (i < s[0] - '0' || i > w[0] - '0') continue;
        for (int j = 0; j <= 9; j++)
        {
            int k = (i + j) % 10;
            if (i == s[0] - '0' && k == s[1] - '0') continue;
            if (i == w[0] - '0' && k == w[1] - '0') continue;
            s1[0] = i + '0';
            s1[1] = k + '0';
            if(s1 >= s && s1 <= w) res++;
        }
    }
    cout <<res<<endl;
}
void sub3()
{
    int res = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++) res++;
    cout <<res<<endl;
}
void sub4()
{
    int del = (s[1] - s[0] + 10) % 10;
    int res = 0;
    string s1 = s;
    for (int i = 2; i < s.size(); i++) s1[i] = (del + s1[i-1]) % 10;
    if (s1 >= s && s1 <= w) res++;

    del = (w[1] - w[0] + 10) % 10;
    s1 = w;
    for (int i = 2; i < w.size(); i++) s1[i] = (del + s1[i-1]) % 10;
    if (s1 >= s && s1 <= w) res++;

    for (int i = 1; i <= 9; i++)
    {
        if (i < s[0] - '0' || i > w[0] - '0') continue;
        for (int j = 0; j <= 9; j++)
        {
            int k = (i + j) % 10;
            if (i == s[0] - '0' && k == s[1] - '0') continue;
            if (i == w[0] - '0' && k == w[1] - '0') continue;
            s1[0] = i + '0';
            s1[1] = k + '0';
            if(s1 >= s && s1 <= w) res++;
        }
    }
    cout <<res*(w.size()-s.size() + 1) - 1<<endl;
}
bool ok3(string w)
{
    if (w[0] != '1') return 0;
    for (int i = 1; i < w.size(); i++) if (w[i] != '0') return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ARITHDIG.INP", "r", stdin);
    freopen("ARITHDIG.OUT", "w", stdout);
    int t; cin >> t;
    while (t--)
    {
        cin >> s >> w;
        if (s.size() <= 10 && w.size() <= 10) sub1();
        else if (s.size() == w.size()) sub();
        else if (s == "1" && ok3(w)) sub3();
        else sub4();
    }

}
