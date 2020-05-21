#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<LL,LL>
#define LL long long
#define st first
#define nd second
#define endl '\n'
using namespace std;

const int MAXN=100005,MAXK=201;
LL n,k,sum[MAXN],t,pnt,val[2][MAXN],top;
int used[MAXN][MAXK];
pair<pii,int> line[MAXN];

double inter(pii a,pii b) {

	if(a.st==b.st)
		return -1e9;
	return 1.0*(b.nd-a.nd)/(a.st-b.st);

}

void upd(LL val) {

	while(pnt+1<top&&inter(line[pnt].st,line[pnt+1].st)<=1.0*val)
		++pnt;

}

void add(pii ll,int y) {

	while(top>=2&&inter(line[top-1].st,line[top-2].st)>=inter(ll,line[top-1].st))
		--top;
	line[top++]=mp(ll,y);
	pnt=min(pnt,top-1);

}

int main() {

	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;++i) {
		scanf("%lld",&t);
		sum[i]=sum[i-1]+t;
	}
	for(int j=1;j<=k;++j) {
		int cur=j&1,old=cur^1;
		pnt=top=0;
		add(mp(sum[j],-sum[j]*sum[j]+val[old][j]),j);
		for(int i=j+1;i<=n;++i) {
			upd(sum[i]);
			val[cur][i]=line[pnt].st.st*sum[i]+line[pnt].st.nd;
			used[i][j]=line[pnt].nd;
			add(mp(sum[i],-sum[i]*sum[i]+val[old][i]),i);
		}
	}
	printf("%lld\n",val[k&1][n]);
	int cur=n;
	for(int i=k;i>=1;--i) {
		cur=used[cur][i];
		printf("%lld ",cur);
	}
	printf("\n");

}
