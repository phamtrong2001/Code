//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "toponym"
#define maxn 1000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

string a[maxn];
int n;
int khop[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i++) getline(cin, a[i]);
    sort(a+1, a+n+1);
    for (int i = 2; i <= n; i++)
    {
        int x = 0;
        while (x < a[i].length() && x < a[i-1].length() && a[i][x] == a[i-1][x]) x++;
        khop[i] = x;
    }
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i+1;
        for (int l = a[i].length(); l >= 1; l--)
        {
            while (j <= n && khop[j] >= l) j++;
            res = max(res, (j-i) * l);
        }
    }
    cout << res;
    return 0;
}
