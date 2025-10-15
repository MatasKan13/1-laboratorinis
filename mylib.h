#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> // Skirta sort metodui
#include <cctype> // Skirta toupper ir tolower metodams
#include <random> // Skirta atsitiktinių skaičių generavimui
#include <fstream> // Skirta darbui su failais
#include <sstream> // Skirta stringstream (eilutės pavertimo srautu) metodui
#include <chrono> // Skirta laiko matavimams
#include <map>
#include <list>

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
using std::ofstream;
using std::getline;
using std::ws;
using std::stringstream;
using std::istringstream;
using std::map;
using std::to_string;
using std::list;
using std::stoi;
using std::pair;

struct Studentas {
    string vardas;
    string pavarde;
    vector <int> paz;
    int egz;
    double galVid;
    double galMed;
    bool islaike;
};

double Mediana(vector <int> vekt);
Studentas Balo_skaiciavimas(Studentas stud);
char Iv_raid_patikra(char ivestis, string raides);
int Iv_paz_patikra(string ivestis, bool);
pair <string, int> Failo_pasirinkimas();
Studentas Stud_ivestis(int sk);
string Failo_patikra(string failo_pav);
char Rikiavimo_tipas();
vector <Studentas> Rikiavimas_vector(vector <Studentas> Rikiuojamas, char rik);
list <Studentas> Rikiavimas_list(list <Studentas> Rikiuojamas, char rik);

template <typename T>
void Failo_nuskaitymas(T &Grupe, string failo_pav) {
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
        Grupe.push_back(stud);
    }
}

template <typename T>
void Paskirstymas(T &Grupe, T &Moksliukai, T &Vargsai) {
    for (auto stud : Grupe) {
        stud = Balo_skaiciavimas(stud);
        if (stud.islaike) {
            Moksliukai.push_back(stud);
        }
        else {
            Vargsai.push_back(stud);
        }
    }
    Grupe.clear();
}

template <typename T>
void Spausdinimas(T Spausd_gr) {
    stringstream ss;
    ss << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(16) << left << "Galutinis (Med.)" << endl;
    ss << string(68,'-');
    for (const auto &Past : Spausd_gr) {
        ss << endl << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(17) << left << fixed << setprecision(2) << Past.galVid << setw(16) << left << fixed << setprecision(2) << Past.galMed;
    }
    
    auto it = Spausd_gr.begin();
    if (it->islaike) {
        ofstream out("kietiakai.txt");
        out << ss.str();
        out.close();
    } else {
        ofstream out("nuskriaustukai.txt");
        out << ss.str();
        out.close();
    }
}

template <typename T>
void Ekrano_isvestis(T Vargsai, T Moksliukai) {
    if(Moksliukai.size()!=0) {
        cout << "Islaike studentai:" << endl;
        cout << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(17) << left << "Galutinis (Med.)" << setw(17) << left << "Adresas atmintyje" << endl;
        cout << string(86,'-');
        for (const auto &Past : Moksliukai) {
            cout << endl << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(17) << left << fixed << setprecision(2) << Past.galVid << setw(17) << left << fixed << setprecision(2) << Past.galMed << setw(17) << left << &Past;
        }
    }
    else {
        cout << "Islaikiusiu studentu nera! :(";
    }
    cout << endl << endl;
    if(Vargsai.size()!=0) {
        cout << "Neislaike studentai:" << endl;
        cout << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(17) << left << "Galutinis (Med.)" << setw(17) << left << "Adresas atmintyje" << endl;
        cout << string(86,'-');
        for (const auto &Past : Vargsai) {
            cout << endl << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(17) << left << fixed << setprecision(2) << Past.galVid << setw(17) << left << fixed << setprecision(2) << Past.galMed << setw(17) << left << &Past;
        }
    }
    else {
        cout << "Neislaikiusiu studentu nera! :)";
    }
    cout << endl;
}

template <typename T>
void Ivestis_ranka(T &Vargsai, T &Moksliukai) {
    int m;
    char rik;
    cout << "Kiek studentu grupeje? "; cin >> m;
    for (auto i = 0; i < m; i++) {
        Studentas laik;
        laik = Stud_ivestis(i);
        if (laik.islaike) {
            Moksliukai.push_back(laik);
        }
        else {
            Vargsai.push_back(laik);
        }
    }
}
