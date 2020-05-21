#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int n, a[N], res;
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int i = 1, j = n;
    while (i < j)
    {
        if (a[i] == a[j]) i++, j--;
        else if (a[i] < a[j])
        {
            a[i+1] += a[i];
            i++;
            res++;
        }
        else if (a[i] > a[j])
        {
            a[j-1] += a[j];
            j--;
            res++;
        }
    }
    cout <<res;
}
