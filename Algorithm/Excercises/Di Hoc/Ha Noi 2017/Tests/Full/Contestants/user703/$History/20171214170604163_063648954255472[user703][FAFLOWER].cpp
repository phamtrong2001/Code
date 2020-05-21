//*******GIANG*******//
#include <bits/stdc++.h>
#define N 20
#define MOD 1000000007
#define MAXX 1000000007
#define FORU(i,a,b) for(int i=a ; i<=b ; ++i)
#define FORD(i,a,b) for(int i=a ; i>=b ; --i)
#define pii pair <int, int>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "FAFLOWER"

using namespace std;

int n, a[N+7][N+7], mark[(1<<N)+7], mask[(1<<N)+7][N+7];
ll t, flower[(1<<N)+7];

int readInt()
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while(true)
  {
		if(ch == '-') break;
		if(ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if(ch == '-') minus = true; else result = ch-'0';
	while(true)
  {
		ch = getchar();
		if(ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if(minus) return -result;
	else return result;
}

pii operator + (pii a, pii b)
{
  return make_pair(a.F + b.F, a.S + b.S);
}

void readData()
{
  cin >> n >> t;
  FORU(i,1,n)
  {
    FORU(j,1,n)
    {
      char c;
      cin >> c;
      a[i][j] = c - 48;
    }
  }
}

int getBIT(int x, int y)
{
  return (x >> y) & 1;
}

void solveProblem()
{
  int temp = 0, minute = 1;
  FORU(i,2,n)
    if(a[1][i]) temp += 1 << (i-1), mask[1][i] = 1, flower[1]++;
//  cout << temp << " " << flower[1] << "\n";
  while(!mark[temp] && minute <= t)
  {
    mark[temp] = minute, temp = 0, minute++;
    if(minute > 2) flower[minute] = flower[minute-1];
    FORU(i,1,n)
    {
      FORU(j,1,n)
      {
        if(mask[minute-1][i] && a[i][j]) mask[minute][j] = (mask[minute][j] + 1) % 2, flower[minute]++;
        if(!mask[minute-1][i] && a[i][j]) flower[minute] += 2;
      }
    }
    FORU(i,1,n)
      if(mask[minute][i]) temp += 1 << (i-1);
//    cout << minute << " " << temp << " " << flower[minute] << "\n";
  }
//  cout << minute <<  " " << flower[minute] << " " << mark[temp] <<"\n" ;
  long long res = flower[1] + flower[minute];
//  cout << res << "\n";
  int ct = (t - minute) / (minute - mark[temp]);
//  cout << ct << "\n";
  res += (flower[minute] - flower[mark[temp]]) * ct;
//  cout << res << "\n";
  ct = t - minute - ct * (minute - mark[temp]);
//  cout << ct << "\n";
  res += flower[mark[temp]+ct] - flower[mark[temp]];
  cout << res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  freopen(Task".inp","r",stdin);
  freopen(Task".out","w",stdout);
  readData();
  solveProblem();
  return 0;
}
