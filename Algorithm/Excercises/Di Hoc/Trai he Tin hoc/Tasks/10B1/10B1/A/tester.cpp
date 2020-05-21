#include <bits/stdc++.h> 
#define maxn 200005 
#define maxc 1000000007 
using namespace std; 
long long n,m,lazy[4*maxn],t[maxn*4]; 
void push(long long x,long long y,long long l,long long r) 
{ 
    t[y] = 1ll*lazy[x]*(r-l+1); 
    lazy[y] = lazy[x]; 
} 
void update(long long l,long long r,long long id,long long x,long long y,long long w) 
{ 
    if (l > y || r < x) return; 
    long long mid = (l+r)/2; 
    if (lazy[id] != -1) 
    { 
        push(id,id*2,l,mid); 
        push(id,id*2+1,mid+1,r); 
        lazy[id] = -1; 
    } 
    if ( x <= l && r <= y) 
    { 
        t[id] = 1ll*w*(r-l+1); 
        lazy[id] = w; 
        return; 
    } 
    update(l,mid,2*id,x,y,w); 
    update(mid+1,r,2*id+1,x,y,w); 
    t[id] = t[id*2+1] + t[id*2]; 
} 
long long get(long long l,long long r,long long id,long long x,long long y) 
{ 
    if (l > y || r < x) return 0; 
    long long mid = (l+r)/2; 
    if (lazy[id] != -1) 
    { 
        push(id,id*2,l,mid); 
        push(id,id*2+1,mid+1,r); 
        lazy[id] = -1; 
    } 
    if ( x <= l && r <= y) return t[id]; 
    long long m1 = get(l,mid,2*id,x,y); 
    long long m2 = get(mid+1,r,2*id+1,x,y); 
    return (m1+m2); 
} 
int main() 
{ 
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL); 
    //freopen("inp.txt","r",stdin); 
    cin >> n >> m; 
    memset(lazy, -1, sizeof lazy);
    while(m--) 
    { 
        long long type; 
        cin >> type; 
        if ( type == 1) 
        { 
            long long x,y; 
            cin >> x >> y; 
            cout << get(1,n,1,x,y) << '\n'; 
        } 
        else { 
            long long x,y,z; 
            cin >> x >> y >> z; 
            update(1,n,1,x,y,z); 
        } 
    } 
} 
