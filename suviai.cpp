#include <bits/stdc++.h>

struct saulys{
    
    std::string vardas;
    int suviu;
    std::vector<int>taskai;
   
   double vidurkis(){
       int suma=0;
       for(int i=0; i<taskai.size(); i++){
          suma+= taskai[i]; 
       }
       return suma * 1.00/ suviu;
   }
   
   double proc(){
       int count = 0;
       for(int i=0; i<taskai.size(); i++){
           if(taskai[i] == 10)count ++; 
       }
      
       return count *100.00/taskai.size();
   }
   
};

void skaityti(std::vector<saulys> &s, int &n){
    std::ifstream fd("duom.txt");
    fd >> n;
    s.resize(n);
    
    for(int i=0; i<s.size(); i++){
        int k;
        fd >> s[i].vardas >> s[i].suviu;
        s[i].taskai.resize(s[i].suviu);
        for(int j=0; j<s[i].suviu; j++){
            fd >> s[i].taskai[j];
        }
        
    }
}


void rasyti(saulys index, saulys index1, saulys index2){
    std::ofstream fr("rez.txt");
    
    fr << "Taikliausias - "<< index.vardas << ' ' << std::fixed << std::setprecision(1) << index.vidurkis() <<'\n';
    fr << "Dazniausiai saude - "<< index1.vardas << ' ' <<index1.suviu <<'\n';
    fr << "Daug. des. % - "<<index2.vardas << ' ' <<std::fixed << std::setprecision(1) << index2.proc() <<'\n';
}

void skaiciuoti(std::vector<saulys> &s){
    
    saulys index, index1, index2;
    double maxx=DBL_MIN;
    int maxxx = INT_MIN;
    double maxproc = DBL_MIN;
    for(int i=0; i<s.size(); i++){
        if(s[i].suviu > maxxx) {
            index1 = s[i];
            maxxx = s[i].suviu;
        }
        if(s[i].vidurkis() > maxx){
            maxx = s[i].vidurkis();
            index = s[i];
        }
        if(s[i].proc() > maxproc){
            index2 = s[i];
            maxproc = s[i].proc();
        }
    }
    
    rasyti(index, index1, index2);
    
}

int main()
{
    

    
    int n;
    std::vector<saulys> s;
    
    skaityti(s, n);
    skaiciuoti(s);
    
    
    


    return 0;
}
