#include "mylib.h"
#include "timer.h"

int main() {
    int m;
    char kont, rik, sp, rodinys;
    string ivesties_pav;
    cout << "Sveiki!" << endl << "Pasirinkite, ar norite studentu duomenis laikyti vektoriuje [V], ar sarase [S]? "; cin >> kont;
    kont = Iv_raid_patikra(kont, "vf");
    if (kont == 'v') {
        vector <Studentas> Grupe, Vargsai, Moksliukai;
        char f_tip;
        cout << "Pasirinkite, kokio studentu skaiciaus faila tikrinsite:\n[A] 1.000\t[B] 10.000\t[C] 100.000\t[D] 1.000.000\t[E] 10.000.000\n";
        cin >> f_tip;
        f_tip = Iv_raid_patikra(f_tip, "abcde");
        rodinys = 'a';
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
        Moksliukai = Rikiavimas(Moksliukai, rik);
        Vargsai = Rikiavimas(Vargsai, rik);
        cout << irasu_sk << " irasu dvieju grupiu isrikiavimo su sort funkcija laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Vargsai, rodinys);
        cout << irasu_sk << " irasu vargseliu irasymo i faila laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Moksliukai, rodinys);
        cout << irasu_sk << " irasu kietiaku irasymo i faila laikas: " << t.elapsed() << " s\n\n";

        cout << irasu_sk << " irasu testo bendras laikas: " << visas.elapsed() << " s\n";
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

        /*Timer t, visas;
        Failo_nuskaitymas(Grupe, ivesties_pav);
        cout << "Failo is " << irasu_sk << " irasu nuskaitymo laikas: " << t.elapsed() << " s\n";

        t.reset();
        Paskirstymas(Grupe,Moksliukai,Vargsai);
        cout << irasu_sk << " dalijimo i dvi grupes, isvalant pradini vektoriu, laikas: " << t.elapsed() << " s\n";

        t.reset();
        Moksliukai = Rikiavimas(Moksliukai, rik);
        Vargsai = Rikiavimas(Vargsai, rik);
        cout << irasu_sk << " irasu dvieju grupiu isrikiavimo su sort funkcija laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Vargsai, rodinys);
        cout << irasu_sk << " irasu vargseliu irasymo i faila laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Moksliukai, rodinys);
        cout << irasu_sk << " irasu kietiaku irasymo i faila laikas: " << t.elapsed() << " s\n\n";

        cout << irasu_sk << " irasu testo bendras laikas: " << visas.elapsed() << " s\n";*/
    }
}
