# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
A. Pengertian

Linked list didefinisikan sebagai struktur data linear yang terdiri dari elemen-elemen yang disebut node[1]. Setiap node memiliki dua bagian utama:

    Data: Menyimpan nilai aktual dari elemen.
    Pointer: Menunjuk ke node berikutnya dalam list.

Node pertama dalam list disebut head (kepala), dan node terakhir disebut tail (ekor). Linked list tidak memiliki awal dan akhir yang pasti, karena node terakhir menunjuk kembali ke node pertama, membentuk lingkaran[1].
B. Jenis-jenis linked list
a. Single Linked List 

Setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya.
Operasi umum:
Penambahan data: Di depan (insert depan), di belakang (insert belakang), di tengah (insert tengah).
Penghapusan data: Di depan (hapus depan), di belakang (hapus belakang), di tengah (hapus tengah).
Pencarian data: Menelusuri list dari head hingga data yang dicari ditemukan [2].
Pada singel linked list erbagi juga atas circular dan non-circular.
b. Doubel Linked List

Setiap node memiliki dua pointer:
Pointer depan (next) yang menunjuk ke node berikutnya.
Pointer belakang (prev) yang menunjuk ke node sebelumnya.
Operasi umum:
Sama seperti single linked list, ditambah dengan:
Penelusuran list dari tail ke head.
Penghapusan node dengan lebih mudah [2].
## Guided 

### Guided 1
##### Membuat sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data. 

Source code:
```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```

Program ini dibuat untuk mengimplementasikan daftar tertaut single linked list non-sirkular untuk mengelola data bilangan bulat. Program ini menyediakan berbagai fungsi untuk menambahkan, mengubah, menghapus, dan menampilkan data dalam list.

### Guided 2
#### Membuat sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

Source Code:

 ```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr; // prev; untuk melihat data sebelumnya
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
 ```

Program ini dibuat untuk mengimplementasikan struktur data double linked list untuk mengelola kumpulan bilangan bulat. Program ini menawarkan berbagai fungsi menu yang mudah digunakan, memungkinkan untuk:
Menambahkan data: Memasukkan nilai integer (bilangan bulat) baru di awal list.
Menghapus data: Menghapus nilai integer dari node terdepan (awal) list.
Memperbarui data: Memodifikasi nilai integer yang ada di dalam list berdasarkan nilai sebelumnya.
Membersihkan data: Menghapus semua elemen dari list, sehingga menjadi kosong.
Menampilkan data: Mencetak isi list, menampilkan semua integer yang tersimpan.
Keluar: Menutup program.

### Guided 3
#### Membuat sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

Source Code:

 ```C++
#include<iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

//Deklarasi Struct Node
struct Node{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty(){
    if (head == NULL)
        return 1; // true
    else 
        return 0; // false

}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung list
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;

        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;

        }

        tail->next = baru;
        baru->next = head;
    }
} 

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;

        }

        baru->next = bantu->next;
        bantu->next = baru;
    
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang 
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearlist(){
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhsil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0){
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else{
        cout << "List masih kosong!" << endl;
    }
}
 int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
 }
 ```

Program ini dibuat untuk mengimplementasikan struktur data single linked list  circular untuk mengelola kumpulan data string (teks). Program ini menyediakan berbagai fungsi untuk menambahkan, mengubah, menghapus, dan menampilkan data dalam list.

## Unguided 

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 

#### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa
##### Kode program 

