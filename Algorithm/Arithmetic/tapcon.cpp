//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "tapcon"
#define maxn 105
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define haimu(x) (1ll << (x))

using namespace std;

int n, k, a[maxn];

void Tapcon()
{
    string st;
    getline(cin, st);
    stringstream scin(st);
    k = 0;
    int x;
    while (scin >> x) a[++k] = x;
    long long lower = -1;
    a[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        lower ++;
        for (int j = a[i-1] + 1; j < a[i]; j++)
            lower += haimu(n-j);
    }
    cout << lower + 1 << endl;
//    for (int i  = 1; i <= k; i++) cout << a[i] << " ";

}

void ThuTu()
{
    long long pos;
    cin >> pos;
    pos ++;
    k = 0;
    while (--pos)
    {
        k++;
        for (int j = a[k-1] + 1; j <= n; j++)
            if (pos > haimu(n-j)) pos -= haimu(n-j);
                else
                {
                    a[k] = j;
                    break;
                }
    }
    for (int i = 1; i <= k; i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    cout << haimu(n) - 1 << endl;
    int type;
    while (cin >> type)
        if (type == 1) Tapcon();
            else ThuTu();
    return 0;
}

