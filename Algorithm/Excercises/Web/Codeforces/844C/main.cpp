#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005

using namespace std;

int n, dd[N], cur_time;
vector<int> res[N];
pair<int, int> a[N];
void DFS(int u)
{
    dd[u] = cur_time;
    int v = a[u].S;
    if (!dd[v]) DFS(v);
    return;
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].F);
        a[i].S = i;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        if (!dd[i])
        {
            cur_time++;
            DFS(i);
        }
    printf("%d\n", cur_time);
    for (int i = 1; i <= n; i++)
        res[dd[i]].PB(i);
    for (int i = 1; i <= cur_time; i++)
    {
        printf("%d ", res[i].size());
        for (auto v : res[i]) printf("%d ", v);
        printf("\n");
    }
}
