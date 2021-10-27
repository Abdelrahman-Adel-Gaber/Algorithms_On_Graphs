#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int reach(vector<vector<int> > &adj,vector<int>&v, int x, int y) {
  //write your code here
  v[x]=1;
  for(int i=0;i<adj[x].size();i++) {
    if(adj[x][i]==y)
       return 1;
      }
   for(int i=0;i<adj[x].size();i++) {
     if(v[adj[x][i]]==0)
     {
      int temp=reach(adj,v,adj[x][i],y);
      if(temp==1)
        return 1;
        }
   }
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size(),0);
  int ret;

  for(int i=0; i<adj.size(); i++) { 
      ret =reach(adj,visited,i,i);
      if(ret !=0 )
       return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
