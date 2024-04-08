# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
Searching (Pencarian) data merupakan proses yang fundamental dalam pengolahan data. Proses pencarian adalah menemukan nilai (data) tertentu di dalam sekumpulan data yang bertipe sama, baik bertipe dasar atau bertipe bentukan [1].


A. Sequential Search

Algortima sequential searching adalah pencarian data semantik menggunakan teknologi array 
satu dimensi untuk melakukan proses pencarian tanpa melalui semua elemen array secara berurutan, sehingga 
tidak perlu dilakukan pengurutan data terlebih dahulu [2].
 

B. Binary Search

Algoritma binary search merupakan sebuah teknik pencarian data dengan cara berulang kali membagi separuh dari jumlah data yang dicari sehingga memperkecil lokasi pencarian sampai menjadi satu data [3]. Dengan teknik ini data akan dibuang setengah dari jumlah data. Apabila ditemukan kecocokan data maka program akan mengembalikan output, jika tidak pencarian akan terus berlanjut hingga akhir dari pembagian jumlah data tersebut. Dua kemungkinan yang akan terjadi yaitu data yang dicari ditemukan atau data  tersebut tidak ditemukan. Algoritma binary search ini sering digunakan dalam pencarian data karena kompleksitas dari algoritma ini adalah Ο(log n) [4].


## Guided 

### Guided 1
##### Membuat sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data. 

Source code:
```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data [n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

Kode tersebut adalah contoh program pengaplikasian dari algoritma sequential search. Program dimulai dengan deklarasi variabel berupa “n” yaitu jumlah elemen dalam array, “data” yaitu array yag berisis kumpulan data yang akan dicari. “cari” elemen yang ingin dicari dalam array,  “ketemu” yaitu variabel boolean yang menandakan apakah elemen "cari" ditemukan dalam array, dan “I” yaitu variabel untuk iterasi dalam proses pencarian. Program dilanjutkan dengan sequential search. Sequential search pada program memiliki perulangan for yang akan mengiterasi melalui setiap elemen dalam array. Setiap elemen akan diperiksa satu persatu. Jika elemen yang sedang diperiksa sama dengan elemen “cari”, maka variabel “ketemu” diubah menjadi “true”, dan iterasi dihentikan dengan menggunakan “break”. Setelah pencarian selesai, program akan mencetak hasilnya. Jika "ketemu" bernilai "true", program akan mencetak bahwa elemen "cari" ditemukan pada indeks keberapa dalam array. Jika "ketemu" masih "false" setelah iterasi selesai, program akan mencetak bahwa elemen "cari" tidak ditemukan dalam array.

### Guided 2
#### Membuat sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

Source Code:

 ```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i,j;
    for(i = 0; i < length; i++) {
        min = i;
        for(j = i + 1; j < length; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH" << endl;
    cout << "\n Data : ";

    // Tampilkan data awal
    for (int x = 0; x < length; x++)
        cout << setw(3) << data [x];
    cout << endl;

    cout<<"\n Masukkan data yang ingin Anda cari : ";
    cin>>cari;
    cout<<"\n Data diurutkan : ";
    //urutkan data dengan selection sort
    selection_sort(data, length);
    //tampilkan data setelah diurutkan
    for(int x = 0; x<7;x++)
          cout << setw(3) << data[x];
    cout << endl;
    
       binarysearch(data, length);

    _getche();
    return EXIT_SUCCESS;
}   

 ```

Kode tersebut adalah contoh program pengaplikasian dari algoritma binary search. Program ini menggunakan library "conio.h" untuk fungsi "_getche()" yang digunakan untuk membaca karakter dari keyboard tanpa menunggu, dan "iomanip" untuk manipulasi tampilan output. Deklarasi variabel "cari" digunakan untuk menyimpan nilai yang ingin dicari dalam array. Fungsi "selection_sort()" digunakan untuk mengurutkan array menggunakan algoritma selection sort, sedangkan fungsi "binarysearch()" digunakan untuk melakukan pencarian biner di dalam array yang sudah diurutkan. Fungsi "main()" adalah titik awal program. Di dalamnya, sebuah array "data" dengan panjang 7 elemen diinisialisasi dengan nilai tertentu. Panjang array dihitung menggunakan "sizeof" dan dibagi dengan "sizeof(data[0])". Kemudian, data awal ditampilkan menggunakan loop "for". Pengguna diminta memasukkan nilai yang ingin dicari, lalu array diurutkan menggunakan fungsi "selection_sort()". Data yang sudah diurutkan ditampilkan kembali, dan kemudian fungsi "binarysearch()" dipanggil untuk mencari nilai yang dimasukkan oleh pengguna.


## Unguided 

### 1.Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!


```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Deklarasi fungsi
void selection_sort(string &kalimat);
void binary_search(string kalimat, char huruf);

int main() {
    // Menampilkan judul pencarian
    cout << "Pencarian huruf dalam kalimat" << endl;

    // Deklarasi variabel
    string kalimat;
    char huruf;

    // Meminta input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat); // Menggunakan getline() untuk membaca seluruh baris

    // Meminta input huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Mengurutkan kalimat dengan selection sort
    selection_sort(kalimat);

    // Menampilkan kalimat yang sudah diurutkan
    cout << "\nKalimat yang sudah diurutkan: " << endl;
    for (int i = 0; i < kalimat.length(); i++) {
        cout << setw(3) << kalimat[i];
    }
    cout << endl;

    // Mencari huruf dengan binary search
    binary_search(kalimat, huruf);

    // Menekan tombol apa pun untuk keluar
    cout << "\nTekan tombol apa pun untuk keluar...";
    _getch();

    return 0;
}

// Fungsi selection sort untuk mengurutkan string
void selection_sort(string &kalimat) {
    for (int i = 0; i < kalimat.length() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < kalimat.length(); j++) {
            if (kalimat[j] < kalimat[min_idx]) {
                min_idx = j;
            }
        }

        // Menukar karakter pada indeks minimum dengan karakter pada indeks i
        char temp = kalimat[i];
        kalimat[i] = kalimat[min_idx];
        kalimat[min_idx] = temp;
    }
}

