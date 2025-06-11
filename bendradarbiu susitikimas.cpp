#include <bits/stdc++.h>

struct laikas {
	std::string diena;
	int valanda;
	std::vector<std::string> vardai;

};

void skaityti(std::vector<laikas> &laikai,
              std::vector<laikas> &zmones,
              int &d, int &n, int &k) {

	std::ifstream fd("U2.txt");
	fd >> d >> k;

	for(int i=0; i<d; i++) {
		std::string diena;
		int valanda;
		fd >> diena >> n;
		for(int j=0; j<n; j++) {
			fd >> valanda;
			laikai.push_back({diena, valanda});
		}
	}

	for(int i=0; i<k; i++) {
		laikas temp;
		int dienu;
		std::string vardas;
		fd >> vardas;
		temp.vardai.push_back(vardas);
		fd >> dienu;
		for(int j=0; j<dienu; j++) {
			fd >> temp.diena;
			fd >> temp.valanda;
			zmones.push_back({temp});
		}



	}


}

void bentketuri(std::vector<laikas> &laikai,
                std::vector<laikas> &zmones) {

	for(int i=0; i<laikai.size(); i++) {
		for(int j=0; j<zmones.size(); j++) {
			if(zmones[j].diena == laikai[i].diena && zmones[j].valanda == laikai[i].valanda) {
				laikai[i].vardai.push_back(zmones[j].vardai.back());
			}
		}
	}

	for(int i=0; i<laikai.size(); i++) {
		for(int j=0; j<laikai.size()-1; j++) {
			if(laikai[j].vardai.size() < laikai[j+1].vardai.size())std::swap(laikai[j], laikai[j+1]);
		}
	}

	for(int i=0; i<laikai.size(); i++) {
		for(int j=0; j<laikai[i].vardai.size(); j++) {
			for(int g=0; g<laikai[i].vardai.size()-1; g++) {
				if(laikai[i].vardai[g] > laikai[i].vardai[g+1])std::swap(laikai[i].vardai[g], laikai[i].vardai[g+1]);
			}
		}
	}


	std::vector<laikas> naujas;
	for(int i=0; i<laikai.size(); i++) {
		if(laikai[i].vardai.size() >= 4)naujas.push_back(laikai[i]);
	}

	laikai = naujas;
}

void rasyti(std::vector<laikas> laikai) {
	std::ofstream fr("U2rez.txt");
	for(int i=0; i<laikai.size(); i++) {
		fr << laikai[i].diena << ' ' <<laikai[i].valanda << ' '<< laikai[i].vardai.size() <<'\n';
		for(int j=0; j<laikai[i].vardai.size(); j++) {
			fr << laikai[i].vardai[j] << '\n';
		}

	}
	fr<<'\n';

}

int main() {


	std::vector<laikas> laikai;
	std::vector<laikas> zmones;
	int d, n, k;

	skaityti(laikai, zmones, d, n, k);
	bentketuri(laikai, zmones);
	rasyti(laikai);

	return 0;
}
