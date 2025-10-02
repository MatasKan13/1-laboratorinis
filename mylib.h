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
char Iv_paz_patikra(int ivestis);
Studentas Stud_ivestis(int sk);
string Failo_patikra(string failo_pav);
void Failo_nuskaitymas(vector <Studentas> &Grupe, string failo_pav);
void Paskirstymas(vector <Studentas> &Grupe, vector <Studentas> &Moksliukai, vector <Studentas> &Vargsai);
char Rikiavimo_tipas();
void Spausdinimas(vector <Studentas> , char rodinys);
vector <Studentas> Rikiavimas(vector <Studentas> , char rik);
