#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 22
#define maxc 1000000007

using namespace std;

ll n, a[N][N], st[1 << 21][N], curTime = 1, beginCircle, endCircle;
long long sumState[1 << 21];
ll dd[1 << 21];
long long T;
void duyet(ll id)
{
    for (ll i = 1; i <= n; i++) st[id+1][i] = st[id][i];
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j < i; j++)
            if (a[i][j])
            {
                if ((st[id][i] - st[id-1][i]) % 2 == 0) st[id+1][j] += 2;
                else st[id+1][j]++;

                if ((st[id][j] - st[id-1][j]) % 2 == 0) st[id+1][i] += 2;
                else st[id+1][i]++;
            }
}
int main()
{
    freopen("FAFLOWER.INP", "r", stdin);
    freopen("FAFLOWER.OUT", "w", stdout);
    cin >> n >> T;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
        {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    for (ll i = 1; i <= n; i++)
        if (a[1][i]) st[1][i]++;
    ll beginState = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (st[1][i] % 2) beginState |= (1 << i);
        sumState[1] += st[1][i];
    }
    //dd[beginState] = 1;

    while (1)
    {
        duyet(curTime);
        curTime++;
        ll state = 0;
        for (ll i = 1; i <= n; i++)
        {
            if ((st[curTime-1][i] - st[curTime-2][i]) % 2) state |= (1 << i);
            sumState[curTime] += st[curTime][i];
        }
        if (dd[state])
        {
            beginCircle = dd[state];
            endCircle = curTime-1;
            break;
        }
        dd[state] = curTime;
    }
    //cout <<sumState[T]<<endl;
    if (T <= endCircle) cout <<sumState[T];
    else
    {
        ll len = endCircle - beginCircle + 1;
        ll pos = (T - beginCircle) % len + beginCircle;
        ll cntRep = (T - beginCircle) / len;
        cout <<sumState[beginCircle-1] + cntRep*(sumState[endCircle] - sumState[beginCircle-1]) + sumState[pos] - sumState[beginCircle-1];
    }
}
