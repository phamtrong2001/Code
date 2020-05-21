#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 25
#define Task "FAFLOWER"
using namespace std;
int n,cur,dd[1 << 21],b[maxn];
long long t,ans,temp;
vector <int> a[maxn];
pair <int,int> save;
int Get_cur(int x)
{
    int res = 0;
    temp = 0;
    if (!x) return 0;
    for (int v : a[1])
        res += (1 << (v-1));
    temp += a[1].size();
    FOR(i,2,x)
    {
        FOR(j,1,n) b[j] = 0;
        FOR(j,0,n-1)
            if ((res >> j) & 1)
                {
                    for (int v : a[j+1]) b[v] ^= 1;
                    temp += a[j+1].size();
                }
            else temp += 2*a[j+1].size();
        res = 0;
        FOR(j,1,n)
            if (b[j]) res += (1 << (b[j] - 1));
    }
    return res;
}
void Find()
{
    cur = Get_cur(1);
    dd[cur] = 1;
    FOR(i,2,1 << n)
    {
        FOR(j,1,n) b[j] = 0;
        FOR(j,0,n-1)
            if ((cur >> j) & 1)
                for (int v : a[j+1]) b[v] ^= 1;
        cur = 0;
        FOR(j,1,n)
            if (b[j]) cur += (1 << (b[j] - 1));
        if (dd[cur])
        {
            save = mp(dd[cur],i);
            break;
        }
        else dd[cur] = i;
    }
}
long long POWW(long long a,long long b)
{
    if (b == 1) return a;
    long long c = POWW(a,b/2);
    c *= c;
    if (b & 1) return c * a;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n >> t;
    FOR(i,1,n)
        FOR(j,1,n)
            {
                char c;
                cin >> c;
                if (c == '1') a[i].pb(j);
            }
    Find();
    if (t <= save.F)
    {
        Get_cur(t);
        cout << temp;
        return 0;
    }
    cur = Get_cur(save.F - 1);
    ans += temp;
    long long qwe = 0;
    FOR(i,save.F,save.S - 1)
    {
        FOR(j,1,n) b[j] = 0;
        FOR(j,0,n-1)
            if ((cur >> j) & 1)
               {
                    for (int v : a[j+1]) b[v] ^= 1;
                    qwe += a[j+1].size();
               }
            else qwe += 2*a[j+1].size();
        cur = 0;
        FOR(j,1,n)
            if (b[j]) cur += (1 << (b[j] - 1));
    }
    t -= save.F - 1;
    int ck = save.S - save.F;
    qwe = qwe * (t / ck);
    ans += qwe;
    Get_cur(t % ck);
    cout << ans + temp;
    return 0;
}
