#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define eps 1e-8
#define maxc 1000000007

using namespace std;

int n, r;
double x[N], y[N], xmax[N];

void calc(int id)
{
    y[id] = r;
    for (int i = 1; i < id; i++)
    {
        if (abs(x[i] - x[id]) <= 2*r)
        {
            double cc = r*2;
            double bb = abs(x[id] - x[i]);
            double res = sqrt(cc*cc - bb*bb);
            y[id] = max(y[id], y[i]+res);
        }
    }
}
int main()
{
    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) calc(i);
    for (int i = 1; i <= n; i++) printf("%0.6f ", y[i]);
}
