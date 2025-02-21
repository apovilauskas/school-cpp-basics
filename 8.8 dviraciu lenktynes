#include <bits/stdc++.h>

struct dviratininkas{
    std::string vardas, pavarde;
    int nr, min, krit;
};

int main()
{
    std::ifstream fd("Dviraciai.csv");
    std::ofstream fr("Rezultatai.csv");
    std::vector<dviratininkas> d;
    dviratininkas temp;
    std::string nnnn;
    std::getline(fd, nnnn);
    while(std::getline(fd, temp.vardas, ',')){
        std::getline(fd, temp.pavarde, ',' );
        char skyriklis;
        fd >> temp. nr >>skyriklis >> temp.min >> skyriklis >> temp.krit;
        fd.ignore(80, '\n');
        d.push_back(temp);
    }
    
    for(int i=0; i<d.size(); i++){
        for(int j=0; j<d.size()-1; j++){
            if(d[j].krit == d[j+1].krit && d[j].min > d[j+1].min) std::swap(d[j], d[j+1]);
            else if(d[j].krit < d[j+1].krit) std::swap(d[j], d[j+1]);
        }
    }
    fr << "Vardas,Pavardė,GalutinisLaikas" << '\n';
    for(int i=0; i<d.size(); i++){
        fr << d[i].vardas <<','<< d[i].pavarde << ','<<d[i].min + (d[i].krit*2) <<  '\n';
    }

    return 0;
}
