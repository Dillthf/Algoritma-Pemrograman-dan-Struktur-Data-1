#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Deklarasi fungsi
void selection_sort(string &kalimat);
void binary_search(string kalimat, char huruf);

int main() {
    // Menampilkan judul pencarian
    cout << "Pencarian huruf dalam kalimat" << endl;

    // Deklarasi variabel
    string kalimat;
    char huruf;

    // Meminta input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat); // Menggunakan getline() untuk membaca seluruh baris

    // Meminta input huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Mengurutkan kalimat dengan selection sort
    selection_sort(kalimat);

    // Menampilkan kalimat yang sudah diurutkan
    cout << "\nKalimat yang sudah diurutkan: " << endl;
    for (int i = 0; i < kalimat.length(); i++) {
        cout << setw(3) << kalimat[i];
    }
    cout << endl;

    // Mencari huruf dengan binary search
    binary_search(kalimat, huruf);

    // Menekan tombol apa pun untuk keluar
    cout << "\nTekan tombol apa pun untuk keluar...";
    _getch();

    return 0;
}

// Fungsi selection sort untuk mengurutkan string
void selection_sort(string &kalimat) {
    for (int i = 0; i < kalimat.length() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < kalimat.length(); j++) {
            if (kalimat[j] < kalimat[min_idx]) {
                min_idx = j;
            }
        }

        // Menukar karakter pada indeks minimum dengan karakter pada indeks i
        char temp = kalimat[i];
        kalimat[i] = kalimat[min_idx];
        kalimat[min_idx] = temp;
    }
}

// Fungsi binary search untuk mencari huruf dalam kalimat
void binary_search(string kalimat, char huruf) {
    // Menentukan batas awal dan akhir pencarian
    int low = 0;
    int high = kalimat.length() - 1;

    // Inisialisasi flag ditemukan
    bool found = false;

    // Inisialisasi indeks pertama kali ditemukan
    int firstIndex = -1;

    // Melakukan loop binary search
    while (low <= high && !found) {
        // Menghitung indeks tengah
        int mid = (low + high) / 2;

        // Membandingkan huruf dengan karakter pada indeks tengah
        if (kalimat[mid] == huruf) {
            // Huruf ditemukan
            found = true;

            // Jika ini merupakan huruf pertama kali ditemukan, simpan indeksnya
            if (firstIndex == -1)
                firstIndex = mid;

            // Menampilkan hasil
            cout << "\nHuruf '" << huruf << "' ditemukan pada indeks " << mid << endl;
        } else if (kalimat[mid] < huruf) {
            // Huruf yang dicari berada di bagian kanan
            low = mid + 1;
        } else {
            // Huruf yang dicari berada di bagian kiri
            high = mid - 1;
        }
    }

    // Jika huruf tidak ditemukan
    if (!found) {
        cout << "\nHuruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    } else if (firstIndex != -1) {
        // Menampilkan indeks lain jika huruf ditemukan lebih dari satu kali
        int currentIndex = firstIndex;
        while (kalimat[currentIndex] == huruf && currentIndex < kalimat.length()) {
            if (currentIndex != firstIndex)
                cout << "Dan juga ditemukan pada indeks " << currentIndex << endl;
            currentIndex++;
        }
    }
}

