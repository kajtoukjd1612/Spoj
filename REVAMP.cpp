#include <bits/stdc++.h>
using namespace std;
 
const int oo = 1e9;
typedef pair<int , int> ii;
typedef pair<int , ii> iii;
vector< vector< ii > > Adjlist;
int dist[10001][21] , n , m , k , don;
int trace[30001];
 
void dijkstra(int s, int f, int node) {
    for(int i = 1 ; i <= node ; ++i) {
        for(int j = 0 ; j <= k ; ++j) {
            dist[i][j] = oo;
        }
    }
 
    for(int i = 0 ; i <= k ; ++i) {
        dist[s][i] = 0;
    }
 
    priority_queue<iii , vector<iii> , greater<iii> > pq;
    pq.push(iii(0 ,ii(s , 0)));
 
    while(!pq.empty()) {
        iii cur = pq.top();
        pq.pop();
 
        int u = cur.second.first;
        int current_w = cur.first;
        int cnt = cur.second.second;
 
        if(u == f) break;
        if(current_w != dist[u][cnt]) continue;
 
        for(int i = 0 ; i < Adjlist[u].size() ; ++i) {
            int v = Adjlist[u][i].second;
            int new_w = Adjlist[u][i].first;
 
 
 
            if(cnt < k) {
                if(dist[v][cnt + 1] > dist[u][cnt]) {
                    dist[v][cnt + 1] = dist[u][cnt];
                    pq.push(iii(dist[v][cnt + 1] , ii(v , cnt + 1)));
                }
            }
 
            if(dist[v][cnt] > dist[u][cnt] + new_w) {
                dist[v][cnt] = dist[u][cnt] + new_w;
                pq.push(iii(dist[v][cnt] , ii(v , cnt)));
            }
 
 
        }
    }
}
 
main() {
    //freopen("revamp.inp","r",stdin);
    cin >> n >> m >> k;
    Adjlist.assign(n + 1 , vector< ii >());
    for(int i = 0 ; i < m ; ++i) {
        int u , v , w;
        cin >> u >> v >> w;
        Adjlist[u].push_back(ii(w , v));
        Adjlist[v].push_back(ii(w , u));
    }
 
    dijkstra(1 , n , n);
 
    printf("%d", dist[n][k]);
}
