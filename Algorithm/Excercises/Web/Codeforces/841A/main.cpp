#include <bits/stdc++.h>
#define S second
#define PB push_back
#define maxc 1000000007
#define pii pair<int, int>
#define mp make_pair
#define F first
#define N 100005


using namespace std;

int n, k, skipppp[100000];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        char c; cin >> c;
        skipppp[c-'a']++;
    }
    for (int i = 'a'; i <= 'z'; i++){
        if (skipppp[i - 'a'] > k)
        {
            cout <<"NO";
            return 0;
        }
    }
    cout <<"YES";
}
