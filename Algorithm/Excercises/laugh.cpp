/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "laugh"
#define maxc 1000000007
#define maxn 100005

using namespace std;

int n, f[maxn];

string s;

struct Tries
{
    bool dd = 0;
    Tries *c[27];
    Tries()
    {
        for (int i = 0; i < 26; i++) c[i] = NULL;
    }
} T;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> s;
    while (n--)
    {
        string z;
        cin >> z;
        Tries *p = &T;
        for (char &t : z)
        {
            int k = t - 'a';
            if (p->c[k] == NULL) p->c[k] = new Tries();
            p = p->c[k];
        }
        p->dd = 1;
    }
    for (int i = 0; i < s.length(); i++)
    {
        Tries *p = &T;
        for (int j = i; j < s.length(); j++)
        {
            int t = s[j] - 'a';
            if (p->c[t] == NULL) break;
            p = p->c[t];
            if (p->dd) f[j] = max(f[j], f[i-1]+j-i+1);
        }
    }
    cout << *max_element(f, f+s.length());
    return 0;
}
