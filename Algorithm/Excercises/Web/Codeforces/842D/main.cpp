#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int n, m, dd[N];
struct Tries
{
    int sl, sl_full;
    Tries *child[2];
    Tries()
    {
        sl = sl_full = 0;
        child[0] = child[1] = NULL;
    }
};
Tries T;

bool bit(int x, int i)
{
    return (x >> i) & 1;
}

void add(int x)
{
    Tries *p = &T;
    for (int i = 23; i >= 0; i--)
    {
        int c = bit(x, i);
        if (p->child[c] == NULL) p->child[c] = new Tries();

        p->child[c]->sl++;
        p = p->child[c];
    }
}
void nhap()
{
    scanf("%d %d", &n, &m);
    Tries *q = &T;

    for (int id = 1; id <= n; id++)
    {
        int x; scanf("%d", &x);
        dd[x] = 1;
    }
    for (int i = 0; i < N; i++)
        if (!dd[i]) add(i);
}
void solve()
{
    int x = 0;
    while (m--)
    {
        int z; scanf("%d", &z);
        x ^= z;
        Tries *p = &T;
        int res = 0;
        for (int i = 23; i >= 0; i--)
        {
            int c = bit(x, i);
            //if (p->child[c] == NULL) p->child[c] = new Tries();
            //if (p->child[1^c] == NULL) p->child[1^c] = new Tries();

            if (p->child[c] == NULL)
            {
                res += (1 << i);
                p = p->child[1 ^ c];
            }
            else p = p->child[c];
        }
        printf("%d\n", res);
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
