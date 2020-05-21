#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, a[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n+1] = n+1; int p = 0;
    for (int i = n-1; i >= 1; i--)
        if (a[i] < a[i+1])
        {
            p = i;
            break;
        }
    if (p == 0) {cout <<-1; return 0;}
    int cur = n+1;
    for (int i = p+1; i <= n; i++)
        if (a[p] < a[i] && a[i] < a[cur]) cur = i;
    vector <int> v;
    for (int i = p; i <= n; i++) if (i != cur) v.PB(a[i]);
    for (int i = 1; i < p; i++) cout <<a[i]<<" ";
    cout <<a[cur]<<" ";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout <<v[i]<<" ";
}
