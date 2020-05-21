#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
vector<int> v;
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i += 2) v.PB(i);
    for (int i = 1; i <= n; i += 2) v.PB(i);
    for (int i = 2; i <= n; i += 2) v.PB(i);
    cout<<v.size()<<'\n';
    for (auto x : v) cout <<x<<" ";
}
