#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n, a[N], group[N];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> n;
    int pos = 1; bool flag = 0; int dem = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (a[1] % 2 == 0) flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 1 && (i - pos + 1) % 2 == 1)
        {
            group[++dem] = i - pos + 1;
            pos = i+1;
        }
    }
    if (pos <= n || dem % 2 == 0) flag = 1;
    if (flag) cout <<"No";
    else cout <<"Yes";
}
