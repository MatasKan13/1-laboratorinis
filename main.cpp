#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> // Skirta sort metodui
#include <cctype> // Skirta toupper ir tolower metodams
#include <random> // Skirta atsitiktinių skaičių generavimui
#include <fstream> // Skirta darbui su failais
#include <sstream> // Skirta stringstream (eilutės pavertimo srautu) metodui

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::sort;
using std::toupper;
using std::tolower;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::ifstream;
using std::getline;
using std::ws;
using std::stringstream;

struct Studentas {
    string vardas;
    string pavarde;
    vector <int> paz;
    int egz;
    double galVid;
    double galMed;
};

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
    return stud;
}

char Iv_raid_patikra(char ivestis, string raides) {
    bool tesiam = true;
    while (tesiam) {
        ivestis = tolower(ivestis);
        for (auto raide : raides) {
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

void Failo_nuskaitymas(vector <Studentas> &Grupe, string failo_pav) {
    failo_pav = Failo_patikra(failo_pav);
    cout << "Puiku! Nuskaitomas failas..." << endl;
    ifstream in(failo_pav);
    string stulp;
    getline(in, stulp);
    while (!in.eof()) {
        Studentas stud;
        string eil;
        int pazymys;
        vector <int> pazymiai;
        getline(in, eil);
        stringstream srautas(eil);
        srautas >> stud.vardas >> stud.pavarde;
        while(srautas >> pazymys) {
            stud.paz.push_back(pazymys);
        }
        stud.egz = stud.paz.back();
        stud.paz.pop_back();
        stud = Balo_skaiciavimas(stud);
        Grupe.push_back(stud);
    }
    in.close();
}

int main() {
    int m;
    char rodinys, ar_f;
    vector <Studentas> Grupe;
    string failo_pav;
    cout << "Sveiki!" << endl << "Pasirinkite, ar norite studentu duomenis irasyti patys [P], ar ikelti faila [F]? "; cin >> ar_f;
    ar_f = Iv_raid_patikra(ar_f, "pf");
    if (ar_f == 'p') {
        cout << "Kiek studentu grupeje? "; cin >> m;
        for (auto i = 0; i < m; i++) {
            Grupe.push_back(Stud_ivestis(i));
        }
    }
    if (ar_f == 'f') {
        cout << "Iveskite failo pavadinima: "; cin >> failo_pav;
        Failo_nuskaitymas(Grupe, failo_pav);
    }
    cout << "Kaip skaiciuoti galutini ivertinima? Pasirinkite: su vidurkiu [V], su mediana [M] ar abu [A]? "; cin >> rodinys;
    rodinys = Iv_raid_patikra(rodinys, "vma");
    if (rodinys == 'v') {
        cout << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
        cout << string(51,'-') << endl;
        for (auto Past : Grupe) {
            cout << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galVid << endl;
        }
    } else if (rodinys == 'm') {
        cout << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
        cout << string(51,'-') << endl;
        for (auto Past : Grupe) {
            cout << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
    } else if (rodinys == 'a') {
        cout << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(16) << left << "Galutinis (Med.)" << endl;
        cout << string(68,'-') << endl;
        for (auto Past : Grupe) {
            cout << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(17) << left << fixed << setprecision(2) << Past.galVid << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
    }
}
