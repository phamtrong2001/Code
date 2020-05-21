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
#define task "design"
#define maxc 1000000007
#define maxn 1003

using namespace std;

int m, n;
long long res;

long long d[maxn][maxn], dd[maxn][maxn];

vector <vector<pii> > state;

void nhap()
{
    cin >> n >> m;
}

void Duyet(vector<pii> cur, int pos)
{
    if (pos == m) {state.PB(cur); return;}
    for (int i = 1; i <= m - pos; i++)
        for (int j = 1; j <= i; j++)
        {
            cur.PB(MP(i, j));
            Duyet(cur, pos+i);
            cur.erase(cur.end());
        }
}

int khop(vector<pii> duoi, vector<pii> tren)
{
    int u, v, i, j;
    u = v = 1;
    i = j = 0;
    while (u <= m)
    {
        while (u <= m && tren[i].F == tren[i].S && i < tren.size()) u += tren[i++].F;
        while (v <= m && duoi[j].S == 1 && j < duoi.size()) v += duoi[j++].F;
        if (u != v) return 0;
        if (u <= m)
        {
            if (tren[i].F != duoi[j].F) return 0;
            if ((tren[i].S + 1) != duoi[j].S) return 0;
            u += tren[i++].F;
            v += duoi[j++].F;
        }
    }
    return 1;
}

void chuanbi()
{
    vector <pii> p;
    p.clear();
    state.clear();
    Duyet(p, 0);
    memset(d, 0, sizeof (d));
    memset(dd, 0, sizeof (dd));
    d[0][0] = 1;
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
            dd[i][j] = khop(state[i], state[j]);
}

void xuli()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
            {
                d[i][j] = (d[i][j] + d[i-1][k] * dd[j][k]) % maxc;
            }
}

int kt(vector<pii> p)
{
   for (int i = 0; i < p.size(); i++)
        if (p[i].F != p[i].S) return 0;
   return 1;
}

void ghi()
{
    res = 0;
    for (int i = 0; i < state.size(); i++)
        res = (res + d[n][i] * kt(state[i])) % maxc;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    chuanbi();
    xuli();
    ghi();
//    vector <pii> p;
//    Duyet(p, 0);
//    for (int i = 0; i < state.size(); i++)
//    {
//        for (int j = 0; j < state[i].size(); j++)
//            cout << state[i][j].F << " " << state[i][j].S << "  ";
//        cout << endl;
//    }
    return 0;
}
