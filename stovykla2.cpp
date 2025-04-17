#include <bits/stdc++.h>

struct mokinys {

	std::string vardas;
	double vidurkis;
	int desimtuku=0;
	
};

void skaityti(std::vector<mokinys> &m, int &n) {
	std::ifstream fd("input.txt");
	fd >> n;
	fd.ignore(80, '\n');
	m.resize(n);

	char temp[21];
	for(int i=0; i<n; i++) {
	    fd.get(temp, 21);
	    m[i].vardas = temp;
	    int k; //pazymiai
	    fd >> k;
	    int suma=0;
		for(int j=0; j<k; j++){
		    int temp;
		    fd >> temp;
		    suma+= temp;
		    if(temp == 10) m[i].desimtuku ++;
		}
		m[i].vidurkis = 1.00*suma/k;
		
		fd.ignore(80, '\n');
	}
}

void atranka(std::vector<mokinys> &geriausi, std::vector<mokinys> &m) {
	double max=0;
	for(int i=0; i<m.size(); i++) {
		if(m[i].vidurkis > max) max = m[i].vidurkis;
	}

	for(int i=0; i<m.size(); i++) {
		if(m[i].vidurkis == max) geriausi.push_back(m[i]);
	}
    
    for(int i=0; i<geriausi.size(); i++){
        for(int j=0; j<geriausi.size()-1; j++){
            if(geriausi[j].vidurkis == geriausi[j+1].vidurkis && geriausi[j].desimtuku < geriausi[j+1].desimtuku) std::swap(geriausi[j], geriausi[j+1]);
            else if(geriausi[j].vidurkis > geriausi[j+1].vidurkis)std::swap(geriausi[j], geriausi[j+1]);
            
            
        }
    }

}

void rasyti(std::vector<mokinys> &geriausi) {
	std::ofstream fr("output.txt");


		fr << geriausi[0].vardas << ' ' <<std::fixed << std::setprecision(1) << geriausi[0].vidurkis <<' '<<geriausi[0].desimtuku <<'\n';


}

int main()
{



	int n;
	std::vector<mokinys> m;

	skaityti(m, n);

	std::vector<mokinys> geriausi;
	atranka(geriausi, m);

	rasyti(geriausi);



	return 0;
}
