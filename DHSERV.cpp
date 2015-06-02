#include <bits/stdc++.h>
using namespace std;
 
const int oo = 1e9 + 7;
 
int n, k, m;
long long floyd[501][501];
 
void init() {
     for(int i = 1 ; i <= n ; ++i) {
          for(int j = 1 ; j <= n ; ++j) {
               floyd[i][j] = oo;
          }
     }
}
 
main() {
     //freopen("DHSERV.in.c","r",stdin);
     scanf("%d %d %d", &n, &m, &k);
     init();
     for(int i = 0 ; i < m ; ++i) {
          int u, v;
          long long w;
          scanf("%d %d %lld", &u, &v, &w);
          floyd[u][v] = w;
     }
 
     while(k--) {
          int t;
          scanf("%d", &t);
          if(t == 1) {
               int x;
               scanf("%d", &x);
               for(int i = 1 ; i <= n ; ++i) {
                    for(int j = 1 ; j <= n ; ++j) {
                         floyd[i][j] = min(floyd[i][j], floyd[i][x] + floyd[x][j]);
                    }
               }
          }
          else if(t == 2) {
               int x, y;
               scanf("%d %d", &x, &y);
               if(floyd[x][y] != oo) printf("%lld\n", floyd[x][y]);
               else printf("-1\n");
          }
     }
} 
