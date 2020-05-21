#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define maxc 1000000007ll
#define N 33335
using namespace std;

int n, x, y, now = 1;
int dd[N], luu[N], all[N];
vector<int> allprime;
void prepare()
{
    dd[0] = dd[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (dd[i]) continue;
        allprime.PB(i);
        for (int j = i*2; j < N; j += i) dd[j] = 1;
    }
}
bool ok(int x, int y)
{
    int sz = 0;
    for (int i = 0; allprime[i]*allprime[i] <= x; i++)
    {
        int dem = 0;
        int zz = allprime[i];
        if (x % zz) continue;
        while (x % zz == 0) {dem++; x /= zz;}
        all[++sz] = zz;
        luu[sz] = dem;
        while (x % zz == 0) {dem++; x /= zz;}
    }
    if (x > 1)
    {
        all[++sz] = x;
        luu[sz] = 1;
    }
    for (int i = 1; i <= sz; i++)
    {
        int dem = 0;
        int zz = all[i];
        if (y % zz) return 0;
        while (y % zz == 0) {dem++; y /= zz;}

        int dem2 = luu[i];
        if (dem > dem2) swap(dem, dem2);
        if (dem2 > dem*2) return 0;
        if ((dem + dem2) % 3) return 0;
    }
    if (y > 1) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    prepare();
    cin >> n;
    while (n--)
    {
        now++;
        int x, y; cin >> x >> y;
        if (ok(x, y)) cout <<"Yes"<<'\n';
        else cout <<"No"<<'\n';
    }
}
