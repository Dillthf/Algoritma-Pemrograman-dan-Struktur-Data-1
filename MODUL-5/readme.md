# <h1 align="center">Laporan Praktikum Modul Struct dan Implementasi</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
A. Variabel
Berdasarkan ruang lingkupnya, variabel dibedakan menjadi dua, yaitu variabel lokal dan variabel global. Penentuan variabel sebagai variabel global atau lokal akan tergantung dari penempatannya di dalam program. Variabel lokal hanya dapat digunakan di dalam blok fungsi di mana variabel tersebut dideklarasikan. Sedakan variabel global didefinisikan di luar blok atau fungsi sehingga dapat digunakan pada blok fungsi manapun [1].
B. Struct
Struktur adalah kumpulan item data (bidang) atau variabel dari tipe data berbeda yang direferensikan dengan nama yang sama. Ini menyediakan cara yang mudah untuk menyimpan informasi terkait bersama-sama. Kata kunci struct memberi tahu kompiler bahwa templat struktur sedang ditentukan, yang dapat digunakan untuk membuat variabel struktur. Bidang-bidang yang membentuk struktur disebut anggota atau elemen struktur. Semua elemen dalam suatu struktur secara logis berhubungan satu sama lain [2].

## Guided 
### Guided 1
##### Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan 

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}

```

Kode program ini dibuat untuk menyimpan informasi tentang buku favorit. Program dibuat dengan mendefinisikan sebuah struct yang diiberi nama buku untuk menampung informasi tentang sebuah buku. Berikutnya terdapat fungsi untuk mengisi tiap-tiap atribut struct yang ada sesuai data buku favorit. Kemudian menanmpilkan struct tersebut sebagai informasi sebuah buku.

### Guided 2
#### Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![Screenshot 2024-04-29 064252](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/7733f84d-792e-4cff-9c6f-9d197e323361)

 ```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}

 ```

Kode program ini bertujuan menyimpan informasi terkait hewanmenurut beberapa klasifikasi menggunakan struct. Program mendefinisikan 3 struct berbeda, yaitu hewan, hewanDarat, dan hewanLaut. Kemudian setiap informasi hewan dimasukkan sebagai data yang mengisi tiap-tiap atribut pada ketiga elemen tersebut.

## Unguided 

### 1.Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.


```C++
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
  // judulBuku: array string dengan ukuran 5 untuk menyimpan judul buku.
  favorit.judulBuku[0] = "Tetaplah Bodoh Jangan Pintar";
  favorit.judulBuku[1] = "Gadis Kota Jerash";
  favorit.judulBuku[2] = "Sang Pemimpi";
  favorit.judulBuku[3] = "Ronggeng Dukuh Paruk";
  favorit.judulBuku[4] = "Digital Fortress";

// pengarang: array string dengan ukuran 5 untuk menyimpan nama pengarang.
  favorit.pengarang[0] = "Tere Liye";
  favorit.pengarang[1] = "Habiburrahman El Shirazy";
  favorit.pengarang[2] = "Andrea Hirata";
  favorit.pengarang[3] = "Ahmad Tohari";
  favorit.pengarang[4] = "Dan Brown";

//  penerbit: array string dengan ukuran 5 untuk menyimpan nama penerbit.
  favorit.penerbit[0] = "Sabak Grip Nusantara ";
  favorit.penerbit[1] = "Lingkar Pena Publishing House";
  favorit.penerbit[2] = "Bentang";
  favorit.penerbit[3] = "Gramedia Pustaka Utama";
  favorit.penerbit[4] = "Serambi";

// tebalHalaman: array integer dengan ukuran 5 untuk menyimpan tebal halaman.
  favorit.tebalHalaman[0] = 371;
  favorit.tebalHalaman[1] = 268;
  favorit.tebalHalaman[2] = 289;
  favorit.tebalHalaman[3] = 408;
  favorit.tebalHalaman[4] = 567;

// hargaBuku: array integer dengan ukuran 5 untuk menyimpan harga buku.
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
```

Kode di atas akan menampilkan daftar 5 buku favorit dengan informasi lengkap (judul, pengarang, penerbit, tebal halaman, harga). Kode tersebut berisi 3 perintah penting yaitu mendefinisikan array yang berisi struct dalam setiap elemen, mengisi data di setiap atribut struct, dan menampilkan data-data tersebut. 
#### Output:
![Screenshot 2024-04-29 010226](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/09143570-4916-4cf3-9286-c536ce0611d9)
![Screenshot 2024-04-29 010232](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/4cc26b6a-eed9-4bb6-b048-a09bf52b7e2e)
#### Full screenshot 
![Screenshot 2024-04-29 010248](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f4c54234-33ec-4455-8bb8-6a0fb45c1775)



### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

Jika variabel struct yang dibuat pada tugas guided I berjenis array maka akan menghasilkan array yang setiap elemennya merupakan struct. Ini memungkinkan menyimpan banyak data dengan tipe data yang sama dalam satu struktur. Contohnya dapat dilihat pada unguided satu, dimana variabel dideklarasikan sebagai array dengan 5 elemen, yang setiap elemen berupa struct berisi data buku dari 5 buku berbeda. Untuk mengisi data diisi sesuai atribut, contohnya pada guided satu dengan atribut berupa judul buku, pengarang, penerbit, tebal halaman, dan harga buku. Setiap data diisi sesuai elemen array secara berurutan. Untuk menampilkannya di dalam perulangan for, sehingga setiap buku akan dicetak satu persatu dengan mengakses nilai dari array pada indeks yang sesuai, dan ditampilkan menggunakan fungsi cout.

## Kesimpulan

Struct merupakan salah satu fungsi yang menjadi pilihan dalam menyimpan suatu informasi. Dengan menggunakan struct data akan diklasifikasi secara spesifik di setiap atribut struct. Anggota-anggota struct terdiri dari variabel fungsi. 
Praktikum struct memudahkan untuk memahami cara mendefinisikan struct, mengisi data ke dalam struct, dan mengakses data dari struct.

## Referensi

[1] A. D. Samala, B. Ramadhani, F. Ranurja, Pemrograman C++, Padang: UNP Press, 2021. 
[2] S. N Mohanty, P. K. Tripathy, Data Structure and Algorithms Using C++ A Practical Implementation, USA: Wiley, 2021. 
