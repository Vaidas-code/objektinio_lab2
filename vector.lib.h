#pragma once
#ifndef HEADER_FILE_1_H
#define HEADER_FILE_1_H
#include "vector.func.cpp"

/*TEST_CASE("Addition Test") {
    int a = 2;
    int b = 3;
    int result = a + b;

    // Check if the addition is correct
    REQUIRE(result == 5);
}*/
void studentas::aver()
{
	double sum = accumulate(paz.begin(), paz.end(), 0);
	if (paz.size() > 0)
		vid = 0.4 * (sum / paz.size()) + 0.6 * getEgzaminas();
	else
		vid = 0;
}
void studentas::medi() {
    if (paz.size() != 0) {
        int n = paz.size();
        std::sort(paz.begin(), paz.end());

        if (n % 2 == 0) {
            med = (0.4 * (paz[n / 2 - 1] + paz[n / 2]) / 2) + (0.6 * getEgzaminas());
        }
        else {
            med = (0.4 * paz[n / 2]) + (0.6 * getEgzaminas());
        }
    }
    else {
        med = 0.0;
    }
}



// tikrina ar egzistuoja failas
bool egzistuojantis(const std::string& Filename)
{
	return access(Filename.c_str(), 0) == 0;
}

// generuoja pazymiu faila
void fgeneravimas(int kiekis, string failovardas, double& laikas, bool genl)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10);
    if (genl)
    {
        ofstream file1(failovardas);
        char buffer[200];
        sprintf_s(buffer, sizeof(buffer), "%-6s%-14s%-6s%-14s%-5s%-5s%-5s%-5s%-5s%-5s\n", "Vardas", "Nr.", "Pavarde", "Nr.", "ND1", "ND2", "ND3", "ND4", "ND5", "EGZ.");
        file1 << buffer;
        for (int i = 1; i < kiekis + 1; i++)
        {
            sprintf_s(buffer, sizeof(buffer), "%-6s%-14d%-6s%-14d", "Vardas", i, "Pavarde", i);
            for (int j = 0; j < 5; j++)
            {
                sprintf_s(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "%-5d", dist(gen));
            }
            sprintf_s(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "%-5d\n", dist(gen));
            file1 << buffer;
        }
        file1.close();
    }
    else
    {
        ofstream file1(failovardas);
        char buffer[200];
        sprintf_s(buffer, sizeof(buffer), "%-20s%-14s%-21s%-14s%-5s%-5s%-5s%-5s%-5s%-5s\n", "Vardas", "Nr.", "Pavarde", "Nr.", "ND1", "ND2", "ND3", "ND4", "ND5", "EGZ.");
        stringstream zod(buffer);
        for (int i = 1; i < kiekis + 1; i++)
        {
            sprintf_s(buffer, sizeof(buffer), "%-6s%-14d%-6s%-14d", "Vardas", i, "Pavarde", i);
            for (int j = 0; j < 5; j++)
            {
                sprintf_s(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "%-5d", dist(gen));
            }
            sprintf_s(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "%-5d\n", dist(gen));
            zod << buffer;
        }
        file1 << zod.str();
        file1.close();
    }
}

// palygina vardus
bool palyginti_vardus(const studentas& a, const studentas& b) {
	return a.getVardas() < b.getVardas();
}

// palygina galutinius pazymius
bool palyginti_galutinius(const studentas& a, const studentas& b) {
	return a.getGalutinis() > b.getGalutinis();
}

// apskaiciuoja vidurki
double vidurkis(const Vektorius<int>& paz, studentas& tempas) {
	double sum = accumulate(paz.begin(), paz.end(), 0);
	if (paz.size() > 0)
		return 0.4 * (sum / paz.size()) + 0.6 * tempas.getEgzaminas();
	else
		return 0;
}

