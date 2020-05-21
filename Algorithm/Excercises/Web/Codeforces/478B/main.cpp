#include <bits/stdc++.h>

using namespace std;

long long n, m, kmin, kmax;
int main()
{
   //freopen("INP.TXT", "r", stdin);
    cin >> n >> m;

    kmax = (n-m+1)*(n-m)/2;
    kmin = (n/m + 1) * (n/m)/2 * (n % m) + (n/m) * (n/m-1) * (m-n%m)/2;
    cout <<kmin<<" "<<kmax;
}
