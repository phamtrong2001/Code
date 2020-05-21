#include <bits/stdc++.h>
#define N 500005
using namespace std;

int m;
struct Tries
{
    int sl;
    Tries *child[2];
    Tries(int sl = 0) : sl(sl)
    {
        for (int i = 0; i <= 1; i++) child[i] = NULL;
    }
};
Tries root[N];

void add(Tries *p, Tries *oldId, int x, int pos)
{
    int z = (x >> pos) & 1;
    if (oldId->child[z] == NULL) oldId->child[z] = new Tries(0);
    if (oldId->child[1-z] == NULL) oldId->child[1-z] = new Tries(0);
    p->child[z] = new Tries(oldId->child[z]->sl + 1);
    p->child[1-z] = oldId->child[1-z];
    if (pos == 0) return;
    add(p->child[z], oldId->child[z], x, pos-1);
    //p->sl = p->child[0]->sl + p->child[1]->sl;
}
int get_less(Tries *p, int x, int pos)
{
    if (p == NULL) return 0;
    if (pos == -1) return p-> sl;
    int z = (x >> pos) & 1;
    /*if (pos == 0)
    {
        if (z == 0) return p->child[z]->sl;
        return p->sl;
    }*/
    if (z == 0) return get_less(p->child[z], x, pos-1);
    if (p->child[1-z] == NULL) p->child[1-z] = new Tries();
    return p->child[1-z]->sl + get_less(p->child[z], x, pos-1);
}
int get_xor(Tries *p, Tries *q, int x, int pos)
{
    if (pos == -1) return 0;
    int z = (x >> pos) & 1;
    int u, v;
    if (p->child[1-z] == NULL) u = 0; else u = p->child[1-z]->sl;

    if (q->child[1-z] == NULL) v = 0; else v = q->child[1-z]->sl;
    if ((u - v == 0))
        return (z << (pos)) + get_xor(p->child[z], q->child[z], x, pos-1);
    return ((1-z) << (pos)) + get_xor(p->child[1-z], q->child[1-z], x, pos-1);
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d", &m);
    int dem = 0;
    Tries *p = &root[0];
    p = new Tries(0);
    //cout <<p->child[0]->sl<<" ";
    for (int i = 1; i <= m; i++)
    {
        int type, u, v, x;
        scanf("%d", &type);
        if (type == 0)
        {
            scanf("%d", &x);
            dem++;
            add(&root[dem], &root[dem-1], x, 24);
        }
        if (type == 1)
        {
            scanf("%d %d %d", &u, &v, &x);
            printf("%d \n", get_xor(&root[v], &root[u-1], x, 24));
        }
        if (type == 2)
        {
            scanf("%d", &x);
            dem -= x;
        }
        if (type == 3)
        {
            scanf("%d %d %d", &u, &v, &x);
            int a = get_less(&root[v], x, 24);
            int b = get_less(&root[u-1], x, 24);
            //cout <<a<<" "<<b<<" "<<endl;
            printf("%d \n", a-b);
        }
        if (type == 4)
        {
            scanf("%d %d %d", &u, &v, &x);
            int l = 0, r = 1e6;
            while (r - l > 1)
            {
                int mid = (r + l) / 2;
                if (get_less(&root[v], mid, 24) - get_less(&root[u-1], mid, 24) >= x) r = mid;
                else l = mid;
            }
            printf("%d \n", r);
        }
    }

}
