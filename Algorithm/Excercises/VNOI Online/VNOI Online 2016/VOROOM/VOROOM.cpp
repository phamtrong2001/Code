#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, dd[N], cnt1[N], cnt2[N], cc;
vector<int> a[N];
pii e[N];

void DFS(int u, int p)
{
    dd[u] = cc;
    for (auto v : a[u])
    {
        if (v == p) continue;
        DFS(v, u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VOROOM.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v; cin >> u >> v;
        e[i] = mp(u, v);
        a[u].PB(v);
        a[v].PB(u);
    }
    for (int i = 1; i <= n+1; i++)
    {
        if (dd[i]) continue;
        cc++;
        DFS(i, -1);
    }
    for (int i = 1; i <= n; i++)
    {
        int id = dd[e[i].F];
        cnt1[id]++;
    }
    for (int i = 1; i <= n+1; i++) cnt2[dd[i]]++;
    long long res = 0;
    for (int i = 1; i <= cc; i++)
    {
        if (cnt1[i] > cnt2[i]) {cout <<0; return 0;}
        else if (cnt1[i] < cnt2[i]) res += cnt2[i];
    }
    cout <<res*(res-1)/2 + res*(n-res+1);
}
