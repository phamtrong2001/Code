#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
#define f1(i,n) for (int i=1; i<=n; i++)
#define __unique(a) sort(a.begin(), a.end()), a.resize(unique(a.begin(), a.end())-a.begin())
int n, m, cnt;
vector<int> a[N];
int Low[N], Visited[N], Parent[N], LastComponent[N];
stack<int> st;
int ComponentCount, Answer;

bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }
bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

void visit(int u){
   Low[u]=Visited[u]=++cnt;

   for (int i=0,v; v=a[u][i]; i++){
      if (Visited[v]) minimize(Low[u], Visited[v]);
      else { 
         st.push(u);
         Parent[v]=u; visit(v); minimize(Low[u], Low[v]);
         if (Low[v]>=Visited[u]) {
            int Current=0;
            ComponentCount++;
            do {
               v=st.top(); st.pop();
               if (maximize(LastComponent[v], ComponentCount))
               Current++;
            } while (u!=v);
            maximize(Answer, Current);
         }
      }
   }
   st.push(u);
}

main(){
   ios :: sync_with_stdio(false);
   cin >> n >> m;
   f1(i,m){
      int p, q;
      cin >> p >> q;
      a[p].push_back(q);
      a[q].push_back(p);
   }
   f1(i,n) a[i].push_back(0);
   f1(i,n) if (!Visited[i]) visit(i);
   cout << max(Answer,1) << endl;
}