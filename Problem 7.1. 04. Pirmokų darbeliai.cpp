#include <bits/stdc++.h>

struct vaikas {
	std::string vardas;
	std::vector<int> k;

};



void skaityti(int &n, int &m, std::vector<vaikas> &v) {
	std::ifstream fd("Duomenys.txt");
    fd >> n >> m;
    fd.ignore(80, '\n');
    
    v.resize(n);
    for(int i=0; i<n; i++){
        v[i].k.resize(m);
        char temp[16];
        fd.get(temp, 16);
        v[i].vardas = temp;
        for(int j=0; j<m; j++){
            int temp;
            fd >> temp;
            v[i].k[temp-1]++; 
        }
        fd.ignore(80, '\n');
    }

}

void rasyti(std::vector<vaikas> &v) {
	std::ofstream fr("Rezultatai.txt");
    for(int i=0; i<v.size(); i++){
        fr << v[i].vardas;
        for(int j=0; j<v[i].k.size(); j++){
            fr<< ' ' <<v[i].k[j] ;
        }
        fr <<'\n';
    }
}

int main()
{
    int n,m;
    std::vector<vaikas> v;
	skaityti(n,m,v);
	rasyti(v);
	
	

	return 0;
}
