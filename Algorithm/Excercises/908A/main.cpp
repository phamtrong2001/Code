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

char a[10] = {'a', 'i', 'e', 'o', 'u', '1', '3', '5', '7', '9'};

int main()
{
    string s; int res = 0;cin >> s;
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < 10; j++) res+=(s[i] == a[j]);
    cout <<res;
}
