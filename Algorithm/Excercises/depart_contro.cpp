#include <bits/stdc++.h>
#define maxn 100005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define Task "depart"

using namespace std;

struct trie
{
    bool dd = 0;
    trie *c[26];
    trie()
    {
        FOR(i,0,25) c[i] = NULL;
    }
} T;
int n;
string s;
long long f[maxn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n;
    while (n--)
    {
        cin >> s;
        trie *p = &T;
        for (char &c : s)
        {
            int u = c - 'a';
            if (!p->c[u]) p ->c[u] = new trie();
            p = p->c[u];
        }
         p->dd = 1;
    }
    cin >> s;
    n = s.length();
    FOR(i,0,n-1)
        {
            trie *p = &T;
            FOR(j,i,n-1)
                {
                    int u = s[j] - 'a';
                    if (!p -> c[u]) break;
                    p = p -> c[u];
                    if (p->dd)
                        f[j] = i ? (f[j] + f[i-1])%maxc : (f[j]+1)%maxc;
                }
        }
    cout << f[n-1];
    return 0;
}
