#include <bits/stdc++.h>
#define maxn 5005
using namespace std;

char S[2*maxn];
int F[2*maxn];

int Manacher(char S[], int N)
{
    int i, L, R = L = -1, M, d = 0, res = 0;
    M = 2*N+1;
    for(i = M-1; i >= 0; i--)
    {
        if (d) S[i] = S[(i-1) >> 1]; else S[i] = '#';
        d = 1-d;
    }
    for(i = 0; i <= M-1; i++)
    {
        if (i <= R) d = min(F[L+R-i], R-i);
        else d = 0;
        while ((i-d-1 >= 0) && (i+d+1 < M) && (S[i-d-1] == S[i+d+1])) d++;
        F[i] = d;
        if (i+d > R) L = i-d, R = i+d;
        res = max(res, d);
    }
    return res;
}
int main()
{
    int n;
    cin >> n >> S;
    cout << Manacher(S, n);
}
