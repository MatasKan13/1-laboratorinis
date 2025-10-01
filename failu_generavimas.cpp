#include "failu_generavimas.h"

int patikra(int n) {
    while (true) {
        if (n >= 1 && n <= 99) {
            return n;
        }
        else {
            cout << "Neteisinga ivestis! Bandykite dar karta ([0;99]): "; cin >> n;
        }
    }
}

void failo_kurimas(int nd_sk, int stud_sk) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dist(1,10);
    string failo_pav = "stud" + to_string(stud_sk) + ".txt";
    ostringstream ss;
    ss << setw(15) << left << "Vardas" << setw(16) << left << "Pavarde";
    for (int i = 1; i<=nd_sk; i++) {
        ss << setw(7) << left << "ND" + to_string(i);
    }
    ss << setw(7) << left << "Egz.";
    for (int i = 1; i<=stud_sk; i++) {
        ss << '\n';
        ss << setw(15) << left << "Vardas" + to_string(i) << setw(16) << left << "Pavarde" + to_string(i);
        for (int j = 1; j <= nd_sk+1; j++) {
            int p = dist(gen);
            ss << setw(7) << left << p;
        }
    }
    ofstream out(failo_pav);
    out << ss.str();
    out.close();
}

int main() {
    int nd_sk = 0;
    cout << "Iveskite ND paz. skaiciu (intervale [1;99]): "; cin >> nd_sk;
    nd_sk = patikra(nd_sk);
    cout << "Generuojama..." << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    failo_kurimas(nd_sk, 1000);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "1.000 studentu failas sugeneruotas per " << diff.count() << " s!" << endl;
    start = std::chrono::high_resolution_clock::now();
    failo_kurimas(nd_sk, 10000);
    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "10.000 studentu failas sugeneruotas per " << diff.count() << " s!" << endl;
    start = std::chrono::high_resolution_clock::now();
    failo_kurimas(nd_sk, 100000);
    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "100.000 studentu failas sugeneruotas per " << diff.count() << " s!" << endl;
    start = std::chrono::high_resolution_clock::now();
    failo_kurimas(nd_sk, 1000000);
    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "1.000.000 studentu failas sugeneruotas per " << diff.count() << " s!" << endl;
    start = std::chrono::high_resolution_clock::now();
    failo_kurimas(nd_sk, 10000000);
    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "10.000.000 studentu failas sugeneruotas per " << diff.count() << " s!" << endl;
    diff = std::chrono::high_resolution_clock::now() - st;
    cout << "Visas failu generavimui sugaistas laikas: " << diff.count() << " s!" << endl;
}
