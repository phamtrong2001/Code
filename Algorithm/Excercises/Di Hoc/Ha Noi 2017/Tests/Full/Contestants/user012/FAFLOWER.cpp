#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
#define ll long long
#define maxN 1000001
#define oo 100000000000000001
#define pii pair<ll,ll>
#define fi first
#define se second

using namespace std;
ll n,k;
vector<ll> f[maxN];
ll p[1<<20];
ll h[1<<20];
ll g[1<<20];
void Solve()
{
    fill_n(&p[0],sizeof(p)/sizeof(p[0]),-1);
    ll x=0;
    for(int i=0;i<f[0].size();i++)
        x+=(1<<f[0][i]);
    p[x]=f[0].size();
    h[x]=1;
    g[1]=x;
    ll ans=p[x];
    for(int i=2;i<=k;i++)
    {
        ll y=0;
        ll t=p[x];
        //cout<<x<<endl;
        for(int i=0;i<n;i++)
        {
            if((x&(1<<i))!=0)
            {
                //cout<<"th1 "<<i<<endl;
                for(int j=0;j<f[i].size();j++)
                {
                    y=y^(1<<f[i][j]);
                    t+=1;
                }
            }
            else
            {
                //cout<<"th2 "<<i<<endl;
                t+=2*f[i].size();
            }

        }
        //cout<<x<<" "<<y<<" "<<t<<endl;
        if(p[y]==-1)
        {
            p[y]=t;
            ans=t;
            h[y]=i;
            x=y;
            g[i]=y;
        }
        else
        {
            //cout<<(t-p[y])<<" "<<((k-h[y])/(i-h[y]))<<endl;
            ans=p[y]+(t-p[y])*((k-h[y])/(i-h[y]))+(p[g[h[y]+(k-h[y])%(i-h[y])]]-p[y]);
            cout<<ans;
            return;
        }
    }
    cout<<ans;

}
void Enter()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            char x;
            cin>>x;
            if(x=='1')
                f[i].push_back(j);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("FAFLOWER.inp","r",stdin);
    freopen("FAFLOWER.out","w",stdout);

    Enter();
    Solve();
}
