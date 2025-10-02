#include "mylib.h"

int main() {
    int m;
    char ar_f, rik, sp, rodinys;
    vector <Studentas> Grupe, Vargsai, Moksliukai;
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
        rik = Rikiavimo_tipas();
        Moksliukai = Rikiavimas(Moksliukai, rik);
        Vargsai = Rikiavimas(Vargsai, rik);
        cout << "Kaip skaiciuoti galutini ivertinima? Pasirinkite: su vidurkiu [V], su mediana [M] ar abu [A]? "; cin >> rodinys;
        rodinys = Iv_raid_patikra(rodinys, "vma");
        Spausdinimas(Vargsai, rodinys);
        Spausdinimas(Moksliukai, rodinys);
    }
    if (ar_f == 'f') {
        cout << "Ar norite atlikti spartos tikrinima? [T/N] "; cin >> sp;
        sp = Iv_raid_patikra(sp, "tn");
        if (sp == 'n') {   
            cout << "Iveskite failo pavadinima: "; cin >> ivesties_pav;
            Failo_nuskaitymas(Grupe, ivesties_pav);
            Paskirstymas(Grupe,Moksliukai,Vargsai);
            rik = Rikiavimo_tipas();
            Moksliukai = Rikiavimas(Moksliukai, rik);
            Vargsai = Rikiavimas(Vargsai, rik);
            cout << "Kaip skaiciuoti galutini ivertinima? Pasirinkite: su vidurkiu [V], su mediana [M] ar abu [A]? "; cin >> rodinys;
            rodinys = Iv_raid_patikra(rodinys, "vma");
            Spausdinimas(Vargsai, rodinys);
            Spausdinimas(Moksliukai, rodinys);
        }
        else {
            char f_tip;
            cout << "Pasirinkite, kokio studentu skaiciaus faila tikrinsite:\n[A] 1.000\t[B] 10.000\t[C] 100.000\t[D] 1.000.000\t[E] 10.000.000\n";
            cin >> f_tip;
            f_tip = Iv_raid_patikra(f_tip, "abcde");
            rodinys = 'a';
            rik = Rikiavimo_tipas();
            map <char, int> tipai = {{'a', 1000}, {'b', 10000}, {'c', 100000}, {'d', 1000000}, {'e', 10000000}};
            int irasu_sk = tipai[f_tip];
            ivesties_pav = "stud" + to_string(irasu_sk) + ".txt";

            auto start = std::chrono::high_resolution_clock::now(); auto st = start;
            Failo_nuskaitymas(Grupe, ivesties_pav);
            std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
            cout << "Failo is " << irasu_sk << " irasu nuskaitymo laikas: " << diff.count() << " s\n";

            start = std::chrono::high_resolution_clock::now();
            Paskirstymas(Grupe,Moksliukai,Vargsai);
            diff = std::chrono::high_resolution_clock::now() - start;
            cout << irasu_sk << " dalijimo i dvi grupes, isvalant pradini vektoriu, laikas: " << diff.count() << " s\n";

            start = std::chrono::high_resolution_clock::now();
            Moksliukai = Rikiavimas(Moksliukai, rik);
            Vargsai = Rikiavimas(Vargsai, rik);
            diff = std::chrono::high_resolution_clock::now() - start;
            cout << irasu_sk << " irasu dvieju grupiu isrikiavimo su sort funkcija laikas: " << diff.count() << " s\n";

            start = std::chrono::high_resolution_clock::now();
            Spausdinimas(Vargsai, rodinys);
            diff = std::chrono::high_resolution_clock::now() - start;
            cout << irasu_sk << " irasu vargseliu irasymo i faila laikas: " << diff.count() << " s\n";

            start = std::chrono::high_resolution_clock::now();
            Spausdinimas(Moksliukai, rodinys);
            diff = std::chrono::high_resolution_clock::now() - start;
            cout << irasu_sk << " irasu kietiaku irasymo i faila laikas: " << diff.count() << " s\n\n";

            diff = std::chrono::high_resolution_clock::now() - st;
            cout << irasu_sk << " irasu testo bendras laikas: " << diff.count() << " s\n";
        }
    }
}
