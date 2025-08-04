#include <bits/stdc++.h>

struct preke {
	std::string pav;
	int kiekis;

};

int main()
{
	std::ifstream fd("prekes.txt");
	std::ifstream fk("tiekejai.txt");
	std::ofstream fr("rez.txt");

	std::vector<preke> p;

	std::string temppav;
	int tempkiekis;
	while(std::getline(fd, temppav, ';')) {
		fd >> tempkiekis;
		p.push_back({temppav, tempkiekis});
		fd.ignore(800, '\n');
	}
	while(std::getline(fk, temppav, ';')) {
		fk >> tempkiekis;
		p.push_back({temppav, tempkiekis});
		fk.ignore(800, '\n');
	}

	for(int i=0; i<p.size(); i++) {
		for(int j=0; j<p.size()-1; j++) {
			if(p[j].pav > p[j+1].pav)std::swap(p[j], p[j+1]);
		}
	}

	std::vector<preke> tinkami;
	tinkami.push_back(p[0]);
	for(int i=1; i<p.size(); i++) {
		if(p[i].pav != p[i-1].pav) {
			tinkami.push_back(p[i]);
		}
		else tinkami.back().kiekis += p[i].kiekis;
	}

	for(int i=0; i<tinkami.size(); i++) {
		fr << tinkami[i].pav << ' ' <<tinkami[i].kiekis <<'\n';
	}

	return 0;
}
