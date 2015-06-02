#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<long long,int> lli;
 
const int oo = 1e9;
vector< lli > Adjlist[10001];
int dist[10001];
long long cnt[10001];
int mindis = 0;
 
void dijkstra(int s,int f,int node) {
    for(int i=1;i<=node;++i) {
        dist[i] = oo;
    }
    memset(cnt, 0, sizeof(cnt));
    dist[s] = 0;
    cnt[s] = 1;
    priority_queue<lli , vector<lli> , greater<lli> > pq;
    pq.push(lli(0,s));
 
 
    while(!pq.empty()) {
        lli cur = pq.top();
        pq.pop();
        int v = cur.second;
        int w = cur.first;
 
        if(v == f) break;
        if(w != dist[v]) continue;
 
        for(int i=0;i<Adjlist[v].size();++i) {
            int v2 = Adjlist[v][i].second;
            int w_extra = Adjlist[v][i].first;
 
            if(w_extra + w > dist[v2]) continue;
            else if(w_extra + w == dist[v2]) cnt[v2] += cnt[v];
            else {
                dist[v2] = w + w_extra;
                cnt[v2] = cnt[v];
                pq.push(lli(dist[v2],v2));
            }
        }
    }
    mindis = dist[f];
    cout << mindis << " " << cnt[f];
}
 
main() {
    //freopen("QBSCHOOL.txt","r",stdin);
    int N,M;
    cin >> N >> M;
 
    for(int i=1;i<=M;++i) {
        int dir,u,v,l;
        cin >> dir >> u >> v >> l;
        Adjlist[u].push_back(lli(l,v));
        if(dir == 2) {
            Adjlist[v].push_back(lli(l,u));
        }
    }
 
    dijkstra(1,N,N);
}
