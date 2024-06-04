# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
 Hash table adalah struktur data yang memfasilitasi proses pencarian nilai kunci. Ini menghilangkan kebutuhan untuk mencari kunci yang cocok secara berurutan dan mengambil nilai yang sesuai. Tabel hash menggunakan fungsi hash untuk mengubah kunci hash menjadi indeks hash, dan menyimpan nilai hash yang sesuai dalam entri array yang indeksnya sesuai dengan indeks hash. Dengan adanya kunci hash, proses pencarian mengubah kunci hash menjadi indeks hash menggunakan fungsi hash, dan langsung mengakses entri array yang sesuai dengan indeks hash[1]. Struktur tabel hash memiliki properti yang luar biasa: sebagian besar operasinya (diamortisasi, rata-rata, dll.) waktu yang konstan, yaitu kompleksitas teoretisnya adalah O(1) [2].
 

## Guided 

### Guided 1 

Source code:
```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
} 

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}

```

Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan modulus untuk memetakan setiap input kunci ke nilai indeks array.

### Output
![Screenshot 2024-06-04 085121](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f91eeaaa-7db2-4d8c-8e8a-0c7fa2524877)

### Guided 2 

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

Pada program di atas, class HashNode merepresentasikan setiap node dalam hash table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap digunakan untuk mengimplementasikan struktur hash table dengan menggunakan vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi remove digunakan untuk menghapus data dari hash table, dan fungsi searchByName digunakan untuk mencari nomor telepon dari karyawan dengan nama yang diberikan.

### Output
![Screenshot 2024-06-04 081718](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/6031fe3d-5539-46ea-82b3-8528be849be2)



## Unguided 

1.	Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. 
Dengan ketentuan :
a.	Setiap mahasiswa memiliki NIM dan nilai.
b.	Program memiliki tampilan pilihan menu berisi poin C.
c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

#### Kode program 

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

class HashNode {
public:
    int nim;
    float nilai;

    HashNode(int nim, float nilai) {
        this->nim = nim;
        this->nilai = nilai;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int nim, float nilai) {
        int hash_val = hashFunc(nim);

        for (auto node : table[hash_val]) {
            if (node->nim == nim) {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim, nilai));
    }

    void remove(int nim) {
        int hash_val = hashFunc(nim);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->nim == nim) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    float searchByNim(int nim) {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val]) {
            if (node->nim == nim) {
                return node->nilai;
            }
        }
        return -1;
    }

    vector<HashNode*> searchByNilai(float nilai_min, float nilai_max) {
        vector<HashNode*> result;
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                if (node->nilai >= nilai_min && node->nilai <= nilai_max) {
                    result.push_back(node);
                }
            }
        }
        return result;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->nim << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap mahasiswa_map;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai" << endl;
        cout << "5. Keluar" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            int nim;
            float nilai;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan nilai: ";
            cin >> nilai;
            mahasiswa_map.insert(nim, nilai);
            cout << "Data berhasil ditambahkan" << endl;
        } else if (choice == 2) {
            int nim;
            cout << "Masukkan NIM: ";
            cin >> nim;
            mahasiswa_map.remove(nim);
            cout << "Data berhasil dihapus" << endl;
        } else if (choice == 3) {
            int nim;
            cout << "Masukkan NIM: ";
            cin >> nim;
            float nilai = mahasiswa_map.searchByNim(nim);
            if (nilai != -1) {
                cout << "Nilai mahasiswa dengan NIM " << nim << " adalah " << nilai << endl;
            } else {
                cout << "Data tidak ditemukan" << endl;
            }
        } else if (choice == 4) {
            float nilai_min, nilai_max;
            cout << "Masukkan nilai minimum: ";
            cin >> nilai_min;
            cout << "Masukkan nilai maksimum: ";
            cin >> nilai_max;
            vector<HashNode*> result = mahasiswa_map.searchByNilai(nilai_min, nilai_max);
            if (!result.empty()) {
                cout << "Data mahasiswa dengan nilai antara " << nilai_min << " dan " << nilai_max << ":" << endl;
                for (auto node : result) {
                    cout << "NIM: " << node->nim << " Nilai: " << node->nilai << endl;
                }
            } else {
                cout << "Tidak ada data yang ditemukan" << endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Menu tidak valid" << endl;
        }
    }

    return 0;
}


```
Kode program menggunakan hash table untuk menyimpan data mahasiswa berdasarkan NIM dan Nilai. Program menyediakan beberapa fungsi yang ditampilkan pada menu awal.

 Program menyediakan fungsi menambahkan, menggunanakan fungsi insert. fungsi akan menghitung indeks hash menggunakan hashFunc. Kemudian memeriksa apakah NIM sudah ada di indeks tersebut. Jika ada, nilai diperbarui. Jika tidak ada, data baru ditambahkan ke vector pada indeks tersebut.

 Fungsi selanjutnya adalah menghapus data mahasiswa berdasarkan NIM menggunakan fungsi remove dengan menghitung indeks hash menggunakan hashFunc. Fungsi mencari dan menghapus elemen yang sesuai di vector pada indeks tersebut. 

 Fungsi pencarian berdasarkan NIM diinisialisasikan dengan fungsi searchByNim. Fungsi menghitung indeks hash menggunakan hashFunc. Setekah itu mencari elemen yang sesuai di vector pada indeks tersebut.

 Fungsi yang terakhhir mencari data mahasiswa berdasarkan rentang nilai. Fungsi akan memeriksa semua elemen di seluruh hash table dan mengumpulkan elemen yang nilai mereka berada dalam rentang yang ditentukan.



###### Output 

![Screenshot 2024-06-04 081732](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/0bc2d1f3-dbdc-43f7-a0f1-fac49d0ae83d)
![Screenshot 2024-06-04 082308](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/68f1a6e2-1738-4508-bb5f-76e57c9d82ca)
![Screenshot 2024-06-04 083304](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/bfe25122-c86e-448a-9f3d-141295fee603)

###### Full screenshot 

![Screenshot 2024-06-04 085055](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/32fd22a5-2f7f-4cdc-8eb8-e8d816d0fe94)

## Kesimpulan

Hash table menawarkan solusi efisien untuk operasi pencarian dan manajemen data melalui penggunaan fungsi hash. Dengan kompleksitas waktu rata-rata yang konstan untuk berbagai operasi, hash table memungkinkan pengelolaan data yang cepat dan efektif, menjadikannya pilihan yang unggul untuk banyak aplikasi komputasi yang memerlukan akses data yang cepat dan terstruktur.

## Referensi

[1] Issariyakul, T., Hossain, E.Introduction to Network Simulator NS2. Jerman: Springr US. 2008.
[2] Santiago T. "Key Concepts, Weakness and Benchmark on Hash Table Data Structures" .(n.p). 2022

