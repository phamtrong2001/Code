#include <bits/stdc++.h>
#define pii pair<unsigned long long, unsigned long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

unsigned long long n, k, f[N];

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending ";
string s2 = "? Are you busy? Will you send ";
string s3 = "?";


void in(string w, unsigned long long pos)
{
    cout <<w[pos-1];
}
void DFS(unsigned long long u, unsigned long long v)
{
    if (u == 0)
    {
        in(s, v);
        return;
    }
    if (v > s1.size()) v -= s1.size();
    else
    {
        in(s1, v);
        return;
    }
    if (u > 60)
    {
        DFS(u-1, v-1);
        return;
    }
    else if (v > f[u-1] + 2) v -= (f[u-1] + 2);
    else if (v > f[u-1] + 1 || v == 1)
    {
        cout <<'"';
        return;
    }
    else
    {
        DFS(u-1, v-1);
        return;
    }
    if (v > s2.size()) v -= s2.size();
    else
    {
        in(s2, v);
        return;
    }
    if (u > 60)
    {
        DFS(u-1, v-1);
        return;
    }
    else if (v > f[u-1] + 2) v -= (f[u-1] + 2);
    else if (v > f[u-1] + 1 || v == 1)
    {
        cout <<'"';
        return;
    }
    else
    {
        DFS(u-1, v-1);
        return;
    }
    in(s3, v);
    return;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    f[0] = s.size();
    for (unsigned long long i = 1; i < N; i++)
        f[i] = 1ll*s1.size() + 1ll*s2.size() + 1ll*s3.size() + 2ll*f[i-1] + 4ll;
    unsigned long long q; cin >> q;
    while (q--)
    {
        cin >> n >> k;
        if (n == 0)
        {
            if (s.size() < k) {cout <<'.'; continue;}
            else in(s, k);
            continue;
        }
        if (f[n] < k)
        {
            cout <<'.';
            continue;
        }
        DFS(n, k);
    }
}