```C++
#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk menyimpan data mahasiswa
struct Node {
  string nama;
  string nim;
  Node* next; // Pointer ke node berikutnya
};

// Deklarasi pointer head untuk awal list
Node* head = nullptr;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
  cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
  cout << "=========================================\n";
  cout << "1. Tambah Depan\n";
  cout << "2. Tambah Belakang\n";
  cout << "3. Tambah Tengah\n";
  cout << "4. Ubah Depan\n";
  cout << "5. Ubah Belakang\n";
  cout << "6. Ubah Tengah\n";
  cout << "7. Hapus Depan\n";
  cout << "8. Hapus Belakang\n";
  cout << "9. Hapus Tengah\n";
  cout << "10. Hapus List\n";
  cout << "11. TAMPILKAN\n";
  cout << "0. KELUAR\n";
  cout << "Pilih Operasi : ";
}

// Fungsi untuk menambahkan node di depan list
void tambahDepan() {
  string nama, nim;
  cout << "\nMasukkan Nama : ";
  cin >> nama;
  cout << "Masukkan NIM : ";
  cin >> nim;

  Node* newNode = new Node;
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->next = head;
  head = newNode;

  cout << "Data " << nama << " telah ditambahkan di depan list.\n";
}

// Fungsi untuk menambahkan node di belakang list
void tambahBelakang() {
  string nama, nim;
  cout << "\nMasukkan Nama : ";
  cin >> nama;
  cout << "Masukkan NIM : ";
  cin >> nim;

  Node* newNode = new Node;
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  cout << "Data " << nama << " telah ditambahkan di belakang list.\n";
}

// Fungsi untuk menambahkan node di tengah list
void tambahTengah() {
  string nama, nim;
  int posisi;

  cout << "\nMasukkan Nama : ";
  cin >> nama;
  cout << "Masukkan NIM : ";
  cin >> nim;
  cout << "Masukkan Posisi : ";
  cin >> posisi;

  if (posisi <= 0) {
    cout << "Posisi tidak valid. Data tidak ditambahkan.\n";
    return;
  }

  Node* newNode = new Node;
  newNode->nama = nama;
  newNode->nim = nim;

  int count = 1;
  Node* prev = nullptr;
  Node* curr = head;

  while (curr != nullptr && count < posisi) {
    prev = curr;
    curr = curr->next;
    count++;
  }

  if (curr == nullptr) {
    cout << "Posisi melebihi jumlah node. Data tidak ditambahkan.\n";
  } else {
    newNode->next = curr;
    if (prev == nullptr) {
      head = newNode;
    } else {
      prev->next = newNode;
    }
    cout << "Data " << nama << " telah ditambahkan di tengah list (posisi " << posisi << ").\n";
  }
}

// Fungsi untuk mengubah data node di depan list
void ubahDepan() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang diubah.\n";
    return;
  }

  string namaBaru, nimBaru;
  cout << "\nMasukkan Nama Baru : ";
  cin >> namaBaru;
  cout << "Masukkan NIM Baru : ";
  cin >> nimBaru;

  head->nama = namaBaru;
  head->nim = nimBaru;

  cout << "Data di depan telah diubah.\n";
}

// Fungsi untuk mengubah data node di belakang list
void ubahBelakang() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang diubah.\n";
    return;
  }

  string namaBaru, nimBaru;
  cout << "\nMasukkan Nama Baru : ";
  cin >> namaBaru;
  cout << "Masukkan NIM Baru : ";
  cin >> nimBaru;

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->nama = namaBaru;
  temp->nim = nimBaru;

  cout << "Data di belakang telah diubah.\n";
}

// Fungsi untuk mengubah data node di tengah list
void ubahTengah() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang diubah.\n";
    return;
  }

  string namaBaru, nimBaru;
  int posisi;
  cout << "\nMasukkan Nama Baru : ";
  cin >> namaBaru;
  cout << "Masukkan NIM Baru : ";
  cin >> nimBaru;
  cout << "Masukkan Posisi : ";
  cin >> posisi;

  if (posisi <= 0) {
    cout << "Posisi tidak valid. Tidak ada data yang diubah.\n";
    return;
  }

  int count = 1;
  Node* temp = head;
  while (temp != nullptr && count < posisi) {
    temp = temp->next;
    count++;
  }

  if (temp == nullptr) {
    cout << "Posisi melebihi jumlah node. Tidak ada data yang diubah.\n";
  } else {
    temp->nama = namaBaru;
    temp->nim = nimBaru;
    cout << "Data pada posisi " << posisi << " telah diubah.\n";
  }
}

// Fungsi untuk menghapus node di depan list
void hapusDepan() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang dihapus.\n";
    return;
  }

  Node* temp = head;
  head = head->next;
  delete temp;

  cout << "Data di depan telah dihapus.\n";
}

// Fungsi untuk menghapus node di belakang list
void hapusBelakang() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang dihapus.\n";
    return;
  }

  Node* temp = head;
  Node* prev = nullptr;
  while (temp->next != nullptr) {
    prev = temp;
    temp = temp->next;
  }

  if (prev == nullptr) {
    head = nullptr;
  } else {
    prev->next = nullptr;
  }

  delete temp;
  cout << "Data di belakang telah dihapus.\n";
}

// Fungsi untuk menghapus node di tengah list
void hapusTengah() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang dihapus.\n";
    return;
  }

  int posisi;
  cout << "Masukkan Posisi yang akan dihapus: ";
  cin >> posisi;

  if (posisi <= 0) {
    cout << "Posisi tidak valid. Tidak ada data yang dihapus.\n";
    return;
  }

  Node* temp = head;
  Node* prev = nullptr;
  int count = 1;

  while (temp != nullptr && count < posisi) {
    prev = temp;
    temp = temp->next;
    count++;
  }

  if (temp == nullptr) {
    cout << "Posisi melebihi jumlah node. Tidak ada data yang dihapus.\n";
  } else {
    if (prev == nullptr) {
      head = temp->next;
    } else {
      prev->next = temp->next;
    }
    delete temp;
    cout << "Data pada posisi " << posisi << " telah dihapus.\n";
  }
}

// Fungsi untuk menghapus seluruh list
void hapusList() {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  cout << "Seluruh list telah dihapus.\n";
}

// Fungsi untuk menampilkan isi list
void tampilkan() {
  if (head == nullptr) {
    cout << "List kosong.\n";
  } else {
    cout << "Daftar Mahasiswa:\n";
    Node* temp = head;
    while (temp != nullptr) {
      cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
      temp = temp->next;
    }
  }
}

// Fungsi utama
int main() {
  int choice;

  do {
    tampilkanMenu();
    cin >> choice;

    switch (choice) {
      case 1:
        tambahDepan();
        break;
      case 2:
        tambahBelakang();
        break;
      case 3:
        tambahTengah();
        break;
      case 4:
        ubahDepan();
        break;
      case 5:
        ubahBelakang();
        break;
      case 6:
        ubahTengah();
        break;
      case 7:
        hapusDepan();
        break;
      case 8:
        hapusBelakang();
        break;
      case 9:
        hapusTengah();
        break;
      case 10:
        hapusList();
        break;
      case 11:
        tampilkan();
        break;
      case 0:
        cout << "Keluar dari program.\n";
        break;
      default:
        cout << "Operasi tidak valid.\n";
    }
  } while (choice != 0);

  return 0;
}

```
Program ini dibuat untuk mengimplementasikan struktur data single linked list non-circular untuk menyimpan data mahasiswa. Program ini menyediakan berbagai operasi yang dapat dilakukan pada list, seperti menambah data, mengubah data, menghapus data, dan menampilkan data.

