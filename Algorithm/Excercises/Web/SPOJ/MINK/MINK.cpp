#include <bits/stdc++.h>
#define NguyenQuan main
#define maxn 17006
using namespace std;

int t, n, k, a[maxn];
deque <int> d;
void push(int i)
{
  while (!d.empty() && a[i] < a[d.back()]) d.pop_back();
  d.push_back(i);
}
void pop(int i)
{
  while (!d.empty() && d.front() <= i) d.pop_front();
}
int NguyenQuan()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("MINK.INP", "r", stdin);
    //freopen("MINK.OUT", "w", stdout);
    cin >> t;
    while (t--)
    {
      cin >> n >> k;
      d.clear();
      for (int i = 1; i <= n; i++) cin >> a[i];
      for (int i = 1; i <= k; i++) push(i);
      cout <<a[d.front()]<<" ";
      for (int i = k+1; i <= n; i++)
      {
        pop(i-k);
        push(i);
        cout <<a[d.front()]<<" ";
      }
      cout <<endl;
    }
    return 0;
}
