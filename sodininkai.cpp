#include <bits/stdc++.h>

struct draugas {
    int x1, y1, x2, y2;
};


int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    std::vector<draugas> d;
    
    int x1,x2,y1,y2;
    while(fd >> x1){
        fd >> y1 >> x2 >>y2;
        d.push_back({x1,y1,x2,y2});
    }
    
    draugas keturkampis;
    int maxx1=INT_MIN, maxy1=INT_MIN, minx2=INT_MAX, miny2=INT_MAX;
    for(int i=0; i<d.size(); i++){
        if(d[i].x1 > maxx1)maxx1 = d[i].x1;
         if(d[i].x2 < minx2)minx2 = d[i].x2;
          if(d[i].y1 > maxy1)maxy1 = d[i].y1;
           if(d[i].y2 < miny2)miny2 = d[i].y2;
        
        
    }
    
    int ats = (miny2-maxy1)*(minx2-maxx1);
    fr << ats;
    
    

    return 0;
}
