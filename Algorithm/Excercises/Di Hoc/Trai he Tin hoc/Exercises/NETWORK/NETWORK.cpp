#include <bits/stdc++.h>
#include "network.h"
#define maxn 2005
#define PB push_back

using namespace std;

vector <int> v[maxn];

void findRoute(int N, int a, int b)
{
    int path = ping(a, b);
    for (int i = 1; i <= N; i++)
    {
        if (i == b) continue;
        int s2 = ping(i, b);
        v[s2].PB(i);
    }
    int pos = a;
    for (int i = path-1; i >= 1; i--)
    {
        if (v[i].size() == 1)
        {
            travelTo(v[i][0]);
            pos = v[i][0];
        }
        else
        {
            for (int &u : v[i])
            {
                int s1 = ping(pos, u);
                if (s1 == 1)
                {
                    travelTo(u);
                    pos = u;
                    break;
                }
            }
        }
    }
    travelTo(b);
}



