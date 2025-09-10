#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

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
        med = (vekt[n/2] + vekt[n/2 - 1]) / 2;
    } else {
        med = vekt[n/2];
    }
    return(med);
}

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
    stud.galVid = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
    stud.galMed = 0.4 * Mediana(stud.paz) + 0.6 * stud.egz;
    return(stud);
}

int main() {
    /*int m;
    vector <Studentas> Grupe;
    cout << "Kiek studentu grupeje? "; cin >> m;
    for (auto i = 0; i < m; i++) {
        Grupe.push_back(Stud_ivestis(i));
    }
    cout << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
    cout << string(41,'-') << endl;
    for (auto Past : Grupe) {
        cout << setw(10) << left << Past.vardas << setw(15) << left << Past.pavarde << setw(16) << left << fixed << setprecision(2) << Past.galVid << endl;
    }*/
   vector <int> vekt;
   for (int i = 24;i>0; i-=3) {
       i += i%2;
       vekt.push_back(i);
   }
   for (auto i = 0;i < vekt.size(); i++) {
       cout << vekt[i] << " ";
   }
   cout << endl;
   sort(vekt.begin(), vekt.end());
   double mediana = Mediana(vekt);
   cout << mediana;
}
