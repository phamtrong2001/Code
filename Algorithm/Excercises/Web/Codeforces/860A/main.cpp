#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, pos[N];
string str = "aeiou", s;
int main()
{
    cin >> s; n = s.size();
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] != s[i+1]) pos[i] = i+1;
        else pos[i] = pos[i+1];
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cout <<s[i];
        if (str.find(s[i]) == -1) cur++;
        else cur = 0;
        if (cur >= 2)
        {
            if (i == n-1 || str.find(s[i+1]) != -1) continue;
            if (s[i] != s[i-1]) cout <<' ';
            else
            {
                for (int j = i+1; j < pos[i]; j++) cout <<s[j];
                if (str.find(s[pos[i]]) == -1) cout <<' ';
                i = pos[i]-1;
            }
            cur = 0;
        }
    }
}
