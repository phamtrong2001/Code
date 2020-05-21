#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define PB push_back
#define maxc 1000000007
#define N 100005

using namespace std;

int n, k, cur;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        cur += x;
        if (cur <= 8)
        {
            k -= cur;
            cur = 0;
        }
        else
        {
            k -= 8;
            cur -= 8;
        }
        if (k <= 0)
        {
            cout <<i;
            return 0;
        }
    }
    cout <<-1;
}
