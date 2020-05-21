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
#define task "depart"
#define maxc 1000000007
#define maxn 400005
#define maxm 102

using namespace std;

int n;

void xulitrau()
{
    long long f[maxn];

    string s, x;

    map <string, int> dd;

    for (int i = 1; i <= n; i++)
        {
            cin >> s;
            dd[s]++;
        }
    cin >> x;
    for (int i = 0; i < x.length(); i++)
        for (int j = 0; j <= i; j++)
        {
            string t = x.substr(j, i-j+1);
            if (dd[t])
            {
                if (!j) f[i] = (f[i] + dd[t]) % maxc;
                    else f[i] = (f[i] + f[j-1]*dd[t]) % maxc;
            }
        }
    cout << f[x.length()-1];
}

int f[maxn], Next[maxn][26], cnt = 1;
int leaf[maxn];

void add(string s)
{
    int u = 1;
    for (char &c : s)
    {
        int x = c - 'a';
        if (!Next[u][x]) Next[u][x] = ++cnt;
        u = Next[u][x];
    }
    leaf[u]++;
}

bool check(string s)
{
    int u = 1;
    for (char &c : s)
    {
        int x = c - 'a';
        if (!Next[u][x]) return 0;
        u = Next[u][x];
    }
    return leaf[u];
}

void xuli()
{
    memset(Next, 0, sizeof(Next));
    memset(leaf, 0, sizeof (leaf));
    string s, x;
    int pos = -maxc;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int z = s.length();
        pos = max(pos, z);
        add(s);
    }
    cin >> x;
    int l = x.size();
    for (int i = 0; i < l; i++)
    {
        int u = 1;
        for (int j = i; j < min(i+pos, l); j++)
        {
            int v = x[j] - 'a';
            if (Next[u][v])
            {
                u = Next[u][v];
                if (leaf[u]) f[j] = (i ? ((f[j] + f[i-1]) % maxc) : (f[j]+leaf[u]));
            }
                else break;
        }
    }
    cout << f[x.size()-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    //xulitrau();
    xuli();
    return 0;
}
