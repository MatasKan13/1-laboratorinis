#include "mylib.h"

double Mediana(vector <int> vekt) {
    int n = vekt.size();
    double med;
    sort(vekt.begin(), vekt.end());
    if (n % 2 == 0) {
        med = double(vekt[n/2] + vekt[n/2 - 1]) / 2.0;
    } else {
        med = vekt[n/2];
    }
    return(med);
}

Studentas Balo_skaiciavimas(Studentas stud) {
    int suma = 0, n = stud.paz.size();
    for (int p : stud.paz) {
        suma+=p;
    }
    stud.galVid = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
    stud.galMed = 0.4 * Mediana(stud.paz) + 0.6 * stud.egz;
    if (stud.galVid >= 5) {
        stud.islaike = true;
    } else {
        stud.islaike = false;
    }
    return stud;
}

char Iv_raid_patikra(char ivestis, string raides) {
    bool tesiam = true;
    while (tesiam) {
        ivestis = tolower(ivestis);
        for (auto &raide : raides) {
            if (ivestis == raide) {
                tesiam = false;
                break;
            }
        }
        if (tesiam) {
            cout << "Neteisinga ivestis! Bandykite dar karta: "; cin >> ivestis;
        }
    }
    return(ivestis);
}

char Iv_paz_patikra(int ivestis) {
    bool tesiam = true;
    while (tesiam) {
        for (int sk = 1; sk <=10; sk++) {
            if (ivestis == sk) {
                tesiam = false;
                break;
            }
        }
        if (tesiam) {
            cout << "Neteisinga ivestis! Bandykite dar karta: "; cin >> ivestis;
        }
    }
    return(ivestis);
}

Studentas Stud_ivestis(int sk){
    Studentas stud;
    int laik_paz, n = 1;
    bool pabaiga = false;
    char testi, atsit;
    cout << "Kuo vardu " << sk+1 << "-asis studentas(-e)? "; cin >> stud.vardas;
    cout << "Kokia jo (jos) pavarde? "; cin >> stud.pavarde;
    cout << "Ar noretumete sio studento pazymius sugeneruoti atsitiktinai? [T/N] "; cin >> atsit;
    atsit = Iv_raid_patikra(atsit, "tn");
    if (atsit == 't') {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution dist(1,10);
        while (!pabaiga) {
            cout << "Generuojama..." << endl;
            int p = dist(gen);
            cout << "Sugeneruotas pazymys: " << p << endl;
            stud.paz.push_back(p);
            cout << "Ar norite toliau rasyti pazymius? [T/N] "; cin >> testi;
            testi = Iv_raid_patikra(testi, "tn");
            if (testi == 'n'){
                break;
            }
        }
        cout << "Generuojama..." << endl;
        stud.egz = dist(gen);
        cout << "Sugeneruotas egzamino ivertinimas: " << stud.egz << endl;
    }
    else {
        cout << "Iveskite pazymius." << endl;
        while (!pabaiga) {
            cout << n << "-asis pazymys: "; cin >> laik_paz;
            laik_paz = Iv_paz_patikra(laik_paz);
            stud.paz.push_back(laik_paz);
            cout << "Ar norite toliau rasyti pazymius? [T/N] "; cin >> testi;
            testi = Iv_raid_patikra(testi, "tn");
            if (testi == 't') {
                n++;
            }
            else if (testi == 'n'){
                break;
            }
        }
        cout << "Koks egzamino ivertinimas? "; cin >> stud.egz;
        stud.egz = Iv_paz_patikra(stud.egz);
    }
    stud = Balo_skaiciavimas(stud);
    return(stud);
}

string Failo_patikra(string failo_pav) {
    while (true) {
        ifstream in(failo_pav);
        if(in.fail()) {
            cout << "Failo pavadinimas neteisingas! Bandykite dar karta: "; cin >> failo_pav;
        }
        else {
            in.close();
            break;
        }
    }
    return failo_pav;
}

void Failo_nuskaitymas(vector <Studentas> &Vargsai, vector <Studentas> &Moksliukai, string failo_pav) {
    failo_pav = Failo_patikra(failo_pav);
    cout << "Puiku! Nuskaitomas failas..." << endl;
    stringstream buferis;
    ifstream in(failo_pav);
    buferis << in.rdbuf();
    in.close();
    string stulp;
    getline(buferis, stulp);
    while (!buferis.eof()) {
        Studentas stud;
        string eil;
        int pazymys;
        vector <int> pazymiai;
        getline(buferis, eil);
        istringstream srautas(eil);
        srautas >> stud.vardas >> stud.pavarde;
        while(srautas >> pazymys) {
            stud.paz.push_back(pazymys);
        }
        stud.egz = stud.paz.back();
        stud.paz.pop_back();
        stud = Balo_skaiciavimas(stud);
        if (stud.islaike) {
                Moksliukai.push_back(stud);
        }
        else {
                Vargsai.push_back(stud);
        }
    }
}

vector <Studentas> Rikiavimas(vector <Studentas> Rikiuojamas, char rik) {
    sort(Rikiuojamas.begin(), Rikiuojamas.end(), [rik](const Studentas &a, const Studentas &b) {
        if (rik == 'a') {
            return a.pavarde < b.pavarde;
        } else if (rik == 'b') {
            return a.vardas < b.vardas;
        } else if (rik == 'c') {
            return a.galVid > b.galVid;
        } else {
            return a.galMed > b.galMed;
        }
    });
    return Rikiuojamas;
}

void Spausdinimas(vector <Studentas> Moksliukai, vector <Studentas> Vargsai) {//, string failo_pav) {
    char rodinys;
    cout << "Kaip skaiciuoti galutini ivertinima? Pasirinkite: su vidurkiu [V], su mediana [M] ar abu [A]? "; cin >> rodinys;
    rodinys = Iv_raid_patikra(rodinys, "vma");
    //failo_pav = failo_pav + ".txt";
    stringstream ss1;
    stringstream ss2;
    if (rodinys == 'v') {
        ss1 << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
        ss1 << string(51,'-') << endl;
        for (const auto &Past : Moksliukai) {
            ss1 << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galVid << endl;
        }
        ss2 << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
        ss2 << string(51,'-') << endl;
        for (const auto &Past : Vargsai) {
            ss2 << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galVid << endl;
        }
    } else if (rodinys == 'm') {
        ss1 << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
        ss1 << string(51,'-') << endl;
        for (const auto &Past : Moksliukai) {
            ss1 << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
        ss2 << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
        ss2 << string(51,'-') << endl;
        for (const auto &Past : Vargsai) {
            ss2 << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
    } else if (rodinys == 'a') {
        ss1 << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(16) << left << "Galutinis (Med.)" << endl;
        ss1 << string(68,'-') << endl;
        for (const auto &Past : Moksliukai) {
            ss1 << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(17) << left << fixed << setprecision(2) << Past.galVid << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
        ss2 << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(16) << left << "Galutinis (Med.)" << endl;
        ss2 << string(68,'-') << endl;
        for (const auto &Past : Vargsai) {
            ss2 << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(17) << left << fixed << setprecision(2) << Past.galVid << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
    }
    ofstream out1("kietiakai.txt");
    out1 << ss1.str();
    out1.close();
    ofstream out2("nuskriaustukai.txt");
    out2 << ss2.str();
    out2.close();
}
