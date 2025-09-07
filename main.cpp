#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;

struct Studentas {
    string vardas;
    string pavarde;
    vector <int> paz;
    int egz;
    double gal;
};

Studentas Stud_ivestis(int sk){
    Studentas stud;
    int n, laik_paz, suma =0;
    cout << "Kuo vardu " << sk+1 << "-asis studentas(-e)? "; cin >> stud.vardas;
    cout << "Kokia jo (jos) pavarde? "; cin >> stud.pavarde;
    cout << "Kiek pazymiu ivesite? "; cin >> n;
    for (auto i = 0; i<n; i++) {
        cout << i+1 << "-asis pazymys: "; cin >> laik_paz;
        stud.paz.push_back(laik_paz);
        suma+=laik_paz;
    }
    cout << "Koks egzamino ivertinimas? "; cin >> stud.egz;
    stud.gal = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
    return(stud);
}

int main() {
    int m;
    vector <Studentas> Grupe;
    cout << "Kiek studentu grupeje? "; cin >> m;
    for (auto i = 0; i<m; i++) {
        Grupe.push_back(Stud_ivestis(i));
    }
    cout << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
    cout << string(41,'-') << endl;
    for (auto Past : Grupe) {
        cout << setw(10) << left << Past.vardas << setw(15) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.gal << endl;
    }
}
