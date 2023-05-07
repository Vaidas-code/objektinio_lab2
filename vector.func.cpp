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

     // kopijavimo konstruktorius
    studentas(const studentas& kitas) {
        vardas = kitas.vardas;
        pavarde = kitas.pavarde;
        paz = kitas.paz;
        egz = kitas.egz;
        vid = kitas.vid;
        med = kitas.med;
    }

    // kopijavimo priskyrimas
    studentas& operator=(const studentas& kitas) {
        if (this != &kitas) {
            vardas = kitas.vardas;
            pavarde = kitas.pavarde;
            paz = kitas.paz;
            egz = kitas.egz;
            vid = kitas.vid;
            med = kitas.med;
        }
        return *this;
    }

    // move konstruktorius
    studentas(studentas&& kitas) noexcept {
        vardas = std::move(kitas.vardas);
        pavarde = std::move(kitas.pavarde);
        paz = std::move(kitas.paz);
        egz = kitas.egz;
        vid = kitas.vid;
        med = kitas.med;
    }

    // move priskyrimas
    studentas& operator=(studentas&& kitas) noexcept {
        if (this != &kitas) {
            vardas = std::move(kitas.vardas);
            pavarde = std::move(kitas.pavarde);
            paz = std::move(kitas.paz);
            egz = kitas.egz;
            vid = kitas.vid;
            med = kitas.med;
        }
        return *this;
    }

    // Output funkcija
    friend std::ostream& operator<<(std::ostream& os, const studentas& stud) {
    os << std::left << std::setw(20) << stud.getVardas()
       << std::setw(20) << stud.getPavarde()
       << std::setw(6) << std::fixed << std::setprecision(2) << stud.getGalutinis()
       << std::setw(6) << std::fixed << std::setprecision(2) << stud.getMediana() << '\n';
    return os;
}


    void aver();
    void medi();

};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b);
void skait(studentas& tempas, int kiekis, vector<studentas>& mas, string pav);
void pild(studentas& tempas);
void spausd(studentas& tempas);
void sukurti1(studentas& tempas, vector<studentas>& mas);
bool palyginti_galutinius(const studentas& a, const studentas& b);
void fgeneravimas(int kiekis, string failovardas, double& laikas, bool genl);
bool egzistuojantis(const string& filename);