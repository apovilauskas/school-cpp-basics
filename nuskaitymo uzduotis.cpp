/*
nuskaitymo failas
Jonas,25,180.5
Aiste,30,165.2
Mantas,22,175.0
*/
 
#include <bits/stdc++.h>
 
struct zmogus{

std::string vardas;

int amzius;

double ugis;
 
};
 
int main()

{

    std::ifstream fd("duom.txt");

    std::ofstream fr("rez.txt");

    std::vector<zmogus> z;
 
    std::string temp;

    while(std::getline(fd, temp, ',')){

       std::string temp1;

        std::string temp2;

        std::getline(fd, temp1, ',');

        fd >> temp2;

        fd.ignore(80, '\n');

        z.push_back({temp, std::stoi(temp1), std::stod(temp2)});

    }
 
    for(int i=0; i<z.size(); i++){

       fr << z[i].vardas << ' ' <<z[i].amzius << ' ' <<z[i].ugis <<'\n';

    }
 
    return 0;

}

 
