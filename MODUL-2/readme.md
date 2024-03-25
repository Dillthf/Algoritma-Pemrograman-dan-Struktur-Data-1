# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
Array adalah objek yang menyimpan beberapa variabel dengan tipe yang sama (homogen) bertipe yang sama yang disimpan di lokasi memori yang berdekatan Untuk menjamin efisiensi ekstrim untuk menemukan nilai- nilai tersebut. Misalnya jika sebuah array bertipe "int", array hanya dapat menyimpan elemen integer dan tidak dapat mengizinkan elemen bertipe lain seperti double, float, char, dll. Namun, array itu sendiri adalah objek pada heap. Dan, jenis elemen yang dapat disimpan dalam bentuk array ditentukan oleh bahasa pemrograman.[1].

Array terbagi atas:

A. Array Satu Dimensi

Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris. Elemen-elemen tersebut memiliki tipe data yang sama, tetapi isi dari elemen tersebut dapat berbeda[2].

B. Array Dua Dimensi
 Array dua dimensi adalah array yang terdiri dari elemen-elemen data yang disusun dalam dua dimensi atau baris dan kolom [3].


C. Array Multi Dimensi

Array multi dimensi Array multi-dimensi adalah kumpulan elemen yang disusun secara terstruktur dalam dua atau lebih dimensi[3].

## Guided 

### Guided 1
### Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
  // Deklarasi array
  int arr[2][3][3];
  // Input elemen
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // Output Array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;
  // Tampilan array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}
```
Kode di atas merupakan penerapan dari array multidimensi. Dimana pada kode tersebut array yang digunakan adalah array 3 dimesdi. Memungkinkan user untuk membuat array dengan memasukkan nilai pada setiap elemen array kemudian ditampilkan kembali. Kode mendklarasikan array 3 dimensi yang diberi nama arr. Ukuran array adalah 3x3 yang berjumlah dua. Kemudian pada input elemen terdapat perulangan sebanyak 3 kali. Perulangan pertama adalah perulangan x, untuk  jumlah array yaitu dua. Perulangan kedua adalah perulangan y, untuk jumlah baris yaitu 3. Dan perulangan terakhir adalah perulangan , untuk jumlah kolom yaitu 3. Perulangan ini akan dijalankan dengan inputan pengguna menggunakan fungsi cin. Perulangan pada bagian utput array menampilkan nilai yang sudah diinputkan sebelumnya pada setiap elemen array menggunakan cout. Array akan ditampilkan dalam format baris dan kolom seperti matriks

### Guided 2
### Program Mencari Nilai Maksimal pada Array

 ```C++
 #include <iostream>
using namespace std;

