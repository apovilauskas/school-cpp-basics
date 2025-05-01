#include <bits/stdc++.h>

struct zmogus{
    std::string vardas;
    long long kodas;
    
};

void skaityti(std::vector<zmogus> &vyrai, std::vector<zmogus> &moterys){
    std::ifstream fd("data.csv");
    
    std::string vardas;
    long long kodas;
    while(std::getline(fd, vardas, ',')){
        fd >> kodas >>std::ws;
        if(kodas/10000000000 %2 == 0)moterys.push_back({vardas, kodas});
        else vyrai.push_back({vardas, kodas});
    }
    
}

void rikiuoti(std::vector<zmogus> &zmoguciai){
    
    for(int i=0; i<zmoguciai.size(); i++){
        for(int j=0; j<zmoguciai.size()-1; j++){
            if(zmoguciai[j].kodas > zmoguciai[j+1].kodas){
                std::swap(zmoguciai[j], zmoguciai[j+1]);
            }
        }
    }
    
}

void spausdinti(std::ofstream &fr, std::string lytis, std::vector<zmogus> zmones){
    
    std::vector<std::string> menesiai = {"sausio", "vasario", "kovo", "balandzio","geguzes", "birzelio", "liepos","rugpjucio" ,"rugsejo","spalio","lapkricio","gruodzio"};
    std::vector<int> data = {1800, 1800, 1900, 1900, 2000, 2000};
    fr << lytis <<'\n';
    if(zmones.size()==0) fr <<"NERASTA\n";
    else{
       
    for(int i=0; i<zmones.size(); i++){
        int pirmas = zmones[i].kodas/10000000000;
        int metai = zmones[i].kodas /100000000 % 100;
        int menuo = zmones[i].kodas /1000000 % 100;
        int diena = zmones[i].kodas /10000 %100;
        
        fr << zmones[i].vardas << ',' <<data[pirmas-1] +metai << ','<<menesiai[menuo-1] <<',' <<diena <<'\n';
    } 
        
        
    } 
    
    
}

int main()
{
    std::ofstream fr("rez.csv");
    
    
    std::vector<zmogus> vyrai;
    std::vector<zmogus> moterys;
    
    skaityti(vyrai, moterys);
    rikiuoti(vyrai);
    rikiuoti(moterys);
    spausdinti(fr, "MOTERYS", moterys);
    spausdinti(fr, "VYRAI", vyrai);
    

    return 0;
}