Tampilkan: Menampilkan seluruh data mahasiswa dalam list.

###### Output Program :

![Screenshot 2024-04-28 145603](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/31fd0bfd-793f-4860-8300-2f41e4d692c5)

###### Full screenshot 

![Screenshot 2024-04-28 153952](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/2ec591ec-4407-4fef-930a-c0451bc6b2cc)

#### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 

##### Input data

![Screenshot 2024-04-28 145905](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/ca00e57f-012e-4979-8128-30502da81999)

##### Tampilan keseluruhan data yang diinput

![Screenshot 2024-04-28 145918](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/bbcf0249-fc08-4f23-9de7-beb90677c38b)

#### 3. Lakukan perintah berikut: 
##### (a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004 
###### Tampilan saat menginput
![Screenshot 2024-04-28 150019](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/d4c55633-4a0b-4460-8675-3a2fb2212f38)
###### Tampilan data 
![Screenshot 2024-04-28 150203](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/e49d96ec-6083-4ca2-b869-c43656372016)
##### (b) Hapus data Denis 
###### Tampilan saat menghapus
![Screenshot 2024-04-28 150212](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/84ea7f56-0ae9-4183-92f9-ec9ab70902d2)
###### Tampilan data 
![Screenshot 2024-04-28 150222](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/34cc0ee4-fa6e-4c7f-8f93-35c692d4cbfb)
##### (c) Tambahkan data berikut di awal: Owi 2330000 
###### Tampilan saat menghapus
![Screenshot 2024-04-28 150255](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/81d0c943-d0e2-418c-99ad-e6a5bc41b8b9)
###### Tampilan data 
![Screenshot 2024-04-28 150304](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1fc59115-07e6-406b-abc1-ff9e35b23895)
##### (d) Tambahkan data berikut di akhir: David 23300100 
###### Tampilan saat menginput
![Screenshot 2024-04-28 150345](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/2d6e18d6-ef2a-48f2-9b47-c13d78e394fa)
###### Tampilan data 
![Screenshot 2024-04-28 150401](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/7ac7c8c5-b80d-4116-a333-753bc1651508)
##### (e) Ubah data Udin menjadi data berikut: Idin 23300045 
###### Tampilan saat menginput
![Screenshot 2024-04-28 150451](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/a9c0cea4-91ef-4412-829d-d2f6c0022470)
###### Tampilan data 
![Screenshot 2024-04-28 150550](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/3741f84b-ab44-40ac-8683-d06cf9ae949b)
##### (f) Ubah data terkahir menjadi berikut: Lucy 23300101 
###### Tampilan saat menginput
![Screenshot 2024-04-28 150542](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/497f1190-7e2c-45cc-a5a1-a522b68b10d5)
###### Tampilan data 
![Screenshot 2024-04-28 150550](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/4afd1aca-d93d-43e0-a4dc-747a51d8325c)
##### (g) Hapus data awal 
###### Tampilan saat menghapus
![Screenshot 2024-04-28 150607](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/e31d9927-2335-438e-aff6-24430df29615)
###### Tampilan data 
![Screenshot 2024-04-28 150622](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1f0173b2-cdf9-45cf-968d-ccb1235d9396)
##### (h) Ubah data awal menjadi berikut: Bagas 2330002 
###### Tampilan saat menginput
![Screenshot 2024-04-28 150710](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/3c649437-6ddb-4a4d-917d-bf8ed792eab5)
###### Tampilan data 
![Screenshot 2024-04-28 150720](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/0197671d-5bc2-424a-ab72-255ce2560150)
##### (i) Hapus data akhir 
###### Tampilan saat menghapus
![Screenshot 2024-04-28 150743](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/b675bb10-a78e-45c3-bcc9-765c18c1cb8e)
##### (j) Tampilkan seluruh data
![Screenshot 2024-04-28 150756](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/76b46992-496b-4788-9498-8f10aa97dfd4)

## Kesimpulan

Linked list merupakan struktur data yang terdiri dari node-node yang saling terhubung. Setiap node memiliki dua bagian: data dan pointer yang menunjuk ke node berikutnya. Linked list erdiri dari singel linked list dan double linked list. Pada prakteknya, membantu memahami dan membedakan penggunaan masing-masing jenis linked list dan berbagai operasi pada linked list.
 

## Referensi

[1] G. Williams, H. Williams, A Survey of recent Advances in Linked List Research. ACM Digital Library, 2019. doi:DOI 10.1145/3379748.3379795
[2] C. Brown, D. Brown, Linked List-Based Data Structures for Efficient Graph Representation. Springer Link, 2021. doi: DOI 10.1007/s10444-021-10524-8 
