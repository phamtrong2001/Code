#include <bits/stdc++.h>
#define N 1000006
#define LN 25

using namespace std;

int n, l, d, a[N], M1[N][LN], M2[N][LN];
int get_min(int u, int v)
{
    int k = log2(v-u+1);
    return min(M1[u][k], M1[v - (1 << k) + 1][k]);
}
int get_max(int u, int v)
{
    int k = log2(v-u+1);
    return max(M2[u][k], M2[v - (1 << k) + 1][k]);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d %d", &n, &l, &d);
    l++;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        M1[i][0] = a[i];
        M2[i][0] = a[i];
    }
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j + (1 << i) - 1<= n; j++)
        {
            M1[j][i] = min(M1[j][i-1], M1[j + (1 << (i-1))][i-1]);
            M2[j][i] = max(M2[j][i-1], M2[j + (1 << (i-1))][i-1]);
        }
    int j = 1; int valmin, valmax;
    valmin = get_min(1, l);
    valmax = get_max(1, l);

    long long res = 0;
    for (int i = l; i <= n; i++)
    {
        valmin = get_min(j, i);
        valmax = get_max(j, i);
        while (abs(valmin - valmax) > d && j < i)
        {
            j++;
            valmin = get_min(j, i);
            valmax = get_max(j, i);
        }
        res += max(0, (i - l + 1) - j + 1);
    }
    cout <<res;
}
