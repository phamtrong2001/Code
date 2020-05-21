#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define LN 4
#define maxc 1000000007
#define bit(x, i) ((x >> i) & 1)

using namespace std;

int n, q;
struct Tries
{
    int sl;
    Tries* child[2];
    Tries()
    {
        sl = 0;
        for (int i = 0; i < 2; i++) child[i] = NULL;
    }
}T;

void add(int x)
{
    Tries *p = &T;
    for (int i = LN-1; i >= 0; i--)
    {
        int z = bit(x, i);
        if (p->child[z] == NULL) p->child[z] = new Tries();
        p->child[z]->sl++;
        p = p->child[z];
    }
}
int getsl(Tries *p)
{
    if (p == NULL) return 0;
    return p->sl;
}
int get(int x, int k)
{
    Tries *p = &T;
    int res = 0;
    for (int i = LN-1; i >= 0; i--)
    {
        int z = bit(x, i);
        int sz = getsl(p->child[1^z]);
        if (sz >= k)
        {
            p = p->child[1^z];
            res += (1 << i);
        }
        else
        {
            k -= sz;
            p = p->child[z];
        }
    }
    return res;
}
int main()
{
    freopen("VOXOR.INP", "r", stdin);
    freopen("VOXOR.INP", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        add(x);
    }
    int curXor = 0;
    for (int i = 1; i <= q; i++)
    {
        string type; int val;
        cin >> type >> val;
        if (type[0] == 'X') curXor ^= val;
        else cout <<get(curXor, val)<<endl;
    }
}
