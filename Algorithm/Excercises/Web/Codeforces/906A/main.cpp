#include <bits/stdc++.h>
#define ll long long
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
    freopen("INP.TXT", "r", stdin);
    cin >> n;

    int fullmask = 0;
    for (int i = 0; i < 26; i++) fullmask |= (1 << i);

    int maskres = fullmask;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        char type; string s;
        cin >> type >> s;
        int mask = 0;
        for (int j = 0; j < s.size(); j++)
            mask |= (1 << (s[j] - 'a'));
        if (type == '!')
        {
            if (__builtin_popcount(maskres) == 1) res++;
            maskres &= mask;
        }
        else if (type == '.')
        {
            mask = fullmask^mask;
            maskres &= mask;
        }
        else
        {
            if (__builtin_popcount(maskres) == 1 && maskres != mask) res++;
            mask = fullmask^mask;
            maskres &= mask;
        }
    }
    cout <<res;
}
