# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
 Ketika suatu fungsi memanggil dirinya sendiri, itu membuat panggilan rekursif. Menurut Sianpar, metode rekursif adalah metode yang secara langsung atau tidak langsung memanggil dirinya sendiri. Kata rekursif berarti "memiliki karakteristik untuk datang kembali, atau mengulangi". Dalam hal ini, pemanggilan fungsi diulangi oleh fungsi itu sendiri. Jenis rekursi ini kadang-kadang disebut rekursi langsung karena fungsinya secara langsung menyebut dirinya. Selain itu, ada jenis rekursi yang kedua yang disebut dengan rekursi tidak langsung. Rekursi tidak langsung terjadi ketika fungsi A memanggil fungsi B, dan fungsi B memanggil kembali ke fungsi A maka itu melibatkan rekursi tidak langsung [1].

 Sebuah fungsi rekursif memanggil dirinya sendiri, memori untuk fungsi yang dipanggil dialokasikan di atas memori yang dialokasikan untuk fungsi pemanggil dan salinan variabel lokal yang berbeda dibuat untuk setiap panggilan fungsi. Ketika base case tercapai, fungsi mengembalikan nilainya ke fungsi yang memanggil, dilanjutkan dengan melepaskan memori dan proses ber- lanjut. Kekurangan dari program rekursif adalah memiliki persyaratan ruang yang lebih besar daripada program iteratif karena semua fungsi akan tetap ada di tumpukan hingga base case tercapai. Program rekursif juga memiliki persyaratan waktu yang lebih besar karena pemanggilan fungsi dan pengembalian overhead.
 Sedangkan, kelebihan rekursi menyediakan cara yang bersih dan sederhana dalam penulisan kode program. Beberapa masalah secara inheren bersifat rekursif seperti Tree Traversal, Tower of Hanoi, dan lain-lain [1]. 

## Guided 

### Guided 1 (Rekursif Langsung)

Source code:
```C++
#include <iostream>

using namespace std;

void countdown(int n){
    if ( n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1); // setiap iterasi dikurangi satu sampai n nilainya 0
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```

Cara kerja program berupa, ketika fungsi countdown(5) dipanggil, maka akan dicetak 5 dan memanggil fungsi countdown(4) yang akan mencetak 4 dan memanggil countdown(3), begitu seterusnya hingga fungsi countdown(0). Program akan mencapai kondisi basis dan fungsi keluar tanpa mencetak apa-apa.

### Output
![Screenshot 2024-05-04 100525](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/204930f1-9907-47a4-be9f-cb0fab31bba9)

### Guided 2 (Rekursif Tidak Langsung)

Source code:
```C++
#include <iostream>

using namespace std;

void functionB (int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB (int n) {
    if ( n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main () {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}


```

Cara kerja pada program menggunakan rekursif tidak langsung. Ketika functionA(5) dipanggil dari fungsi main, angka 5 dicetak, lalu memanggil functionB(4). Saat functionB(4) dipanggil, angka 4 dicetak dan memanggil functionA(2) (4 / 2). Kemudian akan mencetak angka 2 dan memanggil functionB(1). Pada functionB(1) angka 1 dicetak dan memanggil functionA(0) (1 / 2). FunctionA(0) tidak mencetak apa-apa dan keluar dari fungsi.

### Output
![Screenshot 2024-05-04 100525](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/204930f1-9907-47a4-be9f-cb0fab31bba9)



## Unguided 

### 1.Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!


#### Kode program 

```C++
#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    if (n <= 1) {
        return 1; // Basis rekursi
    } else {
        return n * faktorial(n - 1); // Rekursi
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Bilangan harus positif." << endl;
    } else {
        int hasil = faktorial(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}


```
Program dimulai dan meminta pengguna untuk memasukkan bilangan bulat positif.
Saat pengguna memasukkan bilangan, program mengecek apakah bilangan tersebut positif. Jika bilangan negatif, program mencetak pesan kesalahan dan selesai.
Jika bilangan positif atau nol, program melanjutkan untuk menghitung faktorial.
Fungsi faktorial dipanggil secara rekursif untuk menghitung faktorial dari bilangan tersebut.
Program mendefinisikan fungsi faktorial yang menerima satu argumen integer n. Kemudian membuat kondisi basis dari rekursi. Jika n kurang dari atau sama dengan 1, fungsi mengembalikan nilai 1. Jika n lebih besar dari 1, eksekusi blok berikutnya. Pada baris fungsi return n * faktorial(n - 1) akan mengembalikan hasil perkalian n dengan hasil pemanggilan rekursif faktorial(n - 1). Ini mengurangi nilai n secara berulang hingga mencapai kondisi basis.
Fungsi utama yang akan dieksekusi saat program dijalankan. Awalnya variabel dideklerasikan sebagai num untuk menyimpan input dari pengguna. Fungsi mencetak pesan untuk inputan pengguna dan membaca input dari pengguna dan menyimpannya ke dalam variabel num.
Pada fungsi if (num < 0) mengecek apakah nilai num kurang dari 0. Jika num kurang dari 0, fungsi mencetak pesan kesalahan bahwa bilangan harus positif. Jika num tidak kurang dari 0, eksekusi blok berikutnya. Fungsi faktorial akan dipanggil dengan argumen num dan menyimpan hasilnya ke dalam variabel hasil. Diakhir, program mencetak hasil perhitungan faktorial.


