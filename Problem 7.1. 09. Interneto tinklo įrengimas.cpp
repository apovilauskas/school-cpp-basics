#include <bits/stdc++.h>

struct namas {
	int x, y;

};

void skaityti(std::vector<namas> &n, int &m) {
	std::ifstream fd("U1.txt");
	std::cin >> m;
	n.resize(m);
	for(int i=0; i<m; i++) {
	std::cin >> n[i]. x >> n[i].y;
	}
}

int mediana(std::vector<namas> &n){
    for(int i=0; i<n.size(); i++){
        for(int j=0; j<n.size()-1; j++){
            if(n[j].y < n[j+1].y)std::swap(n[j], n[j+1]);
        }
    }
    int mediana;
    if(n.size()%2 != 0)mediana= n[n.size()/2].y;
    else mediana = std::min(n[n.size()/2].y, n[n.size()/2-1].y);
    return mediana;
    
}

int skaiciuoti(std::vector<namas> &n){
    
      
    int minx=INT_MAX, maxx=INT_MIN;
    for(int i=0; i<n.size(); i++) {
		if( n[i]. x > maxx) maxx = n[i].x;
		if( n[i]. x < minx) minx = n[i].x;
		
	}
	
    int ilgis = maxx-minx;
    
    int med = mediana(n);
    for(int i=0; i<n.size(); i++){
        ilgis += abs(med-n[i].y);
    }
    
    
   return ilgis;
}



int main()
{

	std::ofstream fr("U1rez.txt");

	int m;
	std::vector<namas> n;
    skaityti(n, m);

 std::cout << skaiciuoti(n);
	
	
    
	return 0;
}
