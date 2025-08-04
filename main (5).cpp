#include <bits/stdc++.h>

struct projektas {
	std::string pav;
	int balu=0;
	int desimtuku=0;

};

void skaityti(std::vector<projektas> &p) {
	std::ifstream fd("balsavimas.csv");

	projektas temp;
	std::string antraste, vardas;

	std::getline(fd, antraste, '\n');
	while(std::getline(fd, vardas, ';')) {
		std::getline(fd, temp.pav, ';');
		fd >> temp.balu >>std::ws;
		if(temp.balu == 10)temp.desimtuku=1;
		p.push_back(temp);
	}



}

void balai(    std::vector<projektas> &p,
               std::vector<projektas> &tinka) {

	for(int i=0; i<p.size(); i++) {
		for(int j=0; j<p.size()-1; j++) {
			if(p[j].pav > p[j+1].pav)std::swap(p[j], p[j+1]);
		}
	}


	tinka.push_back(p[0]);

	for(int i=1; i<p.size(); i++) {
		if(p[i].pav != p[i-1].pav)tinka.push_back(p[i]);
		else {
			tinka.back().balu += p[i].balu;
			tinka.back().desimtuku += p[i].desimtuku;
		}
	}

	for(int i=0; i<tinka.size(); i++) {
		for(int j=0; j<tinka.size()-1; j++) {
			if(tinka[j].balu < tinka[j+1].balu)std::swap(tinka[j], tinka[j+1]);
		}
	}
}

void daugiausia10(std::vector<projektas> tinka,
                  std::vector<std::string> &daugiausia) {

	int maxx=INT_MIN;
	for(int i=0; i<tinka.size(); i++) {
		if(tinka[i].desimtuku > maxx)maxx = tinka[i].desimtuku;
	}

	for(int i=0; i<tinka.size(); i++) {
		if(tinka[i].desimtuku == maxx)daugiausia.push_back(tinka[i].pav);
	}

	for(int i=0; i<daugiausia.size(); i++) {
		for(int j=0; j<daugiausia.size()-1; j++) {
			if(daugiausia[j] >daugiausia[j+1])std::swap(daugiausia[j], daugiausia[j+1]);
		}
	}
}

void daugiausiabalu(std::ofstream &fr, std::vector<projektas>tinka) {
	int maxx=INT_MIN;
	std::string maxi;
	int desimt;
	for(int i=0; i<tinka.size(); i++) {
		if(tinka[i].balu > maxx) {
			maxx = tinka[i].balu;
			maxi = tinka[i].pav;
			desimt = tinka[i].desimtuku;
		}
	}

	fr << maxi << ' ' <<maxx<<'\n';
	fr <<"10 balu jis gavo " << desimt << " kartu \n";

}

int visibalai(std::vector<projektas> tinka){
    
    int count=0;
    for(int i=0; i<tinka.size(); i++){
        count += tinka[i].balu;
    }
    return count;
}

void rasyti(std::vector<projektas> tinka, std::vector<std::string> daugiausia) {
	std::ofstream fr("rezultatai.txt");
	fr <<"Projektai ir taskai mazejimo tvarka\n";
	for(int i=0; i<tinka.size(); i++) {
		fr << tinka[i].pav << ' ' <<tinka[i].balu <<'\n';
	}
	fr << "\nDaugiausia desimtu turintys projektai:\n";
	for(int i=0; i<daugiausia.size(); i++) {
		fr <<daugiausia[i] <<'\n';
	}
	fr <<"\nDaugiausia balu is viso gavo\n";
	daugiausiabalu(fr, tinka);

    fr << "\nBendri balai "<<visibalai(tinka);
}

int main()
{



	std::vector<projektas> p;
	std::vector<projektas> tinka;
	std::vector<std::string> daugiausia;
	skaityti(p);
	balai(p, tinka);
	daugiausia10(tinka, daugiausia);
    rasyti(tinka, daugiausia);



	return 0;
}






