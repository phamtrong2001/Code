#include <bits/stdc++.h>

using namespace std;

int n, res;
string s;
struct Tries
{
    int sl;
    Tries *child[27];
    Tries()
    {
        sl = 0;
        for (int i = 0; i < 27; i++) child[i] = NULL;
    }
};
Tries T;
void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
    cin >> s;
    Tries *p = &T;
    for (int j = 0; j < s.length(); j++)
    {
        int ch = s[j] - 'a';
        if (p->child[ch] == NULL) p->child[ch] = new Tries();
        p->child[ch]->sl = max(p->sl, p->child[ch]->sl);
        p = p->child[ch];
    }
    p->sl++;
    }
}
void DFS(Tries *p)
{
    res = max(res, p->sl);
    for (int i = 0; i < 27; i++)
    if (p->child[i] != NULL) DFS(p->child[i]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TRIE.INP", "r", stdin);
    //freopen("TRIE.OUT", "w", stdout);
    nhap();
    Tries *p = &T;
    DFS(p);
    cout <<res;
    return 0;
}
