#include <bits/stdc++.h>

void skaitymas(int &n,int &m, std::vector<std::vector<int>> &lenta){
  std::ifstream fd("U1.txt");
  fd >> n >>m;
    lenta.resize(n, std::vector<int>(m));

    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            fd >> lenta[i][j];
        }
    }
}

bool pirminis(int sk){
    if(sk<2) return 0;
    for(int i=2; i<sqrt(sk)+1; i++){
        if(sk%i == 0)return 0;
    }
    return 1;
}

int suma(std::vector<std::vector<int>> &lenta, int n, int m){
    int suma=0;
    for(int j=1; j<m-1; j++){
        suma += lenta[0][j];
        suma += lenta[n-1][j];
    }
    for(int i=1; i<n-1; i++){
        suma += lenta[i][0];
        suma += lenta[i][m-1];
    }
    return suma;
}


int main()
{
    
    std::ofstream fr("U1rez.txt");
    
    int n, m;
    std::vector<std::vector<int>> lenta;
    skaitymas(n, m, lenta);
    if(pirminis(suma(lenta, n, m)) == 1) fr << "YES";
    else fr << "NO";
    
    return 0;
}
