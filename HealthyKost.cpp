#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void inputMakan() {
    int jumlah;
    cout << endl << "Masukkan jumlah makan hari ini: ";
    cin >> jumlah;

    int kategori[50];
    cout << endl;
    cout << "1. Makanan Sehat (+3)" << endl;
    cout << "2. Cepat Saji (-1)" << endl;
    cout << "3. Mie Instan (-2)" << endl;
    cout << "4. Gorengan (-1)" << endl;
    cout << "5. Protein (+2)" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "Makanan ke-" << i + 1 << " (1-5): ";
        cin >> kategori[i];
    }

    int skor = hitungSkor(kategori, jumlah);
    string status = tentukanStatus(skor);
    string warning = buatPeringatan(jumlah, kategori, skor);

    cout << endl << "=== Ringkasan Makan Hari Ini ===" << endl;
    cout << "Jumlah makan: " << jumlah << endl;
    cout << "Kategori makan: ";
    for (int i = 0; i < jumlah; i++) {
        cout << kategoriMakan(kategori[i]) << " | ";
    }
    cout << endl;
    cout << "Skor kesehatan: " << skor << endl;
    cout << "Status: " << status << endl;
    cout << "Peringatan:" << endl << warning;

    simpanKeFile(jumlah, kategori, skor, status, warning);

    cout << endl << "Data berhasil disimpan ke Riwayat.txt" << endl;
}

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
