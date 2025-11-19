#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int hitungSkor(int kategori[], int jumlah) {
    int skor = 0;
    for (int i = 0; i < jumlah; i++) {
        if (kategori[i] == 1) skor += 3;
        else if (kategori[i] == 2) skor -= 1;
        else if (kategori[i] == 3) skor -= 2;
        else if (kategori[i] == 4) skor -= 1;
        else if (kategori[i] == 5) skor += 2;
    }
    return skor;
}

string tentukanStatus(int skor) {
    if (skor >= 5) return "Sangat Sehat";
    else if (skor >= 1) return "Cukup Sehat";
    return "Kurang Sehat";
}