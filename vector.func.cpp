#include "Vector.h"
#define _CRT_SECURE_NO_WARNINGS

class studentas {
public:
    string vardas, pavarde;
    int egz = 0;
    vector<int> paz;
    double vid, med;

    // pradinis konstruktorius
    studentas() {
        vardas = "";
        pavarde = "";
        egz = 0;
        paz.clear();
        vid = 0;
        med = 0;
    }

    // parametru konstruktorius
    studentas(string v, string p, int e, vector<int> pazymiai) {
        vardas = v;
        pavarde = p;
        egz = e;
        paz = pazymiai;
        vid = 0;
        med = 0;
    }
};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b);
void skait(studentas& tempas, int kiekis, vector<studentas>& mas, string pav);
void pild(studentas& tempas);
double vidurkis(const vector<int>& paz, studentas& tempas);
double mediana(vector<int>& paz, studentas& tempas);
void spausd(studentas& tempas);
void sukurti1(studentas& tempas, vector<studentas>& mas);
bool palyginti_galutinius(const studentas& a, const studentas& b);
void fgeneravimas(int kiekis, string failovardas, double& laikas, bool genl);
bool egzistuojantis(const string& filename);