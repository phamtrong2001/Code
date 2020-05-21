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

char a[2*N], b[2*N];
int n, p[2*N];

void prepare()
{
    int cnt = 0;
    b[++cnt] = '#';
    for (int i = 1; a[i]; i++)
    {
        b[++cnt] = a[i];
        b[++cnt] = '#';
    }
    b[++cnt] = 0;
    b[0] = '^';
}
void nhap()
{
    cin >> a+1;
    n = strlen(a+1);
}
int manacher()
{
    int R = 1, C = 1, n = strlen(b+1);
    int r = 0;
    for (int i = 2; i < n; i++)
    {
        int mirror = 2*C - i;
        p[i] = (R > i) ? min(R-i, p[mirror]) : 0;
        while (b[i+p[i]+1] == b[i-p[i]-1]) p[i]++;
        r = max(r, p[i]);
        if (i + p[i] > R) {C = i; R = i + p[i];}
    }
    return r;
}

int main()
{
    //freopen("INP.TXT", "r", stdin);
    nhap();
    prepare();
    cout <<manacher();
}