int main()
{
    //deklarasi variabel
    int maks, a, i = 1, lokasi;
    // masukkan data
    cout << "Masukkan panjang array: " ;
    cin >> a;
    int array [a];
    cout << "Masukkan " << a << "angka\n";
    // mencari nilai maksimum
    for (i = 0; i < a; i++)
    {
       cout << "Array ke-" << (i) << ":";
       cin >> array[i]; 
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array [i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << "berada di Array ke " << lokasi << endl;
}
 ```

 Kode diatas dimaksudkan untuk membuat suatu program yang akan membantu pengguna menemukan nilai maksimum yang ada pada suatu array. Setelah variable dideklarasikan, pengguna akan diminta menginput panjang array dan nilai untuk setiap elemen array yang disesuaikan dengan panjang array yang diinput sebelumnya. Selanjutnya adalah perulangan for yang akan membandingkan nilai-nilai elemn array dengan nilai maks. Jika nilai elemen lebih besar dari maks, maka nilai elemen tersebut disimpan sebagai nilai maksimum yang disimpan sebagai lokasi. Isi array dan nilai maksimum akan ditampilkan dengan fungsi cout. 

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![Screenshot 2024-03-25 094031](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/5e3eb5cb-2faa-4c09-b5d3-bceca6c85dc7)


```C++
#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel
  int x, i;
  
  // Input panjang array
  cout << "Masukkan panjang array: ";
  cin >> x;
  
  // Deklarasi array
  int arr[x];
  
  // Input data array
  cout << "Masukkan Data Array: ";
  for (i = 0; i < x; i++) {
    cin >> arr[i];
  }
  
  // Menampilkan output array
  cout << "Data Array: ";
  for (i = 0; i < x; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  // Menampilkan nomor genap
  cout << "Nomor Genap : ";
  for (i = 0; i < x; i++) { // perulangan untuk mencari nilai genap dari array
    if (arr[i] % 2 == 0) { 
      cout << arr[i] << " "; 
    }
  }
  cout << endl;
  
  // Menampilkan nomor ganjil
  cout << "Nomor Ganjil : ";
  for (i = 0; i < x; i++) { // perulangan untuk mencari nilai ganjil dari array
    if (arr[i] % 2 == 1) { 
      cout << arr[i] << " ";
    }
  }
  cout << endl;
  
  return 0;
}

```

Program di atas akan menampilkan output berupa data aray sesuai inputan pengguna, bilangan genap pada array, dan bilangan ganjil pada array. Program akan mendeklarasikan variabel berupa x untuk menyimpan panjang elemen array dan i untuk setiap elemennya. Berkikutnya adalah pengguna menginput panjang array. Array tersebut akan dideklarasikan sebagai arr[x]. Kemudian pengguna menginput isi dari array tersebut yang akan dideklarasikan sebagai arr[i]. Untuk mencari nomor genap dan nomor ganjil pada array, digunakan perulangan for. Perulangan untuk mencari nomor genap, nilai array yang telah diinput pengguna akan dibagi dua, jika sisa hasilnya = 0, maka akan ditampilkan bahwa nilai tersebut adalah nomor genap. Sementara itu, untuk perulangan mencari nomor ganjil, nilai array yang telah diinput pengguna akan dibagi dua, jika sisa hasilnya = 1, maka akan ditampilkan bahwa nilai tersebut adalah nomor ganjil.
#### Output:

![Screenshot 2024-03-25 101459](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/41c595d6-4eb8-4ab1-8224-04df0f0ce01f)

#### Full screenshot 

![Screenshot 2024-03-25 101525](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/e078fc78-3aa1-4d43-ba98-9aacb45aa5b0)


### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel
  int dimensi, x, y, z;

  // Input jumlah dimensi (maksimal 3)
  cout << "Masukkan jumlah dimensi array (maksimum 3): ";
  cin >> dimensi;

  // Validasi input dimensi
  if (dimensi < 1 || dimensi > 3) {
    cout << "Error: Dimensi array harus antara 1 sampai 3." << endl;
    return 1;
  }

  // Deklarasi array sesuai dimensi
  int arr[dimensi][dimensi][dimensi]; // Maksimal 3 dimensi

  // Input elemen
  for (x = 0; x < dimensi; x++) {
    for (y = 0; y < dimensi; y++) {
      for (z = 0; z < dimensi; z++) {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }

  // Output Array
  for (x = 0; x < dimensi; x++) {
    for (y = 0; y < dimensi; y++) {
      for (z = 0; z < dimensi; z++) {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;

  cout << endl;
  // Tampilan array
  for (int x = 0; x < dimensi; x++)
  {
    for (int y = 0; y < dimensi; y++)
    {
      for (int z = 0; z < dimensi; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}

```

Kode di atas merupakan penerapan dari array multidimensi. Dimana pada kode tersebut array yang digunakan adalah array 3 dimensi. Pengguna dapat memasukkan jumlah dimensi, namun pada program akan disertakan arahan untuk memasukan angka maksimal 3 agar array yang ditampilkan berdimensi 3. Jika pengguna memasukkan angka lebih dari 3 maka program akan menampilkan error. Kemudian pada input elemen terdapat perulangan sebanyak 3 kali. Perulangan pertama adalah perulangan x, untuk  jumlah array yaitu dua. Perulangan kedua adalah perulangan y, untuk jumlah baris yaitu 3. Dan perulangan terakhir adalah perulangan , untuk jumlah kolom yaitu 3. Perulangan ini akan dijalankan dengan inputan pengguna menggunakan fungsi cin. Perulangan pada bagian utput array menampilkan nilai yang sudah diinputkan sebelumnya pada setiap elemen array menggunakan cout. Array akan ditampilkan dalam format baris dan kolom seperti matriks
#### Output:

![Screenshot 2024-03-25 104628](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1da6da1f-e9da-4230-ab4d-39379d3e1bc4)
![Screenshot 2024-03-25 104712](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f1a81068-d7df-4440-b4ed-c81a4f8afe5b)
![Screenshot 2024-03-25 104720](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/7960d35e-647e-4544-b068-98c106939801)

#### Full Screenshot

![Screenshot 2024-03-25 104745](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/00b15a05-3857-4ff4-b661-487969c97c42)


### 3.  Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
using namespace std;

int main() 
{
  // Deklarasi variabel
  int n, i, maks, min, lokasi;
  float total = 0;

  // Input jumlah elemen array
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  // Deklarasi array
  int arr[n];

  // Input data array
  cout << "Masukkan data array: ";
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Mencari nilai maksimum
  maks = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] > maks) {
      maks = arr[i];
      lokasi = i;
    }
  }

  // Mencari nilai minimum
  min = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  // Menghitung nilai rata-rata
  for (i = 0; i < n; i++) {
    total += arr[i];
  }
  float rata = total / n;

  // Output hasil
  cout << "Nilai maksimum adalah " << maks <<  endl;
  cout << "Nilai minimum adalah " << min  << endl;
  cout << "Nilai rata-rata adalah " << rata << endl;

  return 0;
}
```


 Kode diatas dimaksudkan untuk membuat suatu program yang akan membantu pengguna menemukan nilai maksimum, minimun, dan rata-rata yang ada pada suatu array. Setelah variable dideklarasikan, pengguna akan diminta menginput panjang array dan nilai untuk setiap elemen array yang disesuaikan dengan panjang array yang diinput sebelumnya. Selanjutnya adalah perulangan for yang akan membandingkan nilai-nilai elemen array dengan nilai maks. Jika nilai elemen lebih besar dari maks, maka nilai elemen tersebut disimpan sebagai nilai maksimum. Perulangan berikutnya adalah perulangan for yang akan membandingkan nilai-nilai elemen array dengan nilai min. Jika nilai elemen lebih keicil dari min, maka nilai elemen tersebut disimpan sebagai nilai minimum. Perulangan terakhir adalah untuk mengetahui rata-rata dari keseluruhan nilai array tersebut. Jumlah dari semua nilai array (total) akan dibagi dengan panjang array (n). Isi array, nilai maksimum, nilai minimum, dan rata-rata akan ditampilkan dengan fungsi cout. 
#### Output:

![Screenshot 2024-03-25 111102](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/e3799a98-fcd4-4169-ac6c-2d4eb8ba0414)

#### Full Screenshot
![Screenshot 2024-03-25 111125](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1eb7f2b2-b92d-46b9-a5ca-c0e17f2c5f14)


## Kesimpulan

Dengan mempelajari materi array dapat diketahui bahwa array memiliki beberapa jenis yaitu :
- Array satu dimensi
- Array dua dimensi
- Array multidimensi
 Praktikum terkait array juga membantu dalam memahami pengertian, deklarasi, dan penggunaan array dalam program C++
 

## Referensi

[1] Zayid Musiafa, SDIA: Pemrograman Python C C++ Java.(n.p): CV. AA. RIZKY, 2022.
[2] A. Sindar, Struktur Data dan Algoritma dengan C++.(n.p) CV. AA. RIZKY, 2019  
[3] Rangga Guntara. ALGORITMA DAN PEMROGRAMAN DASAR: Menggunakan Bahasa Pemrograman C++ dengan Contoh Kasus Aplikasi untuk Bisnis dan Manajemen. (n.p.): CV. Ruang Tentor, 2023