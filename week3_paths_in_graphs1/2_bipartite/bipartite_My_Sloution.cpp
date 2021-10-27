#include <iostream>
#include <vector>
#include <queue>

#define INF -1

using std::vector;
using std::queue;


int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector <int> color(adj.size(),INF);
  queue<int> My_queue;

  for(int j=0;j<color.size(); j++) {
      if(color[j]==INF){
       My_queue.push(j);
       color[j]=0;
    while(!My_queue.empty()){
     int u=My_queue.front();
      My_queue.pop();
      for(int i=0;i<adj[u].size(); i++) {
          if(color[adj[u][i]]==INF) {
              My_queue.push(adj[u][i]);
              color[adj[u][i]]=color[u]==0?1:0;
          }
          else if(color[u]==color[adj[u][i]]) {
            return 0;
          }
        }
      }
      }
  }


  return 1;
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
  std::cout << bipartite(adj);
}
