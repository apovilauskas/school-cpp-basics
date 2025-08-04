#include <bits/stdc++.h>

struct figura {
	int x1, y1, x2, y2;
};

void skaityti(std::vector<figura> &f, int &n) {
	std::ifstream fd("U1.txt");
	fd >> n;
	f.resize(n);

	for(int i=0; i<f.size(); i++) {
		fd >> f[i].x1 >> f[i].y1 >> f[i].x2 >> f[i].y2;
	}
}

int main()
{

	std::ofstream fr("U1rez.txt");

	int n;
	std::vector<figura> f;

    skaityti(f, n);


	std::vector<std::vector<figura>> sarasai;
	sarasai.resize(n, std::vector<figura> (0));
	for(int i=0; i<f.size(); i++) {
		sarasai[i].push_back(f[i]);
		for(int j=0; j<f.size(); j++) {
			if(i == j)continue;
			else {
				if(f[j].x1 >= f[i].x1 && f[j].y1 >= f[i].y1 && f[j].x1 <= f[i].x2 && f[j].y1 <= f[i].y2) {
					sarasai[i].push_back(f[j]);
				}

			}

		}

	}
	std::vector<figura> persidengimai;

	for(int i=0 ; i<sarasai.size(); i++) {
		int x1=INT_MIN, y1=INT_MIN, x2=INT_MAX, y2=INT_MAX;
		if(sarasai[i].size() == 1)continue;
		for(int j=0; j<sarasai[i].size(); j++) {
			if(sarasai[i][j].x1 > x1)x1 = sarasai[i][j].x1;
			if(sarasai[i][j].x2 < x2)x2 = sarasai[i][j].x2;
			if(sarasai[i][j].y1 > y1)y1 = sarasai[i][j].y1;
			if(sarasai[i][j].y2 < y2)y2 = sarasai[i][j].y2;

		}
		if(y1 != y2 && x1 !=x2) persidengimai.push_back({x1, y1, x2, y2});

	}

	for(int i=0; i<persidengimai.size(); i++) {
		fr << persidengimai[i].x1<< ' ' <<persidengimai[i].y1<<' ' << persidengimai[i].x2<<' ' << persidengimai[i].y2 <<'\n';
	}


	return 0;
}
