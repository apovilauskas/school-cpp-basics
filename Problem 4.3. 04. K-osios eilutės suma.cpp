#include <bits/stdc++.h>

int main()
{
   std::ifstream fd("U1.txt");
   std::ofstream fr("U1rez.txt");
   
   
   int n, k;
   std::vector<std::vector<int>> v;
   
   
   fd >>n >>k;
   v.resize(n, std::vector<int>(n,0));
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           fd >> v[i][j];
       }
   }

//suprantu kad galima viska atlikt tam paciam cikle, net nebutina naudot vektoriu bet taip praso uzduotis
int suma=0;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            if(i+1 == k){
                suma+= v[i][j];
            }
        }
    }
fr << suma;

    return 0;
}
