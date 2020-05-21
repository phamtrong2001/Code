#include<bits/stdc++.h>
#define maxn 205
using namespace std;
struct data
{
    int x,y;
};
data trc[maxn][maxn],T;
vector<data > dcm;
string F[maxn][maxn];
int len,f[maxn][maxn],X[maxn][maxn];
int n,m;
char a[maxn],b[maxn];
vector<char > res;
void go(string S,string T)
{
    if (S.length()==1)
    {
        cout<<T;
        return;
    }
    if (T.length()==1)
    {
        cout<<S;
        return;
    }
    int n=S.length()-1;
    int m=T.length()-1;
    string f[maxn][maxn];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            string A=f[i-1][j]+S[i];
            string B=f[i][j-1]+T[j];
            if (A>B)
            {
                f[i][j]=A;
            }
            else f[i][j]=B;
        }
    cout<<f[n][m];
}
int main()
{
    freopen("LEXLCS.inp","r",stdin);
    freopen("LEXLCS.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>(a+1);
    cin>>(b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    for (int i=n; i>=1; --i)
    {
        int tmp=m+1;
        for (int j=m; j>=1; --j)
        {
            if (a[i]==b[j])
            {
                f[i][j]=f[i+1][tmp]+1;
                trc[i][j]= {i,j};
                X[i][j]=tmp;
                if (f[i][j]>len||(f[i][j]==len&&a[i]>a[T.x]))
                {
                    T= {i,j};
                    len=f[i][j];
                }
            }
            if (a[i]!=b[j])
            {
                f[i][j]=f[i+1][j];
                trc[i][j]=trc[i+1][j];
            }
            if ((f[i+1][j]>f[i+1][tmp])||(f[i+1][j]&&f[i+1][j]==f[i+1][tmp]&&b[j]>b[tmp]))
            {
                tmp=j;
            }
        }
    }
    dcm.push_back({0,0});
    while(len--)
    {
        res.push_back(a[T.x]);
        dcm.push_back({T.x,T.y});
        if (len==0&&(T.x!=n||T.y!=m))
        {
            dcm.push_back({n+1,m+1});
        }
        int x=X[T.x][T.y];
        T=trc[T.x+1][x];
    }
    for (int i=0; i<res.size(); ++i)
        cout<<res[i];
    cout<<"\n";
    for (int k=0; k<dcm.size()-1; ++k)
    {
        string S="";
        string T="";
        S="#"+S;
        T="#"+T;
        for (int j=dcm[k].x+1; j<dcm[k+1].x; ++j)
            S=S+a[j];
        for (int j=dcm[k].y+1; j<dcm[k+1].y; ++j)
            T=T+b[j];
        if (S.length()==1)
        {
            for (int j=1; j<T.length(); ++j)
                cout<<T[j];
            cout<<a[dcm[k+1].x];
            continue;
        }
        if (T.length()==1)
        {
            for (int j=1; j<S.length(); ++j)
                cout<<S[j];
            cout<<a[dcm[k+1].x];
            continue;
        }
        int n=S.length()-1;
        int m=T.length()-1;
        for (int i=0; i<=n; ++i)
            for (int j=0; j<=m; ++j)
            {
                if (i==0&&j==0) continue;
                if (i==0)
                {
                    F[i][j]=F[i][j-1]+T[j];
                    continue;
                }
                if (j==0)
                {
                    F[i][j]=F[i-1][j]+S[i];
                    continue;
                }
                string A=F[i-1][j]+S[i];
                string B=F[i][j-1]+T[j];
                if (A<B)
                {
                    F[i][j]=A;
                }
                else F[i][j]=B;
            }
        cout<<F[n][m];
        cout<<a[dcm[k+1].x];
    }
}
