#include <bits/stdc++.h>
#define maxc 100000
using namespace std;

int n, res, speednow;
stack<int> s1, s2;
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int type, u; scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d", &u);
            speednow = u;
            while (!s1.empty() && s1.top() < u)
            {
                res++;
                s1.pop();
            }
        }
        if (type == 2)
        {
            while (!s2.empty() && s2.top() == 0)
            {
                res++;
                s2.pop();
            }
        }
        if (type == 3)
        {
            scanf("%d", &u);
            if (speednow > u) res++;
            else s1.push(u);
        }
        if (type == 4) s2.push(1);
        if (type == 5) s1.push(maxc);
        if (type == 6) s2.push(0);
    }
    cout <<res;
}
