#include "Vector.h"
#define _CRT_SECURE_NO_WARNINGS

class studentas{
private:
    string vardas, pavarde;
    vector<int> paz;
    double egz;
    double vid;
    double med;
public:
    studentas() = default;

    void setVardas(string vardas_) { vardas = vardas_; }
    void setPavarde(string pavarde_) { pavarde = pavarde_; }
    void setPazymiai(vector<int> paz_) { paz = paz_; }
    void setEgzaminas(double egz_) { egz = egz_; }
    void setGalutinis(double vid_) { vid = vid_; }
    void setMediana(double med_) { med = med_; }

    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getPazymiai() const { return paz; }
    double getEgzaminas() const { return egz; }
    double getGalutinis() const { return vid; }
    double getMediana() const { return med; }
    ~studentas () {paz.clear();}

	std::istream& readStudent(std::istream&);

    friend double average(const  studentas&);
    double median(const studentas& tempas);

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