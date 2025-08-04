#include <bits/stdc++.h>

void skaitymas(int &n, int &m, std::vector<std::vector<int>> &lenta) {
	std::ifstream fd("U1.txt");
	fd >> n >> m;
	lenta.resize(n, std::vector<int> (m));

	for(int i=0; i<lenta.size(); i++) {
		for(int j=0; j<lenta[i].size(); j++) {
			fd >> lenta[i][j];
		}
	}
}

int mineilute(std::vector<std::vector<int>> &lenta) {
	int minsuma=INT_MAX;
	int suma=0;
	int index = -1;
	for(int i=0; i<lenta.size(); i++) {
		suma=0;
		for(int j=0; j<lenta[i].size(); j++) {
			suma+=lenta[i][j];
		}
		if(suma < minsuma) {
			minsuma=suma;
			index = i;
		}
	}

	return index;
}

int didziausias(std::vector<std::vector<int>> &lenta, int index) {
	int did = INT_MIN;
	for(int i=0; i<lenta.size(); i++) {
		for(int j=0; j<lenta[i].size(); j++) {
			if(i == index && lenta[i][j]>did) {
				did = lenta[i][j];
			}
		}
	}
	return did;
}

void rasymas(std::vector<std::vector<int>> &lenta, int &index) {
	std::ofstream fr("U1rez.txt");
	fr << didziausias(lenta, index);
}


int main()
{

	int n, m;
	std::vector<std::vector<int>> lenta;

	skaitymas(n, m, lenta);
	int index = mineilute(lenta);
	rasymas(lenta, index);

	return 0;
}
