#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, k, DEM;
bool win[N], lose[N];
string s;
struct Tries
{
    int id;
    Tries *child[27];
    Tries()
    {
        id = ++DEM;
        for (int i = 0; i < 27; i++) child[i] = NULL;
    }
};
Tries T;

void nhap()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        Tries *p = &T;
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if (p->child[c] == NULL) p->child[c] = new Tries();
            p = p->child[c];
        }
    }
}

void DFS(Tries *p)
{
    int dem = 0;
    for (int i = 0; i < 27; i++)
        if (p->child[i] != NULL)
        {
            dem++;
            DFS(p->child[i]);
        }
    if (dem == 0)
    {
        win[p->id] = 0;
        lose[p->id] = 1;
        return;
    }
    for (int i = 0; i < 27; i++)
        if (p->child[i] != NULL)
        {
            win[p->id] |= (!win[p->child[i]->id]);
            lose[p->id] |= (!lose[p->child[i]->id]);
        }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("INP.TXT", "r", stdin);
    nhap();
    Tries *p = &T;
    DFS(p);
    int ans;
    if (win[p->id] == 0) ans = 0;
    else
    {
        if (lose[p->id] == 1) ans = 1;
        else ans = k % 2;
    }


    if (ans == 1) cout <<"First";
    else cout <<"Second";
}
