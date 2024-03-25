#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel
  int dimensi, x, y, z;

  // Input jumlah dimensi (maksimal 3)
  cout << "Masukkan jumlah dimensi array (maksimum 3): ";
  cin >> dimensi;

  // Validasi input dimensi
  if (dimensi < 1 || dimensi > 3) {
    cout << "Error: Dimensi array harus antara 1 sampai 3." << endl;
    return 1;
  }

  // Deklarasi array sesuai dimensi
  int arr[dimensi][dimensi][dimensi]; // Maksimal 3 dimensi

  // Input elemen
  for (x = 0; x < dimensi; x++) {
    for (y = 0; y < dimensi; y++) {
      for (z = 0; z < dimensi; z++) {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }

  // Output Array
  for (x = 0; x < dimensi; x++) {
    for (y = 0; y < dimensi; y++) {
      for (z = 0; z < dimensi; z++) {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;

  cout << endl;
  // Tampilan array
  for (int x = 0; x < dimensi; x++)
  {
    for (int y = 0; y < dimensi; y++)
    {
      for (int z = 0; z < dimensi; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
