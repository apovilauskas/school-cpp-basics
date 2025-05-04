#include <bits/stdc++.h>

int main()
{
	std::ifstream fd("U1.txt");
	std::ofstream fr("U1rez.txt");

	int n;
	fd >> n;

	std::vector<std::string> z;
	z.resize(n);

	for(int i=0; i<n; i++) {
		int temp;
		std::string zodis;
		fd >> temp >>zodis;

		z[i]=(zodis);

	}

	for(int i=0; i<z.size(); i++) {
		for(int j=0; j<z.size()-1; j++) {
			if(z[j].size() < z[j+1].size()) std::swap(z[j], z[j+1]);
		}
	}

	int maxx = 0;
	for(int i=0; i<z.size()-1; i++) {
		int streak = 0;
		for(int j = i+1; j<z.size(); j++) {
			for(int k=0; k<z[i].size(); k++) {
                std::string tmp = z[i];
				if(tmp.erase(k, 1) == z[j]) {
					streak ++;
					z[i].erase(k, 1);
					break;
				}
			}




		}
		if(streak > maxx) maxx = streak;
	}
	fr << maxx;


	return 0;
}
