#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 120
#define maxc 1000000007

using namespace std;

int n, m, visit[N], v[5], dem, dd[N][N][N][N], res[N][N][N][N];
bool kkk;
vector<int> a[N];

void DFS(int u)
{
    visit[u] = 1;
    dem++;
    for (auto v : a[u])
    {
        if (visit[v]) continue;
        DFS(v);
    }
}

bool Try(int x[])
{
    if (dd[x[0]][x[1]][x[2]][x[3]]) return res[x[0]][x[1]][x[2]][x[3]];
    dd[x[0]][x[1]][x[2]][x[3]] = 1;
    if (x[0] + x[1] + x[2] + x[3] == 3)
    {
        int z = x[0] + x[1];
        int y = x[2] + x[3];
        if (z == 1 || z == 3)
        {
            if (kkk == 1) return (res[x[0]][x[1]][x[2]][x[3]] = 0);
            return (res[x[0]][x[1]][x[2]][x[3]] = 1);
        }
        else
        {
            if (kkk == 1) return (res[x[0]][x[1]][x[2]][x[3]] = 1);
            return (res[x[0]][x[1]][x[2]][x[3]] = 0);
        }
    }
    bool ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = i; j < 4; j++)
        {
            if (!x[i] || !x[j] || (i == j && x[i] < 2)) continue;
            x[i]--; x[j]--;
            x[(i+j)%4]++;
            ans |= Try(x);
            x[i]++; x[j]++;
            x[(i+j)%4]--;
        }
    return res[x[0]][x[1]][x[2]][x[3]] = ans^1;
}
int main()
{
    freopen("JOINT.INP", "r", stdin);
    //freopen("JOINT.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    int x = 0;
    for (int i = 1; i <= n; i++)
        if (!visit[i])
        {
            dem = 0; x++;
            DFS(i);
            v[dem % 4]++;
        }
    if (x <= 2)
    {
        if (x == 2) cout <<"first";
        else cout <<"second";
        return 0;
    }
    bool ans = Try(v);
    kkk = (m + x + 1) % 2;
    if (!ans) cout <<"first";
    else cout <<"second";
}
