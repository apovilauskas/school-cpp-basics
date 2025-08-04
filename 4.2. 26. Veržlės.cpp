#include <bits/stdc++.h>

void skaityti(int &n,  std::vector<int> &v){
    std::ifstream fd("duom.txt");
    fd >> n;
    v.resize(17);
    
      for(int i=0; i<n; i++){
        int temp, sk;
        fd >> temp >> sk;
        v[temp]+= sk;
    }
}

void didziausias(std::vector<int> &v, std::vector<int> &maxa, int &maxx){
    
   for(int i=0; i<v.size(); i++){
        if(v[i] > maxx){
            maxx = v[i];
        }
    }  
    for(int i=0; i<v.size(); i++){
        if(v[i] == maxx) maxa.push_back(i);
    }
}

void rasyti(std::vector<int> &v, std::vector<int> &maxa){
    std::ofstream fr("rez.txt");
     for(int i=0; i<v.size(); i++){
        if(v[i] != 0) fr << i << ' ' <<v[i] <<'\n';
    }
    
    fr << "Daugiausia yra ";
    int sum=0;
    for(int i=0; i<maxa.size(); i++){
        if(i == 0)fr << maxa[i];
        else fr <<", " << maxa[i];
        sum++;
    }
    if(sum == 1){
        fr << " rūšies";
    }
    else fr <<" rūšių";
}

int main()
{
    
    
    
    int n;
    std::vector<int> v;
    skaityti(n, v);
    std::vector<int> maxa;
    int maxx = INT_MIN;
    didziausias(v, maxa, maxx);
    rasyti(v, maxa);
 
    
    return 0;
}
