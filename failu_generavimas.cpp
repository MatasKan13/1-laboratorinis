#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <sstream>
#include <string>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::to_string;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::ostringstream;
using std::ofstream;
using std::string;

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
        ss << endl;
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
    failo_kurimas(nd_sk, 1000);
    cout << "1.000 studentu failas sugeneruotas!" << endl;
    failo_kurimas(nd_sk, 10000);
    cout << "10.000 studentu failas sugeneruotas!" << endl;
    failo_kurimas(nd_sk, 100000);
    cout << "100.000 studentu failas sugeneruotas!" << endl;
    failo_kurimas(nd_sk, 1000000);
    cout << "1.000.000 studentu failas sugeneruotas!" << endl;
    failo_kurimas(nd_sk, 10000000);
    cout << "10.000.000 studentu failas sugeneruotas!" << endl;
}