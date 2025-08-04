#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    std::string a;
    fd >> a;
    
    int count = 0;
    for(int i=1; i<a.size()-1; i++){
        if(a[i] == '@')count++;
    }
    if(count == 1)fr <<"TAIP";
    else fr <<"NE";
  
    return 0;
}
