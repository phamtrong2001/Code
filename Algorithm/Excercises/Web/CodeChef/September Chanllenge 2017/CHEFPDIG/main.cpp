#include <bits/stdc++.h>

using namespace std;

string s;
int dem[20], dd[1000];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    int t; cin >> t;
    while (t--)
    {
        cin >> s;
        memset(dem, 0, sizeof dem);
        memset(dd, 0, sizeof dd);
        for (int i = 0; i < s.size(); i++) dem[s[i]-'0']++;
        for (int i = 0; i < 10; i++)
        {
            if (dem[i] == 0) continue;
            dem[i]--;
            for (int j = 0; j < 10; j++)
            {
                if (dem[j] == 0) continue;
                dd[i*10 + j] = 1;
            }
            dem[i]++;
        }
        for (int i = 'A'; i <= 'Z'; i++)
            if (dd[i]) cout <<(char)i;
        cout <<endl;
    }

}
