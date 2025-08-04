#include <bits/stdc++.h>

struct laikas{
    std::string diena;
    int valanda;
    std::vector<std::string> vardai;

};

void skaityti(std::vector<laikas> &laikai,
    std::vector<laikas> &zmones,
    int &d, int &n, int &k){

std::ifstream fd("U2.txt");
fd >> d >> k;

for(int i=0; i<d; i++){
    std::string diena;
    int valanda;
    fd >> diena >> k;
    for(int j=0; j<k; j++){
        fd >> valanda;
        laikai.push_back({diena, valanda}); 
    }
}

for(int i=0; i<k; i++){
laikas temp; 
int dienu;
std::string vardas;
temp.vardai.push_back(vardas);
fd >> dienu;
for(int j=0; j<dienu; j++){
    fd >> temp.diena;
    fd >> temp.valanda;
    zmones.push_back({temp});
}



}


}


int main(){


    std::vector<laikas> laikai;
    std::vector<laikas> zmones;
    int d, n, k;

   skaityti(laikai, zmones, d, n, k);


   std::ofstream fr("U2rez.txt");
   for(int i=0; i<laikai.size(); i++){
    fr << laikai[i].diena << ' ' <<laikai[i].valanda << ' ' ;
    for(int j=0; j<laikai[i].vardai.size(); j++){
        fr << laikai[i].vardai[j] << ' ';
    }
    fr<<'\n';
   }


    return 0;
}