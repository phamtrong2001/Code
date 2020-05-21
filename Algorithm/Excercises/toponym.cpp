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
#define task "toponym"
#define maxc 1000000007
#define maxn 1000006

using namespace std;

string s;

int n, res = 0;

struct Tries
{
    int cnt = 0;
    Tries *c[53];
    Tries()
    {
        for (int i = 0; i < 53; i++) c[i] = NULL;
    }
} T;

int decode(char c)
{
    if (c == 32) return 52;
    if (c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    getline(cin, s);
    while (n--)
    {
        getline(cin, s);
        Tries *p = &T;
        for (int i = 0; i < s.length(); i++)
        {
            int k = decode(s[i]);
            if (p->c[k] == NULL) p->c[k] = new Tries();
            p = p->c[k];
            p->cnt++;
            res = max(res, (i+1) * p->cnt);
        }
    }
    cout << res;
    return 0;
}
