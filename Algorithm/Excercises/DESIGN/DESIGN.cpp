#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define PB push_back
#define N 200
#define mod 1000000007
using namespace std;

int m, n, dem;
int dp[1000005][N];
bool okk[N][N];
int luu[N][N];

vector <vector<pii> > state, ghep;


void duyet(vector<pii> cur, int pos)
{
    if (pos == m)
    {
        state.PB(cur);
        return;
    }
    for (int i = 1; i <= m-pos; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cur.PB(mp(i, j));
            duyet(cur, pos + i);
            cur.erase(cur.end());
        }
    }
}
void duyet1(vector<pii> cur, int pos)
{
    if (pos == m)
    {
        ghep.PB(cur);
        return;
    }
    for (int i = 1; i <= m-pos; i++)
    {
        cur.PB(mp(i, 0));
        duyet1(cur, pos+i);
        cur.erase(cur.end());
    }
}
bool check(int u, int v)
{
    int cur = 0;
    int sum[10];
    sum[0] = 0;
    for (int i = 0; i < ghep[v].size(); i++) sum[i+1] = sum[i] + ghep[v][i].F;
    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < state[u].size(); i++)
    {
        if (state[u][i].F == state[u][i].S) cur += state[u][i].F;
        else
        {
            while (sum[pos1] < cur) pos1++;
            if (cur != sum[pos1]) return 0;
            cur += state[u][i].F;
            while (sum[pos2] < cur) pos2++;
            if (pos2 - pos1 > 1 || cur != sum[pos2]) return 0;
        }
    }
    return 1;
}

vector <pii> fusion(int u, int v)
{
    vector<pii> ne;
    int cur = 0;
    int sum[10];
    sum[0] = 0;
    for (int i = 0; i < ghep[v].size(); i++) sum[i+1] = sum[i] + ghep[v][i].F;

    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < state[u].size(); i++)
    {
        if (state[u][i].F == state[u][i].S)
        {
            while (sum[pos1] < cur) pos1++;
            cur += state[u][i].F;
            while (sum[pos2] < cur) pos2++;
            for (int z = pos1; z < pos2; z++) ne.PB(mp(ghep[v][z].F, 1));
        }
        else
        {
            cur += state[u][i].F;
            ne.PB(mp(state[u][i].F, state[u][i].S+1));
        }
    }
    return ne;
}
bool full(int u)
{
    for (int i = 0; i < state[u].size(); i++)
        if (state[u][i].F != state[u][i].S) return 0;
    return 1;
}
bool start(int u)
{
    for (int i = 0; i < state[u].size(); i++)
        if (state[u][i].S != 1) return 0;
    return 1;
}
int main()
{
    freopen("DESIGN.INP", "r", stdin);
    freopen("DESIGN.OUT", "w", stdout);
    cin >> n >> m;
    vector<pii> zz;
    duyet(zz, 0);
    vector<pii> zzz;
    duyet1(zzz, 0);

    for (int i = 0; i < state.size(); i++)
        if (start(i)) dp[1][i] = 1;

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < ghep.size(); j++)
            if (check(i, j))
            {
                okk[i][j] = 1;
                vector <pii> ne;
                ne = fusion(i, j);
                for (int z = 0; z < state.size(); z++)
                    if (ne == state[z])
                    {
                        luu[i][j] = z;
                        break;
                    }
            }
    for (int col = 2; col <= n; col++)
    {
        for (int i = 0; i < state.size(); i++)
            for (int j = 0; j < ghep.size(); j++)
                if (okk[i][j])
                {
                    int z = luu[i][j];
                    dp[col][z] = (dp[col][z] + dp[col-1][i]) % mod;
                }
    }
    int res = 0;
    for (int i = 0; i < state.size(); i++)
        if (full(i)) res = (res + dp[n][i]) % mod;
    cout <<res;
    return 0;

}
