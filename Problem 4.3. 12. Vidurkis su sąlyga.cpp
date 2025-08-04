#include <bits/stdc++.h>

void skaitymas(int y, int x, std::vector<std::vector<int>> &lenta){
    std::ifstream fd("U1.txt");
    
    fd >> y >> x;
    lenta.resize(y, std::vector<int> (x));
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            fd >> lenta[i][j];
        }
    }
    
}
//eilutes, kurioje didziausias elementas, vidurkis
double vidurkis(std::vector<std::vector<int>> &lenta){
    
    
    //eilutes radimas
    int maxx=INT_MIN;
    int eilute;
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            if(lenta[i][j]> maxx){
                eilute = i;
                maxx = lenta[i][j];
            }
        }
    } 
    
    
    //vidurkio radimas
    double suma=0;
    for(int i=0; i<lenta[eilute].size(); i++){
        suma+= lenta[eilute][i];
    }
    return suma/lenta[eilute].size();
    
}



int main()
{
    std::ofstream fr("U1rez.txt");
    int y, x;
    std::vector<std::vector<int>> lenta;

    skaitymas(y, x, lenta);
    fr << std::fixed << std::setprecision(2) << vidurkis(lenta);
    
    return 0;
}
