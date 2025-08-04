#include <bits/stdc++.h>

void skaitymas(int &n, int &m, std::vector<std::vector<int>> &lenta){
    std::ifstream fd("U1.txt");
    fd >> n >>m;
    lenta.resize(n, std::vector<int> (m));
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            fd >> lenta[i][j];
        }
    }
    
}

bool pirminis(int sk){
    if(sk<2) return 0;
    for(int i=2; i*i<=sk; i++){
        if(sk%i == 0) return 0;
    }
    return 1;
}

//konturuose ir pirminis
int tinkamas(std::vector<std::vector<int>> &lenta){
    int count = 0;
        for(int i=0; i<lenta.size(); i++){
            if(pirminis(lenta[i][0]) == 1){
                count ++;
            }
            if(pirminis(lenta[i][lenta[0].size()-1]) == 1){
                count ++;
            }
        }
        
        for(int i=1; i<lenta.size()-1; i++){
            if(pirminis(lenta[0][i]) == 1){
                count ++;
            }
            if(pirminis(lenta[lenta.size()-1][i]) == 1){
                count ++;
            }
        }
       return count; 
    }
    

int main()
{
    
    std::ofstream fr("U1rez.txt");
    
    std::vector<std::vector<int>> lenta;
    int n, m;
    skaitymas(n, m, lenta);
    fr <<tinkamas(lenta);
    
    
    return 0;
}