// Fungsi binary search untuk mencari huruf dalam kalimat
void binary_search(string kalimat, char huruf) {
    // Menentukan batas awal dan akhir pencarian
    int low = 0;
    int high = kalimat.length() - 1;

    // Inisialisasi flag ditemukan
    bool found = false;

    // Inisialisasi indeks pertama kali ditemukan
    int firstIndex = -1;

    // Melakukan loop binary search
    while (low <= high && !found) {
        // Menghitung indeks tengah
        int mid = (low + high) / 2;

        // Membandingkan huruf dengan karakter pada indeks tengah
        if (kalimat[mid] == huruf) {
            // Huruf ditemukan
            found = true;

            // Jika ini merupakan huruf pertama kali ditemukan, simpan indeksnya
            if (firstIndex == -1)
                firstIndex = mid;

            // Menampilkan hasil
            cout << "\nHuruf '" << huruf << "' ditemukan pada indeks " << mid << endl;
        } else if (kalimat[mid] < huruf) {
            // Huruf yang dicari berada di bagian kanan
            low = mid + 1;
        } else {
            // Huruf yang dicari berada di bagian kiri
            high = mid - 1;
        }
    }

    // Jika huruf tidak ditemukan
    if (!found) {
        cout << "\nHuruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    } else if (firstIndex != -1) {
        // Menampilkan indeks lain jika huruf ditemukan lebih dari satu kali
        int currentIndex = firstIndex;
        while (kalimat[currentIndex] == huruf && currentIndex < kalimat.length()) {
            if (currentIndex != firstIndex)
                cout << "Dan juga ditemukan pada indeks " << currentIndex << endl;
            currentIndex++;
        }
    }
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

[1] Hendy, K., & Istiono, W. (2020). Efficiency Analysis of Binary Search and Quadratic Search in Big and Small Data Computational Science and Techniques, 7, 605–615. https://doi.org/10.15181/csat.v7i1.2091
[3] Darmawantoro, R. Y., Utami, Y. R. W., & Kustanto, 
K. (2022). Implementasi Binary Search Untuk 
Data Obat di Apotek. Jurnal Teknologi 
Informasi Dan Komunikasi (TIKomSiN), 
10(1).
https://doi.org/10.30646/tikomsin.v10i1.607
