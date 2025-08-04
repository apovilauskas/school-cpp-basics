#include <bits/stdc++.h>

struct zaidimas {
	std::string pav;
	std::string zanras;
	double reitingas;
	double kaina;
};

void skaityti(std::vector<zaidimas> &p) {
	std::ifstream fd("duom.txt");
	zaidimas temp;
	char tempa[26];
	while(fd.get(tempa, 26)) {
		temp.pav = tempa;
		fd.get(tempa, 16);
		temp.zanras = tempa;
		fd >> temp.reitingas >> temp.kaina;
		fd.ignore(80, '\n');
		p.push_back(temp);
	}
}

void didziausireitingai(std::vector<zaidimas> &maxr, std::vector<zaidimas> &p) {
	double maxreitingas = 0;
	for(int i=0; i<p.size(); i++) {
		if(p[i].reitingas > maxreitingas) maxreitingas=p[i].reitingas;
	}

	for(int i=0; i<p.size(); i++) {
		if(p[i].reitingas  == maxreitingas) maxr.push_back(p[i]);
	}

}

void rasymas(std::vector<zaidimas> &maxr, std::vector<zaidimas> &p) {
std::ofstream fr("rez.txt");
	for(int i=0; i<p.size(); i++) {
		fr << p[i].pav<<' ' << p[i].zanras << ' ' <<p[i].reitingas << ' ' <<p[i].kaina <<'\n';
	}

	fr<<"\nGeriausi reitingai:\n";
	for(int i=0; i<maxr.size(); i++) {
		fr << maxr[i].pav << ' ' <<p[i].zanras << ' ' <<maxr[i].reitingas << ' ' << maxr[i].kaina <<'\n';
	}
}

int main()
{

	

	std::vector<zaidimas> p;
	skaityti(p);
	std::vector<zaidimas> maxr;
	didziausireitingai(maxr, p);
	rasymas(maxr, p);




	return 0;
}
