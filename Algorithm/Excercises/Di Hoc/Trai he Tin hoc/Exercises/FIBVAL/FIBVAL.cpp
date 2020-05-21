#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int u, v; cin >> u >> v;
        if ((v - u + 1) / 16 >= 2) cout <<(v - u + 1) /16*16<<endl;
        else
        {
            bool flag = 0;
            for (int i = u+1; i <= v; i++) if (i % 16 == 1 || i % 16 == 9)
            {
                cout <<2<<endl;
                flag = 1;
                break;
            }
            if (!flag) cout <<-1<<endl;
        }
    }
}
