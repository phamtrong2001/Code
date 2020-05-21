#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, beginTime[N], endTime[N], t[N], dd[N];
pii allEnd[N];
vector<int> res;

void upd(int x)
{
    for (; x < N; x += (x & -x)) t[x]++;
}
int get(int x)
{
    int ans = 0;
    for (; x; x -= (x & -x)) ans += t[x];
    return ans;
}
int get_ans(int id)
{
    return get(endTime[id]) - get(beginTime[id] - 1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ADVERTISE.INP", "r", stdin);
    freopen("ADVERTISE.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> beginTime[i] >> endTime[i];
        allEnd[i] = mp(endTime[i], i);
    }
    sort(allEnd+1, allEnd+n+1);
    for (int i = 1; i <= n; i++)
    {
        int id = allEnd[i].S;
        int value = get_ans(id);
        if (value == 2) continue;
        if (value == 1)
        {
            if (dd[endTime[id]]) {
                upd(endTime[id] - 1);
                dd[endTime[id]-1] = 1;
            }
            else upd(endTime[id]);
            dd[endTime[id]] = 1;
        }
        if (value == 0)
        {
            upd(endTime[id] - 1);
            upd(endTime[id]);
            dd[endTime[id]] = dd[endTime[id] - 1] = 1;
        }
    }
    for (int i = 1; i <= allEnd[n].F; i++)
        if (dd[i]) res.PB(i);
    cout <<res.size()<<'\n';
    for(auto x: res) cout <<x<<' ';
}
