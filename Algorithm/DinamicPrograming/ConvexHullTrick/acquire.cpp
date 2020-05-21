#include <bits/stdc++.h>
using namespace std;
int pointer;
vector<long long> M;
vector<long long> B;

bool bad(int l1,int l2,int l3)
{
	return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);
}

void add(long long m,long long b)
{
	M.push_back(m);
	B.push_back(b);
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
}

long long query(long long x)
{
	if (pointer>=M.size())
		pointer=M.size()-1;
	while (pointer<M.size()-1&&
	  M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
		pointer++;
	return M[pointer]*x+B[pointer];
}
int main()
{
	int M,N,i;
	pair<int,int> a[50000];
	pair<int,int> rect[50000];
	freopen("acquire.inp","r",stdin);
	freopen("acquire.out","w",stdout);
	scanf("%d",&M);
	for (i=0; i<M; i++)
		scanf("%d %d",&a[i].first,&a[i].second);
	sort(a,a+M);
	for (i=0,N=0; i<M; i++)
	{
		while (N>0&&rect[N-1].second<=a[i].second)
			N--;
		rect[N++]=a[i];
	}
	long long cost;
	add(rect[0].second,0);
	pointer=0;
	for (i=0; i<N; i++)
	{
		cost=query(rect[i].first);
		if (i < N-1)
			add(rect[i+1].second,cost);
	}
	printf("%lld\n",cost);
	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  