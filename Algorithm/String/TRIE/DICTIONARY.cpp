#include <bits/stdc++.h>
#define maxn 400003
#define PB push_back
using namespace std;

string t, s, a[maxn], res;
int n, m, len;
vector <int> kq;

struct Tries
{
  int id;
  Tries *child[26];
  Tries()
  {
    id = 0;
    for (int i = 0; i <= 26; i++) child[i] = NULL;
  }
};
Tries T;

void setup()
{
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; i++)
  {
    s = a[i];
    sort(s.begin(), s.end());
    Tries *p = &T;
    for (int j = 0; j < s.size(); j++)
    {
      int ch = s[j] - 'a';
      if (p->child[ch] == NULL) p->child[ch] = new Tries();
      p = p->child[ch];
    }
    if (p->id == 0) p->id = i;
  }
}
void DFS(Tries *p, int u)
{
  for (int v = u+1; v < t.length(); v++)
  {
    int ch = t[v] - 'a';
    if (p->child[ch] != NULL)
    {
      DFS(p->child[ch], v);
      if (p->child[ch]->id > 0) kq.PB(p->child[ch]->id);
    }
  }
}
void solve()
{
  cin >> m;
  while (m--)
  {
    cin >> t;
    sort(t.begin(), t.end());
    kq.clear();
    Tries *p = &T;
    DFS(p, -1);
    if (!kq.size()) cout <<"IMPOSSIBLE"<<endl;
    else
    {
      len = 0;
      sort(kq.begin(), kq.end());
      for (int i = 0; i < kq.size(); i++)
        if (a[kq[i]].size() > len) {len = a[kq[i]].size(); res = a[kq[i]];}
      cout<<res<<endl;
    }
  }
}
int main()
{
    freopen("DICTIONARY.INP", "r", stdin);
    freopen("DICTIONARY.OUT", "w", stdout);
    setup();
    solve();
    return 0;
}
