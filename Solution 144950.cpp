#include <bits/stdc++.h>

void skaityti(int n, int m,  std::vector<std::vector<int>> &lenta){
     std::ifstream fd("U1.txt");
     fd >> n >>m;
    lenta.resize(n, std::vector<int> (m));
    
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            fd >> lenta[i][j];
        }
    }
    
}

int minstulp(std::vector<std::vector<int>> &lenta){
    int minn= INT_MAX;
    int index = -1;
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            if(lenta[i][j] < minn){
                minn = lenta[i][j];
                index = j;
            }
        }
    }
    return index;
}

double vidurkis(std::vector<std::vector<int>> &lenta, int &index){
    int suma=0;
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            if(j==index){
                suma+= lenta[i][j];
            }
        }
    }
    return suma*1.00/lenta.size(); //-------------lenta.size()
}

int main()
{
   
    std::ofstream fr("U1rez.txt");
    
    int n, m;
    std::vector<std::vector<int>> lenta;
    
    
    skaityti(n,m,lenta);
    int index = minstulp(lenta);
    double vid = vidurkis(lenta, index);
    fr << std::fixed << std::setprecision(2) << vid;
    

    return 0;
}
