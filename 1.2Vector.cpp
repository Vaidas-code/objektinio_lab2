#include "vector.lib.h"


int main() {
  vector<int> paz {2,3,8,10, 10};
  studentas t1;
    t1.setVardas("StudentoV1");
    t1.setPavarde("StudentoP1");
    t1.setPazymiai(paz);
	t1.setEgzaminas(10);
    t1.aver();
    t1.medi();
  cout << "t1: \n" << t1 << endl;

  // Kopijavimo konstruktorius
  studentas t2(t1);
  cout << "t2: \n" << t2 << endl;

  // Kopijavimo priskyrimas
  studentas t3;
  cout << "tuscias t3: \n" << t3 << endl;
  t3 = t2;
  cout << "t2 prilygintas t3: \n" << t3 << endl;

  // Move konstruktorius
  studentas t4;
    t4.setVardas("StudetoV2");
    t4.setPavarde("StudentoP2");
    t4.setPazymiai(paz);
	t4.setEgzaminas(10);
    t4.aver();
    t4.medi();
  cout << "t4: \n" << t4 << endl;

  // Move priskyrimas
  studentas t5 = std::move(t4);
    t5.setPazymiai(paz);
    t5.aver();
    t5.medi();
  cout << "t5: \n" << t5 << endl;

	char tikr, tikr1;
	cout << "Ar norite sugeneruoti faila arba ji skaityti? Jei taip iveskite 't':" << endl;
	cin >> tikr1;
	if (tikr1 != 't' && tikr1 != 'T')
	{
		cout << "Ar norite kad duomenys butu skaitomi is failo? Jei taip iveskite 'y':" << endl;
		cin >> tikr;
		if (tikr == 'y' || tikr == 'Y')
		{
			int kiekis = 0;
			vector <studentas> mas;
			studentas tempas;
			skait(tempas, kiekis, mas, "kursiokai1.txt");
			sort(mas.begin(), mas.end(), palyginti_vardus);
			cout << "Vardas" << setw(20) << "Pavarde " << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
			cout << "-----------------------------------------------------------" << endl;
			for (auto& i : mas) spausd(i);
			for (auto& i : mas) i.getPazymiai().clear();
		}
		else
		{
			vector <studentas> mas;
			studentas tempas;
			char uzkl = 'n';
			do {
				pild(tempas);
				mas.push_back(tempas);
				tempas.getPazymiai().clear();
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
				for (auto& i : mas) i.getPazymiai().clear();
			}
		}
	}
	else {
		vector <studentas> mas;
		studentas tempas;
		sukurti1(tempas, mas);
	}
	cout << endl;
}


