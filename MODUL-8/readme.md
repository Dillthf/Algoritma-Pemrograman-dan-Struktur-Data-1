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

Program ini dibuat untuk membuat antrian dengan struktur data queue. Program tersebut memiliki berbagai fungsi. Didefinisikan konstanta maksimalQueue yang menentukan jumlah maksimal elemen dalam antrian. Terdapat dua variabel global front dan back yang menunjukkan posisi depan dan belakang antrian. Fungsi isfull() dan isEmpty() digunakan untuk memeriksa apakah antrian penuh atau kosong. Fungsi enqueueAntrian(string data) digunakan untuk menambahkan elemen ke dalam antrian. Fungsi dequeueAntrian() digunakan untuk menghapus elemen dari antrian. Fungsi countQueue() mengembalikan jumlah elemen dalam antrian. Fungsi clearQueue() mengosongkan seluruh elemen dalam antrian. Fungsi viewQueue() digunakan untuk menampilkan isi dari antrian. Di dalam fungsi main(), beberapa operasi seperti menambahkan, menghapus, menghitung jumlah, dan mengosongkan antrian dilakukan untuk menguji fungsionalitas program.

### Output
![Screenshot 2024-05-13 101204](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/057076b9-c5d4-40cc-9fff-870dadd49e5a)

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi
linked list.


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
Program dibuat dengan maksud yang sama seperti program pada Guided 1. Namun penggunaan array diganti dengan linked list. Pada bagian baris-baris awal kode program, didefinisikan sebuah struktur Node yang memiliki dua anggota, yaitu data yang menyimpan informasi dari elemen antrian dan next yang merupakan pointer ke node selanjutnya dalam linked list. Bagian kedua mendefinisikan kelas Queue yang mengimplementasikan antrian. Beberapa atribut yang dimilikinya adalah front yang merupakan pointer ke node pertama dalam antrian, rear yang merupakan pointer ke node terakhir dalam antrian, dan size yang menyimpan jumlah elemen dalam antrian. Beberapa fungsi yang dipakai dalam program adalah enqueue(), yang digunakan untuk menambahkan elemen baru ke dalam antrian. Sebuah node baru dibuat, diisi dengan data yang diberikan, dan ditambahkan ke belakang antrian. Jika antrian kosong, maka front dan rear diatur ke node baru tersebut. Fungsi berikutnya, dequeue() digunakan untuk menghapus elemen pertama dari antrian. Node pertama dihapus dan front diupdate ke node berikutnya dalam antrian. clearQueue() digunakan untuk mengosongkan seluruh elemen dalam antrian dengan menghapus satu per satu menggunakan method dequeue(). Dan, viewQueue() digunakan untuk menampilkan isi dari antrian. Ini dilakukan dengan melakukan iterasi melalui seluruh node dalam antrian dan menampilkan datanya. Jika antrian kosong, maka akan ditampilkan "(kosong)". Program ini memiliki main fungsi (main()), sebuah objek queue dari kelas Queue dibuat. Kemudian, beberapa operasi seperti penambahan, penghapusan, penghitungan jumlah, dan pengosongan antrian dilakukan untuk menguji fungsionalitas program. Setelah setiap operasi, isi antrian ditampilkan beserta jumlah elemennya.

###### Output 

![Screenshot 2024-05-13 101241](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/8352b696-afd1-4184-8587-624ea0b7d2fd)

###### Full screenshot 

