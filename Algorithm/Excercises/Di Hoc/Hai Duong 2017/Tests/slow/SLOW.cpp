#include <bits/stdc++.h>
#define maxn 100005

using namespace std;
int n, deg[maxn], a[maxn];
vector<int> g[maxn];
int cl[maxn], cur[maxn], s[maxn], sn;
int b[maxn];
int ret[maxn];


void update(int u,int val) {
    while (u<=n) {
        b[u]+=val;
        u+=u&(-u);
    }
}

int get(int u) {
    int kq=0;
    while (u) {
        kq+=b[u];
        u&=(u-1);
    }
    return kq;
}

void DFS() {
    for(int i=1;i<=n;i++) cl[i]=cur[i]=b[i]=0;
    sn=0;
    s[++sn]=1;
    ret[a[1]]=0; update(a[1],1);

    while (sn) {
        int u=s[sn];
        while (cur[u]<deg[u] && cl[g[u][cur[u]]]) cur[u]++;
        if (cur[u]==deg[u]) {
            update(a[u],-1);
            sn--;
        } else {
            int v=g[u][cur[u]];
            s[++sn]=v; cl[v]=1;
            ret[a[v]]=get(a[v]-1);
            update(a[v],1);
        }
    }
}

int main() {
    freopen("slow.inp","r",stdin);
    freopen("slow.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); deg[u]++;
        g[v].push_back(u); deg[v]++;
    }
    for(int i=1;i<=n;i++) {
        int u; scanf("%d",&u);
        a[u]=i;
    }


    DFS();
    for(int i=1;i<=n;i++) printf("%d\n",ret[i]);
}
