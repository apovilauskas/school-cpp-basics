#include <bits/stdc++.h>

struct vardas{
    std::string vard;
    int sum;
};

void skaityti(std::vector<vardas> &v, std::string &antraste){
    std::ifstream fd("vardai_atrinkimui_data.txt");
    
    std::getline(fd, antraste, '\n');
    //fd.ignore(80, '\n');
    
    std::string vard;
    while(std::getline(fd, vard, ';')){
        int temp;
        v.push_back({vard, 0});
        for(int i=0; i<10; i++){
            fd >> temp;
            fd.ignore(1);
            v.back().sum += temp;
        }
        fd.ignore(80, '\n');
    }
}

void rasyti(std::vector<vardas> &v, std::string &antraste){
    std::ofstream fr("vardai_atrinkti_res.txt");
    fr << antraste <<'\n';
    for(int i=0; i<v.size(); i++){
        fr << v[i].vard << ' ' <<v[i].sum <<'\n';
    }
    
    
}

void atrinkti(std::vector<vardas> &v){
    std::vector<vardas> tinka;
    for(int i=0; i<v.size(); i++){
       if(v[i].sum < 1000 && v[i].sum > 200) tinka.push_back(v[i]);
    }
    
    v = tinka;
}

int main()
{
    std::vector<vardas> v;
    std::string antraste;
    
    skaityti(v, antraste);
    atrinkti (v);
    rasyti(v, antraste);
    
    

    

    return 0;
}
