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
string s[N];
map<long long, int> ma;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < 9; j++)
        {
            long long sum = 0;
            for (int k = j; k < 9; k++)
            {
                sum = sum*100ll + 1ll*(s[i][k] - '0' + 1);
                ma[sum]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            long long sum = 0;
            for (int k = j; k < 9; k++)
            {
                sum = sum*100ll + 1ll*(s[i][k] - '0' + 1);
                ma[sum]--;
            }
        }
        int len = 9, st = 0;
        for (int j = 0; j < 9; j++)
        {
            long long sum = 0;
            for (int k = j; k < 9; k++)
            {
                sum = sum*100ll + 1ll*(s[i][k] - '0' + 1);
                if (!ma[sum] && k - j + 1 < len)
                {
                    len = k - j + 1;
                    st = j;
                }
            }
        }
        cout <<s[i].substr(st, len)<<endl;
        for (int j = 0; j < 9; j++)
        {
            long long sum = 0;
            for (int k = j; k < 9; k++)
            {
                sum = sum*100ll + 1ll*(s[i][k] - '0' + 1);
                ma[sum]++;
            }
        }
    }
}
