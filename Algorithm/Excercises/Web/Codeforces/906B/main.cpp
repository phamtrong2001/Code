#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, m;
vector<int> a[N], b[N], all;

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        a[i].resize(m+1);
        b[i].resize(m+1);
        for (int j = 1; j <= m; j++) a[i][j] = (i-1)*m + j;
    }
    bool bswap = 0;
    if (n > m) bswap = 1;
    if (bswap == 1)
    {
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++) all.PB(a[i][j]);
        for (int j = 1; j <= m; j++)
        {
            if (n % 2 == 0)
            {
                for (int i = 1; i <= n/2; i++)
                    b[i][j] = all[(j-1)*n+(i-1)*2+1];
                for (int i = n/2+1; i <= n; i++)
                    b[i][j] = all[(j-1)*n+(i-1-n/2)*2];
                if (j % 2 == 1) for (int i = 1; i <= n/2; i++) swap(b[i][j], b[n-i+1][j]);
            }
            else
            {
                if (j % 2 == 1)
                {
                    for (int i = 1; i <= n/2; i++)
                        b[i][j] = all[(j-1)*n+(i-1)*2+1];
                    for (int i = n/2+1; i <= n; i++)
                        b[i][j] = all[(j-1)*n+(i-1-n/2)*2];
                }
                else
                {
                    for (int i = 1; i <= n/2+1; i++)
                        b[i][j] = all[(j-1)*n+(i-1)*2];
                    for (int i = n/2+2; i <= n; i++)
                        b[i][j] = all[(j-1)*n+(i-2-n/2)*2+1];
                }
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) all.PB(a[i][j]);
        for (int i = 1; i <= n; i++)
        {
            if (m % 2 == 0)
            {
                for (int j = 1; j <= m/2; j++)
                    b[i][j] = all[(i-1)*m+(j-1)*2+1];
                for (int j = m/2+1; j <= m; j++)
                    b[i][j] = all[(i-1)*m+(j-1-m/2)*2];
                if (i % 2 == 1) for (int j = 1; j <= m/2; j++) swap(b[i][j], b[i][m-j+1]);
            }
            else
            {
                if (i % 2 == 1)
                {
                    for (int j = 1; j <= m/2; j++)
                        b[i][j] = all[(i-1)*m+(j-1)*2+1];
                    for (int j = m/2+1; j <= m; j++)
                        b[i][j] = all[(i-1)*m+(j-1-m/2)*2];
                }
                else
                {
                    for (int j = 1; j <= m/2+1; j++)
                        b[i][j] = all[(i-1)*m+(j-1)*2];
                    for (int j = m/2+2; j <= m; j++)
                        b[i][j] = all[(i-1)*m+(j-2-m/2)*2+1];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout <<b[i][j]<<" ";
        cout <<endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout <<"YES"<<endl<<1;
        return 0;
    }
    if ((n == 1 && m == 4) || (n == 4 && m == 1))
    {
        cout <<"YES"<<endl;
        solve();
        return 0;
    }
    if (n + m <= 5)
    {
        cout <<"NO";
        return 0;
    }
    cout <<"YES"<<endl;
    if (n == 3 && m == 3)
    {
        cout <<6<<" "<<1<<" "<<8<<endl;
        cout <<7<<" "<<5<<" "<<3<<endl;
        cout <<2<<" "<<9<<" "<<4;
        return 0;
    }
    if (n > 3 || m > 3)
        solve();

}
