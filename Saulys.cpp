#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("duom.txt");
    std::ofstream fr("rez.txt");
    int n;
    fd >> n;
    std::vector<int> a(10); //0-9
    for(int i=0; i<n; i++){
        int temp;
        fd >> temp;
        a[temp]++;
    }
    int max=0;
    for(int i=0; i<a.size(); i++){
        if(a[i] > max) max = a[i];
    }
    bool pirmas = 0;
    for(int i=0; i<a.size(); i++){
        if(pirmas ==0 && a[i] == max){
            fr <<i;
            pirmas =1;
        }
        else if(a[i] == max)  fr <<',' <<i;
    }
   
   
   
   
    return 0;
}
