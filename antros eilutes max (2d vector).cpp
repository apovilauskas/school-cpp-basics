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

	int did = INT_MIN;
	
	for(int i=0; i<a.size(); i++){
	    for(int j=0; j<a[i].size(); j++){
	        if(i == 1){
	            if(a[i][j] > did) did = a[i][j];
	        }
	    }
	}
	


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
