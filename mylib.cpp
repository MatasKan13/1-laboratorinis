#include "mylib.h"

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

Studentas Balo_skaiciavimas(Studentas stud) {
    int suma = 0, n = stud.paz.size();
    for (int p : stud.paz) {
        suma+=p;
    }
    stud.galVid = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
    stud.galMed = 0.4 * Mediana(stud.paz) + 0.6 * stud.egz;
    if (stud.galVid >= 5) {
        stud.islaike = true;
    } else {
        stud.islaike = false;
    }
    return stud;
}

char Iv_raid_patikra(char ivestis, string raides) {
    bool tesiam = true;
    while (tesiam) {
        ivestis = tolower(ivestis);
        for (auto &raide : raides) {
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

int Iv_paz_patikra(string ivestis, bool egzas) {
    bool tesiam = true;
    int paz;
    while (tesiam) {
        try {
            paz = stoi(ivestis); 
            for (int sk = 0; sk <=10; sk++) {
                if (egzas && sk == 0) {
                    continue;
                }
                if (paz == sk) {
                    tesiam = false;
                    break;
                }
            }
            if (tesiam) {
                cout << "Neteisinga ivestis! Bandykite dar karta: "; cin >> ivestis;
            }
        }
        catch(...) {
            cout << "Neteisinga ivestis! Bandykite dar karta: "; cin >> ivestis;
        }
    }
    return(paz);
}

Studentas Stud_ivestis(int sk){
    Studentas stud;
    int laik_paz, n = 1;
    char testi, atsit;
    cout << "Kuo vardu " << sk+1 << "-asis studentas(-e)? "; cin >> stud.vardas;
    cout << "Kokia jo (jos) pavarde? "; cin >> stud.pavarde;
    cout << "Ar noretumete sio studento pazymius sugeneruoti atsitiktinai? [T/N] "; cin >> atsit;
    atsit = Iv_raid_patikra(atsit, "tn");
    if (atsit == 't') {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution dist(1,10);
        while (true) {
            cout << "Generuojama..." << endl;
            int p = dist(gen);
            cout << "Sugeneruotas pazymys: " << p << endl;
            stud.paz.push_back(p);
            cout << "Ar norite toliau rasyti pazymius? [T/N] "; cin >> testi;
            testi = Iv_raid_patikra(testi, "tn");
            if (testi == 'n'){
                break;
            }
        }
        cout << "Generuojama..." << endl;
        stud.egz = dist(gen);
        cout << "Sugeneruotas egzamino ivertinimas: " << stud.egz << endl;
    }
    else {
        string egz_iv, paz_iv;
        cout << "Iveskite pazymius (baige iveskite 0)." << endl;
        while (true) {
            cout << n << "-asis pazymys: "; cin >> paz_iv;
            laik_paz = Iv_paz_patikra(paz_iv, 0);
            if (laik_paz == 0) {
                if (stud.paz.size() != 0) {
                    break;
                } else {
                    cout << "Prasome ivesti pazymiu!\n";
                }
            }
            else {
                stud.paz.push_back(laik_paz);
                n++;
            }
        }
        cout << "Koks egzamino ivertinimas? "; cin >> egz_iv;
        stud.egz = Iv_paz_patikra(egz_iv, 1);
    }
    stud = Balo_skaiciavimas(stud);
    return(stud);
}

string Failo_patikra(string failo_pav) {
    while (true) {
        ifstream in(failo_pav);
        if(in.fail()) {
            cout << "Failo pavadinimas neteisingas! Bandykite dar karta: "; cin >> failo_pav;
        }
        else {
            in.close();
            break;
        }
    }
    return failo_pav;
}

char Rikiavimo_tipas() {
    char rik;
    cout << "Pasirinkite, pagal ka norite isrikiuoti duomenis:" << endl;
    cout << "[A] pavardes\t[B] vardus\t[C] galutini bala pagal vidurki\t [D] galutini bala pagal mediana" << endl; cin >> rik;
    rik = Iv_raid_patikra(rik, "abcd");
    return rik;
}

pair <string, int> Failo_pasirinkimas() {
    string ivesties_pav;
    char f_tip, rik;
    cout << "Pasirinkite, kokio studentu skaiciaus faila tikrinsite:\n[A] 1.000\t[B] 10.000\t[C] 100.000\t[D] 1.000.000\t[E] 10.000.000\n";
    cin >> f_tip;
    f_tip = Iv_raid_patikra(f_tip, "abcde");
    rik = Rikiavimo_tipas();
    map <char, int> tipai = {{'a', 1000}, {'b', 10000}, {'c', 100000}, {'d', 1000000}, {'e', 10000000}};
    int irasu_sk = tipai[f_tip];
    ivesties_pav = "stud" + to_string(irasu_sk) + ".txt";
    return {ivesties_pav, irasu_sk};
}

vector <Studentas> Rikiavimas_vector(vector <Studentas> Rikiuojamas, char rik) {
    sort(Rikiuojamas.begin(), Rikiuojamas.end(), [rik](const Studentas &a, const Studentas &b) {
        if (rik == 'a') {
            return a.pavarde < b.pavarde;
        } else if (rik == 'b') {
            return a.vardas < b.vardas;
        } else if (rik == 'c') {
            return a.galVid > b.galVid;
        } else {
            return a.galMed > b.galMed;
        }
    });
    return Rikiuojamas;
}

list <Studentas> Rikiavimas_list(list <Studentas> Rikiuojamas, char rik) {
    Rikiuojamas.sort([rik](const Studentas &a, const Studentas &b){
        if (rik == 'a') {
            return a.pavarde < b.pavarde;
        } else if (rik == 'b') {
            return a.vardas < b.vardas;
        } else if (rik == 'c') {
            return a.galVid > b.galVid;
        } else {
            return a.galMed > b.galMed;
        }
    });
    return Rikiuojamas;
}
