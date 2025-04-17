#include <bits/stdc++.h>

struct mokinys {

	std::string vardas;
	int trukme;
	int kl;
};

void skaityti(std::vector<mokinys> &m, int &n) {
	std::ifstream fd("input.txt");
	fd >> n;
	fd.ignore(80, '\n');
	m.resize(n);

	char temp[21];
	int t1,t2,t3,t4,kl;
	for(int i=0; i<n; i++) {
		fd.get(temp, 21);
		m[i].vardas = temp;
		fd >> t1 >> t2 >>t3 >>t4 >>kl;
		m[i].trukme = (t3*60+t4)-(t1*60+t2);
		m[i].kl = kl;
		fd.ignore(80, '\n');
	}
}

void maxtrukme(std::vector<mokinys> &ilgiausi, std::vector<mokinys> &m) {
	int max=0;
	for(int i=0; i<m.size(); i++) {
		if(m[i].trukme > max) max = m[i].trukme;
	}

	for(int i=0; i<m.size(); i++) {
		if(m[i].trukme == max) ilgiausi.push_back(m[i]);
	}
    
    for(int i=0; i<ilgiausi.size(); i++){
        for(int j=0; j<ilgiausi.size()-1; j++){
            if(ilgiausi[j].kl >ilgiausi[j+1].kl) std::swap(ilgiausi[j], ilgiausi[j+1]);
        }
    }

}

void rasyti(std::vector<mokinys> &ilgiausi) {
	std::ofstream fr("output.txt");


		fr << ilgiausi[0].vardas << ' ' <<ilgiausi[0].trukme/60 <<' '<< ilgiausi[0].trukme%60 <<' ' <<ilgiausi[0].kl <<'\n';


}

int main()
{



	int n;
	std::vector<mokinys> m;

	skaityti(m, n);

	std::vector<mokinys> ilgiausi;
	maxtrukme(ilgiausi, m);

	rasyti(ilgiausi);



	return 0;
}
