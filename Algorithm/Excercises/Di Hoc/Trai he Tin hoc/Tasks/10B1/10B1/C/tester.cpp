 #include<cstdio>
#include<algorithm>
#define SZ 131072
using namespace std;
struct Tree{
    int S, K;
}IT[SZ+SZ];
int n, mm, w[101000], Q[101000][2];
void Fill(int nd, int b, int e, int K){
    IT[nd].K = K;
    IT[nd].S = K*(e-b+1);
}
void Spread(int nd, int b, int e, int m){
    if(IT[nd].K==-1)return;
    Fill(nd*2, b, m, IT[nd].K);
    Fill(nd*2+1, m+1, e, IT[nd].K);
    IT[nd].K = -1;
}
void UDT(int nd){
    IT[nd].K = -1;
    IT[nd].S = IT[nd*2].S + IT[nd*2+1].S;
}
void init(int nd, int b, int e, int M){
    if(b==e){
        if(w[b] <= M) Fill(nd, b, e, 0);
        else Fill(nd, b, e, 1);
        return;
    }
    int m = (b+e)>>1;
    init(nd*2,b,m,M);
    init(nd*2+1,m+1,e,M);
    UDT(nd);
}
int Sum(int nd, int b, int e, int s, int l){
    if(b==s&&e==l)return IT[nd].S;
    int m = (b+e)>>1, r = 0;
    Spread(nd, b, e, m);
    if(s <= m)r += Sum(nd*2,b,m,s,min(m,l));
    if(l > m)r += Sum(nd*2+1,m+1,e,max(s,m+1),l);
    UDT(nd);
    return r;
}
void Ins(int nd, int b, int e, int s, int l, int x){
    if(s>l)return;
    if(b==s&&e==l){
        Fill(nd,b, e, x);
        return;
    }
    int m = (b+e)>>1, r = 0;
    Spread(nd, b, e, m);
    if(s <= m)Ins(nd*2,b,m,s,min(m,l),x);
    if(l > m)Ins(nd*2+1,m+1,e,max(s,m+1),l,x);
    UDT(nd);
}
bool Pos(int M){
    int i;
    init(1,1,n,M);
    for(i=1;i<=mm;i++){
        int Mn = min(Q[i][0],Q[i][1]), Mx = max(Q[i][0],Q[i][1]);
        int s1 = Sum(1,1,n,Mn,Mx), s0;
        s0 = Mx-Mn+1-s1;
        if(Q[i][0] <= Q[i][1]){
            Ins(1,1,n,Mn,Mn+s0-1,0);
            Ins(1,1,n,Mn+s0,Mx,1);
        }
        else{
            Ins(1,1,n,Mn,Mn+s1-1,1);
            Ins(1,1,n,Mn+s1,Mx,0);
        }
    }
    int s = Sum(1,1,n,(n+1)/2,(n+1)/2);
    if(s==0)return true;
    return false;
}
int main(){
    int i, b, e, mid, r = 0;
    scanf("%d%d",&n,&mm);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=mm;i++){
        scanf("%d%d",&Q[i][0],&Q[i][1]);
    }
    b = 1, e = n;
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid)){
            r = mid;
            e = mid - 1;
        }
        else b = mid + 1;
    }
    printf("%d\n",r);
}
