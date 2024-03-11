#include <iostream>
#include <map>

using namespace std;

int main() {
  // Deklarasi map untuk menyimpan data tinggi badan
  map<string, int> tinggiBadan;

  // Menambahkan data ke map
  tinggiBadan["Woozie"] = 166;
  tinggiBadan["Mingyu"] = 187;
  tinggiBadan["The8"] = 178;

  // Menghitung total tinggi badan
  int totalTinggi = 0;
  for (auto it = tinggiBadan.begin(); it != tinggiBadan.end(); ++it) {
    totalTinggi += it->second;
  }

  // Menghitung rata-rata tinggi badan
  double rataRata = (double)totalTinggi / tinggiBadan.size();

  // Menampilkan hasil
  cout << "Rata-rata tinggi badan : " << rataRata << endl;

  return 0;
}