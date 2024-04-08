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

Program di atas dapat mencari huruf dari sebuah kalimat yang diinputkan. Algoritma pencarian yang digunakan adalah binary search. Program ini memakai dua library tambahan yaitu "conio.h" dan "iomanip". Library conio.h memungkinkan untuk mengakses fungsi "_getch()" yang menunggu hingga pengguna menekan tombol sebelum keluar dari program. Fungsi "_getch()" berguna untuk menjaga tampilan layar agar tetap terbuka setelah program selesai dijalankan. Sedangkan library iomanip memungkinkan mengakses fungsi "setw()" yang berfungsi untuk mengatur lebar kolom saat menampilkan kalimat yang sudah diurutkan. Dengan menggunakan "setw()", program dapat menampilkan setiap karakter dalam kalimat dengan lebar yang konsisten, sehingga tampilannya menjadi lebih rapi dan mudah dibaca. Fungsi yang dideklarasikan yaitu "selection_sort" dan fungsi "binary_search". 

Fungsi selection_sort digunakan untuk mengurutkan kaakter dari kalimat yang diinputkan menurut abjad. Sedangkan fungsi binary_search sendiri untuk mencari karakter tertentu dari kalimat yang diinputkan. Pencarian dilakukan dengan beberapa langkah, yaitu deklarasi fungsi binary_search dengan dua parameter berupa kalimat yang merupakan string yang akan dicari hurufnya, dan huruf yang merupakan huruf yang ingin dicari. Kemudian mendefenisikan dua variabel yaitu "low" dan "high" yang menunjukkan batas awal dan akhir dari rentang pencarian. Pada awalnya, low ditetapkan sebagai indeks pertama kalimat (0) dan high ditetapkan sebagai indeks terakhir kalimat. dilanjutkan dengan inisialisasi dua variabel, "found" yang merupakan flag untuk menunjukkan apakah huruf sudah ditemukan atau tidak, dan "firstIndex" untuk menyimpan indeks pertama kali huruf ditemukan. Pada awalnya, kedua variabel ini diinisialisasi dengan nilai yang menandakan bahwa huruf belum ditemukan. Terdapat perulangan "while" yang akan terus berjalan selama low tidak melebihi high dan huruf belum ditemukan. Karena menggunakan bianry search, program akan menghitung indeks tengah dari rentang pencarian. Pada blok if, else if, dan else, dilakukan perbandingan antara huruf yang dicari dengan huruf pada indeks tengah (mid) dari kalimat:

    * Jika huruf yang dicari sama dengan huruf pada indeks tengah, maka huruf tersebut ditemukan. Variabel found diset menjadi true dan indeksnya disimpan di firstIndex.

    * Jika huruf yang dicari lebih besar dari huruf pada indeks tengah, maka rentang pencarian dipindahkan ke bagian kanan (low = mid + 1).

    * Jika huruf yang dicari lebih kecil dari huruf pada indeks tengah, maka rentang pencarian dipindahkan ke bagian kiri (high = mid - 1).

Setelah perulangan selesai dan huruf tidak ditemukan (!found), maka pesan "Huruf tidak ditemukan" akan ditampilkan. Jika huruf ditemukan (found) dan firstIndex tidak sama dengan -1 (artinya huruf ditemukan lebih dari satu kali), maka dilakukan perulangan untuk menampilkan indeks-indeks lain dimana huruf tersebut ditemukan selain indeks pertama kali ditemukan.
Progam menampilkan indeks dimulai dari indeks 1.


#### Output:

![Screenshot 2024-04-07 174126](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/9a05ac2b-7652-45ff-abd9-ee52d3df424a)


#### Full screenshot 

![Screenshot 2024-04-07 180705](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f53cbe1c-4389-41ad-8b9c-29696b6627a5)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Deklarasi variabel
  string kalimat;
  int jumlah_vokal = 0;
  vector<char> huruf_vokal;

  // Meminta input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Mengubah semua huruf menjadi huruf kecil
  for (int i = 0; i < kalimat.length(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Mencari jumlah huruf vokal dan menyimpan huruf vokal yang ditemukan
  for (int i = 0; i < kalimat.length(); i++) {
    if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o') {
      jumlah_vokal++;
      huruf_vokal.push_back(kalimat[i]);
    }
  }

  // Menampilkan hasil
  cout << "Jumlah huruf vokal dalam kalimat: " << jumlah_vokal << endl;
  cout << "Huruf vokal yang ditemukan: ";
  for (char vokal : huruf_vokal) {
    cout << vokal << " ";
  }
  cout << endl;

  return 0;
}

