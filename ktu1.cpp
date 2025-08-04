#include <bits/stdc++.h>

struct pc
{
    std::string brand;
    std::string tipas;
    double kaina;
};

void skaityti(std::vector<pc> &p)
{
    std::ifstream fd("Duomenys.txt");

    pc temp;
    char tempp[9];
    while (fd.get(tempp, 9))
    {
        temp.brand = tempp;
        fd >> temp.tipas >> temp.kaina;
        fd.ignore(80, '\n');
        p.push_back(temp);
    }
}

void rikiuoti(std::vector<pc> &p)
{

    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p.size() - 1; j++)
        {
            if (p[j].kaina < p[j + 1].kaina)
                std::swap(p[j], p[j + 1]);
            if (p[j].kaina == p[j + 1].kaina && p[j].tipas > p[j + 1].tipas)
                std::swap(p[j], p[j + 1]);
        }
    }
}

void atrinkti(std::vector<pc> &p)
{
    std::vector<pc> tinka;
    double riba = p[0].kaina * 0.85;
    tinka.push_back(p[0]);
    for (int i = 1; i < p.size(); i++)
    {
        if (p[i].kaina < riba)
        {
            break;
        }
        tinka.push_back(p[i]);
    }
    p = tinka;
}

void rasyti(std::vector<pc> p)
{
    std::ofstream fr("Rezultatai.txt");

    for (int i = 0; i < p.size(); i++)
    {
        fr << p[i].brand << ' ' << p[i].kaina << ' ' << p[i].tipas << '\n';
    }
}

int main()
{
    std::vector<pc> p;
    skaityti(p);
    rikiuoti(p);
    atrinkti(p);
    rasyti(p);

    return 0;
}
