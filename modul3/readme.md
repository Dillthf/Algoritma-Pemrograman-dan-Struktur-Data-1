# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
Pengurutan data (sorting) adalah suatu proses pengurutan data yang tersusun secara acak pada suatu pola tertentu,  sehingga tersusun secara teratur menurut aturan tertentu. Pengurutan ini dapat dilakukan dengan cara Ascending dan descending serta digunakan juga untuk mengurutkan data yang bertipe angka atau karakter [1].

Algoritma Sorting terbagi atas:

A. Insertion Sort

Insertion Sort adalah sebuah algortima sederhana yang cukup efisien untuk mengurutkan sebuah list yang hampir terurut. Algoritma ini juga bisa digunakan sebagai bagian algoritma yang lebih canggih. Cara kerja algoritma ini adalah dengan  mengambil elemen list satu-per-satu dan memasukkannya di posisi yang benar seperti namanya. Pada array, list yang baru dan elemen sisanya dapat berbagi tempat di array, meskipun cukup rumit. Untuk menghemat memori, implementasinya menggunakan pengurutan di tempat yang membandingkan elemen saat itu dengan elemen sebelumnya yang sudah diurut, lalu menukarnya terus sampai posisinya tepat. Hal ini terus dilakukan sampai tidak ada elemen tersisa di input [1]. 

B. Selection Sort

Selection sort adalah suatu metode pengurutan yang membandingkan elemen yang sekarang dengan elemen berikutnya sampai ke elemen yang terakhir. Jika ditemukan elemen lain yang lebih kecil dari elemen sekarang maka dicatat posisinya dan langsung ditukar [2].
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

Kode di atas adalah contoh pengaplikasian bubble sort secara ascending. Kode tersebut terdiri dari tiga fungsi, yaitu 'bubble_sort', 'print_array', dan 'main'. Fungsi bubble_sort menerima dua parameter, arr yang berisi array bilangan dan length yang berisi jumlah elemen dalam array. Terdapat variabel not_sorted yang dipergunakan untuk menentukan apakah array sudah terurut atau belum. Saat awal, not_sorted diset nilai true. Kemudian, algoritma bubble sort menggunakan perulangan while untuk mengurutkan array bilangan. Perulangan for yang berada dalam perulangan while digunakan untuk menyisipkan elemen yang belum terurut pada posisi yang tepat. Jika terdapat elemen yang belum terurut, maka not_sorted akan diubah menjadi true dan perulangan while akan dilanjutkan. Fungsi ini menggunakan algoritma bubble sort untuk mengurutkan array bilangan. Selanjutnya adalah fungsi print_array: Fungsi ini menerima dua parameter, a yang berisi array bilangan dan length yang berisi jumlah elemen dalam array. Fungsi ini menggunakan perulangan untuk mencetak semua elemen dalam array bilangan. Terdapat perulangan for yang digunakan untuk mencetak semua elemen dalam array bilangan. Fungsi void dipakai sehingga baris program tersebut tidak memerlukan return atau pengembalian nilai. Fungsi terakhir adalah main, fungsi ini merupakan fungsi utama yang melakukan pengurutan array bilangan menggunakan algoritma bubble sort dan menampilkan hasil pengurutan. Pada fungsi main, terdapat variabel length yang berisi jumlah elemen dalam array bilangan. Array bilangan a diisi dengan beberapa elemen. Kemudian, fungsi bubble_sort dipanggil dengan parameter a dan length untuk melakukan pengurutan array bilangan. Setelah pengurutan selesai, fungsi print_array dipanggil dengan parameter a dan length untuk menampilkan hasil pengurutan.

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

