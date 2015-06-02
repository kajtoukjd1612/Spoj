#include <bits/stdc++.h>
using namespace std;
 
typedef pair< int, int > ii;
const int oo = 1e9 + 7;
vector< ii > Adj[30001];
long long dist_1[30001], dist_n[30001], cnt_1[30001], cnt_n[30001], n, m, res = 0;
 
void dijkstra_1(int s, int f, int node) {
     for(int i = 1 ; i <= n ; ++i) {
          dist_1[i] = oo;
     }
 
     memset(cnt_1, 0, sizeof(cnt_1));
     dist_1[s] = 0;
     cnt_1[s] = 1;
     priority_queue< ii, vector< ii >, greater< ii > > heap;
     heap.push(ii(0, s));
 
     while(!heap.empty()) {
          ii cur = heap.top();
          heap.pop();
 
          int u = cur.second;
          int w = cur.first;
 
          if(u == f) break;
          if(w != dist_1[u]) continue;
 
          for(int i = 0 ; i < Adj[u].size() ; ++i) {
               int v = Adj[u][i].second;
               int w_ex = Adj[u][i].first;
 
               if(w + w_ex > dist_1[v]) continue;
               else if(w + w_ex == dist_1[v]) cnt_1[v] += cnt_1[u];
               else {
                    dist_1[v] = w + w_ex;
                    cnt_1[v] = cnt_1[u];
                    heap.push(ii(dist_1[v], v));
               }
          }
     }
}
 
void dijkstra_n(int s, int f, int node) {
     for(int i = 1 ; i <= n ; ++i) {
          dist_n[i] = oo;
     }
 
     memset(cnt_n, 0, sizeof(cnt_n));
     dist_n[s] = 0;
     cnt_n[s] = 1;
     priority_queue< ii, vector< ii >, greater< ii > > heap;
     heap.push(ii(0, s));
 
     while(!heap.empty()) {
          ii cur = heap.top();
          heap.pop();
 
          int u = cur.second;
          int w = cur.first;
 
          if(u == f) break;
          if(w != dist_n[u]) continue;
 
          for(int i = 0 ; i < Adj[u].size() ; ++i) {
               int v = Adj[u][i].second;
               int w_ex = Adj[u][i].first;
 
               if(w + w_ex > dist_n[v]) continue;
               else if(w + w_ex == dist_n[v]) cnt_n[v] += cnt_n[u];
               else {
                    dist_n[v] = w + w_ex;
                    cnt_n[v] = cnt_n[u];
                    heap.push(ii(dist_n[v], v));
               }
          }
     }
}
 
main() {
     //freopen("CENTRE28.in.c","r",stdin);
     scanf("%lld %lld", &n, &m);
     for(int i = 0 ; i < m ; ++i) {
          long long u, v, w;
          scanf("%lld %lld %lld", &u, &v, &w);
          Adj[u].push_back(ii(w, v));
          Adj[v].push_back(ii(w, u));
     }
 
     dijkstra_1(1, n, n);
     dijkstra_n(n, 1, n);
 
     for(int i = 2 ; i < n ; ++i) {
          if(dist_1[i] + dist_n[i] != dist_1[n] || cnt_1[i] * cnt_n[i] != cnt_1[n]) {
               res++;
          }
     }
 
     printf("%lld\n", res);
     for(int i = 2 ; i < n ; ++i) {
          if(dist_1[i] + dist_n[i] != dist_1[n] || cnt_1[i] * cnt_n[i] != cnt_1[n]) {
               printf("%d\n", i);
          }
     }
}
 
