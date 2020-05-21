#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <queue>
#include <map>
#include <string.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
int cnt[15005];
bool f[1000006];
int main() {
    //    freopen(".in", "r", stdin);
    //    freopen(".out", "w", stdout);
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    vector<int> nums;
    for (int i=0; i<3; ++i){
        int a; cin >> a; nums.pb(a);
    }
    sort(nums.begin(), nums.end());
    for (int i=0; i<3; ++i) {
        int k;
        for (k=1; k<=1000005; ++k) {
            if (!f[k]) {
                break;
            }
        }
        for (int j=k; j<=1000005; j+=nums[i]) {
            f[j] = true;
        }
    }
    for (int i=1; i<=1000005; ++i) {
        if (!f[i]) {
            cout << "NO\n"; return 0;
        }
    }
    cout << "YES\n";
}
