#include <iostream>
#include <vector>
#include <fstream>
using std::vector;
using std::pair;
using namespace std;



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

int main() {
  size_t n, m;
 cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector <int>  visited(n,0) ;
   for (size_t i = 0; i < m; i++) {
    int x, y;
    cin>> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  cin >> x >> y;
  std::cout << reach(adj,visited ,x - 1, y - 1);
}
