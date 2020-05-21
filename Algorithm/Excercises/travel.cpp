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
#define task "travel"
#define maxc 1000000007
#define maxn 100005

using namespace std;

int n, f[maxn*2];

pii ke[maxn];

vector <int> d;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ke[i].F >> ke[i].S;
        d.PB(ke[i].F);
        d.PB(ke[i].S);
    }
    f[0] = 0;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 1; i <= n; i++)
    {
        ke[i].F = lower_bound(d.begin(), d.end(), ke[i].F) - d.begin();
        ke[i].S = lower_bound(d.begin(), d.end(), ke[i].S) - d.begin();
    }
    sort(ke+1, ke+n+1);
    for (int i = 1; i <= n; i++)
        f[ke[i].S] = max(f[ke[i].S], f[ke[i].F]+1);
    cout << *max_element(f+1, f+2*n+1);
    return 0;
}
