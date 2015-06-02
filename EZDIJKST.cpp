#include <bits/stdc++.h>
using namespace std;
 
typedef pair< int, int > ii;
const int oo = 1e9 + 7;
 
int dist[10001], n, k, t, a, b;
vector< ii > Adj[10001];
 
void dijkstra(int s, int f, int node) {
     for(int i = 1 ; i <= n ; ++i) {
          dist[i] = oo;
     }
     dist[s] = 0;
     priority_queue< ii, vector< ii >, greater< ii > > heap;
     heap.push(ii(0, s));
 
     while(!heap.empty()) {
          ii cur = heap.top();
          heap.pop();
          int v = cur.second;
          int w = cur.first;
 
          if(v == f) break;
          if(w != dist[v]) continue;
 
          for(int i = 0 ; i < Adj[v].size() ; ++i) {
               int u = Adj[v][i].second;
               int w_ex = Adj[v][i].first;
 
               if(w + w_ex >= dist[u]) continue;
               else {
                    dist[u] = w + w_ex;
                    heap.push(ii(dist[u], u));
               }
          }
     }
     if(dist[f] == oo) printf("NO\n");
     else printf("%d\n", dist[f]);
}
 
main() {
     //freopen("EZDIJKST.in.c","r",stdin);
     scanf("%d", &t);
     while(t--) {
          scanf("%d %d", &n, &k);
          for(int i = 0 ; i < k ; ++i) {
               int u, v, w;
               scanf("%d %d %d", &u, &v, &w);
               Adj[u].push_back(ii(w, v));
          }
 
          scanf("%d %d", &a, &b);
          dijkstra(a, b, n);
          memset(dist, 0, sizeof(dist));
          for(int i = 1 ; i <= 10000 ; ++i) {
               Adj[i].clear();
          }
     }
}
