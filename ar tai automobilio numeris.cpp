#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    std::string a;
    fd >> a;
    
    if(a.size()== 6 &&isupper(a[0]) && isupper(a[1]) && isupper(a[2]) && isdigit(a[3]) && isdigit(a[4]) && isdigit(a[5])) fr << "TAIP";
    
  else fr << "NE";
  
    return 0;
}
