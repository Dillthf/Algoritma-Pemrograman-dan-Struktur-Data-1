# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori

Queue atau antrian adalah suatu jenis struktur data yang dapat diproses dengan sifat FIFO (First In First Out), dimana elemen yang pertama kali masuk ke antrian akan keluar pertama kali [1]. Ada dua jenis operasi yang bisa dilakukan di antrian: enqueue (memasukkan elemen baru ke dalam elemen) dan dequeue (adalah mengeluarkan satu elemen dari suatu antrian). Antrian 
dapat dibuat dengan menggunakan: Linear Array dan Circular Array [2].
First-In First-Out (FIFO) adalah sebuah metode pemecahan dalam masalah antrian yang dapat diterapkan dengan cara laporan pengaduan yang pertama kali masuk diasumsikan keluar pertama kali [3]. Hal ini sudah berjalan sesuai dengan mekanisme antrian pada umumnya, dimana antrian yang pertama kali masuk akan diselesaikan atau dilayani terlebih dahulu [1].

## Guided 

### Guided 1

Source code:
```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isfull() {
    if(back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    }else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isfull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if(isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for(int i =0; i < back; i++) {
            queueTeller[i] = queueTeller[i+ 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back =0;
        front = 0;
    }
}

void viewQueue() {
    cout << "data antrian teller: " << endl;
    for(int i =0; i < maksimalQueue; i++) {
        if(queueTeller[i] !="") {
            cout << i + 1 << "." << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "jumlah antrian =" << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "jumlah antrian = " << countQueue() << endl;
    return 0; 
}
```

Program ini dibuat untuk mengelola buku. Program ini mengelola data buku tersebut menggunakan fungsi-fungsi seperti memeriksa apakah stack kosong atau tidak. Menambahkan data baru ke dalam stack, menghapus data dari stack, mengubah posisi tertentu, dan menampilkan data buku tersebut.

### Output
![Screenshot 2024-05-13 101204](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/057076b9-c5d4-40cc-9fff-870dadd49e5a)

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.


#### Kode program 

```C++
#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void viewQueue() {
        Node* current = front;
        cout << "Data antrian teller:" << endl;
        for (int i = 1; i <= 5; i++) {
            if (current != NULL) {
                cout << i << ". " << current->data << endl;
                current = current->next;
            } else {
                cout << i << ". (kosong)" << endl;
            }
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue("Andi");
    queue.enqueue("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}

```
Program ini dibuat untuk memeriksa apakah kalimat yang dimasukkan oleh pengguna terasuk palindrom atau bukan. Cara kerja program ini dengan membuat sebuah stack yang diberi nama kalimat. Kalimat yang dimasukkan oleh pengguna (bertipe data string) dimasukkan ke dalam stack kalimat. Karena program ini menggunakan stack, maka tumpukkan karakter yang diambil pertama adalah karakter yang terakhir masuk ke dalam stack. Jika kalimat yang dimasukkan adalah palindrom, maka karakter awal dan akhirnya akan dibaca sama. Sehingga kalimat yang dimasukkan pengguna diambil secara terbalik dari stack.



###### Output 

![Screenshot 2024-05-13 101241](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/8352b696-afd1-4184-8587-624ea0b7d2fd)

###### Full screenshot 

![Screenshot 2024-05-13 101331](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/35aaf087-66fd-4355-9753-fab135aef973)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

#### Kode Program

``` C++
#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node;
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = NULL;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void viewQueue() {
        Node* current = front;
        cout << "Data antrian mahasiswa:" << endl;
        int count = 1;
        while (current != NULL) {
            cout << count << ". Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
            current = current->next;
            count++;
        }
        for (int i = count; i <= 5; i++) {
            cout << i << ". (kosong)" << endl;
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue("Dill", "2311110048");
    queue.enqueue("Joonie", "9419120912");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}


```
Program ini dibuat untuk membalikkan kalimat. Cara kerja program ini adalah saat pengguna memasukkan kalimat, kalimat tersebut menggunakan stack "terbalikKalimat". Kalimat akan dibaca perkaraker, jika karakter yang dibaca berupa spasi, maka program akan membalik kata yang sudah terbaca sebelumnya. Spasi juga ditambahkan untuk memisahkan kata dalam kalimat. Jika bukan spasi, maka karakter tersebut dimasukkan ke dalam stack. Setelah selesai, program akan menampilkan kalimat asli yang dimasukkan pengguna dan kalimat yang telah dibalik.

##### Output
![Screenshot 2024-05-13 101304](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f781fcc5-4421-411a-a3d1-36ab45900ebd)

Program ini membalikkan kalimat dengan tidak hanya membalik urutan karakter atau huruf yang terdapat pada kata di dalam kalimat, namun juga membalikkan urutan posisi kata dalam kalimat. Sehingga urutan kata pertama menjadi yang terakhir dan kata terakhir menjadi kata petama. Huruf pertama menjadi huruf terakir dan huruf terakir menjadi huruf pertama, dan seterusnya.

##### Full Screenshot

![Screenshot 2024-05-13 101348](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/6d7b60a4-6d36-45c6-a618-2994b34a42c6)


## Kesimpulan

Stack digunakan dengan metode item yang masuk terakhir akan diakses terlebih dahulu. Stack juga memiliki berbagai operasi seperti pop(), push(), top(), dan operasi lainnya. Stack dapat diaplikasikan pada program yang membutuhkan pengolahan data, penyimpanan, dan lainnya.

## Referensi

[1] G. M. Putri, "Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort", JTeksis, vol.6, no.2, 286-296, April 2024.
doi : https://doi.org/10.47233/jteksis.v6i2.1192

[2] Sihombing, Johnson. 2019. Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. Jurnal Ilmiah Infokom, Hal. 15-24, Vol. 7, No. 2

[3] Fridayanthie1, E. W., Mahdiati, T.. 2016. Rancang Bangun Sistem Informasi Permintaan ATK Berbasis Intranet (Studi Kasus: Kejaksaan Negeri Rangkasbitung). Jurnal Khatulistiwa Informatika, Vol. IV, No. 2 Desember 2016
