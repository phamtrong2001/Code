#include <bits/stdc++.h>

#define TASK "FAFLOWER"

using namespace std;

template<typename T> inline void read(T &x){
    x = 0; char ch; bool neg = 0;
    while(!isdigit(ch=getchar())&&ch!='-');
    if(ch=='-'){neg=1;ch=getchar();}
    do{x=10*x+ch-'0';} while(isdigit(ch=getchar()));
    if(neg) x = -x;
}

template<typename T> inline void readBit(T &x){
    char ch;
    do{ch=getchar();} while(ch!='0'&&ch!='1');
    x = ch-'0';
}

typedef long long ll;

const int N = 22;
const int MASK = 11e5;

int n, fi, Next[MASK], F[MASK], Tr[MASK];
ll t, res;
bool A[N][N], B[MASK];

int getBit(int x, int p){
    return (x>>p)&1;
}

void onBit(int &x, int p){
    x |= (1<<p);
}

void offBit(int &x, int p){
    x &= ~(1<<p);
}

void toggleBit(int &x, int p){
    x ^= (1<<p);
}

void update(int st){
        F[st] = 0;
        int x = 0;
        int add;
        for(int i = 0; i < n; i++){
            if(getBit(st,i)) add = 1;
            else add = 2;
            for(int j = 0; j < n; j++){
                if(A[i][j]){
                    F[st] += add;
                    if(add==1) toggleBit(x,j);
                }
            }
        }
        Next[st] = x;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    read(n); read(t);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            readBit(A[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        if(A[0][i]) onBit(fi,i);
        res += A[0][i];
    }
    int u = fi;
    t--;
    for(ll i = 1; i <= t; i++){
        if(B[u]){
            int v = u;
            ll tmp = 0;
            ll cnt = 0;
            while(1){
                tmp += F[Tr[v]];
                cnt++;
                v = Tr[v];
                if(v==u) break;
            }
            t -= i-1;
            res += t/cnt*tmp;
            i = 0;
            t %= cnt;
            memset(B,0,sizeof(B));
            continue;
        }
        B[u] = B;
        update(u);
        res += (ll)F[u];
        Tr[Next[u]] = u;
        u = Next[u];
    }
    cout<<res<<'\n';
    return 0;
}
