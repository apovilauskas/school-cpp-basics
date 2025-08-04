#include <bits/stdc++.h>

void skaitymas(int &n, int &k, std::vector<std::vector<int>> &a) {
	std::ifstream fd("U1.txt");
	fd >> n >> k;
	a.resize(n, std::vector<int> (k));
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[i].size(); j++) {
			fd >> a[i][j] ;
		}
	}
}

int maxradimas(int &k, std::vector<std::vector<int>> &a) {

	int did = a[0][0];
	did = std::max(did, a[0][a[0].size()-1]);
	did = std::max(did, a[a.size()-1][0]);
	did = std::max(did, a[a.size()-1][a[0].size()-1]);


	return did;

}

void rasymas(int &k, std::vector<std::vector<int>> &a) {
	std::ofstream fr("U1rez.txt");
	if(maxradimas(k, a) == INT_MIN) fr << "NO";
	else fr << maxradimas(k, a);
}

int main()
{
	int n, k;
	std::vector<std::vector<int>> a;
	skaitymas(n, k, a);
	rasymas(k, a);

	return 0;
}
