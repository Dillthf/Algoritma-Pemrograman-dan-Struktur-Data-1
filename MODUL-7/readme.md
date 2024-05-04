# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
A. Pengertian

Stack merupakan sebuah tumpukan dengan 
metode LIFO (Last In First Out), yaitu data terakhir yang masuk ke dalam tumpukan merupakan data pertama yang akan dikeluarkan [1].

Stack C++ mendukung operasi dasar berikut:

    - push : Menambah/mendorong item ke dalam tumpukan [3].

    - peek : Mengembalikan item teratas dari tumpukan tanpa mengeluarkannya [2].

    - top : mengembalikan elemen berikutnya dalam tumpukan [3].

    - pop : menghapus elemen dari tumpukan [3].

    - isFull : Memeriksa apakah tumpukan sudah penuh [2].

    - isEmpty : Memeriksa apakah tumpukan kosong [2].

Perhatikan bahwa pop() menghapus elemen berikutnya tetapi tidak mengembalikannya, sedangkan top() mengembalikan elemen berikutnya tanpa menghapusnya [3].

## Guided 

### Guided 1

Source code:
```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```

Program ini dibuat untuk mengelola buku. Program ini mengelola data buku tersebut menggunakan fungsi-fungsi seperti memeriksa apakah stack kosong atau tidak. Menambahkan data baru ke dalam stack, menghapus data dari stack, mengubah posisi tertentu, dan menampilkan data buku tersebut.

### Output
![Screenshot 2024-05-04 100525](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/204930f1-9907-47a4-be9f-cb0fab31bba9)


## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.


#### Kode program 

```C++
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

```
Program ini dibuat untuk memeriksa apakah kalimat yang dimasukkan oleh pengguna terasuk palindrom atau bukan. Cara kerja program ini dengan membuat sebuah stack yang diberi nama kalimat. Kalimat yang dimasukkan oleh pengguna (bertipe data string) dimasukkan ke dalam stack kalimat. Karena program ini menggunakan stack, maka tumpukkan karakter yang diambil pertama adalah karakter yang terakhir masuk ke dalam stack. Jika kalimat yang dimasukkan adalah palindrom, maka karakter awal dan akhirnya akan dibaca sama. Sehingga kalimat yang dimasukkan pengguna diambil secara terbalik dari stack.



###### Output 

![Screenshot 2024-05-04 155016](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/cadb3cc3-d83c-4257-8b33-9e3d3985cbc6)

###### Full screenshot 

![Screenshot 2024-05-04 155033](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/5b7c8e2c-f446-403e-bffa-89a8f614874f)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

#### Kode Program

``` C++
#include <iostream>
#include <stack>

using namespace std;

string balikKalimat(string kalimat) { // Fungsi untuk membalikkan kalimat didefinisikan sebagai balikKalimat
    stack<char> terbalikKalimat; // meginisialisasi stack berisi karakter dengan nama terbalikKalimat
    string balikKalimat = ""; // deklarasi variabel balikKalimat yang bertipe string

    // perulangan untuk tiap karakter dalam string kalimat
    for (char ch : kalimat) {
        if (ch == ' ') {
           
            while (!terbalikKalimat.empty()) { //jika stack kosong, maka perulangan akan terus dimulai
                balikKalimat += terbalikKalimat.top(); // menambahkan karakter teratas dari stack ke string
                terbalikKalimat.pop(); // menghapus karakter teratas dari stack
            }
            balikKalimat += ' '; // menambahkan spasi untuk memisahkan kalimat yang sudah dibalik
        } else {
            terbalikKalimat.push(ch); // memasukkan karakter baru ke dalam stack terbalikKalimat
        }
    } //penutup perulangan for yang sebelumnya

    while (!terbalikKalimat.empty()) { // perulangan selama stack tidak kosong
        balikKalimat += terbalikKalimat.top(); // menambahkan karakter teratas dari stack
        terbalikKalimat.pop(); // menghapus karakter teratas
    }

    return balikKalimat;
}

int main() {
    string objek;

    // pengguna memasukkan kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, objek);

    // memanggil fungsi untuk membalikkan kalimat
    string dibalik = balikKalimat(objek);

    // menampilkan kalimat 
    cout << "Kalimat Asli: " << objek << endl;
    cout << "Kalimat Terbalik: " << dibalik << endl;

    return 0;
}

```
Program ini dibuat untuk membalikkan kalimat. Cara kerja program ini adalah saat pengguna memasukkan kalimat, kalimat tersebut menggunakan stack "terbalikKalimat". Kalimat akan dibaca perkaraker, jika karakter yang dibaca berupa spasi, maka program akan membalik kata yang sudah terbaca sebelumnya. Spasi juga ditambahkan untuk memisahkan kata dalam kalimat. Jika bukan spasi, maka karakter tersebut dimasukkan ke dalam stack. Setelah selesai, program akan menampilkan kalimat asli yang dimasukkan pengguna dan kalimat yang telah dibalik.

##### Output
![Screenshot 2024-05-04 154817](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/cd08d788-14a5-4ee3-8dba-e4ca4aef1448)

Program ini membalikkan kalimat dengan tidak hanya membalik urutan karakter atau huruf yang terdapat pada kata di dalam kalimat, namun juga membalikkan urutan posisi kata dalam kalimat. Sehingga urutan kata pertama menjadi yang terakhir dan kata terakhir menjadi kata petama. Huruf pertama menjadi huruf terakir dan huruf terakir menjadi huruf pertama, dan seterusnya.

##### Full Screenshot

![Screenshot 2024-05-04 154833](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/6ca41c7f-8f6a-423c-adba-9be1e01a7c8e)


## Kesimpulan

Stack digunakan dengan metode item yang masuk terakhir akan diakses terlebih dahulu. Stack juga memiliki berbagai operasi seperti pop(), push(), top(), dan operasi lainnya. Stack dapat diaplikasikan pada program yang membutuhkan pengolahan data, penyimpanan, dan lainnya.

## Referensi

[1] G. M. Putri, "Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort", JTeksis, vol.6, no.2, 286-296, April 2024.
doi : https://doi.org/10.47233/jteksis.v6i2.1192

[2] A. Nordeen, "Learn C++ in 24 Hours", (n.p): Guru99, 2022.

[3] N.M. Josuttis, "The C++ Standard Library: A Tutorial and Reference, Jerman: Addison-Wesley, 2012.