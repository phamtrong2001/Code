#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int INF = 1e9 + 9;

struct Edge {
    int u, v, cost;
    Edge() {}
    Edge(int u, int v, int c): u(u), v(v), cost(c) {}

    int getAdj(int from) {
        return u ^ v ^ from;
    }
} E[N];

int num[N], low[N];
int trace[N];
int lab[N];

vector<int> a[N];
vector<int> bcc[N];

int n, m, s, t;
int nBCC;
int Time;

stack<int> st;

void dfs(int u, int p) {
    num[u] = ++Time; low[u] = N;
    for (int i = 0; i < a[u].size(); ++i) {
        int e = a[u][i];
        int v = E[e].getAdj(u);
        if (v == p || lab[e]) continue;
        st.push(e);
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) {
                ++nBCC;
                int cur = -1;
                while (cur != e) {
                    cur = st.top(); st.pop();
                    lab[cur] = nBCC;
                    bcc[nBCC].push_back(cur);
                }
            }
        }
    }
}

void bfs() {
    queue<int> Q;
    Q.push(s);
    for (int i = 1; i <= n; ++i) trace[i] = -1;
    trace[s] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < a[u].size(); ++i) {
            int e = a[u][i];
            int v = E[e].getAdj(u);
            if (trace[v] == -1) {
                trace[v] = e;
                Q.push(v);
            }
        }
    }
}

void minimize(int &a, int b) { a = a > b ? b : a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        E[i] = Edge(u, v, c);
        a[u].push_back(i); a[v].push_back(i);
    }
    dfs(s, 0);
    bfs();
    if (trace[t] == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> path;
    int v = t;
    while (v != s) {
        int e = trace[v];
        int u = E[e].getAdj(v);
        path.push_back(e);
        v = u;
    }
    int last[2] = {INF, 0}, cur[2];
    for (int i = 0, j; i < path.size(); i = j + 1) {
        j = i;
        int c = lab[path[i]];
        int sumCost = E[path[i]].cost;
        while (j + 1 < path.size() && c == lab[path[j + 1]]) sumCost += E[path[++j]].cost;
        int all = 0;
        for (int it = 0; it < bcc[c].size(); ++it) all += E[bcc[c][it]].cost;
        int parity = (j - i + 1) & 1;
        int otherWay = (bcc[c].size() & 1) ^ parity;
        cur[0] = cur[1] = INF;
        for (int t = 0; t <= 1; ++t) {
            minimize(cur[t ^ parity], last[t] + sumCost);
            if (j - i + 1 != bcc[c].size())
                minimize(cur[t ^ otherWay], last[t] + all - sumCost);
        }
        swap(last, cur);
    }
    cout << (last[1] < INF ? last[1] : -1) << endl;
    return 0;
}
