#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("duom.txt");
    std::ofstream fr("rez.txt");
    int n;
    fd >> n;
    std::vector<int> p(11);
    int maxx=0;
    for(int i=0; i<n; i++){
        int temp;
        fd >> temp;
        p[temp]++;
        if (p[temp] >maxx) maxx = p[temp];
    }
    bool first = 0;
    for(int i=0; i<p.size(); i++){
        if(p[i] == maxx) {
                if(first == 0){
                fr << i;
                first = 1;
                }
                else fr << ',' << i;
        }
        
        
    }

    return 0;
}
