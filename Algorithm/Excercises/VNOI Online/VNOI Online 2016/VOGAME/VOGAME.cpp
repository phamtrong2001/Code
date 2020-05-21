#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, d, dem, a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VOGAME.INP", "r", stdin);
    int Tests; cin >> Tests;
    while (Tests--)
    {
        cin >> n >> d;
        dem = a[d+1] = 0;
        for (int i = 1; i <= d; i++)
        {
            cin >> a[i];
            a[d+1] ^= a[i];
            dem += a[i];
        }
        dem += a[d+1];
        int res = n/(d+1)*dem;
        int r = n % (d+1);
        for (int i = 1; i <= r; i++) res += a[i];
        if (res % 2 == 0) cout <<0;
        else cout <<1;
        cout <<endl;
    }
}
