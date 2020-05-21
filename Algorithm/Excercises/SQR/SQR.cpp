#include <bits/stdc++.h>
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define okk 15

using namespace std;

char m[4][4], mm[4][4], val;
string s;
map<int, int> mapdist;
void createMatrix(string x)
{
    for (int i = 0; i < 9; i++)
    {
        int xx = i / 3;
        int yy = i % 3;
        m[xx][yy] = x[i];
    }
}
string rotation(int x, int y, int val)
{
    string str = "";
    for (int i = 0; i < 2; i++) str.PB(m[x][y+i]);

    for (int i = 0; i < 2; i++) str.PB(m[x+1][y+i]);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mm[i][j] = m[i][j];
    int pos = 0;
    for (int i = 0; i < 2; i++)
    {
        pos++;
        mm[x][y+i] = str[pos];
    }
    for (int i = 0; i < 2; i++)
    {
        pos++; pos %= 4;
        mm[x+1][y+i] = str[pos];
    }
    str = "";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) str.PB(mm[i][j]);
    return str;
}

bool check(string s)
{

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += s[i*3+j] -'0';
        if (sum != okk) return 0;

        sum = 0;
        for (int j = 0; j < 3; j++)
            sum += s[j*3 + j] -'0';
        if (sum != okk) return 0;
    }
    int sum = s[0] - '0' + s[4] - '0' + s[8] - '0';
    if (sum != okk) return 0;
    sum = s[2] - '0' + s[4] - '0' + s[6] - '0';
    if (sum != okk) return 0;
    return 1;
}
int solve()
{
    queue<pair<string, int> > q;
    q.push(mp(s, 1));
    mapdist[val] = 1;
    while (!q.empty())
    {
        string u = q.front().F;
        int l = q.front().S;
        q.pop();
        int y;
        stringstream sst;
        sst << u;
        sst >> y;
        if (mapdist[y] < l && mapdist[y] != 0) continue;
        if (check(u))
        {
            cout <<u<<endl;
            return l;
        }
        createMatrix(u);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                string v = rotation(i, j, 1);
                int x;
                stringstream ss;
                ss << v;
                ss >> x;
                if (mapdist[x] == 0 || mapdist[x] > l + 1)
                {
                    mapdist[x] = l + 1;
                    q.push(mp(v, l+1));
                }
                v = rotation(i, j, -1);
                int xx;
                stringstream sss;
                sss << v;
                sss >> xx;
                if (mapdist[xx] == 0 || mapdist[xx] > l + 1)
                {
                    mapdist[xx] = l + 1;
                    q.push(mp(v, l+1));
                }
            }
    }
}
int main()
{
    freopen("SQR.INP", "r", stdin);
    //freopen("SQR.OUT", "w", stdout);
    while (cin >> s)
    {
        stringstream ss;
        ss << s;
        ss >> val;
        cout <<s<<endl;
        cout <<solve() - 1;
    }
}
