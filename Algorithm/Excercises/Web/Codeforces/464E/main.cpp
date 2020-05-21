#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long HashVal;
    int num0;

};

node* d[N], root[N];
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].PB(mp(v, w));
        g[v].PB(mp(u, w));
    }
    cin >> s >> t;
    po[0] = 1;
    for (int i = 1; i < N; i++)
        po[i] = po[i-1]*2;
}

void solve()
{
    for (int i = 1; i <= n; i++) d[i] = NULL;
    d[s] = build(0, N);


}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
}
