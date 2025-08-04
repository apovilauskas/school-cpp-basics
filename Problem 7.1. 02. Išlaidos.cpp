#include <bits/stdc++.h>

struct degaline {
	std::string pav;
	double bk;
	double dk;
};

void skaitymas(std::vector<degaline> &deg, double &b, double &d, double &km, int &k) {
	std::ifstream fd("Duomenys.txt");
	fd >> b >> d >> km >> k;
	fd.ignore(80, '\n');
	deg.resize(k);

	for(int i=0; i<k; i++) {
		char temp[16];
		fd.get(temp, 16);
		deg[i].pav = temp;
		fd >> deg[i].bk >> deg[i].dk ;
		fd.ignore(80, '\n');
	}

}

int main()
{

	std::ofstream fr("Rezultatai.txt");

	double b, d, km; //benzo duju kainos ir keliones ilgis
	int k; //degaliniu

	std::vector<degaline> deg;
	skaitymas(deg, b, d, km, k);

	for(int i=0; i<deg.size(); i++) {
		fr << deg[i].pav << ' ' <<std::fixed << std::setprecision(2) <<deg[i].bk /100.0 * km*b <<' '<< std::fixed << std::setprecision(2) << deg[i].dk /100.0* km*d <<'\n';
	}



	return 0;
}
