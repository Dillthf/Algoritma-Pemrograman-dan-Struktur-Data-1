#include <iostream>

using namespace std;

// Mendefinisikan struktur buku dengan array
struct buku {
  string judulBuku[5];
  string pengarang[5];
  string penerbit[5];
  int tebalHalaman[5];
  int hargaBuku[5];
};

int main() {
  // Mendeklarasikan variabel favorit dengan tipe buku
  buku favorit;

  // Mengisi data ke dalam array dalam variabel favorit
  favorit.judulBuku[0] = "Tetaplah Bodoh Jangan Pintar";
  favorit.judulBuku[1] = "Gadis Kota Jerash";
  favorit.judulBuku[2] = "Sang Pemimpi";
  favorit.judulBuku[3] = "Ronggeng Dukuh Paruk";
  favorit.judulBuku[4] = "Digital Fortress";

  favorit.pengarang[0] = "Tere Liye";
  favorit.pengarang[1] = "Habiburrahman El Shirazy";
  favorit.pengarang[2] = "Andrea Hirata";
  favorit.pengarang[3] = "Ahmad Tohari";
  favorit.pengarang[4] = "Dan Brown";

  favorit.penerbit[0] = "Sabak Grip Nusantara ";
  favorit.penerbit[1] = "Lingkar Pena Publishing House";
  favorit.penerbit[2] = "Bentang";
  favorit.penerbit[3] = "Gramedia Pustaka Utama";
  favorit.penerbit[4] = "Serambi";

  favorit.tebalHalaman[0] = 371;
  favorit.tebalHalaman[1] = 268;
  favorit.tebalHalaman[2] = 289;
  favorit.tebalHalaman[3] = 408;
  favorit.tebalHalaman[4] = 567;

  favorit.hargaBuku[0] = 99000;
  favorit.hargaBuku[1] = 107000;
  favorit.hargaBuku[2] = 79000;
  favorit.hargaBuku[3] = 117920;
  favorit.hargaBuku[4] = 165000;

  // Menampilkan informasi buku favorit
  cout << "\tDaftar Buku Favorit Saya" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "\n\tBuku ke-" << i + 1 << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
    cout << "\tPengarang : " << favorit.pengarang[i] << endl;
    cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
  }

  return 0;
}
