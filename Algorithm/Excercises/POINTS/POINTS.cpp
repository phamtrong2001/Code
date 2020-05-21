#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, x[N], y[N], z[N];

struct vect
{
    int x, y, z;
    vect(int _x=0, int _y=0, int _z=0)
    {
        x = _x; y = _y; z = _z;
        if (_x == 0 && _y == 0 && _z == 0) return;
        int g = __gcd(_x, __gcd(_y, _z));
        _x /= g; _y /= g; _z /= g;
        x = _x; y = _y; z = _z;
        if (_x < 0) {x = -_x; y = -_y; z = -_z;}
        else if (_x == 0 && _y < 0) {y = -_y; z = -_z;}
        else if (_x == 0 && _y == 0 && _z < 0) z = -_z;
    }
}a[N];
bool cmp(vect p, vect q)
{
    if (p.x != q.x) return p.x < q.x;
    if (p.y != q.y) return p.y < q.y;
    return p.z < q.z;
}
bool Equal(vect p, vect q)
{
    return (p.x == q.x) && (p.y == q.y) && (p.z == q.z);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("POINTS.INP", "r", stdin);
    freopen("POINTS.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> z[i];
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (int j = i+1; j <= n; j++)
            a[++cur] = vect(x[i] - x[j], y[i] - y[j], z[i] - z[j]);
        sort(a+1, a+cur+1, cmp);
        int curDem = 1;
        for (int j = 2; j <= cur; j++)
        {
            if (!Equal(a[j], a[j-1]))
            {
                if (curDem == 2) res++;
                curDem = 1;
            }
            else curDem++;
        }
        if (curDem == 2) res++;
    }
    cout <<res;
}
