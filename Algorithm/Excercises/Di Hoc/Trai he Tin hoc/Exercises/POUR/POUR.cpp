#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 6005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a[4], dd[N][N], res, V;
vector <pii> st;
bool DFS(int v[], int dep, int x, int y)
{
    if (dd[v[1]][v[2]] != -1) return dd[v[1]][v[2]];
    if (dep > 10000000) return dd[v[1]][v[2]] = 0;
    if (v[1] == 0 || v[2] == 0 || v[3] == 0)
    {
        res = dep;
        return dd[v[1]][v[2]] = 1;

    }

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (v[i] >= v[j] && i != j && x != i && y != j)
            {
                v[i] -= v[j];
                v[j] *= 2;
                if (DFS(v, dep+1, i, j))
                {
                    st.PB(mp(i, j));
                    return dd[v[1]][v[2]] = 1;
                }
                v[j] /= 2;
                v[i] += v[j];
            }
    return dd[v[1]][v[2]] = 0;
}
void nhap()
{
    cin >> a[1] >> a[2] >> a[3];
    V = a[1] + a[2] + a[3];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) dd[i][j] = -1;
}

int main()
{
    freopen("POUR.INP", "r", stdin);
   // freopen("POUR.OUT", "w", stdout);
    nhap();
    int ok = DFS(a, 0, 0, 0);
    cout <<res<<endl;
    for (int i = st.size()-1; i >= 0; i--) cout <<st[i].F <<" "<<st[i].S<<endl;
    return 0;

}
