#include <bits/stdc++.h>

struct avis{
    std::string vardas;
    std::string dnr;
    int kof=0;
};

void skaitymas(int &n, int &m, int &eil, std::vector<avis> &a, avis &svarbi){
    std::ifstream fd("U2.txt");
    fd >> n >> m >> eil;
    fd.ignore(80, '\n');
    avis temp;
    char tempa[11];
    
    for(int i=0; i<n; i++){
        fd.get(tempa, 11);
        temp.vardas = tempa;
        fd >> temp.dnr;
        if(i+1 == eil) svarbi = temp;
        else a.push_back(temp);
        fd.ignore(80, '\n');
    }
    
}

void kof(std::vector<avis> &a, int &m, avis &svarbi){
    
     for(int i=0; i<a.size(); i++){
        for(int j=0; j<m; j++){
            if(a[i].dnr[j] == svarbi.dnr[j]) a[i].kof ++;
        }
    }
}

void rikiavimas(std::vector<avis> &a){
       
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size()-1; j++){
            if(a[j].kof == a[j+1].kof && a[j].vardas > a[j+1].vardas) std::swap(a[j], a[j+1]);
            else if(a[j].kof < a[j+1].kof) std::swap(a[j], a[j+1]);
        }
    }
}

void rasyti(avis svarbi, std::vector<avis> &a){
    std::ofstream fr("U2rez.txt");
    fr << svarbi.vardas <<'\n';
    for(int i=0; i<a.size(); i++){
        a[i].vardas.resize(10, ' ');
        fr << a[i].vardas << ' '<< a[i].kof << '\n';
    }
}

int main()
{
    
    int n; //aviu
    int m; //dnr ilgis
    int eil; //tiriamos dnr
    std::vector<avis> a;
    
    avis svarbi;
    skaitymas(n, m, eil, a, svarbi);
    kof(a,m, svarbi);
    rikiavimas(a);
    rasyti(svarbi, a);
    


    

    return 0;
}
