#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define PB push_back
#define maxc 1000000007
#define N 100005

using namespace std;

int n, k, a[N], seat2, seat4, dem[5];
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> k;

    seat4 = n; seat2 = n*2;
    for (int i = 1; i <= k; i++)
    {
        int x; cin >> x;
        int sl = x/2;
        if (seat2 >= sl)
        {
            seat2 -= sl;
            a[i] = x%2;
        }
        else
        {
            sl -= seat2;
            x -= seat2*2;
            seat2 = 0;
            int sll = x/4;
            seat4 -= sll;
            a[i] = x%4;
        }

    }
    for (int i = 1; i <= k; i++) dem[a[i]]++;
    if (dem[3] > seat4)
    {
        cout <<"NO";
        return 0;
    }
    seat4 -= dem[3];
    int p = min(dem[1], dem[2]);
    seat4 -= p;
    dem[1] -= p; dem[2] -= p;
    if (dem[2] > 0) seat4 -= dem[2];
    else if (dem[1] > 0) seat4 -= (dem[1] - 1) / 2 + 1;

    if (seat4 < 0) cout <<"NO";
    else cout <<"YES";
}
