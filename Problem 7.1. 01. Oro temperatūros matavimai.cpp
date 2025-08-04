#include <bits/stdc++.h>

struct menuo {
	std::string pav;
	std::vector<double> temp;

};

double vidurkis(menuo a){
    	double suma=0;
	for(int i=0; i<a.temp.size(); i++) {
		suma+= a.temp[i];
	}
	suma /= a.temp.size();
	return  suma;
}

int main()
{
	std::ifstream fd("Duomenys.txt");
	std::ofstream fr("rez.txt");


//skaitymas
	int n, k;
	fd >> n >> k;
	std::vector<menuo> m;
	m.resize(n);
	menuo bendri;
	for(int i=0; i<n; i++) {
		m[i].temp.resize(k);
		fd >> m[i].pav;
		for(int j=0; j<k; j++) {
			fd >> m[i].temp[j];
			bendri.temp.push_back(m[i].temp[j]) ;
		}

	}
//rasymas	
	for(int i=0; i<m.size(); i++){
	    fr << m[i].pav << ' ' << std::fixed << std::setprecision(2) << vidurkis(m[i]) <<'\n';
	}
    fr << "Bendras matavimų vidurkis: " <<std::fixed << std::setprecision(2) << vidurkis(bendri);


	return 0;
}