// apskaiciuoja mediana
double mediana(Vektorius<int>& paz, studentas& tempas) {
	if (paz.size() != 0)
	{
		int n = paz.size();
		sort(paz.begin(), paz.end());
		if (n % 2 == 0) {
			return (double)0.4 * ((paz[n / 2 - 1] + paz[n / 2]) / 2) + 0.6 * tempas.getEgzaminas();
		}
		else {
			return (double)0.4 * (paz[n / 2]) + 0.6 * tempas.getEgzaminas();
		}
	}
	else
		return 0;
}

// ispausdina visus reikalingus duomenis
void spausd(studentas& tempas) {
	cout << left << setw(20) << tempas.getVardas() << setw(20) << tempas.getPavarde();
	cout << setw(12) << fixed << setprecision(2) << vidurkis(tempas.getPazymiai(), tempas);
	cout << setw(10) << fixed << setprecision(2) << mediana(tempas.getPazymiai(), tempas) << endl;
}

//skaitymas is failo
void skait(studentas& tempas, int kiekis, Vektorius<studentas>& mas, string pav) {
	string vardas, pavarde, tmp;
	string temp_vardas, temp_pavarde;
	int temp;
	ifstream inputFile(pav);
	try {
		if (!inputFile.is_open()) {
			throw runtime_error("Nepavyko atidaryti failo");
		}
		// read the first student's data
		inputFile >> vardas >> pavarde;
		string line;
		getline(inputFile, line);
		stringstream ss(line);
		string zodis;
		while (ss >> zodis) {
			kiekis++;
		}
		kiekis--;
		while (!inputFile.eof()) {
			inputFile >> temp_vardas >> temp_pavarde;
			tempas.setVardas(temp_vardas);
			tempas.setPavarde(temp_pavarde);
			for (int i = 0; i < kiekis; i++) {
				inputFile >> temp;
				tempas.getPazymiai().push_back(temp);
			}
			inputFile >> temp;
			tempas.setEgzaminas(temp);
			if (tempas.getPazymiai().size() != kiekis) {
				throw runtime_error("Klaidingas duomenu formatas: neteisingas elementu skaicius");
			}
			mas.push_back(tempas);
			tempas.getPazymiai().clear();
		}
	}
	catch (exception& e) {
		cout << "Klaida: " << e.what() << endl;
	}
	inputFile.close();
}

// liepia ivesti varda, pavarde, egzamino ir namu darbu rezultatus
void pild(studentas& tempas) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> tempas.getVardas() >> tempas.getPavarde();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10);
	cout << "Ar norite kad skaiciai butu generuojami? Jei taip, irasykite 'y'," << endl;
	cout << "jei ne, bet koki kita simboli ar skaiciu" << endl;
	char uzklausa;
	cin >> uzklausa;
	if (uzklausa == 'y' || uzklausa == 'Y')
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
			tempas.getPazymiai().push_back(p);
		}
		for (int i = 0; i < p; i++) {
			tempas.getPazymiai().push_back(dist(gen));
		}
		tempas.setEgzaminas(dist(gen));
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
			tempas.getPazymiai().push_back(x);
		}
		cin >> x;
		while (cin.fail() || x < 0 || x > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti nuo 1-10" << endl;
			cin >> x;
			tempas.getPazymiai().push_back(x);
		}
		while (cin >> x)
		{
			if (x <= 0 || x > 10)
			{
				break;
			}
			tempas.getPazymiai().push_back(x);
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Iveskite egzamino paz: ";
		    int egz_in;
            cin >> egz_in;
		while (cin.fail() || egz_in < 0 || egz_in > 10) {
			cout << "Iveskite skaiciu nuo 1-10" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> egz_in;
		}
		tempas.setEgzaminas(egz_in);
	}
}

