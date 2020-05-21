#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define F first
#define S second
#define PB push_back
#define maxc 1000000007
#define N 100005

using namespace std;

long long n, dd[N], res, dem;
double d[N];
vector<long long> a[N];
void nhap()
{
    cin >> n;
    for (long long i = 1; i < n; i++)
    {
        long long u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
}
void DFS(long long u, long long s)
{
    dd[u] = 1;
    bool flag = 0;
    double sum = 0;
    int dem = 0;
    for (auto v : a[u])
    {
        if (dd[v]) continue;
        dem++;
        flag = 1;
        DFS(v, s+1);
        sum += d[v];
    }
    if (flag == 0) d[u] = s;
    else d[u] = sum / dem;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    DFS(1, 0);
    printf("%0.7f", d[1]);
}
