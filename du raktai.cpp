#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Mokinys {
    std::vector<char> vardas;
    int suma = 0;
    double vidurkis = 0.0;
    bool ats =1;
};

void skaitymas(int mokiniu, int k, std::vector<Mokinys>& mok, int temp);
void rasymas(std::vector<Mokinys>& mok);
double vidurkis(int k, std::vector<Mokinys>& mok, int i);

int main() {
    int mokiniu;
    int temp;
    int k;
    std::vector<Mokinys> mok;

    skaitymas(mokiniu, k, mok, temp);
    rasymas(mok);

    return 0;
}

void skaitymas(int mokiniu, int k, std::vector<Mokinys>& mok, int temp) {
    std::ifstream fd("duom.txt");
    fd >> mokiniu >> k;

    mok.resize(mokiniu);
    for (int i = 0; i < mokiniu; i++) {
        char c;
        for (int m = 0; m < 20; m++) {
            fd.get(c);
            mok[i].vardas.push_back(c);
        }

        for (int j = 0; j < k; j++) {
            fd >> temp;
            if(temp <7) mok[i].ats = 0;
            mok[i].suma += temp;
        }
        
        vidurkis(k, mok, i);
    }
}

double vidurkis(int k, std::vector<Mokinys>& mok, int i) {
    mok[i].vidurkis = mok[i].suma / static_cast<double>(k);
    return mok[i].vidurkis;
}

void rasymas(std::vector<Mokinys>& mok) {
    std::ofstream fr("rez.txt");

    std::sort(mok.begin(), mok.end(), [](Mokinys &pirmas, Mokinys &antras) {
        if (pirmas.vidurkis == antras.vidurkis) return pirmas.vardas < antras.vardas;
        return pirmas.vidurkis > antras.vidurkis;
    });

    std::vector<Mokinys> virs;
    for (int i = 0; i < mok.size(); i++) {
        for (int m = 0; m < 20; m++) {
            fr << mok[i].vardas[m];
        }
        fr << mok[i].vidurkis << ' ';
    }
    fr <<"\n\nNeturi mazesniu nei 7-etas pazymiu: ";
    for(int i=0; i<mok.size(); i++){
        if(mok[i].ats == 1) {
            for(int h=0; h<20; h++){
                fr << mok[i].vardas[h];
            }
            fr << mok[i].vidurkis << ' ';
            
        }
    }
}
