#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int x[2*N];
int n;

int main()
{
   // freopen("BALL.INP", "r", stdin);
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        long long res = 1;
        for (int i = 1; i <= n*2-1; i++)
        {
            res = (res*2) % mod;
        }
        for (int i = 1; i <= n*2-1; i+=2) res = (res*i) % mod;
        cout <<res<<endl;
    }
}
