#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
long long T;
pii a[N];

bool check(int k)
{
    priority_queue<int> q;
    ll curSum = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i].S); curSum += a[i].S;
        if (q.size() > k)
        {
            int z = q.top(); q.pop();
            curSum -= z;
        }
        if (q.size() == k && curSum + a[i].F <= T) return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CAKE.INP", "r", stdin);
    //freopen("CAKE.OUT", "w", stdout);
    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1);
    int l = 0, r = n+1;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout <<l;
}
