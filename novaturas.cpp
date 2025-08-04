#include <bits/stdc++.h>

struct kelione
{
    std::string pav;
    int trukme;
    int kaina;
    int papildomai;
};

int suma(kelione k)
{
    return k.papildomai + k.kaina;
}

int trukme(int &dienu, int &truks)
{
    if (dienu == 0) return 0;
    return truks / dienu;
}


void skaityti(int &d1, int &d2, int &d3, std::vector<kelione> &k)
{
    std::ifstream fd("keliones_data.txt");
    fd >> d1 >> d2 >> d3;
    int n;
    fd >> n;
    k.resize(n);
    for (int i = 0; i < n; i++)
    {
        fd >> k[i].pav >> k[i].trukme >> k[i].kaina >> k[i].papildomai;
    }
}

void tinkamos(int draugas, std::vector<kelione> k, std::ofstream &fr, int &dienu, int &trukme)
{
    for (int i = 0; i < k.size(); i++)
    {
        if (suma(k[i]) <= draugas)
        {
            fr << k[i].pav << ' ' << k[i].trukme << ' ' << suma(k[i]) << '\n';
            dienu++;
            trukme += k[i].trukme;
        }
    }
}

bool tikrinimas(int &d1, int &d2, int &d3, kelione k)
{
    if (suma(k) < d1 && suma(k) < d2 && suma(k) < d3)
    {
        return 1;
    }
    return 0;
}

void rasyti(int &d1, int &d2, int &d3, std::vector<kelione> &k)
{
    std::ofstream fr("keliones_res.txt");
    int dienu = 0;
    int truks = 0;
    fr << "Pirmam draugui tinkamos keliones:\n";
    tinkamos(d1, k, fr, dienu, truks);
    fr << "Vidutine keliones trukme dienomis yra: " << trukme(dienu, truks) << '\n';

    dienu= 0;truks=0;
    fr << "Antram draugui tinkamos keliones:\n";
    tinkamos(d2, k, fr, dienu, truks);
    fr << "Vidutine keliones trukme dienomis yra: " << trukme(dienu, truks) << '\n';
dienu= 0;truks=0;
    fr << "Treciam draugui tinkamos keliones:\n";
    tinkamos(d3, k, fr, dienu, truks);
    fr << "Vidutine keliones trukme dienomis yra: " << trukme(dienu, truks) << '\n';

    truks = 0;
    dienu = 0;
    fr << "Visiems draugams tinkamos keliones:\n";
    for (int i = 0; i < k.size(); i++)
    {
        if (tikrinimas(d1, d2, d3, k[i]))
        {
            fr << k[i].pav << ' ' << k[i].trukme << ' ' << suma(k[i]) << '\n';
            truks += k[i].trukme; 
            dienu++;
        }
    }
    fr << "Vidutine keliones trukme dienomis yra: " <<trukme(dienu, truks) << '\n';
}

int main()
{

    int d1, d2, d3;
    std::vector<kelione> k;
    skaityti(d1, d2, d3, k);
    rasyti(d1, d2, d3, k);

    return 0;
}