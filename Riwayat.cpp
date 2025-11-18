#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void simpanKeFile(int jumlah, int kategori[], int skor, string status, string warning) {
    ofstream file("Riwayat.txt", ios::app);
    file << "Jumlah makan: " << jumlah << endl;
    file << "Kategori: ";
    for (int i = 0; i < jumlah; i++) {
        file << kategori[i] << " ";
    }
    file << endl;
    file << "Skor kesehatan: " << skor << endl;
    file << "Status: " << status << endl;
    file << "Pengingat: " << warning << endl;
    file << "-----------------------------------------" << endl;
    file.close();
}

void tampilkanRiwayat() {
    ifstream readFile("Riwayat.txt");
    if (!readFile) {
        cout << endl << "Belum ada riwayat tersimpan." << endl;
        return;
    }

    cout << endl << "=== RIWAYAT MAKAN ===" << endl << endl;
    string line;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();
}
