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
#define task "khoa"
#define maxc 1000000007
#define maxn 5003

using namespace std;

int n, dem = 0;;

vector <int> a[maxn];

bool dd[maxn];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;
        a[j].PB(i);
        a[i].PB(j);
    }
}

void DFS(int u)
{
    dd[u] = 1;
    for (int &v : a[u])
    {
        if (dd[v]) continue;
        DFS(v);
    }
}

void xuli()
{
    for (int i = 1; i <= n; i++)
        if (!dd[i]) DFS(i), dem++;
    cout << dem;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    xuli();
    return 0;
}
