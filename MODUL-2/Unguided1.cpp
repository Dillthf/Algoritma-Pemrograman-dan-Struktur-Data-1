#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel
  int x, i;
  
  // Input panjang array
  cout << "Masukkan panjang array: ";
  cin >> x;
  
  // Deklarasi array
  int arr[x];
  
  // Input data array
  cout << "Masukkan Data Array: ";
  for (i = 0; i < x; i++) {
    cin >> arr[i];
  }
  
  // Menampilkan output array
  cout << "Data Array: ";
  for (i = 0; i < x; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  // Menampilkan nomor genap
  cout << "Nomor Genap : ";
  for (i = 0; i < x; i++) { // perulangan untuk mencari nilai genap dari array
    if (arr[i] % 2 == 0) { 
      cout << arr[i] << " "; 
    }
  }
  cout << endl;
  
  // Menampilkan nomor ganjil
  cout << "Nomor Ganjil : ";
  for (i = 0; i < x; i++) { // perulangan untuk mencari nilai ganjil dari array
    if (arr[i] % 2 == 1) { 
      cout << arr[i] << " ";
    }
  }
  cout << endl;
  
  return 0;
}
