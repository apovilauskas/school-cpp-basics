/*
nuskaitymo failas
Jonas,Skraidantis Motociklas,320,8.5,90
Marius,Reaktyvine Masina,400,9.2,80
Laura,Antigravitacinis Bolidas,380,10.1,85
Tomas,Hyper Dviratis,290,7.8,95
Egle,Kosmine Raketa,500,12.5,70
*/

#include <bits/stdc++.h>
 
struct lenktynininkai
{
    std::string vardas;
    std::string tipas;
    int greitis;
    double pagreitis;
    int reitingas;//patikimumas
 
};
 
int main()
{
    std::ifstream fd("duom.txt");
    std::ofstream fr("rez.txt");
    std::vector<lenktynininkai> m;
 
    std::string temp, temp1;
    int temp2, temp4;
    double temp3;
    char skyriklis;
    while(std::getline(fd, temp, ','))
    {
        std::getline(fd, temp1, ',');
        fd >> temp2 >>skyriklis >> temp3 >>skyriklis >> temp4;
        fd.ignore(80, '\n');
        m.push_back({temp, temp1, temp2,temp3,temp4});
    }
 
    int maxgreitis=0;
    lenktynininkai greiciausias;
    for(int i=0; i<m.size(); i++)
    {
        if(m[i].greitis >maxgreitis){
                maxgreitis = m[i].greitis;
                greiciausias = m[i];
        }
 
    }
    fr << "Greiciausias: "<< greiciausias.vardas << ' '<<greiciausias.greitis <<'\n';
 
 
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m.size()-1; j++){
            if(m[j].reitingas < m[j+1].reitingas){
                std::swap(m[j], m[j+1]);
            }
        }
    }
 
    fr <<"\nPagal patikimumo reitinga:\n";
    for(int i=0; i<m.size(); i++){
        fr <<m[i].reitingas << ' ' <<m[i].vardas << ' ' << m[i].tipas <<'\n';
    }
 
    return 0;
}
