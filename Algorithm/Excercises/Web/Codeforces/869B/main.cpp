#include <bits/stdc++.h>

using namespace std;
int main()
{

    unsigned long long a, b, res = 1;
    cin >> a >> b;
    for (unsigned long long i = a+1; i <= b; i++){
        if (res == 0) break;
        res = (res*i) % 10;}
    cout <<res;
}
