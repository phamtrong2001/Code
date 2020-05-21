#include <bits/stdc++.h>
#define PB push_back
#define maxn 2004
#define maxm 30005
using namespace std;

int n, m, scv[maxn], goc[maxn], scr[maxn], fr[maxn], index[maxn], low[maxn], dem = 0, scc = 0;
vector <int> a[maxn];
stack <int> p;
void nhap()
{
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++)
  {
    cin >> u >> v;
    a[u].PB(v);
  }
}
void visit(int u)
{
  index[u] = ++dem;
  low[u] = index[u];
  p.push(u);
  for (int i = 0; i < a[u].size(); i++)
  {
    int v = a[u][i];
    if (!fr[v])
    {
      if (index[v] != 0) low[u] = min(low[u], index[v]);
      else
      {
        visit(v);
        low[u] = min(low[u], low[v]);
      }
    }
  }
  if (index[u] == low[u])
  {
    int v = 0; goc[++scc] = u;
    while (v != u)
    {
      v = p.top();
      p.pop();
      fr[v] = scc;
    }
  }
}
void solve()
{
  for (int i = 1; i <= n; i++)
    if (index[i] == 0) visit(i);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < a[i].size(); j++)
    {
      int v = a[i][j];
      if (fr[i] != fr[v])
      {
        scv[fr[i]]++;
        scr[fr[v]]++;
      }
    }
  int dr = 0, dv = 0;
  for (int i = 1; i <= scc; i++)
  {
    if (scv[i] == 0) dv++;
    if (scr[i] == 0) dr++;
  }
  if (dv == 1 && dr == 1)
  {
    cout <<"YES"<<endl;
    for (int i = 1; i <= scc; i++) if (scv[i] == 0) {cout <<goc[i]<<" "; break;}
    for (int i = 1; i <= scc; i++) if (scr[i] == 0) {cout <<goc[i]; exit(0);}
  }
  cout <<"NO";
}
int main()
{
  freopen("ONEARC.INP", "r", stdin);
  //freopen("ONEARC.OUT", "w", stdout);
  nhap();
  solve();
}
