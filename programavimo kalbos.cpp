#include <bits/stdc++.h>

struct kalba{
    std::string pav;
    double i1, i2;
    double index(){
        return i1-i2;
    }
};

int main()
{
    std::ifstream fd("Duomenys.txt");
    std::ofstream fr("Rezultatai.txt");
    
    int n;
    fd >> n;
    fd.ignore(80, '\n');
    std::vector<kalba> k;
    k.resize(n);
    for(int i=0; i<n; i++){
        char temp[16];
        fd.get(temp, 16);
        k[i].pav = temp;
        fd >> k[i].i1 >> k[i].i2;
        fd.ignore(80, '\n');
    }
    
    for(int i=0; i<k.size(); i++){
        fr << k[i].pav << ' ' <<std::fixed <<std::setprecision(2) <<k[i].index() <<'\n';
    }
    
    return 0;
}
