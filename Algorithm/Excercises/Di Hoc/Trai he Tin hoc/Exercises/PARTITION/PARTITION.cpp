#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 300
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int n, a[N][N], x[N], res = maxc;
bool check()
{
    vector <int> ve;
    for (int i = 1; i <= n; i++) if (x[i]) ve.PB(i);
    for (int i = 0; i < ve.size(); i++)
        for (int j = i+1; j < ve.size(); j++)
        {
            int u = ve[i]; int v = ve[j];
            if (!a[u][v]) return 0;
        }
    ve.clear();
    for (int i = 1; i <= n; i++) if (!x[i]) ve.PB(i);
    for (int i = 0; i < ve.size(); i++)
        for (int j = i+1; j < ve.size(); j++)
        {
            int u = ve[i]; int v = ve[j];
            if (!a[u][v]) return 0;
        }
    return 1;
}
void upd()
{
    int dem = 0;
    for (int i = 1; i <= n; i++) dem += x[i];
    res = min(abs(dem - (n-dem)), res);
}
void duyet(int pos)
{
    if (pos > n)
    {
        if (check()) upd();
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        x[pos] = i;
        duyet(pos+1);
    }
}

void sub1()
{
    duyet(1);
    if (res == maxc) cout <<"Impossible";
    else cout <<res;
}
int main()
{
    freopen("PARTITION.INP", "r", stdin);
    freopen("PARTITION.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    if (n <= 16) sub1();
    else
    {
        cout <<"Impossible";
    }
}
