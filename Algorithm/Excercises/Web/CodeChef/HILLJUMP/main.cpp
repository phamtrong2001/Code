#include <bits/stdc++.h>
#define N 100005
#define blockSize 200
#define maxdist 100

using namespace std;

int n, query, a[N], blockID[N], c[N], last[N], nex[N];
int add[blockSize];

int get(int pos) {return a[pos] + add[blockID[pos]];}

void updateSum(int x, int y, int value)
{
    if (blockID[x] == blockID[y])
    {
        for (int i = x; i <= y; i++) a[i] += value;
        return;
    }

    for (int i = x; blockID[i] == blockID[x]; i++) a[i] += value;
    for (int i = y; blockID[i] == blockID[y]; i--) a[i] += value;
    for (int i = blockID[x] + 1; i <= blockID[y] - 1; i++) add[i] += value;
}

void updatenex(int x, int y)
{
    stack<int> s;
    for (int i = min(n, y + maxdist); i >= x; i--)
    {
        while (!s.empty() && get(i) >= get(s.top())) s.pop();
        while (!s.empty() && i + maxdist < s.top()) s.pop();
        if (i <= y)
        {
            if (s.empty()) nex[i] = i;
            else nex[i] = s.top();
        }
        s.push(i);
    }
}
void updateLast(int x, int y)
{
    deque<int> q;
    for (int i = min(y + blockSize, n); i >= x; i--)
    {
        while (!q.empty() && get(i) >= get(q.back())) q.pop_back();
        while (!q.empty() && q.back() > i + maxdist) q.pop_back();
        while (!q.empty() && q.front() > i + blockSize) q.pop_front();
        if (i <= y)
        {
            if (q.empty()) last[i] = i, c[i] = 0;
            else
            {
                last[i] = q.front();
                c[i] = q.size();
            }
        }
        q.push_back(i);
    }
}
int go(int pos, int value)
{
    while (value > 0)
    {
        if (last[pos] > pos && c[pos] <= value)
        {
            value -= c[pos];
            pos = last[pos];
        }
        else if (nex[pos] > pos)
        {
            value--;
            pos = nex[pos];
        }
        else break;
    }
    return pos;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &query);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        blockID[i] = (i + blockSize - 1) / blockSize;
    }
    for (int i = n + 1; i <= n + blockSize; ++i) a[i] = -1000000007;
    updatenex(1, n);
    updateLast(1, n);
    while (query--)
    {
        int type, pos, value, x, y;
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d", &pos, &value);
            printf("%d\n", go(pos, value));
        }
        else
        {
            scanf("%d %d %d", &x, &y, &value);
            updateSum(x, y, value);
            updatenex(max(1, x - maxdist), x-1);
            updatenex(max(x, y - maxdist), y);
            updateLast(max(1, x - blockSize), x-1);
            updateLast(max(x, y - blockSize), y);
        }
    }
}
