#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void number_of_components(vector<vector<int> > &adj,vector <int>&v,int x) {
  v[x]=1;
  //write your code here
  for(int i=0;i<adj[x].size();i++){
    if(v[adj[x][i]]==0)
    number_of_components(adj,v,adj[x][i]);
   }

}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<int>visit(n,0);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int num=0;
  for(int i=0;i<adj.size();i++){
    if(!visit[i]) {
    number_of_components(adj,visit,i);
    num++;}
  }
  std::cout << num;
}
