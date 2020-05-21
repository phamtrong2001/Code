int get_root(int u)
{
  return (root[u]) ? root[u] = get_root(root[u]) : u;
}
void Kruskal()
{
  memset(root, 0, sizeof root);
  sort(b+1, b+m+1, cmp);
  int dem = 0;
  long long res = 0;
  for (int i = 1; i <= m; i++)
  {
    if (b[i].w >= b[k].w)   continue;
    int p = get_root(b[i].u);
    int q = get_root(b[i].v);
    if (p != q)
    {
      root[p] = q;
      dem++;
    }
    if (dem == n-1) break;
  }
}
