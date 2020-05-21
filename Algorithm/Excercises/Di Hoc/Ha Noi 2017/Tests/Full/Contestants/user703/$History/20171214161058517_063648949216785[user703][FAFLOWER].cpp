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

int n, Flower[N+7], a[N+7][N+7], minute[5][N+7];
ll t, res;

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

void solveProblem()
{
  int temp0 = 0;
  FORU(i,2,n)
    if(a[1][i]) minute[1][i] = 1, temp0++;
  if(t == 1)
  {
    cout << temp0;
    return;
  }
  FORU(i,2,n)
    if(a[1][i]) minute[1][i] = 1;
  int temp1 = 0;
  FORU(i,1,n)
  {
    FORU(j,1,n)
    {
      if(!a[1][i] && a[i][j]) Flower[j] += 2, temp1 += 2;
      if(a[1][i] && a[i][j]) Flower[j]++, temp1++;
    }
  }
  if(t == 2)
  {
    cout << temp0 + temp1;
    return;
  }
  FORU(i,1,n) minute[2][i] = Flower[i] % 2, Flower[i] = 0;
  int temp2 = 0;
  FORU(i,1,n)
  {
    FORU(j,1,n)
    {
      if(!minute[2][i] && a[i][j]) Flower[j] += 2, temp2 += 2;
      if(minute[2][i] && a[i][j]) Flower[j]++, temp2++;
    }
  }
  FORU(i,1,n) minute[3][i] = Flower[i] % 2;
  res = 1ll * (temp0 + temp1 + temp2);
  bool check = 1;
  FORU(i,1,n)
    if(minute[2][i] != minute[3][i])
    {
      check = 0;
      break;
    }
  if(check) res += 1ll * temp2 * (t-3);
  else
  {
    long long sd = 4, sc = t;
    if(sc % 2 == 1) sc--;
    long long odd = (sc-sd) / 2 + 1;
    res += 1ll * temp1 * odd;
    long long even = t - 3 - odd;
    res += 1ll * temp2 * even;
  }
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
