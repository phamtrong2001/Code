#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a[N], p;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    int z = n;
    int p = 0;
    for (int i = m; i >= 1; i--)
    {
        if (a[i] != z--)
        {
            p = i;
            break;
        }
    }
    if (p == 0) {cout <<-1; return 0;}
    for (int i = 1; i < p; i++) cout <<a[i]<<" ";
    cout <<++a[p]<<" ";
    for (int i = p+1; i <= m; i++) cout <<a[i-1]+1<<" ";
}