Kode di atas adalah contoh pengaplikasian insertion sort untuk mengurutkan karakter secara descending. Kode tersebut terdiri dari tiga fungsi, yaitu 'insertion_sort', 'print_array', dan 'main'.
Fungsi 'insertion_sort' menerima dua parameter yaitu  "arr" berupa array dengan elemen karakter dan "length" (jumlah karakter dalam array). Fungsi 'insertion_sort' memiliki perulangan "for" akan mengulang setiap elemen dalam array Variabel "j" berisi indeks elemen yang sedang diproses, dan "i" berisi indeks elemen yang akan diproses. Perulangan "while" digunakan untuk membandingkan elemen dengan elemen sebelumnya. Jika elemen yang diproses lebih kecil dari elemen sebelumnya, maka elemen akan diganti dengan elemen sebelumnya dan menurunkan indeks "j" Setelah perulangan "while" selesai, indeks "j" dijumlahkan dengan 1.
Fungsi "print_array" menerima dua parameter: "a" (array karakter) dan "length" (jumlah karakter dalam array). Dalam perulangan "for" yang berada dalam "print_array", semua elemen dalam array karakter dicetak.
Fungsi "main" menerima dua parameter: "length" (jumlah karakter dalam array) dan "a" (array karakter).
Urutan karakter sebelum sorting dan setelah sorting ditampilkan menggunakan fungsi "print_array".
## Unguided 

### 1.Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

```C++
#include <iostream>
using namespace std;

void selection_Sort(double arr[], int n) { // Deklarasi variable. Dimana variabel arr berisi Indeks Prestasi Semester, dan n berisi jumlah mahasiswa
    for (int i = 0; i < n - 1; ++i) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n-1.
        int elemen_terurut = i; // Variabel elemen_terurut berisi indeks elemen yang terurut terkecil hingga saat ini.
        for (int j = i + 1; j < n; ++j) { // Perulangan for ini memulai dari indeks i+1 dan berhenti ketika indeks j menjadi sama dengan n.
            if (arr[j] > arr[elemen_terurut]) { //Jika elemen arr[j] lebih besar dari elemen arr[elemen_terurut], maka indeks elemen_terurut diubah menjadi j
                elemen_terurut = j; 
            } // AKhir dari if
        } // Akhir dari perulangan for
        swap(arr[i], arr[elemen_terurut]); // Setelah mencari elemen yang terurut terkecil, elemen arr[i] diganti dengan elemen arr[elemen_terurut]
    } // Akhir dari perulangan for
} // Akhir dari selection_Sort

int main() { // Fungsi main merupakan fungsi utama program.
    double arr[] = {3.8, 2.9, 3.3, 4.0, 2.4}; // Deklarasi variabel array yang berisi tipe data double. Elemen dalam array tersebut adalah Indeks Prestasi Semester
    int n = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen dalam array arr dengan menggunakan fungsi sizeof

    cout << "Indeks Prestasi Semester Mahasiswa sebelum diurutkan : "; //Menampilkan teks "Indeks Prestasi Semester Mahasiswa sebelum diurutkan :" ke layar
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr.
        cout << arr[i] << " "; // Menampilkan setiap elemen dalam array arr ke layar.
    } // Akhir prulangan for
    cout << endl; 

    selection_Sort(arr, n); // Berupa fungsi selection_Sort dengan parameter arr (array yang akan diurutkan) dan n (jumlah elemen dalam array).

    cout << "Indeks Prestasi Semester Mahasiswa setelah diurutkan : "; // Menampilkan teks "Indeks Prestasi Semester Mahasiswa setelah diurutkan :" ke layar.
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr setelah diurutkan.
        cout << arr[i] << " "; // Menampilkan setiap elemen dalam array arr setelah diurutkan ke layar.
    } // Akhir perulangan for
    cout << endl;

    return 0;
}// Akhir main
 

```

Kode di atas merupakan program yang mengurutkan Indeks Prestasi Semester Mahasiswa secara descending menggunakan slection sort. Dimana fungsi Selection Sort untuk mengurutkan array secara menurun. Kemudian menggunakan perulangan untuk membandingkan lalu menukar elemen-elemen array agar terurut secara menurun. Fungsi utama program adalah mendeklarasikan array yang berisi nilai indeks prestarsi semester mahasiswa, kemudian nilai tersebut ditampilkan sebelum diurutkan, kemudia mengurutkan dengan fungsi selection_sort, elemen yang telah diurut akan ditampilkan.

