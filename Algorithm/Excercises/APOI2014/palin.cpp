#include <bits/stdc++.h>
//NickyRio

using namespace std;
#define N 350000

struct Node {
    int cnt, len, sufflink, next[26];
}tree[N];

vector<int> e[N];

struct PalindromicTree {
    string s;
    int currNode, ptr;
    long long ans;
    PalindromicTree(string s): s(s) {
        currNode = ptr = 1;
        for(int i = 0; i<N; i++) {
            tree[i].len = tree[i].cnt = tree[i].sufflink = 0;
            for (int j = 0; j<26; j++) tree[i].next[j] = 0;
        }
        tree[0].len = -1; tree[0].sufflink = 0;
        for (int i = 0; i<(int) s.size(); i++) insert(i);
    }
    long long getMaxAns() {
        ans = 0;
        dfs(1);
        return ans;
    }
private:
    void insert(int pos) {
        int cur = currNode;
        int let = s[pos] - 'a';
        while (true) {
            int curLen = tree[cur].len;
            if (pos - curLen >= 1 && s[pos] == s[pos - curLen - 1]) break;
            cur = tree[cur].sufflink;
        }

        if (tree[cur].next[let]) {
            currNode = tree[cur].next[let];
            tree[currNode].cnt++;
            return;
        }

        currNode = ++ptr;
        tree[cur].next[let] = ptr;
        tree[ptr].cnt = 1;
        tree[ptr].len = tree[cur].len + 2;

        if (tree[ptr].len == 1) {
            tree[ptr].sufflink = 1;
            e[1].push_back(ptr);
            return;
        }

        cur = tree[cur].sufflink;
        while (true) {
            int curLen = tree[cur].len;
            if (pos - curLen >= 1 && s[pos] == s[pos - curLen - 1]) {
                tree[currNode].sufflink = tree[cur].next[let];
                e[tree[currNode].sufflink].push_back(ptr);
                return;
            }
            cur = tree[cur].sufflink;
        }
    }

    void dfs(int u) {
        for (int v : e[u]) {
            dfs(v);
            tree[u].cnt += tree[v].cnt;
        }
        ans = max(ans, 1ll * tree[u].len * 1ll * tree[u].cnt);
    }

};
string s;
int main() {
    //freopen("palindrome.inp","r",stdin);
   // freopen("palindrome.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    PalindromicTree PT(s);
    cout<<PT.getMaxAns();
}
