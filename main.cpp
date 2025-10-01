#include "mylib.h"

int main() {
    int m;
    char ar_f;
    vector <Studentas> Vargsai, Moksliukai;
    string ivesties_pav, isvesties_pav;
    cout << "Sveiki!" << endl << "Pasirinkite, ar norite studentu duomenis irasyti patys [P], ar ikelti faila [F]? "; cin >> ar_f;
    ar_f = Iv_raid_patikra(ar_f, "pf");
    if (ar_f == 'p') {
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
    if (ar_f == 'f') {
        cout << "Iveskite failo pavadinima: "; cin >> ivesties_pav;
        Failo_nuskaitymas(Vargsai, Moksliukai, ivesties_pav);
    }
    sort(Moksliukai.begin(), Moksliukai.end(), Rikiavimas);
    sort(Vargsai.begin(), Vargsai.end(), Rikiavimas);
    //cout << "Iveskite failo, i kuri norite isvesti rezultatus, pavadinima (be .txt): "; cin >> isvesties_pav;
    Spausdinimas(Moksliukai, Vargsai);//, isvesties_pav);
}
