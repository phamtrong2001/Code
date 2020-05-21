#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
string s;
int n,idd,g[25],dd[2000000],cs;
vector <int> a[25];
long long t,f[2000000];
void Enter()
{
    cin >> n >> t;
    getline(cin,s);
    for (int i=1;i<=n;i++)
    {
        getline(cin,s);
        s=" "+s;
        for (int j=1;j<=n;j++)
        {
            if (s[j]=='1') a[i].push_back(j);
        }
    }
}
void BFS(int u)
{
    idd=1;
    while(true)
    {
        long long cnt=0;
        ++idd;
        for (int i=0;i<n;i++) g[i]=0;
        for (int i=0;i<n;i++)
        {
            if ((u>>i)&1)
            {
                for (int j:a[i+1]) g[j-1]++;
                cnt+=a[i+1].size();
            }
            else cnt+=2*a[i+1].size();
        }
        int res=0;
        for (int i=0;i<n;i++)
        {
            if (g[i]%2==1) res+=(1<<i);
        }
        f[idd]=f[idd-1]+cnt;
        if (dd[res]!=0)
        {
            cs=res;
            return;
        }
        dd[res]=idd;
        u=res;
    }
}
void Solve()
{
    int res=0;
    for (int u:a[1]) res+=(1<<(u-1));
    f[1]=a[1].size();
    dd[res]=1;
    BFS(res);
    if (t<=idd) {cout << f[t];return;}
    long long kq=f[dd[cs]];
    t=t-dd[cs];
    kq+=(t/(idd-dd[cs]))*(f[idd]-f[dd[cs]]);
    int r=t%(idd-dd[cs]);
    kq+=f[cs+r]-f[cs];
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("FAFLOWER.INP","r",stdin);
    freopen("FAFLOWER.OUT","w",stdout);
    Enter();
    Solve();
}
