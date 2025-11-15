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
void tambahHistory(const string &isi) {
ofstream file("makan_log.txt", ios::app)
if (!file) {
cout << "Gagal membuka file" << endl;
return;
}
file << isi << endl;
file.close();
}

void tampilHistory() {
ifstream file("makan_log.txt");
if (!file) {
cout << "Belum ada history" << endl;
return;
}
string line;
while (getline(file, line)) {
cout << line << endl;
}
file.close();
}

void hapusHistory() {
ofstream file("makan_log.txt", ios::trunc);
file.close();
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

