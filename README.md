# objektinis-pr

V0.1:

Sukurti dvi 0.1 laboratorinio darbo versijos: viena pavadinimu 0.1.cpp naudoja vektorius, o kita pavadinta 0,1 masyvai.cpp naudoja masyvus, įvykdyti reikalavimus.

V0.2:

Papildymas pirmos versijos (0.1) vektorių failas. Sukurta skait funkcija, kuri skaito visus duomenis iš failo kursiokai.txt, išvedant duomenis jie yra surikiuoti pagal vardą.

V0.3:

Pakeistas (0.2 versijos) failas, v0.3 versijos faile palikta tik main funkcija, funkcijos perdėtos į Mylibfunc.h header'io failą. Funkcijų antraštės aprašytos functions.cpp faile. Mylib.h failas turi visas reikalingas bibliotekas. Pridėtas tikrinimas failo, reakcija, kas nutiktų jei failas būtų tuščias.

V0.4:

Sugeneruoti trys nauji failai: sukurtas1.txt, sukurtas2.txt, sukurtas3.txt Padaryta, taip, kad sukurtas1.txt faile būtų sugeneruojama studento vardas, pavardė, 5 atsitiktiniai namų darbų pažymiai ir atsitiktinis egzamino pažymys Šio failo duomenys nuskaitomi, po to apskaičiuojami kiekvieno žmogaus galutiniai vidurkiai, žmogaus kurio galutinis vidurkis yra didesnis už 5 yra įdedamas į vektorių pavadinimu pirmunai, o kiti į vektorių abejingi. Pirmunu vektorius yra atspausdinamas sukurtas2.txt, o abejingų - sukurtas3.txt Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus.

V0.5:

Patobulinta v0.4 versija, apskaičiuojamas laikas kiek trunka tam tikri procesai kaip failo sukūrimas ir generavimas, failo, nuskaitymas, studentų ir abejingų rūšiavimas, pirmūnų įrašymas, abejingų įrašymas ir bendras laikas. Visi jie yra apskaičiuojami naudojant tris skirtingus konteinerius: 1 - vector, 2 - deque, 3 - list.
Apačioje pateikiamas matavimų laikas.

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant Vector:

| Vector  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo nuskaitymas | 0.031199 | 0.229992 | 2.57409 | 24.8619 | 257.7845 |
| Studentų rūsiavimas pagal vidurkius | 0.009162 | 0.088798 | 0.93408 | 8.94001 | 90.7895 |
| Pirmūnų ir abejingų skirstymas | 0.005727 | 0.073684 | 0.666984 | 6.235 | 61.1687 |
| Bendras laikas  | 0.046088 | 0.392474 | 4.175150| 40.4369 | 409.7427 |

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant Deque:

| Deque  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo nuskaitymas | 0.026916 | 0.268572 | 3.07978 | 34.1083 | 362.4897 |
| Studentų rūsiavimas pagal vidurkius | 0.011449 | 0.109969 | 1.02035 | 13.3648 | 141.4897 |
| Pirmūnų ir abejingų skirstymas  | 0.00656 | 0.065672 | 0.690727 | 8.89532 | 95.1287 |
| Bendras laikas  | 0.044925 | 0.444213 | 4.79086 | 56.3684 | 599.1081 |

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant List:

| List  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo nuskaitymas | 0.030746 | 0.228811 | 2.42725 | 22.8714 | 232.2569 |
| Studentų rūsiavimas pagal vidurkius | 0.000226 | 0.003286 | 0.051877 | 0.719292 | 6.48965 |
| Pirmūnų ir abejingų skirstymas  | 0.004719 | 0.059477 | 0.590061 | 5.99157 | 57.12398 |
| Bendras laikas  | 0.035691 | 0.291574 | 3.06919 | 29.5822 | 295.87053 | 

V1.0:

Deque, list, vector konteinerius naudojančios programos padarytos atskiruose failuose, v0.5 versijoje buvo vienoje. Kiekviena versija dabar naudoja dvi skirtingas strategijas studentų rūšiavimui, pirma strategija naudoja skirstymą iš pagrindinio konteinerio į du atskirus konteinerius ir juos atspausdina, o antra strategija iš pagrindinio konteinerio ištrina „abejingus“, t.y, kurių vidurkis <5, ir juos perkelia į kitą konteinerį, vėliau šie vektoriai yra atspausdinami.Taip pat visų šių konteinerių efektyvumas yra optimizuotas. Šių strategijų programos veikimo laikas yra palygintas:

| Vector  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Pirmūnų ir abejingų skirstymas naudojant pirmą strategiją | 0.005699 | 0.067477 | 0.649836 | 6.37876 | 67.145677 |
| Pirmūnų ir abejingų skirstymas naudojant antrą strategiją | 0.002787 | 0.02959 | 0.32028 | 3.57024 | 31.78414 |

| Deque  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Pirmūnų ir abejingų skirstymas naudojant pirmą strategiją | 0.002712 | 0.026349 | 0.27013 | 2.81263 | 29.17567 |
| Pirmūnų ir abejingų skirstymas naudojant antrą strategiją | 0.006756 | 0.066774 | 0.0697 | 7.53816 | 69.14874 |

| List  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Pirmūnų ir abejingų skirstymas naudojant pirmą strategiją | 0.005413 | 0.053223 | 0.568018 | 6.15839 | 60.73289 |
| Pirmūnų ir abejingų skirstymas naudojant antrą strategiją | 0.002226 | 0.025487 | 0.254313 | 2.80341 | 27.43984 |