```

Program di atas dapat menghitung jumlah huruf vokal dan menampilkan huruf vokal yang dimaksud berdasarkan kalimat inputan dari user. Algoritma pencarian yang digunakan adalah sequntial search. Program ini memakai dua library tambahan yaitu "string" dan "vector". Library string sendiri memberikan berbagai fungsi dan fitur yang memungkinkan untuk bekerja dengan strin. Dalam program tersebut, library string digunakan untuk mendeklarasikan variabel "kalimat" sebagai tipe data string, dan juga digunakan untuk mengakses fungsi "length()" yang memberikan panjang string, serta fungsi "tolower()" yang digunakan untuk mengubah huruf-huruf dalam kalimat menjadi huruf kecil. Program mengubah huruf menjadi huruf kecil agar menghilangkan sensitivitas program terhadap huruf kapital pada kalimat yang diinput. Sedangakan library vector pada program ini digunakan untuk menyimpan huruf vokal yang ditemukan dalam kalimat. Penggunaan vector memungkinkan untuk menyimpan dan mengakses elemen-elemen dengan mudah, serta mengelola memori secara dinamis tanpa perlu khawatir tentang alokasi memori secara manual. 

Program juga menggunakan fungsi "getline()" untuk membaca seluruh baris dari input pengguna dan menyimpannya ke dalam variabel kalimat. Terdapat perulangan for untuk mengiterasi setiap karakter dalam kalimat. Pemeriksaan apakah karakter tersebut adalah huruf vokal atau bukan dilakukan melalui kode program pada baris ke-24 yaitu "if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o')". Jika karakter saat ini adalah huruf vokal, maka jumlah vokal akan bertambah satu dan dimasukkan ke dalam vector "huruf_vokal". Di akhir, program akan menampilkan kalimat yang diinput, jumlah huruf vokal dalam kalimat, dan apa saja huruf vokal yang ditemukan.

#### Output:

![Screenshot 2024-04-08 042802](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/ae8fb629-e21d-4ccb-a7ef-7735cdf32951)

#### Full Screenshot

![Screenshot 2024-04-08 042825](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f088bfeb-d2cd-4e3c-a84b-537fb2fefe53)


### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]);
  int jumlah_angka_4 = 0;

  // Mencari jumlah angka 4 dengan Sequential Search
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      jumlah_angka_4++;
    }
  }

  // Menampilkan hasil
  cout << "Jumlah angka 4 dalam data: " << jumlah_angka_4 << endl;

  return 0;
}

```


Program ini dapat mencari angka 4 dari data yang sudah ada di dalam array sebelumnya dengan menggunakan sequential search. Program menggunakan array "data" untuk menyimpan data yang akan dicari. Variabel n digunakan untuk menyimpan jumlah elemen dalam array "data". Variabel "jumlah_angka_4" digunakan untuk menghitung berapa banyak angka 4 yang ditemukan. Perulangan for digunakan untuk iterasi setiap elemen dalam array data. Di dalam perulangan, program ini memeriksa apakah elemen saat ini sama dengan 4. Jika ya, maka variabel jumlah_angka_4 akan diincrement. Akhirnya, program ini menampilkan jumlah angka 4 yang ditemukan.


#### Output:
![Screenshot 2024-04-08 084518](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/852d1c53-a701-4f10-af65-fab7e3bc9498)

#### Full Screenshot

![Screenshot 2024-04-08 084507](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/d87b29ff-8156-4d6e-a9c6-b0ca77f68bbc)


## Kesimpulan

Algoritma pencarian terdiri dari binary search dan sequential search. Pemakaian kedua jenis ini disesuaikan dengan kebutuhan program, kompleksitas waktu dan ruang, serta kondisi yang ingin dibuat. Praktikum secara langsung terkait materi ini memudahkan dalam memahami materi. Tidak hanya struktur dasar dan bagaimana kedua jenis algoritma ini bekerja, melalui praktikum diketahui bagaimana menggunakan jenis algoritma pencarian yang tepat sesuai program yang ingin dibuat.
 

## Referensi

[1] Hendy, K., & Istiono, "Efficiency Analysis of Binary Search and Quadratic Search in Big and Small Data". Computational Science and Techniques, 7, 605–615. 2020.

[2] Wafiqah S. W, Septi A, Ben R, "Penggunaan Algoritma Sequential Searching Pada Aplikasi Perpustakaan Berbasis Web". Jurnal Ilmiah Penelitian dan Pembelajaran Informatika, 7, 2. 2022.

[3] Darmawantoro, R. Y., Utami, Y. R. W., & Kustanto, "Implementasi Binary Search Untuk Data Obat di Apotek". Jurnal Teknologi Informasi Dan Komunikasi (TIKomSiN), 10(1). 2022.

[4] Bernad J. D. S, Ade Y, Nancy J. R. "Implementasi Algoritma Binary Searching Pada Pencarian Data Jemaat Gereja HKBP Manado". Jurnal Informatika Polinema, 9. 2022.
