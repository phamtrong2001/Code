#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define INF 100

bool A[9][9];

int memo[9][9][1<<9][1<<3][2];

int solve(int r, int c, int mc, int mb, bool p)
{
    if (r == 9) return mc ? INF : 0;
    if (c == 9)
    {
        if (p) return INF;
        if (r % 3 == 2 && mb) return INF;
        return solve(r + 1, 0, mc, mb, 0);
    }
    int& res = memo[r][c][mc][mb][p];
    if(res != -1) return res;
    res = !A[r][c] + solve(r, c + 1, mc ^ 1 << c, mb ^ 1 << c / 3, !p);
    res = min(res, A[r][c] + solve(r, c + 1, mc, mb, p));
    return res;
}

int main()
{
    freopen("BSUDOKU.INP", "r", stdin);
    freopen("BSUDOKU.OUT", "w", stdout);
    for(int i = 0; i < 9; i++)
    {
        string S; cin >> S;
        for(int j = 0; j < 9; j++) A[i][j] = S[j] == '1';
    }
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0, 0, 0, 0) << endl;
}
