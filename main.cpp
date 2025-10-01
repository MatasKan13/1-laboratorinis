#include "mylib.h"

int main() {
    int m;
    char ar_f, rik;
    vector <Studentas> Vargsai, Moksliukai;
    string ivesties_pav;
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
    cout << "Pasirinkite, pagal ka norite isrikiuoti duomenis:" << endl;
    cout << "[A] pavardes\t[B] vardus\t[C] galutini bala pagal vidurki\t [D] galutini bala pagal mediana" << endl; cin >> rik;
    rik = Iv_raid_patikra(rik, "abcd");
    Moksliukai = Rikiavimas(Moksliukai, rik);
    Vargsai = Rikiavimas(Vargsai, rik);
    Spausdinimas(Moksliukai, Vargsai);
}
