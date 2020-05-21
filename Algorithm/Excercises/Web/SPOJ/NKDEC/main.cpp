#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 405
#define maxc 1000000007

using namespace std;

int n, m, deg[N], res, Assigned[N][N], ans[N][N], cnt;
pii e[N*N];

void nhap()
{
    cin >> m >> n;
    for (int u = 1; u <= m; u++)
        for (int v = 1; v <= n; v++)
        {
            char c; cin >> c;
            if (c == '0') continue;
            e[++cnt] = mp(u, v+m);
            deg[u]++;
            deg[v+m]++;
            res = max(res, deg[u]);
            res = max(res, deg[v+m]);
        }
}

void solve()
{
    for (int i = 1; i <= cnt; i++)
    {
        int u = e[i].F;
        int v = e[i].S;
        bool flag = 0;
        for (int col = 1; col <= res; col++)
            if (!Assigned[u][col] && !Assigned[v][col])
            {
                Assigned[u][col] = v;
                Assigned[v][col] = u;
                flag = 1;
                break;
            }
        if (flag) continue;
        else
        {
            int cola, colb;
            for (int col = 1; col <= res; col++)
            {
                if (!Assigned[u][col]) cola = col;
                if (!Assigned[v][col]) colb = col;
            }
            int side = 1;
            vector<int> all;
            all.PB(u);
            int x = u;
            while ((side == 1 && Assigned[x][colb]) || (side == 2 && Assigned[x][cola]))
            {
                if (side == 1)
                {
                    side = 2;
                    x = Assigned[x][colb];
                }
                else
                {
                    side = 1;
                    x = Assigned[x][cola];
                }
                all.PB(x);
            }
            Assigned[u][colb] = v;
            Assigned[v][colb] = u;
            for (int i = 0; i < all.size(); i++)
            {
                int col;
                if (i == all.size()-1)
                {
                    if (i % 2 == 0) col = cola;
                    else col = colb;
                    Assigned[all[i]][col] = 0;
                    break;
                }
                int x = all[i];
                int y = all[i+1];
                if (i % 2 == 0) col = cola;
                else col = colb;
                Assigned[x][col] = y;
                Assigned[y][col] = x;
            }
        }
    }
    cout <<res<<endl;
    for (int i = 1; i <= cnt; i++)
    {
        for (int col = 1; col <= res; col++)
            if (Assigned[e[i].F][col] == e[i].S && Assigned[e[i].S][col] == e[i].F)
            {
                ans[e[i].F][e[i].S-m] = col;
                break;
            }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) cout <<ans[i][j]<<" ";
        cout <<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
    return 0;
}
