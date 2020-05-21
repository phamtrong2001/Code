// MR.J
#include<bits/stdc++.h>
#define maxn 100005
#define maxC 1000000000
#define MOD 1000000000
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "bus"
using namespace std;
int T;

void gcd(int a, int b, int &pa, int &qa, int &pb, int &qb, int &pr, int &qr) {
     int r;
    while(b) {
        int t = a/b;
        r = a - b*t;
        pr = pa - t*pb, qr = qa - t*qb;
        pa = pb, qa = qb, a = b;
        pb = pr, qb = qr, b = r;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> T;
    while(T--) {
        int a, b, t1, t2;
        int pa = 1, qa = 0, pb = 0, qb = -1, pr = 0, qr = 0;
        cin >> a >> b >> t1 >> t2;
        if(t1 == t2) {
            cout << t1 << '\n';
            continue;
        }
        if(t2 < t1) {
            swap(t1, t2);
            swap(a, b);
        }
        ll c = 1ll*(t2 - t1);
        gcd(a, b, pa, qa, pb, qb, pr, qr);
        ll g = pa*a - qa*b;
        if(c % g != 0) {
            cout << -1 << '\n';
            continue;
        }
        ll lcm = (1ll*a*b)/g;
        ll stepa = lcm/a;
        ll x = c/g*pa;
        ll sl = abs(x)/stepa + 1;
        if(x < 0) x += sl*stepa;
        else {
            repd(i, sl, 0)
                if(x - stepa*i > 0) {
                    x-= stepa*i;
                    break;
                }
        }
        cout << a*x+t1 << '\n';
    }
    return 0;
}
