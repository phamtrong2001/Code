#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 300005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, s[N], c[N], a[N], b[N], res, ans[N], now[N], dd[N], belong[N];
stack<int> st;
priority_queue<pii> q;

struct invent
{
    int t, type, id;
    invent(int _t=0, int _type=0, int _id=0) {t = _t; type = _type; id = _id;}
};
vector<invent> all;

bool cmp(invent p, invent q)
{
    if (p.t != q.t) return p.t > q.t;
    return p.type > q.type;
}
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> c[i];
        all.PB(invent(s[i], 3, i));
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        all.PB(invent(b[i], 1, i));
        all.PB(invent(a[i], 2, i));
    }
}
void rem(int id)
{
    if (!dd[id]) return;
    res++;
    int train = belong[id];
    ans[id] = train;
    now[train]--;
    if (now[train] == c[train] - 1)
    {
        //cerr<<id<<" "<<train<<endl;
        st.push(train);
    }
    dd[id] = 0;
}
void add(int id)
{
    if (!st.empty())
    {
        dd[id] = 1;
        int train = st.top();
        belong[id] = train;
        now[train]++;
        if (now[train] == c[train])
        {
            //cerr<<id<<" "<<train<<endl;
            st.pop();
        }
        q.push(mp(-a[id], id));
    }
    else
    {
        while (!q.empty() && !dd[q.top().S] ) q.pop();
        if (q.empty()) return;
        pii z = q.top();
        if (a[id] < -z.F) return;
        else
        {
            q.pop();
            int train = belong[z.S];
            dd[z.S] = 0;
            dd[id] = 1;
            belong[id] = train;
            q.push(mp(-a[id], id));
        }
    }
}
void run(int id)
{
    st.push(id);
}
void solve()
{
    sort(all.begin(), all.end(), cmp);

    for (int i = 0; i < all.size(); i++)
    {
        invent z = all[i];
        if (z.type == 2) rem(z.id);
        if (z.type == 3) run(z.id);
        if (z.type == 1) add(z.id);
    }
    cout <<res<<'\n';
    for (int i = 1; i <= m; i++) cout <<ans[i]<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INFTRAIN.INP", "r", stdin);
    freopen("INFTRAIN.OUT", "w", stdout);
    nhap();
    solve();
}
