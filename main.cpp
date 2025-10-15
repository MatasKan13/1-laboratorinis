#include "mylib.h"
#include "timer.h"

int main() {
    int m;
    char kont, rik, sp, ar_f;
    string ivesties_pav;
    cout << "Sveiki!" << endl << "Pasirinkite, ar norite studentu duomenis laikyti vektoriuje [V], ar sarase [S]? "; cin >> kont;
    kont = Iv_raid_patikra(kont, "vs");
    cout << "Pasirinkite, ar norite studentu duomenis irasyti patys [P], ar vykdyti spartos tikrinima [S]? "; cin >> ar_f;
    ar_f = Iv_raid_patikra(ar_f, "ps");
    if (kont == 'v') {
        vector <Studentas> Grupe, Vargsai, Moksliukai;
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
            Moksliukai = Rikiavimas_vector(Moksliukai, rik);
            Vargsai = Rikiavimas_vector(Vargsai, rik);
            Ekrano_isvestis(Vargsai, Moksliukai);
        }
        else {
            char f_tip;
            cout << "Pasirinkite, kokio studentu skaiciaus faila tikrinsite:\n[A] 1.000\t[B] 10.000\t[C] 100.000\t[D] 1.000.000\t[E] 10.000.000\n";
            cin >> f_tip;
            f_tip = Iv_raid_patikra(f_tip, "abcde");
            rik = Rikiavimo_tipas();
            map <char, int> tipai = {{'a', 1000}, {'b', 10000}, {'c', 100000}, {'d', 1000000}, {'e', 10000000}};
            int irasu_sk = tipai[f_tip];
            ivesties_pav = "stud" + to_string(irasu_sk) + ".txt";

            Timer t, visas;
            Failo_nuskaitymas(Grupe, ivesties_pav);
            cout << "Failo is " << irasu_sk << " irasu nuskaitymo laikas: " << t.elapsed() << " s\n";

            t.reset();
            Paskirstymas(Grupe,Moksliukai,Vargsai);
            cout << irasu_sk << " dalijimo i dvi grupes, isvalant pradini vektoriu, laikas: " << t.elapsed() << " s\n";

            t.reset();
            Moksliukai = Rikiavimas_vector(Moksliukai, rik);
            Vargsai = Rikiavimas_vector(Vargsai, rik);
            cout << irasu_sk << " irasu dvieju grupiu isrikiavimo su sort funkcija laikas: " << t.elapsed() << " s\n";

            t.reset();
            Spausdinimas(Vargsai);
            cout << irasu_sk << " irasu vargseliu irasymo i faila laikas: " << t.elapsed() << " s\n";

            t.reset();
            Spausdinimas(Moksliukai);
            cout << irasu_sk << " irasu kietiaku irasymo i faila laikas: " << t.elapsed() << " s\n\n";

            cout << irasu_sk << " irasu testo su VECTOR bendras laikas: " << visas.elapsed() << " s\n";
        }
    }
    else {
        list <Studentas> Grupe, Vargsai, Moksliukai;
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
            Moksliukai = Rikiavimas_list(Moksliukai, rik);
            Vargsai = Rikiavimas_list(Vargsai, rik);
            Ekrano_isvestis(Vargsai, Moksliukai);
        }
        else {
            char f_tip;
            cout << "Pasirinkite, kokio studentu skaiciaus faila tikrinsite:\n[A] 1.000\t[B] 10.000\t[C] 100.000\t[D] 1.000.000\t[E] 10.000.000\n";
            cin >> f_tip;
            f_tip = Iv_raid_patikra(f_tip, "abcde");
            rik = Rikiavimo_tipas();
            map <char, int> tipai = {{'a', 1000}, {'b', 10000}, {'c', 100000}, {'d', 1000000}, {'e', 10000000}};
            int irasu_sk = tipai[f_tip];
            ivesties_pav = "stud" + to_string(irasu_sk) + ".txt";

            Timer t, visas;
            Failo_nuskaitymas(Grupe, ivesties_pav);
            cout << "Failo is " << irasu_sk << " irasu nuskaitymo laikas: " << t.elapsed() << " s\n";

            t.reset();
            Paskirstymas(Grupe,Moksliukai,Vargsai);
            cout << irasu_sk << " dalijimo i dvi grupes, isvalant pradini sarasa, laikas: " << t.elapsed() << " s\n";

            t.reset();
            Moksliukai = Rikiavimas_list(Moksliukai, rik);
            Vargsai = Rikiavimas_list(Vargsai, rik);
            cout << irasu_sk << " irasu dvieju grupiu isrikiavimo su saraso sort metodu laikas: " << t.elapsed() << " s\n";

            t.reset();
            Spausdinimas(Vargsai);
            cout << irasu_sk << " irasu vargseliu irasymo i faila laikas: " << t.elapsed() << " s\n";

            t.reset();
            Spausdinimas(Moksliukai);
            cout << irasu_sk << " irasu kietiaku irasymo i faila laikas: " << t.elapsed() << " s\n\n";

            cout << irasu_sk << " irasu testo su LIST bendras laikas: " << visas.elapsed() << " s\n";
        }
    }
}
