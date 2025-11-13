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
ofstream file(".txt", ios::app)
if (!file) {
cout << "Gagal membuka file" << endl;
return;
}
file << isi << endl;
file.close();
}

void tampilHistory() {
ifstream file(".txt");
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
ofstream file(".txt", ios::trunc);
file.close();
}

// Fungsi utama
int main() {

   
    return 0;
}

