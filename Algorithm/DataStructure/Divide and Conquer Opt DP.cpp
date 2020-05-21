void calc(int id, int l, int r, int x, int y)
{
    if (l > r) return;
    int mid = (r + l)/2;
    int ans = maxc, pos;
    for (int i = x; i <= min(y, mid); i++)
    {
        int res = dp[id-1][i-1] + sum(i, i, mid, mid)/2;
        if (res < ans)
        {
            ans = res;
            pos = i;
        }
    }
    dp[id][mid] = ans;
    calc(id, l, mid-1, x, pos);
    calc(id, mid+1, r, pos, y);
}
