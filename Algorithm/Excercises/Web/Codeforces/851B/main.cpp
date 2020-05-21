#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

long long Ax, Ay, Bx, By, Cx, Cy;
pair<long long, long long> u, v;

void stop1()
{
    cout <<"No";
    exit(0);
}
void stop2()
{
    cout <<"Yes";
    exit(0);
}
int main()
{
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
    u = mp(Bx - Ax, By - Ay);
    if ((u.F == 0 && Cx == Ax) || (u.S == 0 && Cy == Ay)) stop1();
    v = mp(Cx - Bx, Cy - By);
    if ((v.F == 0 && Cx == Ax) || (v.S == 0 && Cy == Ay)) stop1();
    if (u.F * v.S == u.S * v.F) stop1();
    if (u.F*u.F + u.S*u.S == v.F*v.F + v.S*v.S) stop2();
    stop1();
}
