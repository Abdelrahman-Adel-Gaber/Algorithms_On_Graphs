#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;


void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
  used[x]=1;
  for(int i=0; i<adj[x].size(); i++) {
    if(!used[adj[x][i]]){
    dfs(adj,used,order,adj[x][i]);
      }
  }
  order.push_back(x);
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  //write your code here
 for(int i=0; i<adj.size(); i++) {
         if( (!used[i]) && (adj[i].size()>0) )
          dfs(adj,used,order,i);
        }
   for(int i=0; i<adj.size(); i++) {
         if( !used[i] )
          order.push_back(i);
        }

      reverse(order.begin(),order.end());
  return order;
}



void Explore(vector<vector<int> > &adj,int x,vector<int>&used) {
    used[x]=1;
    for(int i=0;i<adj[x].size();i++) {
        if(!used[adj[x][i]])
         Explore(adj,adj[x][i],used);
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj,vector<vector<int> > adjR) {
  int result = 0;
  //write your code here
   vector<int> order = toposort(adjR);
   vector<int> used(adj.size(),0);
   for(int i=0;i<order.size();i++) {
       if(!used[order[i]]) {
        Explore(adj,order[i],used);
         result++;
       }
   }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adjR(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjR[y - 1].push_back(x - 1);

  }
  std::cout << number_of_strongly_connected_components(adj,adjR);
}