###### Output 

![Screenshot 2024-05-04 155016](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/cadb3cc3-d83c-4257-8b33-9e3d3985cbc6)

###### Full screenshot 

![Screenshot 2024-05-04 155033](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/5b7c8e2c-f446-403e-bffa-89a8f614874f)

### 2. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
#### Kode Program

``` C++
#include <iostream>
using namespace std;

// Deklarasi fungsi-fungsi yang saling memanggil
int faktorialB(int n);

int faktorialA(int n) {
    if (n <= 1) {
        return 1; // Basis rekursi
    } else {
        return n * faktorialB(n - 1); // Panggilan rekursi ke fungsi B
    }
}

int faktorialB(int n) {
    return faktorialA(n); // Panggilan rekursi ke fungsi A
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Bilangan harus positif." << endl;
    } else {
        int hasil = faktorialA(num); // Memulai rekursi dari fungsi A
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}


```
Program ini menggunakan rekursi tidak langsung untuk menghitung faktorial dari sebuah bilangan bulat positif yang dimasukkan oleh pengguna. Program dimulai dan meminta pengguna untuk memasukkan bilangan bulat positif. Saat pengguna memasukkan bilangan, program mengecek apakah bilangan tersebut positif. Jika bilangan negatif, program mencetak pesan kesalahan dan selesai. Jika bilangan positif atau nol, program melanjutkan untuk menghitung faktorial. Program mendefinisikan dua fungsi, faktorialA dan faktorialB, yang saling memanggil secara rekursif untuk menghitung faktorial dari bilangan tersebut. FaktorialA menerima satu argumen integer n. Kemudian ,embuat kondisi basis dari rekursi: jika n kurang dari atau sama dengan 1, fungsi mengembalikan nilai 1.
Jika n lebih besar dari 1, eksekusi blok berikutnya: return n * faktorialB(n - 1).
Ini mengembalikan hasil perkalian n dengan hasil pemanggilan rekursif faktorialB(n - 1), mengurangi nilai n secara berulang hingga mencapai kondisi basis. FaktorialB juga menerima satu argumen integer n dan memanggil faktorialA(n) secara rekursif.
Fungsi utama yang akan dieksekusi saat program dijalankan adalah, awalnya, variabel num dideklarasikan untuk menyimpan input dari pengguna.Fungsi mencetak pesan untuk meminta input dari pengguna dan membaca input tersebut, menyimpannya ke dalam variabel num. Pada kondisi if (num < 0), program mengecek apakah nilai num kurang dari 0. Jika num kurang dari 0, fungsi mencetak pesan kesalahan bahwa bilangan harus positif.Jika num tidak kurang dari 0, eksekusi blok berikutnya:
Fungsi faktorialA dipanggil dengan argumen num dan menyimpan hasilnya ke dalam variabel hasil. Di akhir, program mencetak hasil perhitungan faktorial.

##### Output
![Screenshot 2024-05-04 154817](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/cd08d788-14a5-4ee3-8dba-e4ca4aef1448)

##### Full Screenshot

![Screenshot 2024-05-04 154833](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/6ca41c7f-8f6a-423c-adba-9be1e01a7c8e)


## Kesimpulan

Rekursi adalah metode dalam pemrograman di mana sebuah fungsi memanggil dirinya sendiri secara langsung atau tidak langsung untuk menyelesaikan suatu masalah. Ada dua jenis rekursi: rekursi langsung, di mana fungsi memanggil dirinya sendiri, dan rekursi tidak langsung, di mana fungsi A memanggil fungsi B, yang kemudian memanggil kembali fungsi A. Meskipun rekursi dapat membuat kode lebih sederhana dan bersih, terutama untuk masalah yang secara alami bersifat rekursif seperti Tree Traversal dan Tower of Hanoi, rekursi memiliki beberapa kekurangan. Kekurangan tersebut termasuk kebutuhan memori yang lebih besar dan waktu eksekusi yang lebih lama dibandingkan dengan pendekatan iteratif, karena setiap panggilan fungsi harus disimpan dalam tumpukan hingga mencapai kondisi basis. Meskipun demikian, rekursi tetap menjadi alat yang berguna dalam pemrograman untuk masalah-masalah tertentu yang dapat dipecahkan dengan lebih elegan menggunakan metode ini.

## Referensi

[1] Shofwan H., Wayan J. Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Edisi I. Yogyakarta:Andi. 2020.
