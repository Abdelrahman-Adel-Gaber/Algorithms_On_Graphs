#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define INF 214748364

using namespace std ;


int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
 vector <int> dist(adj.size(),INF);
 vector <int> prev(adj.size(),INF);

  dist[0]=0;
 //smallest value at the end
  int u,j;
 for(int s=1;s<adj.size() ;s++) {
    for(int i=0 ;i<adj.size(); i++) {
        u=i;
        for(int i=0; i<adj[u].size(); i++) {
            if( dist[adj[u][i]]> (dist[u]+cost[u][i]) )
            {
                dist[adj[u][i]]=dist[u]+cost[u][i];
                prev[adj[u][i]]=u;
            }
        }

    }
 }

 for(int i=0 ;i<adj.size(); i++) {
        u=i;
        for(int i=0; i<adj[u].size(); i++) {
            if( dist[adj[u][i]]> (dist[u]+cost[u][i]) )
            {
               return 1;
               }
        }

    }



  return 0;
}






int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
