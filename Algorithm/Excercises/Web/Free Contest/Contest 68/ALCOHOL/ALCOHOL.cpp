#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
string wine[11] = {"ABSINTH", "TEQUILA", "VODKA", "WHISKEY" , "WINE", "BEER", "BRANDY" , "CHAMPAGNE", "GIN", "RUM", "SAKE"};

bool calc1(string s)
{
    int x;
    stringstream ss;
    ss << s; ss >> x;
    return (x < 18);
}
int main()
{
    cin >> n; int res = 0;
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        if (s[0] <= '9' && s[0] >= '0') res += calc1(s);
        else for (int j = 0; j < 11; j++) if (s == wine[j]) res++;
    }
    cout <<res;
}
