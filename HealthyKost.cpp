#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string kategoriMakan(int k) {
    switch (k) {
        case 1: return "Makanan Sehat";
        case 2: return "Cepat Saji";
        case 3: return "Mie Instan";
        case 4: return "Gorengan";
        case 5: return "Protein";
        default: return "Tidak Diketahui";
    }
}
// Bagian Penyimpanan Riwayat Makan
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

// Bagian Analisis Kesehatan Sederhana

// Bagian Sistem Peringatan

// Bagian Input Makanan Harian

// Bagian Menu & Navigasi 
int main() {
    int pilihan;

    do {
        cout << "=== PROGRAM TRACKING MAKAN ANAK KOST ===" << endl;
        cout << "1. Input makan hari ini" << endl;
        cout << "2. Lihat riwayat makan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            inputMakan();
        }
        else if (pilihan == 2) {
            tampilkanRiwayat();
        }
        else if (pilihan == 3) {
            cout << endl << "Terima kasih telah menggunakan program." << endl;
        }
        else {
            cout << endl << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 3);

    return 0;
}