![Screenshot 2024-05-13 101331](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/35aaf087-66fd-4355-9753-fab135aef973)

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM
Mahasiswa

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
Program ini hanya diubah pada bagian isi antrian dengan menggunakan nama dan nim mahasiswa. Sehingga isi barisan kode awal ini berupa mendefinisikan sebuah struktur Mahasiswa yang memiliki dua anggota, yaitu nama untuk menyimpan nama mahasiswa dan nim untuk menyimpan nomor induk mahasiswa. Kemudian pada barisan berikutnya mendefinisikan sebuah struktur Node yang memiliki dua anggota, yaitu data yang merupakan objek dari struktur Mahasiswa untuk menyimpan data mahasiswa, dan next yang merupakan pointer ke node selanjutnya dalam linked list. Selanjutnya, didefinisikan kelas Queue yang mengimplementasikan antrian. Beberapa atribut yang dimilikinya adalah front yang merupakan pointer ke node pertama dalam antrian, rear yang merupakan pointer ke node terakhir dalam antrian, dan size yang menyimpan jumlah elemen dalam antrian. Fungsi-fungsi yang digunakan juga sama seperti program pada unguided 1. Yaitu fungsi isEmpty() digunakan untuk memeriksa apakah antrian kosong. Ini dilakukan dengan memeriksa apakah size sama dengan 0. Kemudian, enqueue(string nama, string nim) digunakan untuk menambahkan data mahasiswa baru ke dalam antrian. Sebuah node baru dibuat, diisi dengan data nama dan nim yang diberikan, dan ditambahkan ke belakang antrian. Jika antrian kosong, maka front dan rear diatur ke node baru tersebut. Fungsi dequeue() digunakan untuk menghapus elemen pertama dari antrian. Node pertama dihapus dan front diupdate ke node berikutnya dalam antrian. Selanjutnya, countQueue() digunakan untuk mengembalikan jumlah elemen dalam antrian, yaitu nilai dari atribut size. Fungsi clearQueue() digunakan untuk mengosongkan seluruh elemen dalam antrian dengan menghapus satu per satu menggunakan method dequeue(). Dan, viewQueue() digunakan untuk menampilkan isi dari antrian. Ini dilakukan dengan melakukan iterasi melalui seluruh node dalam antrian dan menampilkan nama dan nim mahasiswa. Jika antrian kosong, maka akan ditampilkan "(kosong)". Program ini memiliki fungsi main atau utama (main()), sebuah objek queue dari kelas Queue dibuat. Kemudian, beberapa operasi seperti penambahan, penghapusan, penghitungan jumlah, dan pengosongan antrian dilakukan untuk menguji fungsionalitas program. Setelah setiap operasi, isi antrian ditampilkan beserta jumlah elemennya. 

##### Output
![Screenshot 2024-05-13 101304](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f781fcc5-4421-411a-a3d1-36ab45900ebd)

##### Full Screenshot

![Screenshot 2024-05-13 101348](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/6d7b60a4-6d36-45c6-a618-2994b34a42c6)


## Kesimpulan

Dari penjelasan materi dan praktikum dapat menyimpulkan bahwa antrian adalah sebuah struktur data yang mengikuti prinsip FIFO (First In First Out), di mana elemen yang pertama kali dimasukkan ke dalam antrian akan keluar pertama kali saat operasi penghapusan dilakukan. Terdapat dua operasi utama dalam antrian, yaitu enqueue untuk memasukkan elemen baru dan dequeue untuk mengeluarkan satu elemen dari antrian. Antrian dapat diimplementasikan menggunakan dua jenis struktur data, yaitu Linear Array dan Circular Array. Prinsip FIFO dalam antrian juga dapat diterapkan dalam situasi sehari-hari, seperti dalam penyelesaian laporan pengaduan, di mana laporan yang masuk pertama kali akan dianggap yang paling penting dan diselesaikan terlebih dahulu. Oleh karena itu, penggunaan antrian sangat berguna dalam menangani proses yang memerlukan prioritas berdasarkan urutan kedatangan

## Referensi

[1] R. Gunawan, H. Yuana, S. Kirom, Implementasi Metode Queue Pada Sistem Antrian Online Berbasis Web Studi Kasus UPTD Puskesmas Sananwetan. JATI. Vol.7, No. 3. 2023.

[2] Sihombing, Johnson. 2019. Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. Jurnal Ilmiah Infokom, Hal. 15-24, Vol. 7, No. 2

[3] Fridayanthie1, E. W., Mahdiati, T.. 2016. Rancang Bangun Sistem Informasi Permintaan ATK Berbasis Intranet (Studi Kasus: Kejaksaan Negeri Rangkasbitung). Jurnal Khatulistiwa Informatika, Vol. IV, No. 2 Desember 2016
