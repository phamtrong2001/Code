#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 55
#define maxc 1000000007

using namespace std;

int n, m, Visited[N], Assigned[N], cnt, dd[N], res;
char ch[N];
vector<int> a[N];

bool visit(int u, char c2)
{
    if (Visited[u] == cnt) return 0;
    Visited[u] = cnt;
    for (auto v : a[u])
    {
        if (ch[v] != c2) continue;
        if (!Assigned[v] || visit(Assigned[v], c2))
        {
            Assigned[u] = v;
            Assigned[v] = u;
            return 1;
        }
    }
    return 0;
}

void Konig(char c1, char c2)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!Assigned[i] && (ch[i] == c1 || ch[i] == c2)) q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (ch[v] != c1 && ch[v] != c2) continue;
            if (dd[v]) continue;
            dd[v] = 1;
            q.push(Assigned[v]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (Assigned[i] && !dd[i] && !dd[Assigned[i]] && (ch[i] == c1 || ch[i] == c2)) dd[i] = 1;
}
void solve(char c1, char c2)
{
    memset(Assigned, 0, sizeof Assigned);
    memset(Visited, 0, sizeof Visited);
    memset(dd, 0, sizeof dd);
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (ch[i] == c1 && !Assigned[i])
        {
            cnt++;
            visit(i, c2);
        }
    Konig(c1, c2);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!dd[i]) ans++;
    res = max(res, ans);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VOI.INP", "r", stdin);
    freopen("VOI.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ch[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    solve('R', 'G');
    solve('R', 'B');
    solve('G', 'B');
    solve('G', 'R');
    solve('B', 'R');
    solve('B', 'G');
    cout <<n-res;
}
