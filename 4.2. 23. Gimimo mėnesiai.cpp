#include <bits/stdc++.h>

int main()
{
	std::ifstream fd("duom.txt");
	std::ofstream fr("rez.txt");
	int n;
	fd >> n;
	std::vector<int> datos(13);
	int maxx = 0;
	for(int i=0; i<n; i++) {
		int metai, menuo, diena;
		fd >> metai >> menuo >>diena;
		datos[menuo]++;
		if(datos[menuo] > maxx) maxx = datos[menuo];
	}
	bool pirmas=0;
	for(int i=0; i<datos.size(); i++) {
		if(datos[i]== maxx) {
			if(pirmas == 0) {
				fr << i;
				pirmas = 1;
			}
			else {

				fr <<',' <<i;
			}
		}

	}

	return 0;
}
