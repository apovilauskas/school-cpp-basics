#include <bits/stdc++.h>

int main()
{
    std::ifstream fd("duom.txt");
    std::ofstream fr("rez.txt");
    int n;
    fd >> n;
   std::vector<int> p(n);
   int max1=INT_MIN, max2=INT_MIN, min1=INT_MAX, min2=INT_MAX;
   for(int i=0; i<n; i++){
       fd >> p[i];
       if(p[i] > max1){
          max2 = max1;
          max1 = p[i]; 
       } 
       else if(p[i] > max2){
           max2 = p[i];
       }
       else if(p[i] < min1){
          min2 = min1;
          min1 = p[i]; 
       } 
       else if(p[i] < min2){
           min2 = p[i];
       }
   }
   
   if(max1*max2 > min1*min2){
       fr << max1*max2;
   }
   else fr << min1*min2;
   
   
    return 0;
}
