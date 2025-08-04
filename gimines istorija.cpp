#include <bits/stdc++.h>

struct zmogus {
	std::string vardas;
	std::string kodas;
	int lytis() {
		return std::stoi(kodas.substr(0,1));
	}
	int metai() {
		return std::stoi(kodas.substr(1, 2));
	}
	int men() {
		return std::stoi(kodas.substr(3, 2));
	}
	int diena() {
		return std::stoi(kodas.substr(5,2));
	}
	int nr() {
		return std::stoi(kodas.substr(7,3));
	}
	int paskutinis() {
		return std::stoi(kodas.substr(10, 1));
	}
	int metudata() {
		int suma=metai();
		if(lytis() == 1)suma += 1800;
		if(lytis() == 2)suma += 1800;
		if(lytis() == 3)suma += 1900;
		if(lytis() == 4)suma += 1900;
		if(lytis() == 5)suma += 2000;
		if(lytis() == 6)suma += 2000;
		return suma;
	}
	std::string menesiopavadinimas() {
		std::vector<std::string> pavadinimai = {
			"sausio", "vasario", "kovo", "balandzio", "geguzes", "birzelio",
			"liepos", "rugpjucio", "rugsejo", "spalio", "lapkricio", "gruodzio"
		};
		return pavadinimai[men()-1];
	}

	int rikiavimoindeksas() {
		if(lytis()== 2)return 0;
		if(lytis()== 4)return 1;
		if(lytis()== 6)return 2;
		if(lytis()== 1)return 3;
		if(lytis()== 3)return 4;
		if(lytis()== 5)return 5;
		return -1;
	}

};

void rikiuoti(std::vector<zmogus> &z) {
	for(int i=0; i<z.size(); i++) {
		for(int j=0; j<z.size()-1; j++) {
			if(z[j].rikiavimoindeksas()>z[j+1].rikiavimoindeksas())std::swap(z[j],z[j+1]);
		}
	}
}

int main()
{
	std::ifstream fd("U1.txt");
	std::ofstream fr("U1rez.txt");

	std::vector<zmogus> z;

	std::string eilute;
	while(std::getline(fd, eilute, ',')) {
		std::string temp;
		fd >> temp;
		fd.ignore(80, '\n');
		z.push_back({eilute, temp});
	}

	rikiuoti(z);

	int pirmas=0;
	for(int i=0; i<z.size(); i++) {
		if(pirmas == 0 && z[i].lytis()%2 == 0) {
			fr <<"MOTERYS\n";
			pirmas = 1;
		}
		if(pirmas == 0) {
			fr<<"NERASTA\n";
			pirmas =1;
		}
		if((z[i].lytis() == 1 ||z[i].lytis() == 3 ||z[i].lytis() == 5) && pirmas == 1) {
			fr << "VYRAI\n";
			pirmas = 2;
		}
		fr << z[i].vardas << ',';
		fr << z[i].metudata() <<',';
		fr << z[i].menesiopavadinimas() << ',';
		fr << z[i].diena()<<'\n';
	}
	if(pirmas != 2) {
		fr << "NERASTA\n";
	}

	return 0;
}
