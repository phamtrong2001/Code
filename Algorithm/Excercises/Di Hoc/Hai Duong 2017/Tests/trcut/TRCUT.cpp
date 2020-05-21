#include <bits/stdc++.h>
#define maxn 500005

using namespace std;

int n, m;
int a[maxn], deg[maxn]={0};
vector<int> g[maxn];
int cur[maxn], cl[maxn], prev[maxn], x[maxn], s[maxn], sn, slx;
int f[maxn];

void dfs() {
    for(int i=1;i<=n;i++) cl[i]=cur[i]=prev[i]=0;
    sn=0; slx=0;
    s[++sn]=1; cl[1]=1;
    x[++slx]=1;
    while (sn) {
        int u=s[sn];
        while (cur[u]<deg[u] && cl[g[u][cur[u]]]) cur[u]++;
        if (cur[u]==deg[u]) sn--; else {
            int v=g[u][cur[u]];
            prev[v]=u; cl[v]=1;
            s[++sn]=v;
            x[++slx]=v;
        }
    }
}

int k, b[maxn];

bool ok(int val) {
    int cnt=0;
    for(int i=n;i>=1;i--) {
        int u=x[i];
        if (a[u]>val) return false;
        k=0;
        for(int j=0;j<deg[u];j++)
            if (prev[g[u][j]]==u) b[++k]=f[g[u][j]];
        sort(b+1,b+k+1);
        f[u]=a[u];
        for(int j=k;j>=1;j--) f[u]+=b[j];
        int j=k;
        while (f[u]>val) {cnt++;f[u]-=b[j--];}
    }
    return (cnt<=m);
}

int main() {
    freopen("trcut.inp","r",stdin);
    freopen("trcut.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); deg[u]++;
        g[v].push_back(u); deg[v]++;
    }
    dfs();
    // Tim kiem nhi phan
    int lo=-1, hi=1000000001;
    while (hi-lo>1) {
        int mid=(lo+hi)/2;
        if (ok(mid)) hi=mid; else lo=mid;
    }
    printf("%d",hi);
}
