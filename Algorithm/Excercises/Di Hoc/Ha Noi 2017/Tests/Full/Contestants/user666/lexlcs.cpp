#include <bits/stdc++.h>
#define long long long
#define up(i,a,b) for (int i=a; i<=b; i++)
#define down(i,a,b) for (int i=a; i>=b; i--)
#define endl '\n'
#define X first
#define Y second
#define II pair<int, int>
#define III pair<int, pair<int, int> >
#define debug(X) cerr<< #X << " = " <<X << endl
#define debug2(X,Y) cerr<< #X << " = " <<X << ","<<#Y<<" = "<<Y<<endl
#define show(X,a,b) {cerr << #X << " = "; up(__,a,b) cerr << X[__] << ' '; cerr << endl;}
#define gc getchar
#define pc putchar
using namespace std;

inline void read(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeln(int x){

         char buffor[21];
         register int i=0;
         int neg=0; if (x<0) {neg=1; x= -x;}
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
           if (neg) pc('-');
           while(i>=0) pc(buffor[i--]);
           pc('\n');
       }
const int N= 2010;
string s,t;
int f[N][N], Next_s[26][N], Next_t[26][N], m, n;
void input()
{
    cin>>s; m= s.size();
    cin>>t; n= t.size();
}
void init()
{
    up(c,0,25)
    {
     Next_s[c][m]= m;
     down(i,m-1,0)
     {
         Next_s[c][i]= Next_s[c][i+1];
         if (c== (int)(s[i]- 'a')) Next_s[c][i]= i;
     }
    }
    up(c,0,25)
    {
     Next_t[c][n]= n;
     down(i,n-1,0)
     {
         Next_t[c][i]= Next_t[c][i+1];
         if (c== (int)(t[i]- 'a')) Next_t[c][i]= i;
     }
    }
}
void solve1()// maximum lcs , max lexico
{
    down(i,m-1,0)
     down(j,n-1,0)
     {
         if (s[i]== t[j]) f[i][j]= f[i+1][j+1]+ 1;
         else f[i][j]= max(f[i][j+1], f[i+1][j]);
     }

    int i= 0, j= 0;
    down(len, f[0][0], 1)
    {
        down(c,25,0)
        {
            int newi= Next_s[c][i], newj= Next_t[c][j];
            if (f[newi][newj]== len)
            {
                i= newi+1; j= newj+1; cout<<(char)(c+ 'a');
                break;
            }
        }

    }
    cout<<endl;
}
void solve2()
{
    down(i,m-1,0) f[i][n]= m- i;
    down(i,n-1,0) f[m][i]= n- i;
    down(i,m-1,0)
     down(j,n-1,0)
     {
         if (s[i]== t[j]) f[i][j]= f[i+1][j+1]+ 1;
         else f[i][j]= min(f[i][j+1], f[i+1][j])+1;
     }

    int i= 0, j= 0;
    down(len, f[0][0], 1)
    {
        if (i== m)
        {
            cout<<t[j]; j++;
        }
        else if (j== n)
        {
            cout<<s[i]; i++;
        }
        else if (s[i]== t[j])
        {
            cout<<s[i];
            i++; j++;
        }
        else
        {
            if (f[i+1][j]!= len-1) cout<<t[j], j++;
            else if (f[i][j+1]!= len-1) cout<<s[i], i++;
            else
            {
                if (s[i]< t[j]) cout<<s[i], i++;
                else cout<<t[j], j++;
            }
        }
        //cout<<i<<" "<<j<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);// don't use when interactive

    #define TASK "lexlcs"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);


    input();
    init();
    solve1();
    solve2();
    return 0;
}
