#include <bits/stdc++.h>

using namespace std;

string s;
long long n, start, circle;
long long dd[11][11][11];
int main()
{
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);

    cin >> s;
    long long len = s.size();
    long long x = s[len-1] - '0';
    long long y = s[len-2] - '0';
    long long z = s[len-3] - '0';
    dd[x][y][z] = 3;

    bool flag = 0;
    while(1)
    {
        long long len = s.size();
        long long x = s[len-1] - '0';
        long long y = s[len-2] - '0';
        long long z = s[len-3] - '0';
        long long val = x + y + z;
        string str;
        stringstream ss;
        ss << val;
        ss >> str;
        for (long long i = 0; i < str.size(); i++) s.push_back(str[i]);

        len = s.size();
        x = s[len-1] - '0';
        y = s[len-2] - '0';
        z = s[len-3] - '0';
        if (dd[x][y][z])
        {
            flag = 1;
            circle = len - dd[x][y][z];
            start = dd[x][y][z];
            break;
        }
        else dd[x][y][z] = len;
        //cerr<<s<<endl;
    }
    //cerr<<s<<endl;
    while (cin >> n)
    {
        if (n <= start) cout <<s[n-1]<<endl;
        else
        {
            long long len = n - start;
            long long pos = len % circle;
            if (pos == 0) pos = circle;
            cout <<s[start + pos - 1]<<endl;
        }
    }
}
