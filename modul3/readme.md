# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
Pengurutan data (sorting) adalah suatu proses pengurutan data yang tersusun secara acak pada suatu pola tertentu,  sehingga tersusun secara teratur menurut aturan tertentu. Pengurutan ini dapat dilakukan dengan cara Ascending dan descending serta digunakan juga untuk mengurutkan data yang bertipe angka atau karakter [1].

Algoritma Sorting terbagi atas:

A. Insertion Sort

Insertion Sort adalah sebuah algortima sederhana yang cukup efisien untuk mengurutkan sebuah list yang hampir terurut. Algoritma ini juga bisa digunakan sebagai bagian algoritma yang lebih canggih. Cara kerja algoritma ini adalah dengan  mengambil elemen list satu-per-satu dan memasukkannya di posisi yang benar seperti namanya. Pada array, list yang baru dan elemen sisanya dapat berbagi tempat di array, meskipun cukup rumit. Untuk menghemat memori, implementasinya menggunakan pengurutan di tempat yang membandingkan elemen saat itu dengan elemen sebelumnya yang sudah diurut, lalu menukarnya terus sampai posisinya tepat. Hal ini terus dilakukan sampai tidak ada elemen tersisa di input [2]. 

B. Selection Sort

Selection sort adalah suatu metode pengurutan yang membandingkan elemen yang sekarang dengan elemen berikutnya sampai ke elemen yang terakhir. Jika ditemukan elemen lain yang lebih kecil dari elemen sekarang maka dicatat posisinya dan langsung ditukar [3].
Metode selection sort adalah melakukan pemilihan dari suatu nilai yang terkecil dan kemudian menukarnya dengan elemen paling awal, lalu membandingkan dengan elemen yang sekarang dengan elemen berikutnya sampai dengan elemen terakhir, perbandingan dilakukan terus sampai tidak ada lagi pertukaran data [1]


C. Bubble Sort

Bubble sort adalah suatu metode pengurutan yang membandingkan elemen yang sekarang dengan elemen berikunya, jika elemen sekarang > elemen berikutnya maka posisinya ditukar, kalau tidak, tidak perlu ditukar [3].Algoritma bubble sort ini melakukan perbandingan antara setiap elemen kemudian melakukan   penukaran jika terdapat elemen yang tidak sesuai urutannya atau salah. Perbandingan akan terus dilakukan sehingga tidak ada lagi pertukaran data [1].


## Guided 

### Guided 1
##### Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }// end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_short

void print_array(double a[], int length){

    for(int i = 0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

}

int main(){
    
    int length =5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```

Kode di atas merupakan contoh kalkulator sederhana. Dengan program utamanya melakukan operasi perhitungan dua nilai bilangan. Pengguna dapat menginput operasi (bertipe char) berupa +, -, *, dan / serta dua angka yang akan dioperasikan (bertipe float) sesuai kebutuhan. Inputan aka dieksekusi sesuai case operator yang dimasukkan menggunakan fungsi cout. Jika operator yang dimasukkan tidak sesuai dengan empat case yang ada, maka program akan menghasilkan output "Error! operator is not correct".

### Guided 2
#### Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

 ```C++
 #include <iostream>
using namespace std;

void insertion_sort(char arr[], int length){
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j -1] = tmp;
            j--;
        }//end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main (){

    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);

}
 ```

 Kode diatas merupakan program yang menggunakan fungsi struct untuk menyimpan data mahasiswa. Struct Mahasiswa menyimpan data mhs1 dan mhs2 berupa nama, alamat, dan umur. Kemudian data yang disimpanpada struct ditampilkan melalui fungsi print.


## Unguided 

### 1.Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

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


#### Full screenshot 

![Screenshot 2024-03-11 103207](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/517bd842-4108-4e96-99ac-6de4aa9c7e19)


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

![Screenshot 2024-03-11 112836](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/941e48f2-d3ab-4991-b1a2-04398b40b15d)

#### Full Screenshot

![Screenshot 2024-03-11 112933](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/a9fbcbc1-0e51-4d69-92b7-aba51271bc70)


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

![Screenshot 2024-03-11 105232](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/67f11a46-0dd9-4298-9f5b-a7f15dcaae3e)

#### Full Screenshot

![Screenshot 2024-03-11 110017](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/69121829-0b5a-48c6-ac10-c4b96a232ed7)


 #### Perbedaan Array dan Map

Perbedaan antara map dan array dapat dilihat dari urutan data, Pada array data diurutkan berdasarkan indeks sedangkan pada map data tidak diurutkan. Akses data pada array berupa indeks sedangkan map berupa key. Tipe data pada array bertipe sama sedangkan map dapat memuat beragam tipe. Pada array diizinkan duplikasi data, sedangkan pada map karena karakteristik key unik sehingga tidak dapat menduplikasi data. Perbedaan terakhir berupa kecepatan operasi. Array cepat untuk operasi akses dan modifikasi data sedangkan map lebih lambat untuk operasi akses dan modifikasi data.


## Kesimpulan

Tipe data terdiri dari berbagai macam yang kemudian digunakan sesuai kebutuhan pembuatan program. Pemahaman akan tipe-tipe data diperlukan sebagai dasar pemrograman. Pemahaman yang baik akan menciptakan dan meningkatkan kemampuan mahasiswa untuk mengenali dan membedakan tipe-tipe data sehingga mahasiswa dapat memilih tipe data yang tepat sesuai kebutuhan. Dengan adanya praktikum terkait tipe data juga membantu mahasiswa untuk meningkatkan keefetifan program yang dibuat.
 

## Referensi

[1] S. Hanief, I. Jepriana, Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. I. Yogyakarta : Andi, 2020
