#include <bits/stdc++.h>
#define N 200005
using namespace std;

int n, m;
string s;
string alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
struct BIT
{
    int t[N];
    void upd(int x, int val)
    {
        for (; x < N; x += (x & -x)) t[x] += val;
    }
    int get(int x)
    {
        int ans = 0;
        for (; x; x -= (x & -x)) ans += t[x];
        return ans;
    }
    int find_pos(int u)
    {
        int l = 0, r = n;
        while (r - l > 1)
        {
            int mid = (r + l)/2;
            if (get(mid) >= u) r = mid;
            else l = mid;
        }
        return r;
    }
}t1;
struct IntervalTree
{
    int t[N << 2];
    void add(int l, int r, int id, int x)
    {
        if (l > x || r < x) return;
        if (l == r)
        {
            t[id]++; t1.upd(l, 1);
            return;
        }
        int mid = (r + l)/2;
        if (x <= mid) add(l, mid, id*2, x);
        else add(mid+1, r, id*2+1, x);
        t[id] = t[id*2] + t[id*2+1];
    }
    void rem(int l, int r, int id, int x, int y)
    {
        if (l > y || r < x) return;
        if (t[id] == 0) return;
        if (l == r)
        {
            t[id] = 0; t1.upd(l, -1);
            return;
        }
        int mid = (r + l)/2;
        rem(l, mid, id*2, x, y);
        rem(mid+1, r, id*2+1, x, y);
        t[id] = t[id*2] + t[id*2+1];
    }
}t2[64];
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m >> s; s = "#" + s;
    for (int i = 1; i <= n; i++)
    {
        int id = alphabet.find(s[i]);
        t2[id].add(1, n, 1, i);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, id; char c;
        cin >> u >> v >> c;
        u = t1.find_pos(u);
        v = t1.find_pos(v);
        id = alphabet.find(c);
        t2[id].rem(1, n, 1, u, v);
    }
    int curSum = 0;
    for (int i = 1; i <= n; i++)
        if (t1.get(i) > curSum)
        {
            cout <<s[i];
            curSum++;
        }
}
