#include <bits/stdc++.h>

struct ukininkas {
	std::string vardas;
	int du;
	int vienas;

};

struct pirkejas {

	std::string vardas;
	int kg;
};

void skaityti(std::vector<pirkejas> &p, std::vector<ukininkas> &u, int &np, int &nu) {
	std::ifstream fd("Z1.txt");
	fd >> np;
	fd.ignore(80,'\n');

	p.resize(np);
	for(int i=0; i<np; i++) {
		char vardas[21];
		fd.get(vardas, 21);
		p[i].vardas = vardas;
		fd >> p[i].kg;
		fd.ignore(80,'\n');
	}
	fd >> nu;
	fd.ignore(80,'\n');
	u.resize(nu);
	for(int i=0; i<nu; i++) {
		char vardas[21];
		fd.get(vardas, 21);
		u[i].vardas = vardas;
		fd >> u[i].vienas;
		fd >> u[i].du;
		fd.ignore(80,'\n');
	}


}

void kiekreikia(std::vector<pirkejas> &p, std::ofstream &fr) {
	int du=0;
	int vienas=0;

	for(int i=0; i<p.size(); i++) {
		du+= p[i].kg/2;
		vienas += p[i].kg%2;
	}

	fr << vienas << ' ' <<du <<'\n';

}

void siulo(std::vector<ukininkas> &u, std::ofstream &fr) {
	int du=0;
	int vienas=0;

	for(int i=0; i<u.size(); i++) {
		du+= u[i].du;
		vienas += u[i].vienas;
	}

	fr << vienas << ' ' <<du <<'\n';

}

void gaus(std::vector<pirkejas> &p, std::vector<ukininkas> &u, std::ofstream &fr) {
	int po2=0, po1=0;
	int turim=0;
	int reikia=0;

	for (int i = 0; i < p.size(); i++) {
		fr << p[i].vardas << " " << p[i].kg << " ";
		int like = p[i].kg;
		int gaus2 = 0, gaus1 = 0;

		for (int j = 0; j < u.size(); j++) {
			if (like >= 2 && u[j].du > 0) {
				int kiek2 = std::min(like / 2, u[j].du);
				gaus2 += kiek2;
				like -= kiek2 * 2;
				u[j].du -= kiek2;
			}
		}

		for (int j = 0; j < u.size(); j++) {
			if (like > 0 && u[j].vienas > 0) {
				int kiek1 = std::min(like, u[j].vienas);
				gaus1 += kiek1;
				like -= kiek1;
				u[j].vienas -= kiek1;
			}
		}

		fr << gaus1 << " " << gaus2 << '\n';
	}

	for(int i=0; i<u.size(); i++) {
		fr << u[i].vardas << ' ' << u[i].vienas << ' ' <<u[i].du <<'\n';
	}


}


void rasyti(std::vector<pirkejas> &p, std::vector<ukininkas> &u) {
	std::ofstream fr("Z1rez.txt");

	kiekreikia(p, fr);
	siulo(u, fr);
	gaus(p, u, fr);
}

int main()
{


	int np, nu; //pirkeju, ukininku
	std::vector<pirkejas> p;
	std::vector<ukininkas> u;

	skaityti(p, u, np, nu);
	rasyti(p, u);



	return 0;
}
