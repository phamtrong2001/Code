// MR.J
#include<bits/stdc++.h>
#define maxn 1000005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "commando"
using namespace std;
int n, arr[maxn], a, b, c, ptr;
vector <ll > P, M;
ll dp[maxn], s[maxn];

bool check(int pos1, int pos2, int pos3) {
    return (P[pos3] - P[pos1])*(M[pos1] - M[pos2]) < (P[pos2] - P[pos1])*(M[pos1] - M[pos3]);
}

void add(ll m, ll p) {
    M.PB(m);
    P.PB(p);
    while(M.size() > 2 && check(M.size()-3, M.size()-2, M.size()-1)) {
        M.erase(M.end()-2);
        P.erase(M.end()-2);
    }
}

ll calc(ll x) {
    if(ptr >= M.size()) ptr = M.size() - 1;
    while(ptr < M.size() - 1 && M[ptr+1]*x + P[ptr+1] > M[ptr]*x + P[ptr]) ++ptr;
    return M[ptr]*x + P[ptr];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> a >> b >> c;
    rep(i, 1, n) cin >> arr[i], s[i] = s[i-1] + arr[i];
    dp[1] = a*s[1]*s[1] + b*s[1] + c;
    add(-2*a*s[1], dp[1] + a*s[1]*s[1] - b*s[1]);
    rep(i, 2, n) {
        dp[i] = a*s[i]*s[i] + b*s[i] + c;
        dp[i] = max(dp[i], a*s[i]*s[i] + b*s[i] + c + calc(s[i]));
        add(-2*a*s[i], dp[i] + a*s[i]*s[i] - b*s[i]);
    }
    cout << dp[n];
    return 0;
}
