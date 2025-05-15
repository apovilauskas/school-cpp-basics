#include <bits/stdc++.h>

struct zmogus {
	std::string vardas;
	std::string kodas;
};

void skaityti(std::vector<zmogus> &mot, std::vector<zmogus> &vyr) {
	std::ifstream fd("data.csv");
	zmogus temp;
	while(std::getline(fd, temp.vardas, ',')) {
		char tempp[12];
		fd.get(tempp, 12);
		temp.kodas = tempp;
		fd >>std::ws;
		if(temp.kodas[0] % 2 == 0)mot.push_back(temp);
		else vyr.push_back(temp);
	}

}

void rikiuoti(std::vector<zmogus> &z) {
	for(int i=0; i<z.size(); i++) {
		for(int j=0; j<z.size()-1; j++) {
			if(z[j].kodas > z[j+1].kodas)std::swap(z[j],z[j+1]);
		}
	}


}

void rasyti(std::vector<zmogus> z, std::string lytis, std::ofstream &fr) {
	fr << lytis <<'\n';
	if(z.size()==0)fr <<"NERASTA\n";
	else {
		std::vector<int> s{1800, 1800, 1900, 1900, 2000, 2000};
		std::vector<std::string> menesiai = {
			"sausio", "vasario", "kovo", "balandzio",
			"geguzes", "birzelio", "liepos", "rugpjucio",
			"rugsejo", "spalio", "lapkricio", "gruodzio"
		};


		for(int i=0; i<z.size(); i++) {
			int simt = stoi(z[i].kodas.substr(0,1));
			int met = stoi(z[i].kodas.substr(1,2));
			int men = stoi(z[i].kodas.substr(3,2));
			int dien = stoi(z[i].kodas.substr(5,2));

			fr <<z[i].vardas <<',' << s[simt-1]+met << ',' << menesiai[men-1] << ',' << dien <<'\n' ;

		}





	}
}

int main()
{

	std::ofstream fr("rez.csv");
	std::vector<zmogus> mot;
	std::vector<zmogus> vyr;
	skaityti(mot, vyr);
	rikiuoti(mot);
	rikiuoti(vyr);
	rasyti(mot, "MOTERYS", fr);
	rasyti(vyr, "VYRAI", fr);


	return 0;
}
