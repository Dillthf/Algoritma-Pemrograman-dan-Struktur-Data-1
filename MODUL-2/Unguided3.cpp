#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel
  int n, i, maks, min, lokasi;
  float total = 0;

  // Input jumlah elemen array
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  // Deklarasi array
  int arr[n];

  // Input data array
  cout << "Masukkan data array: ";
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Mencari nilai maksimum
  maks = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] > maks) {
      maks = arr[i];
      lokasi = i;
    }
  }

  // Mencari nilai minimum
  min = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  // Menghitung nilai rata-rata
  for (i = 0; i < n; i++) {
    total += arr[i];
  }
  float rata = total / n;

  // Output hasil
  cout << "Nilai maksimum adalah " << maks <<  endl;
  cout << "Nilai minimum adalah " << min  << endl;
  cout << "Nilai rata-rata adalah " << rata << endl;

  return 0;
}
