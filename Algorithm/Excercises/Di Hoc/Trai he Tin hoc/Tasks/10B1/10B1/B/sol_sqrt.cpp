#include<stdio.h>
#include<algorithm>
#define BSZ 1024
using namespace std;
int w[101000], Rev[101000], n, C[101000], D[101000], INF = 2100000000;
struct point{
    int x, y, c, M;
}P[210][1050];
int top[210];
void Ins(int x, int y, int c){
    int a = y/BSZ;
    while(top[a] && P[a][top[a]].y < y)top[a]--;
    P[a][++top[a]] = {x,y,c,c};
    int i;
    for(i=top[a]-1;i>=1;i--){
        P[a][i].M = min(P[a][i].c,P[a][i+1].M);
    }
}
int Get(int y){
    int Mx = -1, i, res = INF, ed;
    ed = y/BSZ*BSZ;
    for(i=y-1;i>=ed;i--){
        if(D[Rev[i]]==INF)continue;
        int t = Rev[i];
        if(Mx >= t)continue;
        Mx = t;
        res = min(res, D[t]);
    }
    for(i=ed/BSZ-1;i>=0;i--){
        if(!top[i] || P[i][top[i]].x <= Mx)continue;
        int b = 1, e = top[i], mid, r = 0;
        while(b<=e){
            mid = (b+e)>>1;
            if(P[i][mid].x > Mx){
                r = mid;
                e = mid - 1;
            }
            else b = mid + 1;
        }
        res = min(res,P[i][r].M);
        Mx = P[i][top[i]].x;
    }
    return res;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&w[i]);
    w[n+1] = n+1;
    for(i=1;i<=n+1;i++){
        if(i<=n)scanf("%d",&C[i]);
        else C[i] = 0;
        D[i]=INF;
        Rev[w[i]] = i;
    }
    Ins(0,0,0);
    for(i=1;i<=n+1;i++){
        int t = Get(w[i]);
        D[i] = t + C[i];
        Ins(i,w[i],D[i]);
    }
    printf("%d\n",D[n+1]);
}
