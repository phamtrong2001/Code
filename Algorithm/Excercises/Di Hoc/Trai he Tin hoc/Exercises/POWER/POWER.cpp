#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

double a, k, b;
void nhap()
{
    cin >> a >> k >> b;
    a = abs(a);
    if (a == 0) {cout <<-1; exit(0);}
    if (a == 1 && k > 1) {cout <<-1; exit(0);}
    if (a == 1 && k == 1) {cout <<1; exit(0);}
    double res = (k-1) * log(b-1)/log(a);
    long long k = res + 1;
    cout <<k;
}
int main()
{
    nhap();
}
