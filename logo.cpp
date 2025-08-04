#include <bits/stdc++.h>

struct logo {
    int balsai = 0;  
    int t = 0;       
};

int main() {
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    int k;
    fd >> k; 
    
    std::vector<logo> lg(3);  
    int b1, b2, b3;
    
   
    for(int i = 0; i < k; i++) {
        fd >> b1 >> b2 >> b3;
        
        
        lg[0].balsai += b1;
        lg[1].balsai += b2;
        lg[2].balsai += b3;
        
        if(b1 == b2 && b2 == b3) {

            continue;
        }
        else if(b1 > b2 && b1 == b3) {
            lg[0].t += 2;
            lg[2].t += 2;
        }
        else if(b1 < b2 && b2 == b3) {
        
            lg[1].t += 2;
            lg[2].t += 2;
        }
        else if(b1 == b2 && b1 > b3) {
            
            lg[0].t += 2;
            lg[1].t += 2;
        }
        else if(b1 > b2 && b1 > b3) {
           
            lg[0].t += 4;
        }
        else if(b2 > b1 && b2 > b3) {
            
            lg[1].t += 4;
        }
        else if(b3 > b1 && b3 > b2) {
            
            lg[2].t += 4;
        }
    }
    fr << lg[0].balsai << ' ' << lg[1].balsai << ' ' << lg[2].balsai << '\n'; 
    fr << lg[0].t << ' ' << lg[1].t << ' ' << lg[2].t << '\n';
   
    fd >> b1 >> b2 >> b3;
    lg[0].t += b1;
    lg[1].t += b2;
    lg[2].t += b3;
    
   
    if(lg[0].t > lg[1].t && lg[0].t > lg[2].t) {
        fr << 1;
    }
    else if(lg[1].t > lg[0].t && lg[1].t > lg[2].t) {
        fr << 2;
    }
    else if(lg[2].t > lg[0].t && lg[2].t > lg[1].t) {
        fr << 3;
    }
    
    return 0;
}
