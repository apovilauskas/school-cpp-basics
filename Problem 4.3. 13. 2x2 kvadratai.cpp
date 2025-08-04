//reikia pasakyti, ar lenteleje yra bent vienas 2x2 kvadratas kurio elementu suma butu pirminis skaicius
#include <bits/stdc++.h>

void skaitymas(int &y, int &x, std::vector<std::vector<int>> &lenta) {
	std::ifstream fd("U1.txt");
	fd >> y >> x;
	lenta.resize(y, std::vector<int> (x));

	for(int i=0; i<y; i++) {
		for(int j=0; j<x; j++) {
			fd >> lenta[i][j];
		}
	}
}
bool pirminis(int sk) {
    if(sk <2) return 0;
	for(int i=2; i<sqrt(sk) +1; i++) {
		if(sk%i == 0)return 0;
	}
	return 1;
}

bool kvadratusumos(std::vector<std::vector<int>> &lenta) {
	bool yes = 0;
	for(int i=0; i<lenta.size()-1; i++) {
		for(int j=0; j<lenta[i].size()-1; j++) {
			int skaicius = lenta[i][j]+lenta[i+1][j]+lenta[i][j+1]+lenta[i+1][j+1];
			if(pirminis(skaicius) == 1) yes = 1;
		}
	}
	return yes;
}



int main()
{

	std::ofstream fr("U1rez.txt");

	int y,x;
	std::vector<std::vector<int>> lenta;
	
	skaitymas(y, x, lenta);
	
	if(kvadratusumos(lenta) == 1) fr <<"YES";
	else fr << "NO";

	return 0;
}
