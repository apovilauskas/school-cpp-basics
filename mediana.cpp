#include <bits/stdc++.h>

void skaityti(std::vector<int> &s)
{
std::ifstream fd("U1.txt");
int i;
while(fd >> i){
s.push_back(i);
}

}

int mediana(std::vector<int> s){
    int median;
    std::sort(s.begin(), s.end());
    if(s.size()%2==0) median = (s[s.size()/2]+s[s.size()/2-1])/2;
    else median = s[s.size()/2];
    return median;
}

int main() {
    
    std::ofstream fr("U1rez.txt");
    
    std::vector<int> skaiciai;
    skaityti(skaiciai);
   fr<< mediana(skaiciai);

    return 0;
}