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

int n;
ll t, ans;

struct Matrix{
    int x, y;
    ll mat[N][N];
    Matrix operator * (const Matrix & rig){
        Matrix ret; ret.x = x; ret.y = rig.y;
        for(int i = 0; i < ret.x; i++){
            for(int j = 0; j < ret.y; j++){
                ret.mat[i][j] = 0;
                for(int k = 0; k < y; k++){
                    ret.mat[i][j] += mat[i][k]*rig.mat[k][j];
                }
            }
        }
        return ret;
    }
} A, res;

Matrix power(ll x){
    if(x==1) return A;
    Matrix tmp = power(x>>1);
    tmp = tmp*tmp;
    if(x%2) tmp = tmp*A;
    return tmp;
}

Matrix mul(const Matrix &lef, const Matrix &rig){
    Matrix ret; ret.x = lef.x; ret.y = rig.y;
    for(int i = 0; i < ret.x; i++){
        for(int j = 0; j < ret.y; j++){
            ret.mat[i][j] = 0;
            for(int k = 0; k < lef.y; k++){
                ret.mat[i][j] += lef.mat[i][k]*(2LL-(rig.mat[k][j]%2LL));
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    read(n); read(t);
    A.x = A.y = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            readBit(A.mat[i][j]);
        }
    }
    res.x = n; res.y = 1;
    for(int i = 0; i < n; i++){
        res.mat[i][0] += A.mat[i][0];
        ans += A.mat[i][0];
    }
    //res = mul(power(t-1),res);
    for(int i = 2; i <= t; i++){
        res = mul(A,res);
        for(int j = 0; j < n; j++){
            ans += res.mat[j][0];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
