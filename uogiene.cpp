#include <bits/stdc++.h>

void skaityti(std::vector<char> &valg, int &liko, int &k){
     std::ifstream fd("U1.txt");
    fd >> liko;
     fd >>k;
    fd.ignore(80, '\n');
    valg.resize(k);
    
     char x;
    for(int i=0; i<valg.size(); i++){
        fd.get(x);
        valg[i] = x;
    }
}

void skaiciuoti(std::vector<char> &valg, int &liko, std::string &paskutinis, int &suvalge){
    
      for(int i=0; i<valg.size(); i++){
        if(valg[i] == 'M' && liko >0){
            paskutinis = "Mazylis";
            
            if(liko - 2 < 0)suvalge = liko;
            else suvalge = 2;
            liko -= suvalge;
        }
       if(valg[i] == 'K' && liko >0){
            paskutinis = "Karlsonas";
            
            if(liko - 5 < 0)suvalge = liko;
            else suvalge = 5;
            liko -= suvalge;
        }
        if(valg[i] == 'F' && liko >0){
            paskutinis = "Frekenbok";
            
            if(liko - 3 < 0)suvalge = liko;
            else suvalge = 3;
            liko -= suvalge;
        }
    }
    
}

void rasyti(int &liko, std::string &paskutinis, int &suvalge){
    
    std::ofstream fr("U1rez.txt");
     if(liko > 0) fr << liko << ' ' <<"liko";
    else fr << suvalge << ' ' <<paskutinis;
    
}

int main()
{
   
    int liko;
    int k;
    std::vector<char> valg;
    std::string paskutinis;
    int suvalge;
    
    skaityti(valg, liko, k);
    skaiciuoti(valg, liko, paskutinis, suvalge);
    rasyti(liko, paskutinis, suvalge);

    return 0;
}
