#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n; // Mendeklarasikan variabel n untuk menyimpan jumlah karakter
  cout << "Masukkan jumlah karakter: " << endl; // Meminta user untuk memasukkan nilai n dan menyimpannya dalam variabel n
  cin >> n;

  char karakter[n]; // Mendeklarasikan array karakter karakter dengan ukuran n

  // Meminta user untuk memasukkan karakter
  cout << "Masukkan " << n << " karakter: " << endl;
  for (int i = 0; i < n; i++) {
    cin >> karakter[i];
  }

  // Sorting karakter secara ascending
  for (int i = 0; i < n - 1; ++i) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n
    for (int j = i + 1; j < n; j++) { // Perulangan for ini memulai dari indeks j = i + 1 dan berhenti ketika indeks j menjadi sama dengan n
      if (karakter[i] > karakter[j]) { // Di dalam perulangan kedua, karakter pada indeks i dibandingkan dengan karakter pada indeks j dengan operator >
        swap(karakter[i], karakter[j]); // Jika karakter pada indeks i lebih besar dari karakter pada indeks j, maka kedua karakter tersebut ditukar
      } // Akhir if
    } // Akhir perulangan for
  } // Akhir perulangan for

  // Menampilkan hasil sorting ascending
  cout << "Karakter setelah sorting ascending: " << endl;
  for (int i = 0; i < n; ++i) {  //  mengulang dari indeks 0 sampai n-1
    cout << karakter[i] << endl; // Di dalam perulangan, karakter pada indeks i dicetak ke layar
  }

  // Sorting karakter secara descending
  for (int i = 0; i < n - 1; i++) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n
    for (int j = i + 1; j < n; j++) { // Perulangan for ini memulai dari indeks j = i + 1 dan berhenti ketika indeks j menjadi sama dengan n
      if (karakter[i] < karakter[j]) { // Di dalam perulangan kedua, karakter pada indeks i dibandingkan dengan karakter pada indeks j dengan operator <
        swap(karakter[i], karakter[j]); // Jika karakter pada indeks i lebih kecil dari karakter pada indeks j, maka kedua karakter tersebut ditukar
      } // Akhir if
    } // Akhir perulangan for
  } // Akhir perulangan for

  // Menampilkan hasil sorting descending
  cout << "Karakter setelah sorting descending: " << endl; 
  for (int i = 0; i < n; i++) {  //  mengulang dari indeks 0 sampai n-1
    cout << karakter[i] << endl; 
  }
  

  return 0;
}