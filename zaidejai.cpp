#include <bits/stdc++.h>
 
struct zaidejas{
std::string vardas;
std::string pavarde;
int startonr;
int laikas;
int kritimu;
int galutinis(){
return laikas+(kritimu*2);
}
 
};
 
void skaityti(std::string &antraste, std::vector<zaidejas> &z){
std::ifstream fd("Dviraciai.csv");
std::getline(fd, antraste, '\n');
std::string t1,t2; //laikini kintamieji
int t3,t4,t5;
char skyr;
while(std::getline(fd, t1, ',')){
    std::getline(fd, t2, ',');
    fd >> t3 >>skyr >> t4 >>skyr >> t5;
    fd.ignore(80, '\n');
    z.push_back({t1,t2,t3,t4,t5});
}
fd.close();
}
 
void rasyti(std::string &antraste, std::vector<zaidejas> &z){
std::ofstream fr("Rezultatai.csv");
fr << antraste<<'\n';
for(int i=0; i<z.size(); i++){
    fr << z[i].vardas <<',' <<z[i].pavarde << ',' <<z[i].galutinis() << '\n';
}
}
 
void rikiuoti(std::vector<zaidejas> &z)
{
    for(int i=0; i<z.size(); i++)
    {
        for(int j=0; j<z.size()-1; j++)
        {
            if(z[j].kritimu < z[j+1].kritimu)std::swap(z[j], z[j+1]);
        }
    }
}
 
int main()
{
    std::string antraste;
    std::vector<zaidejas> z;
 
    skaityti(antraste, z);
    rikiuoti(z);
    rasyti(antraste, z);
 
    return 0;
}
