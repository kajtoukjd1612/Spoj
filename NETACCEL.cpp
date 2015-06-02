#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <bitset>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair< int, int > ii;
typedef pair< int, ii > iii;
typedef pair< double, ii > dii;
const int oo = 1e9 + 7;
 
vector< ii > Adj[1010];
double dist[1010][25];
int n, m, k, used[1010][25];
 
void dijkstra(int s, int f, int node) {
     for(int i = 1 ; i <= n ; ++i) {
          for(int j = 0 ; j <= k ; ++j) {
               dist[i][j] = oo;
          }
     }
 
     priority_queue< dii, vector< dii >, greater< dii > > heap;
     for(int i = 0 ; i <= k ; ++i) {
          dist[s][i] = 0;
          heap.push(dii(dist[s][i], ii(s, i)));
     }
 
     while(!heap.empty()) {
          double w = heap.top().fi;
          int v = heap.top().se.fi;
          int cnt = heap.top().se.se;
          heap.pop();
 
          used[v][cnt] = 1;
          if(w != dist[v][cnt]) continue;
          if(v == f && cnt == k) break;
 
          for(int i = 0 ; i < Adj[v].size() ; ++i) {
               int v2 = Adj[v][i].se;
               double w_ex = Adj[v][i].fi;
 
               int cnt1 = 1;
               for(int j = cnt ; j <= k ; ++j) {
                    if(!used[v2][j] && dist[v2][j] > dist[v][cnt] + w_ex / cnt1) {
                         dist[v2][j] = dist[v][cnt] + w_ex / cnt1;
                         heap.push(dii(dist[v2][j], ii(v2, j)));
                    }
                    cnt1 *= 2;
               }
          }
     }
}
 
main() {
     //freopen("NETACCEL.txt", "r", stdin);
     scanf("%d %d %d", &n, &m, &k);
     for(int i = 0 ; i < m ; ++i) {
          int u, v, w;
          scanf("%d %d %d", &u, &v, &w);
          Adj[u].pb(ii(w, v));
          Adj[v].pb(ii(w, u));
     }
 
     dijkstra(1, n, n);
     printf("%.2lf", dist[n][k]);
}
