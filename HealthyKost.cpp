#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//pengerjaan projek ini akan bibagi menjadi beberapa bagian 

// Bagian 1: Menu & Navigasi

// Bagian 2: Input Makanan Harian

// Bagian 3: Analisis Pola Makan

// Bagian 4: Sistem Peringatan

// Bagian 5: Penyimpanan & Riwayat
void simpanKeFile(int jumlah, int kategori[], int skor, string status, string warning) {
ofstream file("Riwayat.txt", ios::app);
file << "Jumlah makan: " << jumlah << endl;
file << "Kategori: ";
for (int i = 0; i < jumlah; i++) {
file << kategori[i] << " ";
}
file << endl;
file << "Skor kesehatan: " << status << endl;
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

// Fungsi utama
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

