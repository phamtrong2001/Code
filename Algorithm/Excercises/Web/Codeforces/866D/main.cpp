#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
int main()
{
    cin >> n;
    priority_queue<int> buy, sell;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        int a = 0, b = 0;
        while (!buy.empty() && x > buy.top()) a = x - buy.top();
        while (!sell.empty() && x > sell.top()) b = x - sell.top();
        if (a >= b && a > 0)
        {
            res += a;
            buy.pop();
            sell.push(x);
        }
        else
        {
            if (b == 0)
        }
    }
}
