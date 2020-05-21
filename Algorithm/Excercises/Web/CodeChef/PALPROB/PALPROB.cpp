#include <bits/stdc++.h>
#define PB push_back
#define N 100005
using namespace std;

struct PTNode
{
    long long first, length, occurance, child[26], suffix;
    PTNode(long long first = 0, long long length = 0) : first(first), length(length)
    {
        occurance = suffix = 0;
        for (long long i = 0; i < 26; i++) child[i] = 0;
    }
}node[N];

string s;
long long cur, sz, res, A[N];
vector<long long> E[N];

void add(long long pos)
{
    long long start;
    while (1)
    {
        start = pos - node[cur].length - 1;
        if (start >= 0 && s[start] == s[pos])
            break;
        cur = node[cur].suffix;
    }
    long long z = s[pos] - 'a';
    if (node[cur].child[z])
    {
        cur = node[cur].child[z];
        node[cur].occurance++;
        return;
    }
    node[++sz] = PTNode(start, node[cur].length + 2);
    node[cur].child[z] = sz;
    if (node[sz].length == 1)
        node[sz].suffix = 2;
    else
    {
        while (1)
        {
            cur = node[cur].suffix;
            long long start = pos - node[cur].length - 1;
            if (start >= 0 && s[pos] == s[start])
                break;
        }
        node[sz].suffix = node[cur].child[z];
    }
    node[sz].occurance++;
    E[node[sz].suffix].PB(sz);
    cur = sz;
    return;
}



void DFS(long long u, long long cnt)
{
    long long len = node[u].length;
    if (len == 1) A[len] = 1;
    else if (len > 1) A[len] = A[len/2] + 1;
    cnt += A[len];
    res += node[u].occurance * cnt;
    for (long long &v : E[u])
        DFS(v, cnt);
    A[len] = 0;
}
void setup()
{
    cin >> s;
    sz = cur = 2;
    node[1] = PTNode(0, -1), node[2] = PTNode(0, 0);
    node[1].suffix = node[2].suffix = 1;
    for (int i = 0; i <= s.size()+2; i++)
    {
        E[i].clear();
        for (int j = 0; j < 26; j++)
            node[i].child[j] = 0;
    }

}
void solve()
{
    res = 0;
    for (long long i = 0; i < s.size(); i++) add(i);
    //for (long long i = sz; i >= 3; i--)
        //node[node[i].suffix].occurance += node[i].occurance;
    //DFS(1);
    DFS(2, 0);
    cout <<res<<endl;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    long long t; cin >> t;
    while(t--)
    {
        setup();
        solve();
    }
}
