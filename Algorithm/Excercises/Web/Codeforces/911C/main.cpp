#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int a, b, c;
int dd[1550];

int main()
{
    cin >> a >> b >> c;
    dd[a]++; dd[b]++; dd[c]++;
    bool flag = 0;
    if (dd[1]) flag = 1;
    if (dd[2] > 1) flag = 1;
    if (dd[3] > 2) flag = 1;
    if (dd[2] > 0 && dd[4] > 1) flag = 1;
    if (flag) cout <<"YES";
    else cout <<"NO";
}
