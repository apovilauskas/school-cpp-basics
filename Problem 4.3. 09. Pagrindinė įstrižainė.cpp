#include <bits/stdc++.h>

void skaitymas(int &n,  std::vector<std::vector<int>> &lenta){
    std::ifstream fd("U1.txt");
    fd >> n;
     lenta.resize(n, std::vector<int> (n));
      for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            fd >> lenta[i][j];
        }
    }
}

int suma(std::vector<std::vector<int>> &lenta){
    int suma=0;

    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            if(i==j) {
            suma+= lenta[i][j];
            }
        }
    }
    return suma;
}



int main()
{
    
    std::ofstream fr("U1rez.txt");
    
    int n;
     std::vector<std::vector<int>> lenta;
    
   skaitymas(n, lenta);

    fr << suma(lenta);
    
    return 0;
}
