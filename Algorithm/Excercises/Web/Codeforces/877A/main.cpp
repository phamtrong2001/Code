#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int dem;
string zz[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
string s;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < 5; j++)
            if (s.substr(i, zz[j].size()) == zz[j]) dem++;
    if (dem == 1) cout <<"YES";
    else cout <<"NO";
}
