#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define INF 214748364

using namespace std ;

int ExtractMin( vector<int>&dist,vector<bool> &array1) {

    int min1=INF;
    int index=0;

    for(int i=0; i<dist.size(); i++) {
     if(array1[i]) {
        if(min1>dist[i]){
           min1= dist[i];
           index=i;

        }

     }
    }

return index;
}

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
 vector <int> dist(adj.size(),INF);
 vector<bool> array1(dist.size(),true);

 vector <int> prev(adj.size(),0);

  dist[s]=0;
 //smallest value at the end
  for(int i=0 ;i<adj.size(); i++) {
      int u=ExtractMin(dist,array1);
       array1[u]=false;

     for(int i=0; i<adj[u].size(); i++) {
         if( dist[adj[u][i]]> (dist[u]+cost[u][i]) )
         {
            dist[adj[u][i]]=dist[u]+cost[u][i];
         }
     }

  }
    if(dist[t] != INF)
     return dist[t];
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
