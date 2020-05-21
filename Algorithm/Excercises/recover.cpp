#include <bits/stdc++.h>

using namespace std;

string s;
int dem = 1, n;

long long chuyen(string z)
{
    int m = z.length();
    long long cur = 0;
    for (int i = 0; i < m; i++)
    {
        int a = z[i] - '0';
        cur = cur * 10 + a;
    }
    return cur;
}

void duyet(int bd, int pos)
{
    if (pos+bd > n) return;
    if (bd+pos == n)
    {
        (dem++) % 2017;
        return;
    }
    int x = chuyen(s.substr(bd, pos));
    for (int i = 0; i < n - bd - pos; i++)
    {
        string z = s.substr(bd+pos, pos+i);
        if (chuyen(z) > x && z[0] != '0')
            duyet(bd+pos, pos+i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("recover.inp", "r", stdin);
    freopen("recover.out", "w", stdout);
    cin >> s;
    while (s[0] == '0') s.erase(0, 1);
    n = s.length();
    for (int i = 1; i < n; i++)
        duyet(0, i);
    cout << dem % 2017;
    return 0;
}
