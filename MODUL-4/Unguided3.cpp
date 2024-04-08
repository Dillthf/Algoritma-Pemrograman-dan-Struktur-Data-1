#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]);
  int jumlah_angka_4 = 0;

  // Mencari jumlah angka 4 dengan Sequential Search
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      jumlah_angka_4++;
    }
  }

  // Menampilkan hasil
  cout << "Jumlah angka 4 dalam data: " << jumlah_angka_4 << endl;

  return 0;
}