1 strategijos naudojama atmintis 10000000 failam nuo 2GB iki 2.5GB
2 strategijos naudojama atmintis 10000000 failam nuo 1.4GB iki 1.9GB
Kaip matome iš rezultatų - antra strategija yra efektyvesnė.

V1.1:

Iš struct duomenų tipo pereita į class tipą. Atlikti pakeitimai, taip, kad kodas veiktų su nauja padaryta klase. Kiekvienam private klasės nariui padaryta setter ir getter funkcija, kur setter funkcija įrašo duomenis, o getter naudoja tuos duomenis skaičiavimam arba duomenų atspausdinimui. Taip pat yra student() default konstruktorius ir ~studentas() destruktorius, kuris ištrina visus vektoriuje esančius pažymius. 

Laiko palyginimas naudojant klases ir struktūras 1000000 ir 10000000 dydžio failuose naudojant antrą strategiją ir O3 kompiliavimo flag'ą:


| Struct  | 1000000  | 10000000  |
|---|---|---|
||||
| Bendras Laikas | 32.9423 | 342.1945 |

| Class  | 1000000  | 10000000  |
|---|---|---|
||||
| Bendras Laikas | 43.308 | 437.1745 |

Class duomenų tipas įveikia programą kiek lėčiau.

Eksperimentinė analizė, kuri parodo koks yra bendras laikas ir sukurtų exe failų dydis naudojant kompiliavimo flag'us 1000000

| Komiliatoriaus flag'as | O1 | O2 | O3 |
|---|---|---|---|
|||||||
| Skaičiavimų laikas | 42.3752 | 42.1707 | 41.8541 |
| Projekto dydis | 378KB | 352KB | 349KB |

V1.2

Įgyvendinta rule of five. Klasės konteineryje sukurtas kopijavimo konstruktorius, kopijavimo priskyrimas, move konstruktorius, move priskyrimas. Tapi pat sukurta friend output funkcija, kurią iškvietus, atspausdinamas studento vardas, pavardė, galutinis pažymys skaičiuojamas pagal vidurkį ir galutinis pažymys skaičiuojamas pagal medianą.

V1.5 

Padarytos dvi klasės. Sukurta bazinė klasė žmogui (Zmogus), kuri yra visiškai abstrakti, o iš jos išvesta derived klasė (studentas). Iš Zmogus klasės neįmanoma sukurti objektų, o tai padaryti galima tik iš jos išvestinės klasės Studentas.

V2.0

Sukurta dokumentacija naudojant Doxygen, kur aprašytos visos funkcijos, reikalinga informacija. Realizuoti unit testing, naudojant catch library. Taip pat galiausiai sukurtas įdiegimo failas, kurį įdiegus galima naudotis programa be jokių trikdžių.

VektoriausKlasė

Klasėje Vektorius įvykdyta didžioji dalis std::vector funkcijų ir jos buvo ištestuotos. Tos funkcijos yra pavyzdžiuj clear(),  swap(), insert(), erase(), pop_back() ir kitos. Visas funkcijas panaudotas galima pamatyti eksperimentai.cpp faile. 
O čia keli pavyzdžiai viršuje parašytų funkcijų panaudojimo:

clear():
Vektorius sk prieš clear(): {1 5 8 9 20}
Vektorius sk po clear(): {(tuščias)}

swap():
prieš swap()
Vektorius g1 = {1,2,3,4,5}
Vektorius g2 = {10, 20, 30}
po swap()
Vektorius g1 = {10, 20, 30}
Vektorius g2 = {1,2,3,4,5}

insert():
Vektorius numbers5 prieš insert() = {1,2,3,4,5}
Vektorius numbers5 po insert(numbers5.begin() + 2, 10) = {1, 2, 10, 3, 4, 5}

erase():
Vektorius numbers7 prieš erase() = {1,2,3,4,5}
Vektorius numbers7 po erase(numbers7.begin()+2) = {1,2,4,5}

pop_back():
Vektorius numbers4 prieš pop_back() = {1,2,3,4,5}
Vektorius numbers4 po pop_back() = {1,2,3,4}

V2.0 spartos palyginimas naudojant greitesnę (2 strategiją) tarp std::vector ir sukurtos Vektorius klasės naudojant 100000 studentų įrašų

| Sparta  | Vektorius  | std::vector  |
|---|---|---|
||||
| 100000 | 4.51671 | 4.36619|

Efektyvumo/spartos analizė palyginant std::vector ir Vector vidutiniai laikai tuščius vektorius užpildant 10000, 100000, 1000000, 10000000 ir 100000000 int elementų naudojant push_back() funkciją.

| Sparta  | Vektorius  | std::vector  |
|---|---|---|
||||
| 100000 | 0.007599 | 0.007743 |
| 1000000 | 0.071609 | 0.074275 |
| 10000000 | 0.726422 | 0.72843 |
| 100000000 | 7.26988 | 7.39075 |

Patikrintas atminties perskirstymas naudojant int konteinerį ir 100000000 elementų - 46. 

Naudojimosi instrukcija:

Parsisiųskite šį failą: Setup.exe
Pasirinkite ar norite parsisiųsti tik executable failą ar/ir source failus.
Toliau pasirinkite kur norite juos įdiegti.
Ten kur pasirinkote rasite visą atsisiųstą informaciją ir galėsite naudotis programa be jokių problemų.
Dėl vienos funkcijos veikimo reikia parsisiųsti kursiokai.txt ar kursiokai1.txt failus. Net ir neturint jų visos kitos programos funkcijos veiks tinkamai.

Naudotos sistemos parametrai:
RAM: 8GB
CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz   2.30 GHz
SSD: 512 GB
