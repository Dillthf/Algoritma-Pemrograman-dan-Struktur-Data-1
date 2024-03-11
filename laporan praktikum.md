# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
Tipe data adalah jenis data yang akan disimpan di dalam suatu variabel. Tipe data mendefinisikan metode penyimpanan untuk merepresentasikan informasi dan cara informasi diinterpretasikan [1].
Tipe data membantu pengenalan berbagai macam informasi oleh program. Melalui tipe data juga sistem operasional yang dijalankan dapat dipastikan dan mengurangi risiko terjadi error.

Tipe data terbagi atas:

A. Tipe data primitif

Tipe data ini dikenal juga dengan sebutan tipe data dasar. Tipe data primitif adalah tipe data sederhana dan umunya telah tersedia di berbagai bahasa pemrograman. Contoh tipe data primitif yaitu:

(1) Integer (Int), tipe data ini berupa bilangan bulat dengan jangkauan -2,147,483,648 hingga 2,147,483,647.

(2) Float, tipe data ini berupa bilangan desimal dengan jangkauan 1,17 e-38 hingga 3,4 e+38.

(3) Character (Char) tipe data ini berupa sebuah huruf.

(4) Boolean (bool) tipe data ini berupa pernyataan True yang bernilai 1 dan False yang bernilai 0

B. Tipe data abstrak

Adalah tipe data yang memungkinkan pemogram mendefinisikan tipe data baru menggunakan kelas, dan kemudian mendefinisikan operasi.

C. Tipe data koleksi

Tipe data koleksi adalah tipe data yang digunakan untuk menyimpan sejumlah nilai atau objek sebagai satu kesatuan.

## Guided 

### 1. Tipe Data Primitif

```C++
#include<iostream>
using namespace std;

main()
{
     char op;
     float num1, num2; 
     cin >> op;  
     cin >> num1 >> num2;
     switch (op)
     {
     case '+':
         cout<< num1 + num2;
         break;
     
     case '-':
         cout<< num1 - num2;
         break;
     case '*':
         cout << num1 * num2;
         break;
     case '/':
         cout << num1 / num2;
         break;
     default:
         cout << "Error! operator is not correct";
     } 
     return 0;
}


```
Kode di atas merupakan contoh kalkulator sederhana. Dengan program utamanya melakukan operasi perhitungan dua nilai bilangan. Pengguna dapat menginput operasi (bertipe char) berupa +, -, *, dan / serta dua angka yang akan dioperasikan (bertipe float) sesuai kebutuhan. Inputan aka dieksekusi sesuai case operator yang dimasukkan menggunakan fungsi cout. Jika operator yang dimasukkan tidak sesuai dengan empat case yang ada, maka program akan menghasilkan output "Error! operator is not correct".

### 2. Tipe Data Abstrak
 ```C++
 #include<iostream>
using namespace std;
#include <stdio.h>

struct Mahasiswa
{
     const char *name;
     const char *addres;
     int age;
};

int main()
{

     // menggunakan struct
     struct Mahasiswa mhs1, mhs2;
     // mengisi nilai struct
     mhs1.name = "Dian";
     mhs1.addres = "Mataram";
     mhs1.age = 22;
     mhs2.name = "Bambang";
     mhs2.addres = "Surabaya";
     mhs2.age = 23;

    // mencetak isi struct
     printf("## Mahasiswa 1 ##\n");
     printf("Nama: %s\n", mhs1.name);
     printf("Alamat: %s\n", mhs1.addres);
     printf("Nama: %d\n", mhs1.age);
     printf("## Mahasiswa 2 ##\n");
     printf("Nama: %s\n", mhs2.name);
     printf("Alamat: %s\n", mhs2.addres);
     printf("Nama: %d\n", mhs2.age);
     return 0;
}

 ```

 Kode diatas merupakan program yang menggunakan fungsi struct untuk menyimpan data mahasiswa. Struct Mahasiswa menyimpan data mhs1 dan mhs2 berupa nama, alamat, dan umur. Kemudian data yang disimpanpada struct ditampilkan melalui fungsi print.

 ### 3. Tipe Data Koleksi
 ```C++
 #include<iostream>
using namespace std;
int main ()
{
    // deklarasi dan inisialisasi array
    int nilai [5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // Mencetak array
    cout << "isi array pertama :" << nilai [0] << endl;
    cout << "isi array kedua :" << nilai [1] << endl;
    cout << "isi array ketiga :" << nilai [2] << endl;
    cout << "isi array keempat:" << nilai [3] << endl;
    cout << "isi array kelima :" << nilai [4] << endl;
    return 0;
    
}
 ```

