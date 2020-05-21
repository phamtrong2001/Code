#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 10005
#define maxc 1000000007

using namespace std;

int n, notPrime[N], cur, res;
int all[N][55];
vector<int> allPrime;

void xuli(int x)
{
    for (int i = 0; i < allPrime.size(); i++)
    {
        int y = allPrime[i];
        int dem = 0;
        while (x % y == 0) {dem++; x /= y;}
        all[i][dem]++;
    }
}
int main()
{
    freopen("PVOI14_5.INP", "r", stdin);
    cin >> n;
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i < N; i++)
        if (!notPrime[i])
        {
            allPrime.PB(i);
            for (int j = i*2; j < N; j += i)
                notPrime[j] = 1;
        }
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        xuli(x);
    }
    int res = 0, ans = 1;
    for (int i = 0; i < allPrime.size(); i++)
    {
        int bestAns = maxc, poww = 0;
        for (int j = 0; j < 25; j++)
        {
            int curAns = 0;
            for (int h = 0; h < 25; h++)
                curAns += abs(j-h)*all[i][h];
            if (curAns < bestAns)
            {
                bestAns = curAns;
                poww = j;
            }
        }
        res += bestAns;
        for (int j = 1; j <= poww; j++) ans *= allPrime[i];
    }
    cout <<res <<" "<<ans;
}
