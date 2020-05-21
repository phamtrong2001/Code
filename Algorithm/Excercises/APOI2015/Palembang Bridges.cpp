#include <cstdio>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

int sz;
using HW = pair<int, int>;
HW hw[100000];

multiset<int> ms;
multiset<int>::iterator mid;

long long tmp[100001];

template <typename T>
struct Nothing {
    void operator () (T, long long) {}
};

template <typename T, typename Op = Nothing<T>>
long long work(T first, T last, Op op = Op()) {
    op(first, 0);

    ms.insert(first->first);
    ms.insert(first->second);
    mid = ms.begin();
    long long sum = first->second - first->first;
    op(++first, sum);

    while(first != last) {
        ms.insert(first->first);
        ms.insert(first->second);
        sum += abs(*mid - first->first);
        sum += abs(*mid - first->second);

        if(first->second < *mid) {
            --mid;
        } else if(!(first->first < *mid)) {
            sum += 2 * *mid;
            sum -= 2 * *++mid;
        }

        op(++first, sum);
    }

    ms.clear();
    return sum;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        char p[2], q[2];
        int s, t;
        scanf("%1s %d %1s %d", p, &s, q, &t);
        if(*p == *q)
            ans += abs(s - t);
        else {
            ans++;
            hw[sz++] = minmax(s, t);
        }
    }

    if(sz) {
        if(k == 1) {
            ans += work(hw, hw + sz);
        } else {
            sort(hw, hw + sz, [](const HW& lhs, const HW& rhs) {
                 return lhs.first + lhs.second < rhs.first + rhs.second;
            });
            work(hw, hw + sz, [](HW* pp, long long x) {
                tmp[pp - hw] = x;
            });
            using R = reverse_iterator<HW*>;
            work(R(hw + sz), R(hw), [](R pp, long long x) {
                tmp[pp.base() - hw] += x;
            });
            ans += *min_element(tmp, tmp + sz + 1);
        }
    }

    printf("%lld\n", ans);
}