Kompleksitas waktu program di atas adalah O(n^2), dimana n adalah jumlah elemen dalam array. Hal ini disebabkan karena perulangan for yang berada dalam selection_Sort berulang sebanyak n-1 kali, dan setiap iterasi dari perulangan for berulang sebanyak n-i kali.
#### Output:

![Screenshot 2024-04-01 112522](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/8c489aa6-d83f-48f2-8dbd-fd348d04f5c6)


#### Full screenshot 
![Screenshot 2024-04-01 112537](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/968844fb-ee1f-4a69-b6cb-205bf9b1bc62)



### 2.Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>
using namespace std;
void bubble_Sort(string arr[], int n) { // Deklarasi variable. Dimana variabel arr berisi nama warga dengan tipe data string, dan n berisi jumlah warga
    for (int i = 0; i < n - 1; ++i) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n-1.
        int elemen_terurut = i; // Variabel elemen_terurut berisi indeks elemen yang terurut terkecil hingga saat ini.
        for (int j = i + 1; j < n; ++j) { // Perulangan for ini memulai dari indeks i+1 dan berhenti ketika indeks j menjadi sama dengan n.
            if (arr[j] < arr[elemen_terurut]) { //Jika elemen arr[j] lebih kecil dari elemen arr[elemen_terurut], maka indeks elemen_terurut diubah menjadi j
                elemen_terurut = j;
            } // Akhir dari if
        } // Akhir dari for
        swap(arr[i], arr[elemen_terurut]); // Setelah mencari elemen yang terurut terkecil, elemen arr[i] diganti dengan elemen arr[elemen_terurut]
    } // Akhir dari for
} // Akhir dari bubble_sort

