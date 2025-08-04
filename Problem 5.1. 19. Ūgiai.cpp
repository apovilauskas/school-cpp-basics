#include <bits/stdc++.h>

struct mokinys{
    char lytis;
    int ugis;
    
};

int main()
{
    std::ifstream fd("duom.txt");
    std::ofstream fr("rez.txt");
    
    int n;
    fd >> n;
    
    std::vector<mokinys> m;
    m.resize(n);
    
    for(int i=0; i<n; i++){
        fd >> m[i].ugis;
        fd >> m[i].lytis;
    }
    
    int berniuku=0;
    int mergaiciu=0;
    double vidutinisb;
    double vidutinism;
    double auksciausiasb=INT_MIN;
    double auksciausiasm=INT_MIN;
    
    for(int i=0; i<m.size(); i++){
        if(m[i].lytis == 'v'){
            berniuku++;
            vidutinisb += m[i].ugis;
            if(m[i].ugis > auksciausiasb) auksciausiasb = m[i].ugis;
        }
        if(m[i].lytis == 'm'){
            mergaiciu++;
            vidutinism += m[i].ugis;
            if(m[i].ugis > auksciausiasm) auksciausiasm = m[i].ugis;
        }
        
    }
    
    fr << "Berniukų skaičius: " <<berniuku <<'\n';
    fr << "Mergaičių skaičius: " <<mergaiciu <<'\n';
    
    
    fr << "Vidutinis mergaičių ūgis: ";
    if(mergaiciu>=1) fr<< std::fixed << std::setprecision(2)<< vidutinism/1.00/mergaiciu<<'\n';
    else fr << "NĖRA\n";
    fr << "Vidutinis berniukų ūgis: ";
    if(berniuku>=1) fr<< std::fixed << std::setprecision(2) <<vidutinisb/1.00/berniuku<<'\n';
    else fr << "NĖRA\n";
    fr <<"Aukščiausias berniukas: " ;
    if(berniuku>=1) fr<< std::fixed << std::setprecision(0) << auksciausiasb <<'\n';
    else fr << "NĖRA\n";
    fr << "Aukščiausia mergaitė: ";
    if(mergaiciu>=1) fr<< std::fixed << std::setprecision(0)<< auksciausiasm << '\n';
    else fr << "NĖRA\n";
    
     return 0;
}
