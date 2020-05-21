#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, res1, res2;
    cin >> n;
    res2 = n*6;
    res1 = (n/6) + 7 - (n - (n/6)*6);
    cout <<res1<<" "<<res2;
}
