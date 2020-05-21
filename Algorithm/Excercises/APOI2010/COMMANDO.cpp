    /*Design by Dinh Viet Anh(JOKER)*/
//___________________________________$$$$$$$$$
//___________________________________$$$___$
//___________________________$$$____$$$$
//_________________________$$$$$$$__$$$$$$$$$$$
//_______________________$$$$$$$$$___$$$$$$$$$$$
//_______________________$$$___$______$$$$$$$$$$
//________________$$$$__$$$$_________________$$$
//_____________$__$$$$__$$$$$$$$$$$_____$____$$$
//__________$$$___$$$$___$$$$$$$$$$$__$$$$__$$$$
//_________$$$$___$$$$$___$$$$$$$$$$__$$$$$$$$$
//____$____$$$_____$$$$__________$$$___$$$$$$$
//__$$$$__$$$$_____$$$$_____$____$$$_____$
//__$$$$__$$$_______$$$$__$$$$$$$$$$
//___$$$$$$$$$______$$$$__$$$$$$$$$
//___$$$$$$$$$$_____$$$$___$$$$$$
//___$$$$$$$$$$$_____$$$
//____$$$$$$$$$$$____$$$$
//____$$$$$__$$$$$___$$$
//____$$$$$___$$$$$$
//____$$$$$____$$$
//_____$$$$
//_____$$$$
//_____$$$$
#include <bits/stdc++.h>
#define maxn 1000005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "COMMANDO"
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "NO\n"; return;}
#define stop3 {cout << "YES\n"; return;}
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}

using namespace std;

int n, a, b, c, x[maxn] ,dem;
ll u[maxn], v[maxn];
ll s[maxn], f[maxn];

bool check(int p, int q, int r)
{
    return (v[q] - v[p]) * (u[p] - u[r]) >= (u[p] - u[q]) * (v[r] - v[p]);
}

void add(ll p, ll q)
{
    u[++dem] = p;
    v[dem] = q;
    while(dem >= 3 && check(dem-2, dem-1, dem))
    {
        u[dem-1] = p;
        v[dem-1] = q;
        dem--;
    }
}

ll get_val(int id, ll val)
{
    return u[id] * val + v[id];
}

ll get(ll val)
{
    int l = 0, r = dem;
    while(r - l > 1)
    {
        int mid = (l+r) / 2;
        if(get_val(mid, val) < get_val(mid+1, val))
            r = mid;
        else l = mid;
    }
    return get_val(r, val);
}

void setup()
{
    read(n);
    read(a);
    read(b);
    read(c);
    fort(i, 1, n)
    {
        read(x[i]);
        f[i] = -1ll*maxc*maxc;
        s[i] = s[i-1] + x[i];
    }
}

void work()
{
    f[0] = 0;
   // f[1] = a*x[1]*x[1] + b*x[1] + c;
    add(0,0);
   // add(2*a*x[1], -a*x[1]*x[1] - f[1] + b * x[1]);
    fort(i, 1, n)
    {
        f[i] = -get(s[i]) + a*s[i]*s[i] + b * s[i] + c;
        add(2*a*s[i], -a*s[i]*s[i] - f[i] + b * s[i]);
    }
    write(f[n]);
}

int main()
{
    fast
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    work();
    return 0;
}
