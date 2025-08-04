#include <bits/stdc++.h>
 
struct sportininkas
{
    std::string vardas;
    std::string pavarde;
    int startonr;
    int laikas;
    int baudossekundes;
    int galutinis()
    {
        return laikas + baudossekundes;
    }
};
 
void skaityti(std::string &antraste, std::vector<sportininkas> &s)
{
    std::ifstream fd("Sportininkai.csv");
    std::getline(fd, antraste, '\n' );
 
    std::string t1, t2;
    int t3,t4,t5;
    char skyriklis;
    while(std::getline(fd, t1, ','))
    {
        std::getline(fd, t2, ',');
        fd >> t3 >>skyriklis >> t4 >>skyriklis >> t5;
        fd.ignore(80, '\n');
        s.push_back({t1,t2,t3,t4,t5});
    }
    fd.close();
}
 
void rikiuoti(std::vector<sportininkas> &s)
{
    for(int i=0; i<s.size(); i++)
    {
        for(int j=0; j<s.size()-1; j++)
        {
            if(s[j].galutinis()>s[j+1].galutinis())std::swap(s[j], s[j+1]);
        }
    }
 
}
 
void rasyti(std::string &antraste, std::vector<sportininkas> &s)
{
    std::ofstream fr("Rezultatai.csv");
    fr << antraste <<'\n';
    for(int i=0; i<s.size(); i++)
    {
        fr << s[i].pavarde <<','<< s[i].galutinis() << '\n';
    }
    fr.close();
}
 
int main()
{
    std::string antraste;
    std::vector<sportininkas> s;
    skaityti(antraste, s);
    rikiuoti(s);
    rasyti(antraste, s);
 
 
    return 0;
}
