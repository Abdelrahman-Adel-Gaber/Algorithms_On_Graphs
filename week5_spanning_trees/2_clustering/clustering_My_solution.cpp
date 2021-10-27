#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;





double Calculate_distances(int x1,int y1,int x2,int y2) {
double dist=(double)pow(x1-x2,2)+(double)pow(y1-y2,2);
dist =sqrt(dist);
return dist;}



bool fu_sort(vector<double>&temp1,vector<double>&temp2) {
return temp1[2]<temp2[2];
}


double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
 vector<vector <double> > distances;

 vector<int>parent(x.size(),-1);

 for(int i=0; i< x.size() ; i++) {
    for(int j=i+1; j<x.size() ; j++) {
      vector<double>temp;
      temp.push_back((double)i);
      temp.push_back((double)j);
      temp.push_back(Calculate_distances(x[i],y[i],x[j],y[j]));
      distances.push_back(temp);

    }
 }
 sort(distances.begin(),distances.end(),fu_sort);

 vector<int> set_num(x.size());
  for(int i=0;i<x.size();i++)
   set_num[i]=i;


   int n=1;
   while(n<x.size()) {
     int u=(int)distances[0][0];
     int v=(int)distances[0][1];
    if(set_num[u]!=set_num[v]){

       for(int i=0;i<x.size();i++) {
            if(i==v)
            continue;
           if(set_num[i]==set_num[v])
             set_num[i]=set_num[u];
       }
       set_num[v]=set_num[u];
      result +=distances[0][2];
      distances.erase(distances.begin());
    }else{
        distances.erase(distances.begin());
        continue;
    }

   n++;
   }






  return result;
}

int main() {

size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