Kode di atas merupakan program yang menggunakan tipe data koleksi berupa array. Program mendeklarasikan dan menginisialisasikan array. Array tersebut berisi 5 nilai yang dimasukkan ke dalam indeks. Kemudian program mencetak array dengan fungsi cout <<.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

int main() {
  float nilai, hasil;
  int pilihan;

  // Menampilkan menu pilihan satuan
  cout << "Pilih satuan yang ingin dikonversi:" << endl;
  cout << "1. Meter ke Kilometer" << endl;
  cout << "2. Kilometer ke Meter" << endl;
  cout << "Masukkan pilihan: ";
  cin >> pilihan;

  // Meminta nilai yang ingin dikonversi
  cout << "Masukkan nilai: ";
  cin >> nilai;

  // Melakukan konversi berdasarkan pilihan
  switch (pilihan) {
    case 1:
      hasil = nilai / 1000;
      cout << nilai << " meter sama dengan " << hasil << " kilometer." << endl;
      break;
    case 2:
      hasil = nilai * 1000;
      cout << nilai << " kilometer sama dengan " << hasil << " meter." << endl;
      break;
    default:
      cout << "Pilihan tidak valid!" << endl;
  }

  return 0;
}
```

Kode di atas merupakan program konversi satuan sederhana. Pengguna dapat mengonversi satuan panjang berupa meter dan juga kilometer. Deklarasi variabel berupa nilai, hasil, dan pilihan. Program mendefinisikan tipe data float pada inputan nilai dan hasil, sehingga memungkinkan operasi dan hasil berupa bilangan desimal. Sementara untuk menjalankan program, inputan yang dimasukkan bertipe ineteger sehingga akan mengeksekusi melalui fungsi cin >>. Program menggunakan swtich untuk mengkonversi berdasarkan pilian pengguna. Kemudian hasil akan ditampilkan di layar. Jika pilihna yang diinput pengguna tidak sesuai maka output yang ditampilkan adalah "Pilihan tidak valid!".
#### Output:

![Screenshot 2024-03-11 103018](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/deb90ae6-0336-487b-b11e-ef1dab4eae23)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full screenshot 

![Screenshot 2024-03-11 103207](https://github.com/Dillthf/Praktikum-Algoritma-dan-Struktur-Data/assets/161497877/9b3f1cba-a2b6-456e-9cd3-e82e9fbc5d3b)

#### Kesimpulan

Tipe data primitif merupakan tipe data yang paling mendasar. Sekaligus menjadi tipe data yang penting dalam setipa pemrograman yang dibuat. Tipe data primitif seperti int, char, float terus digunakan dalam tipe-tipe data lainnya.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
Secara umum kedua fungsi ini dapat digunakan untuk menyimpan data. Namun, kedua fungsi ini memiliki perbedaan spesifik. Class adalah sebuah template untuk membuat objek dengan karakteristik dan kemampuan yang sama. Class memiliki anggota (member) yang terdiri dari variabel (data) dan fungsi (method). Class dapat mewarisi (inheritance) sifat dan kemampuan dari class lain. Class dapat diakses dengan public, private, dan protected access specifier untuk mengatur visibilitas anggota class. Sedangkan struct secara default memiliki public access specifier untuk semua anggotanya. Struct tidak mendukung inheritance. Struct umumnya digunakan untuk membuat struktur data sederhana.

#### Contoh Program
```C++
#include <iostream>
#include <vector>

using namespace std;

// Struct untuk menyimpan data alamat
struct Alamat {
  string Jalan;
  string Kecamatan;
  string Kabupaten;
};

// Class untuk menyimpan data siswa
class Student {
public:
  string name;
  Alamat alamat; // Menggunakan struct Alamat
  vector<int> nilai; // Vektor untuk menyimpan nilai

  // Fungsi untuk menghitung rata-rata nilai
  double calculateAverage() {
    double total = 0;
    for (int grade : nilai) {
      total += grade;
    }
    return total / nilai.size();
  }
};

