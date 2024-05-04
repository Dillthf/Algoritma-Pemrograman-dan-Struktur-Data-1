#include <iostream>
#include <stack> 

using namespace std;

bool isPalindrome(string str) { // fungsi mengembalikan nilai true atau false
  // Membuat stack kosong
  stack<char> kalimat; // meginisialisasi stack berisi karakter dengan nama kalimat

  // Perulangan untuk menambah semua karakter ke dalam stack (menggunakan fungsi push)
  for (char ch : str) {
    kalimat.push(ch);
  }

  // Menguji apakah kalimat yang dimasukkan pengguna adalah palindrom 
  string kataTerbalik = "";
  while (!kalimat.empty()) { // jika stack kalimat kosong atau bernilai true, maka fungsi dijalankan
    kataTerbalik += kalimat.top(); // mengambil karakter terakhir yang dimasukkan, kemudian menambahkan karakter ke akhir string menggunakan operator +=
    kalimat.pop(); // Menghapus elemen teratas dari stack kalimat
  }

  return str == kataTerbalik; // Mengembalikan nilai dari fungsi dengan memeriksa apakah str (string) sama dengan kataTerbalik
}

int main() {
  string str;

  // Pengguna memasukkan kalimat yang diinginkan
  cout << "Masukkan kalimat: ";
  getline(cin, str);

  // Menguji apakah kalimat itu termasuk palindrom atau bukan
  if (isPalindrome(str)) {
    cout << str << " adalah kalimat palindrom" << endl;
  } else {
    cout << str << " bukan kalimat palindrom" << endl;
  }

  return 0;
}
