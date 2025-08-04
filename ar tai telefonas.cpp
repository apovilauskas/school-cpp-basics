#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    std::string n;
    fd >> n;
    
    int tinka = 1;
    if(n.size() != 12)tinka = 0;
    if(n.substr(0,3) == "+370"){
        for(int i=4; i<n.size(); i++){
            if(!isdigit(n[i]))tinka =0;
        }
    }
    if(tinka == 0) fr << "NE";
    else fr << "TAIP";
    
    return 0;
}
