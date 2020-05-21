#include <bits/stdc++.h>
#define maxc 10000000000000000
using namespace std;

int n;
string s;
struct Tries
{
  bool ok;
  long long res;
  Tries *child[26];
  Tries()
  {
    ok = 0; res = maxc;
    for (int i = 0; i < 26; i++) child[i] = NULL;
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
    for (int j = 0; j < s.size(); j++)
    {
      int ch = s[j] - 'a';
      if (p->child[ch] == NULL) p->child[ch] = new Tries;
      p = p->child[ch];
    }
    p->ok = 1;
  }
}
void DFS(Tries *p, int h)
{
  long long cur = 0;
  if (p->ok) {p->res = (1ll<<(40-h+1)); return;}
  for (int i = 0; i < 26; i++)
    if (p->child[i] != NULL)
    {
      DFS(p->child[i], h+1);
      cur += p->child[i]->res;
    }
  if (cur != 0) p->res = min(1ll<<(40-h+1), cur);
}
int main()
{
    freopen("COMPRESSION.INP", "r", stdin);
    //freopen("COMPRESSION.OUT", "w", stdout);
    nhap();
    Tries *p = &T;
    DFS(p, 1);
    cout <<p->res;
    return 0;
}