int main() { // Fungsi main merupakan fungsi utama program.
    string arr[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"}; // Deklarasi variabel array yang berisi tipe data string. Elemen dalam array tersebut adalah nama-nama warga
    int n = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen dalam array arr dengan menggunakan fungsi sizeof


    cout << "Nama warga sebelum diurutkan: "; //Menampilkan teks "Nama warga sebelum diurutkan :" ke layar
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr.
        cout << arr[i] << " "; // Menampilkan setiap elemen dalam array arr ke layar.
    } // Akhir prulangan for
    cout << endl;

    bubble_Sort(arr, n); // Berupa fungsi bubble_Sort dengan parameter arr (array yang akan diurutkan) dan n (jumlah elemen dalam array).

    cout << "Nama warga setelah diurutkan: "; //Menampilkan teks "Nama warga setelah diurutkan :" ke layar
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr setelah diurutkan.
        cout << arr[i] << " ";
    } // Akhir perulangan for
    cout << endl;

    return 0;
} // Akhir main

 ```


Program ini menggunakan algoritma Bubble Sort untuk mengurutkan nama warga Pak RT. Fungsi "bubble_sort" menerima dua parameter: "arr" (array nama warga) dan "n" (jumlah warga). Fungsi ini menggunakan perulangan "for" untuk mengurutkan nama warga menggunakan algoritma Bubble Sort. Setelah proses sorting selesai, nama warga akan terurut sesuai dengan alfabet.
Kompleksitas waktu kode di atas dapat diklasifikasikan menjadi O(n^2), dimana n merupakan jumlah elemen dalam array. Algoritma Bubble Sort membutuhkan waktu yang lambat ketika jumlah elemen dalam array meningkat. Karena perulangan yang dilakukan dalam algoritma Bubble Sort, kompleksitas waktu akan meningkat seiring dengan jumlah elemen dalam array.


#### Output:

![Screenshot 2024-04-01 120905](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/19e81056-6da2-4d4e-9a1e-a9473ee398db)

#### Full Screenshot

![Screenshot 2024-04-01 120916](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/2ed0a1a7-b169-4630-a775-1f88282f5359)

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n; // Mendeklarasikan variabel n untuk menyimpan jumlah karakter
  cout << "Masukkan jumlah karakter: " << endl; // Meminta user untuk memasukkan nilai n dan menyimpannya dalam variabel n
  cin >> n;

  char karakter[n]; // Mendeklarasikan array karakter karakter dengan ukuran n

  // Meminta user untuk memasukkan karakter
  cout << "Masukkan " << n << " karakter: " << endl;
  for (int i = 0; i < n; i++) {
    cin >> karakter[i];
  }

  // Sorting karakter secara ascending
  for (int i = 0; i < n - 1; ++i) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n
    for (int j = i + 1; j < n; j++) { // Perulangan for ini memulai dari indeks j = i + 1 dan berhenti ketika indeks j menjadi sama dengan n
      if (karakter[i] > karakter[j]) { // Di dalam perulangan kedua, karakter pada indeks i dibandingkan dengan karakter pada indeks j dengan operator >
        swap(karakter[i], karakter[j]); // Jika karakter pada indeks i lebih besar dari karakter pada indeks j, maka kedua karakter tersebut ditukar
      } // Akhir if
    } // Akhir perulangan for
  } // Akhir perulangan for

  // Menampilkan hasil sorting ascending
  cout << "Karakter setelah sorting ascending: " << endl;
  for (int i = 0; i < n; ++i) {  //  mengulang dari indeks 0 sampai n-1
    cout << karakter[i] << endl; // Di dalam perulangan, karakter pada indeks i dicetak ke layar
  }

  // Sorting karakter secara descending
  for (int i = 0; i < n - 1; i++) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n
    for (int j = i + 1; j < n; j++) { // Perulangan for ini memulai dari indeks j = i + 1 dan berhenti ketika indeks j menjadi sama dengan n
      if (karakter[i] < karakter[j]) { // Di dalam perulangan kedua, karakter pada indeks i dibandingkan dengan karakter pada indeks j dengan operator <
        swap(karakter[i], karakter[j]); // Jika karakter pada indeks i lebih kecil dari karakter pada indeks j, maka kedua karakter tersebut ditukar
      } // Akhir if
    } // Akhir perulangan for
  } // Akhir perulangan for

  // Menampilkan hasil sorting descending
  cout << "Karakter setelah sorting descending: " << endl; 
  for (int i = 0; i < n; i++) {  //  mengulang dari indeks 0 sampai n-1
    cout << karakter[i] << endl; 
  }
  

  return 0;
}

```

Kode di atas merupakan salah satu contoh program sorting. Pada bagian awal menyimpan jumlah karakter yang diinput user dalam variabel n. Menyimpan n karakter yang diinput user dalam array karakter.Bagian selanjutnya adalah mengurutkan secara Ascending & Descending. Dengan mengurutkan karakter dalam array karakter dari kecil ke besar (ascending) atau dari besar ke kecil (descending) menggunakan perulangan. Jika ada dua karakter yang tidak berurutan, tukar tempatnya. Yang terakhir adalah menampilkan urutan.
Dua perulangan for digunakan untuk mengurutkan karakter. Dalam setiap perulangan for dalam, terdapat perbandingan dua karakter. Perbandingan dua karakter membutuhkan waktu konstan, yaitu O(1). Oleh karena itu, kompleksitas waktu total untuk sorting adalah O(n * n), yang disederhanakan menjadi O(n^2).

#### Output:


![Screenshot 2024-04-01 130344](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/715fd834-b8c0-421c-a8b1-a196c9e78eeb)


#### Full Screenshot

![Screenshot 2024-04-01 130406](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/e7316aaf-65f9-46fb-a4fc-64436a884f41)


 
## Referensi

[1] Panny Agustia Rahayuningsih, Analisis Perbandingan Kompleksitas Algoritma Pengurutan Nilai (Sorting), Jurnal Evolusi, vol.4, no.2. 2016

[2] Yahya, Sofyansyah Yusari, Analisa 
Perbandingan Algoritma Bubble Sort dan 
Selection Sort Dengan Metode 
Perbandingan Eksponensial. Jurnal Pelita 
Informatika Budi Darma, Vol : VI, No : 3, 2014 
