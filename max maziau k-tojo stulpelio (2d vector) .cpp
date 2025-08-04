#include <bits/stdc++.h>

void skaityti(int &n, int&k, std::vector<std::vector<int>> &v){
    std::ifstream fd("U1.txt");
     fd >>n >>k;
     v.resize(n, std::vector<int>(n,0));
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           fd >> v[i][j];
       }
   }
}

int maxx(std::vector<std::vector<int>> &v, int&k){
int maxx=INT_MIN;
bool yra = 0;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            if(j+1 > k && v[i][j]>maxx){
                maxx = v[i][j];
                yra=1;
            }
        }
    }
    if(yra ==1)return maxx;
    else return -1;
}

int main()
{
   
   std::ofstream fr("U1rez.txt");
   
   int n, k;
   std::vector<std::vector<int>> v;
   
    skaityti(n,k,v);
    if(maxx(v,k) == -1)fr << "NO";
    else fr << maxx(v,k); 

    return 0;
}
