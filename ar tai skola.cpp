#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    std::string a;
    fd >> a;
    
    bool minus=0;
    int count=0;
    int kablelis=0;
    int kablelisnegale=0;
    
    if(a[0] == '-')minus = 1;
    if(isdigit(a[1]) && isdigit(a.back())){
        kablelisnegale=1;
    }
    
    for(int i=1; i<a.size(); i++){
        if(kablelis == 1 && isdigit(a[i])){
            count++;
        }
        if(a[i] ==','){
            kablelis ++;
        }

    }
    
    if(kablelis == 1 && minus == 1 && count == 2&& kablelisnegale == 1) fr <<"TAIP";
    else fr <<"NE";
  
    return 0;
}
