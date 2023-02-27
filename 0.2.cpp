#include "Mylib.h"
const char FILENAME[] = "kursiokai.txt";

struct studentas {
	string vardas, pavarde;
	int egz = 0;
	vector<int> paz;

};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b) {
	return a.vardas < b.vardas;
}
//skaitymas is failo
void skait(studentas& tempas, int kiekis, vector<studentas>& mas) {
	string vardas, pavarde, tmp;
	int temp;
	ifstream inputFile(FILENAME);
	// read the first student's data
	inputFile >> vardas >> pavarde;
	while (inputFile >> tmp && tmp != "Egz.") {
		kiekis++;
	}
	while (!inputFile.eof()) {
		inputFile >> tempas.vardas >> tempas.pavarde;
		for (int i = 0; i < kiekis; i++) {
			inputFile >> temp;
			tempas.paz.push_back(temp);
		}
		inputFile >> tempas.egz;
		mas.push_back(tempas);
		tempas.paz.clear();
	}
}

// liepia ivesti varda, pavarde, egzamino ir namu darbu rezultatus
void pild(studentas& tempas) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> tempas.vardas >> tempas.pavarde;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10);
	cout << "Ar norite kad skaiciai butu generuojami? Jei taip, irasykite 'y'," << endl;
	cout << "jei ne, bet koki kita simboli ar skaiciu" << endl;
	char uzklausa;
	cin >> uzklausa;
	if (uzklausa == 'y' || uzklausa =='Y')
	{
		cout << "Iveskite kiek pazymiu norite sugeneruoti: " << endl;
		int p;
		cin >> p;
		while (cin.fail() || p < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti didesnis uz 0" << endl;
			cin >> p;
			tempas.paz.push_back(p);
		}
		for (int i = 0; i < p; i++) {
			tempas.paz.push_back(dist(gen));
		}
		tempas.egz = dist(gen);
	}
	else
	{
		int x;
		cout << "Iveskite pazymius, kai noresite baigti, parasykite raide arba skaiciu didesni uz 10: ";
		cin >> x;
		while (cin.fail() || x <= 0 || x > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti nuo 1-10" << endl;
			cin >> x;
			tempas.paz.push_back(x);
		}
		cin >> x;
		while (cin.fail() || x < 0 || x > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti nuo 1-10" << endl;
			cin >> x;
			tempas.paz.push_back(x);
		}
		while (cin >> x)
		{
			if (x <= 0 || x > 10)
			{
				break;
			}
			tempas.paz.push_back(x);
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Iveskite egzamino paz: ";
		cin >> tempas.egz;
		while (cin.fail() || tempas.egz < 0 || tempas.egz > 10) {
			cout << "Iveskite skaiciu nuo 1-10" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> tempas.egz;
		}
	}
}
// apskaiciuoja vidurki
double vidurkis(const vector<int>& paz, studentas& tempas) {
	double sum = accumulate(paz.begin(), paz.end(), 0);
	if (paz.size() > 0)
		return 0.4 * (sum / paz.size()) + 0.6 * tempas.egz;
	else
		return 0;
}

// apskaiciuoja mediana
double mediana(vector<int>& paz, studentas& tempas) {
	if (paz.size() != 0)
	{
		int n = paz.size();
		sort(paz.begin(), paz.end());
		if (n % 2 == 0) {
			return (double)0.4 * ((paz[n / 2 - 1] + paz[n / 2]) / 2) + 0.6 * tempas.egz;
		}
		else {
			return (double)0.4 * (paz[n / 2]) + 0.6 * tempas.egz;
		}
	}
	else
		return 0;
}
// ispausdina visus reikalingus duomenis
void spausd(studentas& tempas) {
	cout << left << setw(20) << tempas.vardas << setw(20) << tempas.pavarde;
	cout << setw(12) << fixed << setprecision(2) << vidurkis(tempas.paz, tempas);
	cout << setw(10) << fixed << setprecision(2) << mediana(tempas.paz, tempas) << endl;
}
int main() {
	char tikr;
	cout << "Ar norite kad duomenys butu skaitomi is failo? Jei taip iveskite 'y':" << endl;
		cin >> tikr;
	if (tikr == 'y' || tikr == 'Y')
	{
		int kiekis=0;
		vector <studentas> mas;
		studentas tempas;
		skait(tempas, kiekis, mas);
		sort(mas.begin(), mas.end(), palyginti_vardus);
		cout  << "Vardas" << setw(20) << "Pavarde " << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (auto& i : mas) spausd(i);
		for (auto& i : mas) i.paz.clear();
	}
	else
	{
		vector <studentas> mas;
		studentas tempas;
		char uzkl = 'n';
		do {
			pild(tempas);
			mas.push_back(tempas);
			tempas.paz.clear();
			cout << "Baigti darba spausk n, testi - bet koks klavisas: ";
			cin >> uzkl;
			if (uzkl == 'n' || uzkl == 'N')
			{
				cout << left << setw(10) << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}

		} while (uzkl != 'n' && uzkl != 'N');
		{
			for (auto& i : mas) spausd(i);
			for (auto& i : mas) i.paz.clear();
		}
	}

}


