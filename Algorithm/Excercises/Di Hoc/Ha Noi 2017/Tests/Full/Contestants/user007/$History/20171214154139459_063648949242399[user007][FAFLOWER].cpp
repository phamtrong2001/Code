    /*Design by Dinh Viet Anh(JOKER)*/
//_____________________________________$$$$$__
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
#define maxn 2000005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "FAFLOWER"
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "NO\n"; return;}
#define stop3 {cout << "YES\n"; return;}
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mid (l+r)/2

template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}

using namespace std;

ll n, t, state, sl[maxn], timea, x[maxn];
int dd[maxn];
char c;
vector<int> ke[22];

void setup()
{
    read(n);read(t);
    fort(i, 1, n)
    {
        fort(j, 1, n)
        {
            c = getchar();
            if(c == '1')
                 ke[i].pb(j);
        }
        c = getchar();
    }
}

int d[22];

void work(ll res = 0)
{
    res = ke[1].size();
    fort(i, 0, int(ke[1].size()) - 1)
    {
        int u = ke[1][i];
        state |= (1 << (u-1));
    }
    memset(dd, -1, sizeof dd);
    dd[state] = 2;
    sl[1] = res;
    timea = 2;
    while(timea <= t)
    {
        ll ans = 0;
        fort(i, 1, n) d[i] = 0;
        fort(i, 1, n)
            fort(j, 0, int(ke[i].size()) - 1)
            {
                d[ke[i][j]] = (d[ke[i][j]] + (((state >> (i-1)) & 1) ? 1 : 2)) % 2;
                ans += (((state >> (i-1)) & 1) ? 1 : 2);
            }
        int newstate = 0;
        fort(i, 1, n) if(d[i]) newstate |= (1 << (i-1));
        state = newstate;
       /* if(dd[state] != -1)
        {
            res += ans;
            sl[timea] = res;
            timea++;
            break;
        }*/
        dd[state] = timea+1;res += ans;
        x[timea] = state;
        sl[timea] = res;
        timea++;
        if(timea > t)
        {
            write(res);
            return;
        }
    }
    int T = timea - dd[state];
    res += (sl[timea - 1] - sl[dd[state] - 1]) * ((t - timea + 1) / T);
    ll thua = (t - timea + 1) % T;
    if(thua)
        res += sl[1+ thua] - sl[1];

    write(res);
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

