void DFS(int u, int p)
{
    sz[u] = 1; spe[u] = 0;
    for (auto v : a[u])
    {
        if (v == p) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < LOGN; i++) p[v][i] = p[p[v][i-1]][i-1];
        DFS(v, u);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
}

void HLD(int u, int p)
{
    if (head[curChain] == 0) head[curChain] = u;
    chainInd[u] = curChain;
    posInBase[u] = ++dem;
    pos[dem] = u;

    if (spe[u])
    {
        HLD(spe[u], u);
        for (auto v : a[u])
            if (v != p && v != spe[u])
            {
                curChain++;
                HLD(v, u);
            }
    }
}

int get_ans(int u, int v)
{
    if (h[u] > h[v]) swap(u, v);
    int uchain, vchain = chainInd[v];

    while (1)
    {
        uchain = chainInd[u];
        if (uchain == vchain)
        {
            /// update res
            res = min(res, t.get(1, n, 1, posInBase[v], posInBase[u]));
            break;
        }
        /// update res
        res = min(res, t.get(1, n, 1, posInBase[head[uchain]], posInBase[u]));
        /// nhảy lên trên bỏ qua chain hiện tại
        u = head[uchain];
        u = p[u][0];
    }
    return res;
}
