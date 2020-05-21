#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <limits>
using namespace std;

vector<int> ps[30000];
int dis[30000];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int s, t;
    for(int i = 0; i < m; i++) {
        int b, p;
        scanf("%d %d", &b, &p);
        ps[b].push_back(p);
        if(i == 0)
            s = b;
        else if(i == 1)
            t = b;
    }
    for(int i = 0; i < n; i++) {
        vector<int>& v = ps[i];
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

    fill_n(dis, n, numeric_limits<int>::max());
    dis[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int cost, where;
        tie(cost, where) = pq.top();
        pq.pop();

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        if(where == t) {
#pragma GCC diagnostic pop
            printf("%d\n", cost);
            return 0;
        }
        if(dis[where] < cost)
            continue;

        for(int p : ps[where]) {
            for(int i = 1; where + i * p < n; i++) {
                if(dis[where + i * p] > cost + i)
                    pq.push({dis[where + i * p] = cost + i, where + i * p});
                if(binary_search(ps[where + i * p].begin(), ps[where + i * p].end(), p))
                    break;
            }
            for(int i = 1; where - i * p >= 0; i++) {
                if(dis[where - i * p] > cost + i)
                    pq.push({dis[where - i * p] = cost + i, where - i * p});
                if(binary_search(ps[where - i * p].begin(), ps[where - i * p].end(), p))
                    break;
            }
        }
    }

    puts("-1");
}