void sukurti1(studentas& tempas, Vektorius<studentas>& mas) {
	int tikrinimas;
	string tikrinimas1, fvardas, tikrinimas3;
	bool baigimas = false;
	double laikas = 0;
	auto durationN = std::chrono::microseconds();
	auto durationR = std::chrono::microseconds();
	auto durationS = std::chrono::microseconds();
	Vektorius<studentas> pirmunai;
	Vektorius<studentas> abejingi;
	if (!egzistuojantis("sukurtas1000.txt") && !egzistuojantis("sukurtas10000.txt") && !egzistuojantis("sukurtas100000.txt") && !egzistuojantis("sukurtas1000000.txt") && !egzistuojantis("sukurtas1000000.txt"))
	{
		cout << "Failu nera, ar norite generuoti faila? Jei taip iveskite 1" << endl;
		cin >> tikrinimas3;
		if (tikrinimas3 == "1")
		{
			cout << "Iveskite kiek irasu norite sugeneruoti? Galima rinktis nuo 1-10000000, \n jei norite baigti iveskite 0" << endl;
			cin >> tikrinimas;
			ofstream file2("sukurtas2.txt");
			ofstream file3("sukurtas3.txt");
			file2 << "Pirmunai: " << endl;
			file3 << "Abejingi: " << endl;
			while (baigimas == false)
			{
				while (cin.fail() || tikrinimas <= 0 || tikrinimas > 10000000)
				{
					if (tikrinimas == 0)
						return;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Netinkamas skaicius, iveskite skaiciu nuo 1 iki  10000000" << endl;
					cin >> tikrinimas;
				}
				if (tikrinimas > 0 && tikrinimas <= 1000)
					fvardas = "sukurtas1000.txt";
				if (tikrinimas > 1000 && tikrinimas <= 10000)
					fvardas = "sukurtas10000.txt";
				if (tikrinimas > 10000 && tikrinimas <= 100000)
					fvardas = "sukurtas100000.txt";
				if (tikrinimas > 100000 && tikrinimas <= 1000000)
					fvardas = "sukurtas1000000.txt";
				if (tikrinimas > 1000000 && tikrinimas <= 10000000)
					fvardas = "sukurtas10000000.txt";
				fgeneravimas(tikrinimas, fvardas, laikas, false);
				ifstream rfile1(fvardas);
				string linija;
				getline(rfile1, linija);
				auto startN = std::chrono::high_resolution_clock::now();
				for (int i = 1; i < tikrinimas + 1; i++)
				{
					rfile1 >> tempas.getVardas() >> tempas.getPavarde();
					for (int j = 0; j < 5; j++)
					{
						int pazymys;
						rfile1 >> pazymys;
						tempas.getPazymiai().push_back(pazymys);
					}
					int egzaminas;
					rfile1 >> egzaminas;
					tempas.setEgzaminas(egzaminas);
					tempas.setMediana(mediana(tempas.getPazymiai(), tempas));
					tempas.setGalutinis(vidurkis(tempas.getPazymiai(), tempas));
					mas.push_back(tempas);
					tempas.getPazymiai().clear();
				}
				rfile1.close();
				auto endN = std::chrono::high_resolution_clock::now();
				durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
				auto startW = std::chrono::high_resolution_clock::now();
				sort(mas.begin(), mas.end(), palyginti_galutinius);
				auto endW = std::chrono::high_resolution_clock::now();
				durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
				auto startR = std::chrono::high_resolution_clock::now();
				for (auto& student : mas)
				{
					if (student.getGalutinis()>= 5)
					{
						//	pirmunai.push_back(move(student));
						pirmunai.push_back(student);
					}
					else
					{
						//abejingi.push_back(move(student));
						abejingi.push_back(student);
					}

				}
				mas.clear();
				auto endR = std::chrono::high_resolution_clock::now();
				durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
				for (auto pirm : pirmunai)
				{
					file2 << pirm;
				}
				for (auto abej : abejingi)
				{
					file3 << abej;
				}
				cout << "Jei norite baigti iveskite 0, jei ne bet koki kita skaiciu ar simboli" << endl;
				cin >> tikrinimas1;
				if (tikrinimas1 != "0")
				{
					cout << "Kiek dabar norite sugeneruoti irasu? ";
					cin >> tikrinimas;
				}
				else
				{
					baigimas = true;
				}
			}
			file2.close();
			file3.close();
			cout << endl;
			cout << left << "Tiek trunka failo nuskaitymas:                   " << durationN.count() / 1000000.0 << " seconds. " << endl;
			cout << left << "Tiek trunka studentu rusiavimas pagal vidurkius  " << durationS.count() / 1000000.0 << " seconds  " << endl;
			cout << left << "Tiek trunka pirmunu ir abejingu rusiavimas:      " << durationR.count() / 1000000.0 << " seconds. " << endl;
			cout << left << "Tiek trunka visa programa:                       " << durationN.count() / 1000000.0 + durationR.count() / 1000000.0 + durationS.count() / 1000000.0 << "seconds. " << endl;
		}

	}
	else
	{
		while (baigimas == false)
		{
			cout << "Iveskite kiek irasu norite sugeneruoti? Galima rinktis nuo 1-10000000, \n jei norite baigti iveskite 0" << endl;
			cin >> tikrinimas;
			ofstream file2("sukurtas2.txt");
			ofstream file3("sukurtas3.txt");
			file2 << "Pirmunai: " << endl;
			file3 << "Abejingi: " << endl;
			while (cin.fail() || tikrinimas <= 0 || tikrinimas > 10000000)
			{
				if (tikrinimas == 0)
					return;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Netinkamas skaicius, iveskite skaiciu nuo 1 iki  10000000" << endl;
				cin >> tikrinimas;
			}
			if (tikrinimas > 0 && tikrinimas <= 1000)
				fvardas = "sukurtas1000.txt";
			if (tikrinimas > 1000 && tikrinimas <= 10000)
				fvardas = "sukurtas10000.txt";
			if (tikrinimas > 10000 && tikrinimas <= 100000)
				fvardas = "sukurtas100000.txt";
			if (tikrinimas > 100000 && tikrinimas <= 1000000)
				fvardas = "sukurtas1000000.txt";
			if (tikrinimas > 1000000 && tikrinimas <= 10000000)
				fvardas = "sukurtas10000000.txt";
			if (!egzistuojantis(fvardas))
			{
				cout << "Tokio dydzio failo nera, jei norite ji sugeneruoti iveskite - 1 jei uzbaigti programa - bet koks simbolis" << endl;
				cin >> tikrinimas1;
				if (tikrinimas1 == "1")
				{
					fgeneravimas(tikrinimas, fvardas, laikas, true);
					ifstream rfile1(fvardas);
					string linija;
					getline(rfile1, linija);
					auto startN = std::chrono::high_resolution_clock::now();
					for (int i = 1; i < tikrinimas + 1; i++)
					{
						rfile1 >> tempas.getVardas() >> tempas.getPavarde();
						for (int j = 0; j < 5; j++)
						{
							int pazymys;
							rfile1 >> pazymys;
                            tempas.getPazymiai().push_back(pazymys);
						}
						int egzaminas;
						rfile1 >> egzaminas;
						tempas.setEgzaminas(egzaminas);
						tempas.setMediana(mediana(tempas.getPazymiai(), tempas));
						tempas.setGalutinis(vidurkis(tempas.getPazymiai(), tempas));
						mas.push_back(tempas);
						tempas.getPazymiai().clear();
					}
					rfile1.close();
					auto endN = std::chrono::high_resolution_clock::now();
					durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
					auto startW = std::chrono::high_resolution_clock::now();
					sort(mas.begin(), mas.end(), palyginti_galutinius);
					auto endW = std::chrono::high_resolution_clock::now();
					durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
					auto startR = std::chrono::high_resolution_clock::now();
					int strat;
					cout << "Kuria strategija norite naudoti? Jei pirmaja iveskite - 1, jei antraja - 2" << endl;
					cin >> strat;
					while (cin.fail() || strat != 1 && strat != 2) {
						cout << "Iveskite 1 arba 2" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> strat;
					}
					if (strat == 1)
					{
						auto startR = std::chrono::high_resolution_clock::now();
						for (auto& student : mas)
						{
							if (student.getGalutinis() >= 5)
							{
								pirmunai.push_back(student);
							}
							else
							{
								abejingi.push_back(student);
							}
						}
						mas.clear();
						auto endR = std::chrono::high_resolution_clock::now();
						durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
						for (auto pirm : pirmunai)
						{
			     			file2 << pirm;
						}
						for (auto abej : abejingi)
						{
							file3 << abej;
						}
					}
					else
					{
						auto startR = std::chrono::high_resolution_clock::now();
						auto partition_it = std::partition(mas.begin(), mas.end(),
							[](const auto& elem) { return elem.getGalutinis() < 5; });

						abejingi.insert(abejingi.end(), mas.begin(), partition_it);
						mas.erase(mas.begin(), partition_it);
						auto endR = std::chrono::high_resolution_clock::now();
						durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
						for (auto pirm : pirmunai)
						{
							file2 << pirm;
						}
						for (auto abej : abejingi)
						{
							file3 << abej;
						}
					}
					cout << "Jei norite baigti iveskite 0, jei ne bet koki kita skaiciu ar simboli" << endl;
					cin >> tikrinimas1;
					cout << endl;
					if (tikrinimas1 != "0")
					{
						cout << "Kiek dabar norite sugeneruoti irasu? ";
						cin >> tikrinimas;
					}
					else
					{
						baigimas = true;
					}
				}
				else
					return;
				file2.close();
				file3.close();
				cout << endl;
			}
			else
			{
				cout << "Tokio dydzio failas jau egzistuoja, jei norite ji perskaityti iveskite - 1, \n jei sugeneruoti is naujo - 2, jei uzbaigti programa - bet koks simbolis" << endl;
				cin >> tikrinimas1;
				if (tikrinimas1 == "1")
				{
					ifstream rfile1(fvardas);
					string linija;
					auto startN = std::chrono::high_resolution_clock::now();
					getline(rfile1, linija);
					string vard, pav;
					while (rfile1 >> vard >> pav)
					{
						tempas.setVardas(vard);
						tempas.setPavarde(pav);
						Vektorius<int> pazymys;
						for (int j = 0; j < 5; j++)
						{
							int paz;
							rfile1 >> paz;
							pazymys.push_back(paz);
						}
						tempas.setPazymiai(pazymys);
						int egzaminas;
						rfile1 >> egzaminas;
						tempas.setEgzaminas(egzaminas);
						tempas.medi();
						tempas.aver();
						mas.push_back(tempas);
						tempas.getPazymiai().clear();
						pazymys.clear();
					}
					rfile1.close();
					auto endN = std::chrono::high_resolution_clock::now();
					durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
					auto startW = std::chrono::high_resolution_clock::now();
					sort(mas.begin(), mas.end(), palyginti_galutinius);
					auto endW = std::chrono::high_resolution_clock::now();
					durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
					auto startR = std::chrono::high_resolution_clock::now();
					int strat;
						cout << "Kuria strategija norite naudoti? Jei pirmaja iveskite - 1, jei antraja - 2" << endl;
						cin >> strat;
						while (cin.fail() || strat != 1 && strat != 2) {
							cout << "Iveskite 1 arba 2" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> strat;
						}
						if (strat == 1) {
							auto startR = std::chrono::high_resolution_clock::now();

							for (auto& student : mas) {
								if (student.getGalutinis() >= 5) {
									pirmunai.push_back(std::move(student));
								}
								else {
									abejingi.push_back(std::move(student));
								}
							}

							mas.clear();

							auto endR = std::chrono::high_resolution_clock::now();
							durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);

							for (const auto& pirm : pirmunai) {
								file2 << pirm;
							}

							for (const auto& abej : abejingi) {
								file3 << abej;
							}
						}
						else {
							auto startR = std::chrono::high_resolution_clock::now();

							auto partition_it = std::partition(mas.begin(), mas.end(),
						
								[](const auto& elem) { return elem.getGalutinis() < 5; });

							abejingi.insert(abejingi.end(), mas.begin(), partition_it);
							mas.erase(mas.begin(), partition_it);

							auto endR = std::chrono::high_resolution_clock::now();
							durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);

							for (const auto& pirm : mas) {
								file2 << pirm;
							}

							for (const auto& abej : abejingi) {
								file3 << abej;
							}
						}
				}
				else
					if (tikrinimas1 == "2")
					{
						fgeneravimas(tikrinimas, fvardas, laikas, false);
						ifstream rfile1(fvardas);
						string linija;
						getline(rfile1, linija);
						auto startN = std::chrono::high_resolution_clock::now();
						string vard, pav;
						Vektorius<int> pazymys;
						for (int i = 1; i < tikrinimas + 1; i++)
						{
							rfile1 >> vard >> pav;
							for (int j = 0; j < 5; j++)
							{
								tempas.setVardas(vard);
								tempas.setPavarde(pav);
								int paz;
								rfile1 >> paz;
								pazymys.push_back(paz);
							}
							tempas.setPazymiai(pazymys);
							int egzaminas;
							rfile1 >> egzaminas;
							tempas.setEgzaminas(egzaminas);
							tempas.medi();
						    tempas.aver();
							mas.push_back(tempas);
							tempas.getPazymiai().clear();
							pazymys.clear();

						}

						rfile1.close();
						auto endN = std::chrono::high_resolution_clock::now();
						durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
						auto startW = std::chrono::high_resolution_clock::now();
						sort(mas.begin(), mas.end(), palyginti_galutinius);
						auto endW = std::chrono::high_resolution_clock::now();
						durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
						auto startR = std::chrono::high_resolution_clock::now();
						int strat;
						cout << "Kuria strategija norite naudoti? Jei pirmaja iveskite - 1, jei antraja - 2" << endl;
						cin >> strat;
						while (cin.fail() || strat != 1 && strat != 2) {
							cout << "Iveskite 1 arba 2" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> strat;
						}
						if (strat == 1)
						{
							auto startR = std::chrono::high_resolution_clock::now();
							for (auto& student : mas)
							{
								if (student.getGalutinis() >= 5)
								{
									pirmunai.push_back(student);
								}
								else
								{
									abejingi.push_back(student);
								}
							}
							mas.clear();
							auto endR = std::chrono::high_resolution_clock::now();
							durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
							for (auto pirm : pirmunai)
							{
								file2 << pirm;
							}
							for (auto abej : abejingi)
							{
								file3 << abej;
							}
						}
						else
						{
							auto startR = std::chrono::high_resolution_clock::now();
							auto partition_it = std::partition(mas.begin(), mas.end(),
								[](const auto& elem) { return elem.getGalutinis() < 5; });

							abejingi.insert(abejingi.end(), mas.begin(), partition_it);
							mas.erase(mas.begin(), partition_it);
							auto endR = std::chrono::high_resolution_clock::now();
							durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
							for (auto pirm : pirmunai)
							{
								file2 << pirm;
							}
							for (auto abej : abejingi)
							{
								file3 << abej;
							}
						}
					}
					else
					{
						return;
					}
				cout << left << "Tiek trunka failo nuskaitymas:                   " << durationN.count() / 1000000.0 << " seconds. " << endl;
				cout << left << "Tiek trunka studentu rusiavimas pagal vidurkius  " << durationS.count() / 1000000.0 << " seconds. " << endl;
				cout << left << "Tiek trunka pirmunu ir abejingu rusiavimas:      " << durationR.count() / 1000000.0 << " seconds. " << endl;
				cout << left << "Tiek trunka visa programa:                       " << durationN.count() / 1000000.0 + durationR.count() / 1000000.0 + durationS.count() / 1000000.0 << "seconds. " << endl;
				cout << endl;
				cout << "Jei norite baigti iveskite 0, jei ne bet koki kita skaiciu ar simboli" << endl;
				cin >> tikrinimas1;
				cout << endl;
				if (tikrinimas1 == "0")
				{
					baigimas = true;
				}
				file2.close();
				file3.close();
				//-------------------------------------------
			}
		}
	}
}
#endif

