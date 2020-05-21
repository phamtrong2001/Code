#include <bits/stdc++.h>
#define maxn 1000000
using namespace std;

string s, nu;
int n, res, h;

int convert(char ch)
{
    if (ch == ' ') return 0;
    if (ch >= 'A' && ch <= 'Z') return ch-64;
    return ch-70;
}
struct Tries
{
    int sl;
    Tries *child[53];
    Tries()
    {
        sl = 0;
        for (int i = 0; i < 53; i++) child[i] = NULL;
    }
};

Tries T;

void setup()
{
    cin >> n; getline(cin, nu);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        Tries *p = &T;
        for (int j = 0; j < s.length(); j++)
        {
            int ch = convert(s[j]);
            if (p->child[ch] == NULL) p->child[ch] = new Tries();
            int z = ++p->child[ch]->sl;
            res = max(res, (j+1)*z);
            p = p->child[ch];
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("TOPONYM.INP", "r", stdin);
	freopen("TOPONYM.OUT", "w", stdout);
	setup();
	cout <<res;
}
