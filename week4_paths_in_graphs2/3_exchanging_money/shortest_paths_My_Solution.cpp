#include <iostream>
#include <limits>
#include <vector>
#include <queue>

#define INF 214748364

using namespace std ;



void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here

 distance[s]=0;
 reachable[s]=1;

 queue <int> q;
   for(int s=0;s<adj.size() ;s++) {
    for(int u=0 ;u<adj.size(); u++) {
        for(int i=0; i<adj[u].size(); i++) {
            if( (distance[u]!=numeric_limits<long long>::max())  && distance[adj[u][i]]> (distance[u]+cost[u][i]) )
            {
                distance[adj[u][i]]=distance[u]+cost[u][i];
                reachable[adj[u][i]]=1;
                if(s==(adj.size()-1)) {
                q.push(adj[u][i]);
                }
            }
        }

    }
 }
vector<int> visited(adj.size(),0);
 while(!q.empty()) {
     int t=q.front();
     q.pop();
     visited[t]=1;
     shortest[t]=0;
     for(int i=0;i<adj[t].size();i++) {
         if(!visited[adj[t][i]]) {
             shortest[adj[t][i]]=0;
             q.push(adj[t][i]);
              visited[adj[t][i]]=0;
         }
     }
 }

 distance[s]=0;




}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