int main() {
  // Deklarasi objek Student
  Student siswa1;

  // Mengisi data siswa
  siswa1.name = "Avny";
  siswa1.alamat.Jalan = "Jalan Komak";
  siswa1.alamat.Kecamatan = "Nubatukan";
  siswa1.alamat.Kabupaten = "Lembata";
  siswa1.nilai.push_back(87);
  siswa1.nilai.push_back(93);
  siswa1.nilai.push_back(85);

  // Menampilkan data siswa
  cout << "Nama: " << siswa1.name << endl;
  cout << "Alamat: " << siswa1.alamat.Jalan << ", " << siswa1.alamat.Kecamatan << ", " << siswa1.alamat.Kabupaten << endl;

  // Menampilkan rata-rata nilai
  double average = siswa1.calculateAverage();
  cout << "Rata-rata nilai: " << average << endl;

  return 0;
}
```

Kode diatas merupakan contoh program yang menggunakan fungsi class dan struct sekaligus. Program tersebut bertujuan menampilkan data siswa dan juga menghitung nilai dari siswa tersebut. Fungsi struct di program ini berupa struct Alamat yang digunakan untuk menyimpan data alamat siswa. Sedangkan class yang digunakan adalah class student. Class Student menyimpan data nama siswa, alamat, dan nilai. Program ini juga memiliki fungsi calculateAverage() untuk menghitung rata-rata nilai. Main function program ini berupa deklarasi objek Student bernama siswa1. Mengisi data siswa dengan nama, alamat (menggunakan struct Alamat), dan nilai. Menampilkan data siswa dan memanggil fungsi calculateAverage() untuk menampilkan rata-rata nilai.
#### Output:

![Screenshot 2024-03-11 112836](https://github.com/Dillthf/Praktikum-Algoritma-dan-Struktur-Data/assets/161497877/7a4d03ae-39ed-461a-a579-e17b52b6f35c)

#### Full Screenshot

![Screenshot 2024-03-11 112933](https://github.com/Dillthf/Praktikum-Algoritma-dan-Struktur-Data/assets/161497877/c53e728d-adf0-4aea-a7a3-c21afc2d432a)



### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
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


```


Kode di atas merupakan salah satu contoh program yang menggunakan fungsi map. Map dideklarasikan dengan map<string, int>. Ini digunakan untuk menyimpan data tinggi badan dengan key (nama) bertipe string dan value (nilai) bertipe int.
Data ditambahkan ke map dengan menggunakan key dan value. Kemudian dilakukan untuk iterasi seluruh data di map dan menambahkan nilai ke totalTinggi. Rata-rata tinggi badan dihitung dengan membagi totalTinggi dengan jumlah data di map (tinggiBadan.size()). Rata-rata nilai ditampilkan ke layar. Pada program ini mengunakan fungsi double dengan tujuan untuk mendapatkan nilai rata-rata yang akurat, totalTinggi diubah menjadi double sebelum dibagi dengan tinggiBadan.size(). Tipe data double dapat menyimpan nilai floating-point, yang memungkinkan hasil pembagian lebih akurat.
#### Output:

![Screenshot 2024-03-11 105232](https://github.com/Dillthf/Praktikum-Algoritma-dan-Struktur-Data/assets/161497877/e35b64a2-c46a-47b7-9a23-c9216150197f)

#### Full Screenshot
![Screenshot 2024-03-11 110017](https://github.com/Dillthf/Praktikum-Algoritma-dan-Struktur-Data/assets/161497877/d30c6172-3507-4e28-9731-5aea8ed63934)

 #### Perbedaan Array dan Map

Perbedaan antara map dan array dapat dilihat dari urutan data, Pada array data diurutkan berdasarkan indeks sedangkan pada map data tidak diurutkan. Akses data pada array berupa indeks sedangkan map berupa key. Tipe data pada array bertipe sama sedangkan map dapat memuat beragam tipe. Pada array diizinkan duplikasi data, sedangkan pada map karena karakteristik key unik sehingga tidak dapat menduplikasi data. Perbedaan terakhir berupa kecepatan operasi. Array cepat untuk operasi akses dan modifikasi data sedangkan map lebih lambat untuk operasi akses dan modifikasi data.


## Kesimpulan

Tipe data terdiri dari berbagai macam yang kemudian digunakan sesuai kebutuhan pembuatan program. Pemahaman akan tipe-tipe data diperlukan sebagai dasar pemrograman. Pemahaman yang baik akan menciptakan dan meningkatkan kemampuan mahasiswa untuk mengenali dan membedakan tipe-tipe data sehingga mahasiswa dapat memilih tipe data yang tepat sesuai kebutuhan. Dengan adanya praktikum terkait tipe data juga membantu mahasiswa untuk meningkatkan keefetifan program yang dibuat.
 

## Referensi

[1] S. Hanief, I. Jepriana, Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. I. Yogyakarta : Andi, 2020
