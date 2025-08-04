#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    int n;
    fd >> n;
    
    std::vector<std::vector<int>> lenta;
    lenta.resize(n, std::vector<int> (n));
    
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            fd >> lenta[i][j];
        }
    }
    
    for(int i=0; i<lenta.size(); i++){
        for(int j=lenta.size()-1; j>=0; j--){
            fr << lenta[j][i] << ' ';
        }
        fr <<'\n';
    }
   
    
    
    
    

    return 0;
}
