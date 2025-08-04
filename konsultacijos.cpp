#include <bits/stdc++.h>

struct mokinys {

	std::string vardas;
	int trukme;
};

void skaityti(std::vector<mokinys> &m, int &n) {
	std::ifstream fd("U2.txt");
	fd >> n;
	fd.ignore(80, '\n');
	m.resize(n);

	char temp[21];
	int t1,t2,t3,t4;
	for(int i=0; i<n; i++) {
		fd.get(temp, 21);
		m[i].vardas = temp;
		fd >> t1 >> t2 >>t3 >>t4;
		m[i].trukme = (t3*60+t4)-(t1*60+t2);
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


}

void rasyti(std::vector<mokinys> &ilgiausi) {
	std::ofstream fr("U2rez.txt");
	for(int i=0; i<ilgiausi.size(); i++) {
		fr << ilgiausi[i].vardas << ' ' <<ilgiausi[i].trukme/60 <<' '<< ilgiausi[i].trukme%60 <<'\n';
	}

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
