#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define MM 123143213
#define maxc 1000000007

using namespace std;

int n, val[N], res, type[3], dd[N];
pair<string, int> a[N], ans[N];
string MM1 = "123143213";
stack<int> q1, q2, q3, q4, q5, q6, q7;
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].F >> a[i].S;
        int cur = 0; bool flag = 0;
        type[a[i].S]++;
        if (a[i].F[0] == '0') continue;
        for (int j = 0; j < a[i].F.size(); j++)
        {
            if (a[i].F[j] > '9') flag = 1;
            else cur = cur*10 + a[i].F[j] - '0';
        }
        if (!flag) val[i] = cur;
    }
    for (int i = 1; i <= n; i++)
    {
        if (val[i])
        {
            if (a[i].S == 1)
            {
                dd[val[i]] = 1;
                if (val[i] <= type[1]) continue;
                if (val[i] <= n) q1.push(i);
                else q3.push(i);
            }
            if (a[i].S == 0)
            {
                dd[val[i]] = 1;
                if (val[i] > type[1] && val[i] <= n) continue;
                if (val[i] <= type[1]) q2.push(i);
                else q4.push(i);
            }
        }
        else
        {
            if (a[i].S == 1) q3.push(i);
            else q4.push(i);
        }
    }
    for (int i = 1; i <= type[1]; i++) if (!dd[i]) q6.push(i);
    for (int i = type[1]+1; i <= n; i++) if (!dd[i]) q5.push(i);
    while (!q1.empty() && !q2.empty())
    {
        int u = q1.top(); q1.pop();
        int v = q2.top(); q2.pop();
        ans[++res] = mp(a[u].F, MM);
        ans[++res] = mp(a[v].F, val[u]);
        ans[++res] = mp(MM1, val[v]);
    }
    while (!q1.empty())
    {
        int u = q1.top(); q1.pop();
        int v = q6.top(); q6.pop();
        q5.push(val[u]);
        ans[++res] = mp(a[u].F, v);
    }

    while (!q2.empty())
    {
        int u = q2.top(); q2.pop();
        int v = q5.top(); q5.pop();
        q6.push(val[u]);
        ans[++res] = mp(a[u].F, v);
    }
    while (!q3.empty())
    {
        int u = q3.top(); q3.pop();
        int v = q6.top(); q6.pop();
        ans[++res] = mp(a[u].F, v);
    }
    while (!q4.empty())
    {
        int u = q4.top(); q4.pop();
        int v = q5.top(); q5.pop();
        ans[++res] = mp(a[u].F, v);
    }
    cout <<res<<endl;
    for (int i = 1; i <= res; i++)
    {
        cout <<"move "<<ans[i].F<<" "<<ans[i].S<<endl;
    }
}
