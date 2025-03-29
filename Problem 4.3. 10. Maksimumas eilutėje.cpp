//Duota stačiakampė matrica. Raskite didžiausią elementą eilutėje, kurios vidurkis yra mažiausias.

#include <bits/stdc++.h>

void skaitymas(int y, int x, std::vector<std::vector<int>> &lenta){
    std::ifstream fd("U1.txt");
    fd >> y >> x; 
    
    lenta.resize(y, std::vector<int> (x)); 
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            fd >> lenta[i][j];
        }
    }
}

//funkcija randanti kuri eilute turi maziausia vidurki
int eilute(std::vector<std::vector<int>> &lenta ){
       int suma=0;
    int minsum=INT_MAX;
    int mini;
    for(int i=0; i<lenta.size(); i++){
        for(int j=0; j<lenta[i].size(); j++){
            suma+= lenta[i][j];
        }
        if(suma >minsum){
            minsum = suma;
            mini = i;
        }
        suma=0;
    }
    return mini;
    
}

//didziausias elementas eiluteje
int elementas(std::vector<std::vector<int>> &lenta){
    int maxx= INT_MIN;
    int mini = eilute(lenta);
     for(int i=0; i<lenta[mini].size(); i++){
        if(lenta[mini][i] > maxx) maxx = lenta[mini][i];
    }
    return maxx;
}

void rasymas(int maxx){
    std::ofstream fr("U1rez.txt");
    
    fr << maxx;
}

int main()
{
    
    int y, x;
    std::vector<std::vector<int>> lenta ;
    skaitymas(y, x, lenta);
    rasymas(elementas(lenta));
   
    
    return 0;
}
