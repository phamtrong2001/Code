/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "multiset"
#define maxn 6000000
#define maxk 31

using namespace std;

int q, nt = 0, kq;

struct Tnode
{
    int cnt, nex[2];
}t[maxn];

int AddNode()
{
    ++nt;
    t[nt].cnt = t[nt].nex[0] = t[nt].nex[1]=0;
    return nt;
}

void Them(int x)
{
    int r = 0;
    for (int k = maxk; k >= 0; k--)
    {
        int i =(x >> k) & 1;
        if (t[r].nex[i] == 0) t[r].nex[i] = AddNode();
        r = t[r].nex[i];
        t[r].cnt++;
    }
    t[r].cnt++;
}

void Bot(int x) {
    int r = 0;
    for (int k = maxk; k >= 0; k--)
    {
        int i = (x >> k) & 1;
        r = t[r].nex[i];
        t[r].cnt--;
    }
    t[r].cnt--;
}

int ghi(int x)
{
    int r = 0;
    kq = 0;
    for (int k = maxk; k >= 0; k--)
    {
        int i = (x >> k) & 1;
        if (t[t[r].nex[1-i]].cnt > 0)
        {
            kq += (1 << k);
            r = t[r].nex[1-i];
        }
            else r = t[r].nex[i];
    }
    return kq;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> q;
    Them(0);
    while (q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') Them(x);
            else if (c == '-') Bot(x);
                    else cout << ghi(x) << '\n';
    }
    return 0;
}
