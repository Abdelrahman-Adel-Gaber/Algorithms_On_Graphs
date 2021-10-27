#include <iostream>
#include <vector>
#include <queue>

#define INF -1
using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector <int> dist(adj.size(),INF);
  queue<int> My_queue;
  My_queue.push(s);
  dist[s]=0;
  while(!My_queue.empty()){
     int u=My_queue.front();
      My_queue.pop();
      for(int i=0;i<adj[u].size(); i++) {
          if(dist[adj[u][i]]==INF) {
              My_queue.push(adj[u][i]);
              dist[adj[u][i]]=dist[u]+1;
          }
      }
  }
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
