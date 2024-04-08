#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Deklarasi variabel
  string kalimat;
  int jumlah_vokal = 0;
  vector<char> huruf_vokal;

  // Meminta input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Mengubah semua huruf menjadi huruf kecil
  for (int i = 0; i < kalimat.length(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Mencari jumlah huruf vokal dan menyimpan huruf vokal yang ditemukan
  for (int i = 0; i < kalimat.length(); i++) {
    if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o') {
      jumlah_vokal++;
      huruf_vokal.push_back(kalimat[i]);
    }
  }

  // Menampilkan hasil
  cout << "Jumlah huruf vokal dalam kalimat: " << jumlah_vokal << endl;
  cout << "Huruf vokal yang ditemukan: ";
  for (char vokal : huruf_vokal) {
    cout << vokal << " ";
  }
  cout << endl;

  return 0;
}

