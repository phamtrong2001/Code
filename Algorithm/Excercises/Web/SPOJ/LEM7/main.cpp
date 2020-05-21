#include <bits/stdc++.h>
#define maxc 1000000007
#define N 10005
using namespace std;

int n, C1[N], C2[N], F1[N], F2[N], F3[N];
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        C1[i] = maxc;
        for (int j = sqrt(i); j >= 1; j--)
        {
            if (i % j) continue;
            if (C1[i] > j + i/j)
            {
                C1[i] = j + i/j;
                C2[i] = j;
            }
            else if (C1[i] == j + i/j && C2[i] > j) C2[i] = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        F1[i] = F2[i] = F3[i] = maxc;
        for (int j = 1; j <= i; j++)
        {
            if (F1[i] > F1[i-j] + C1[j])
            {
                F1[i] = F1[i-j] + C1[j];
                F2[i] = F2[i-j] + C2[j];
                F3[i] = F3[i-j] + 1;
            }
            else if (F1[i] == F1[i-j] + C1[j] && F2[i] > F2[i-j] + C2[j])
            {
                F2[i] = F2[i-j] + C2[j];
                F3[i] = F3[i-j] + 1;
            }
            else if (F1[i] == F1[i-j] + C1[j] && F2[i] == F2[i-j] + C2[j] && F3[i] > F3[i-j] + 1)
                F3[i] = F3[i-j] + 1;
        }
    }
    printf("%d %d %d", F1[n], F2[n], F3[n]);
}
