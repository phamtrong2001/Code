/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "permutation"
#define maxn 25

using namespace std;

string s;

long long p[maxn], res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> s;
    int len = s.size();
    s = s + ' ';
    p[1] = 1;
    for (int i = 2; i <= len+1; i++)
        p[i] = 1ll * p[i-1] * i;
    res = p[len];
    sort(s.begin(), s.end());
    int dem = 1;
    for (int i = 1; i <= len+1; i++)
        if (s[i] != s[i-1]) res /= p[dem], dem = 1;
            else dem++;
    cout << res;
    return 0;
}
