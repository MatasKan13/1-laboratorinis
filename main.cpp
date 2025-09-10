#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> // Skirta sort metodui
#include <cctype> // Skirta toupper ir tolower metodams

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
    int laik_paz, suma =0, n=1;
    bool pabaiga = false;
    char testi;
    cout << "Kuo vardu " << sk+1 << "-asis studentas(-e)? "; cin >> stud.vardas;
    cout << "Kokia jo (jos) pavarde? "; cin >> stud.pavarde;
    cout << "Iveskite pazymius." << endl;
    while (!pabaiga) {
        cout << n << "-asis pazymys: "; cin >> laik_paz;
        laik_paz = Iv_paz_patikra(laik_paz);
        stud.paz.push_back(laik_paz);
        suma+=laik_paz;
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
    stud.galVid = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
    stud.galMed = 0.4 * Mediana(stud.paz) + 0.6 * stud.egz;
    return(stud);
}

int main() {
    int m;
    char testi;
    vector <Studentas> Grupe;
    cout << "Kiek studentu grupeje? "; cin >> m;
    for (auto i = 0; i < m; i++) {
        Grupe.push_back(Stud_ivestis(i));
    }
    cout << "Kaip skaiciuoti galutini ivertinima? Pasirinkite: su vidurkiu [V], su mediana [M] ar abu [A]? "; cin >> testi;
    testi = Iv_raid_patikra(testi, "vma");
    if (testi == 'v') {
        cout << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
        cout << string(41,'-') << endl;
        for (auto Past : Grupe) {
            cout << setw(10) << left << Past.vardas << setw(15) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galVid << endl;
        }
    } else if (testi == 'm') {
        cout << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
        cout << string(41,'-') << endl;
        for (auto Past : Grupe) {
            cout << setw(10) << left << Past.vardas << setw(15) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
    } else if (testi == 'a') {
        cout << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(19) << left << "Galutinis (Vid.) / " << setw(16) << left << "Galutinis (Med.)" << endl;
        cout << string(60,'-') << endl;
        for (auto Past : Grupe) {
            cout << setw(10) << left << Past.vardas << setw(15) << left << Past.pavarde << setw(19) << left << fixed << setprecision(2) << Past.galVid << setw(16) << left << fixed << setprecision(2) << Past.galMed << endl;
        }
    }
}
