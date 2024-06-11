# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
 Ketika suatu fungsi memanggil dirinya sendiri, itu membuat panggilan rekursif. Menurut Sianpar, metode rekursif adalah metode yang secara langsung atau tidak langsung memanggil dirinya sendiri. Kata rekursif berarti "memiliki karakteristik untuk datang kembali, atau mengulangi". Dalam hal ini, pemanggilan fungsi diulangi oleh fungsi itu sendiri. Jenis rekursi ini kadang-kadang disebut rekursi langsung karena fungsinya secara langsung menyebut dirinya. Selain itu, ada jenis rekursi yang kedua yang disebut dengan rekursi tidak langsung. Rekursi tidak langsung terjadi ketika fungsi A memanggil fungsi B, dan fungsi B memanggil kembali ke fungsi A maka itu melibatkan rekursi tidak langsung [1].

 Sebuah fungsi rekursif memanggil dirinya sendiri, memori untuk fungsi yang dipanggil dialokasikan di atas memori yang dialokasikan untuk fungsi pemanggil dan salinan variabel lokal yang berbeda dibuat untuk setiap panggilan fungsi. Ketika base case tercapai, fungsi mengembalikan nilainya ke fungsi yang memanggil, dilanjutkan dengan melepaskan memori dan proses ber- lanjut. Kekurangan dari program rekursif adalah memiliki persyaratan ruang yang lebih besar daripada program iteratif karena semua fungsi akan tetap ada di tumpukan hingga base case tercapai. Program rekursif juga memiliki persyaratan waktu yang lebih besar karena pemanggilan fungsi dan pengembalian overhead.
 Sedangkan, kelebihan rekursi menyediakan cara yang bersih dan sederhana dalam penulisan kode program. Beberapa masalah secara inheren bersifat rekursif seperti Tree Traversal, Tower of Hanoi, dan lain-lain [1]. 

## Guided 

### Guided 1 (Rekursi Langsung)

Source code:
```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0,7,8,0,0,0,0},
    {0,0,5,0,0,15,0},
    {0,6,0,0,5,0,0},
    {0,5,0,0,2,4,0},
    {23,0,0,10,0,0,8},
    {0,0,0,0,7,0,3},
    {0,0,0,0,9,4,0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags (ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur [baris][kolom]<< ")";
            }
        }
        cout << endl;
    }
}

int main(){
    tampilGraph();
    return 0;
}

```

Program ini dibuat untuk mengelola buku. Program ini mengelola data buku tersebut menggunakan fungsi-fungsi seperti memeriksa apakah stack kosong atau tidak. Menambahkan data baru ke dalam stack, menghapus data dari stack, mengubah posisi tertentu, dan menampilkan data buku tersebut.

### Output
![Screenshot 2024-05-04 100525](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/204930f1-9907-47a4-be9f-cb0fab31bba9)

### Guided 2 (Rekursi Tidak Langsung)

Source code:
```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left); 
        cout << node -> data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left); 
        postOrder(node->right);
        cout << node -> data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one -> right = five;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5

    nine-> left = eight;
    // 7
    // /\
    // 1 9
    // /\  /\
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder (seven);
    cout << endl;

    return 0;
}


```

Program ini dibuat untuk mengelola buku. Program ini mengelola data buku tersebut menggunakan fungsi-fungsi seperti memeriksa apakah stack kosong atau tidak. Menambahkan data baru ke dalam stack, menghapus data dari stack, mengubah posisi tertentu, dan menampilkan data buku tersebut.

### Output
![Screenshot 2024-05-04 100525](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/204930f1-9907-47a4-be9f-cb0fab31bba9)



## Unguided 

### 1.	Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya


#### Kode program 

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int dill_2311110048;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> dill_2311110048;

    vector<string> namaSimpul(dill_2311110048);
    for (int i = 0; i < dill_2311110048; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> namaSimpul[i];
    }

    vector<vector<int>> horanghae(dill_2311110048, vector<int>(dill_2311110048, 0));
    for (int i = 0; i < dill_2311110048; i++) {
        for (int j = 0; j < dill_2311110048; j++) {
            cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = ";
            cin >> horanghae[i][j];
        }
    }

    cout << endl;
    cout << "Bobot simpul:" << endl;
    cout << "  ";
    for (int i = 0; i < dill_2311110048; i++) {
        cout << namaSimpul[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < dill_2311110048; i++) {
        cout << namaSimpul[i] << " ";
        for (int j = 0; j < dill_2311110048; j++) {
            cout << horanghae[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
Program ini dibuat untuk memeriksa apakah kalimat yang dimasukkan oleh pengguna terasuk palindrom atau bukan. Cara kerja program ini dengan membuat sebuah stack yang diberi nama kalimat. Kalimat yang dimasukkan oleh pengguna (bertipe data string) dimasukkan ke dalam stack kalimat. Karena program ini menggunakan stack, maka tumpukkan karakter yang diambil pertama adalah karakter yang terakhir masuk ke dalam stack. Jika kalimat yang dimasukkan adalah palindrom, maka karakter awal dan akhirnya akan dibaca sama. Sehingga kalimat yang dimasukkan pengguna diambil secara terbalik dari stack.



###### Output 

![Screenshot 2024-05-04 155016](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/cadb3cc3-d83c-4257-8b33-9e3d3985cbc6)

###### Full screenshot 

![Screenshot 2024-05-04 155033](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/5b7c8e2c-f446-403e-bffa-89a8f614874f)

### 2.	Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
#### Kode Program

``` C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int dill_2311110048) {
        data = dill_2311110048;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node!= NULL) {
        cout << node -> data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node!= NULL) {
        inOrder(node->left); 
        cout << node -> data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node!= NULL) {
        postOrder(node->left); 
        postOrder(node->right);
        cout << node -> data << " ";
    }
}

void displayChild(TNode *node, int target) {
    if (node!= NULL) {
        if (node->data == target) {
            if (node->left!= NULL) {
                cout << "Child: " << node->left->data << endl;
            }
            if (node->right!= NULL) {
                cout << "Child: " << node->right->data << endl;
            }
        } else {
            displayChild(node->left, target);
            displayChild(node->right, target);
        }
    }
}

void displayDescendant(TNode *node, int target) {
    if (node!= NULL) {
        if (node->data == target) {
            preOrder(node);
        } else {
            displayDescendant(node->left, target);
            displayDescendant(node->right, target);
        }
    }
}

int main() {
    TNode *root = NULL;

    int choice;
    cout << "Menu:" << endl;
    cout << "1. Tambah node" << endl;
    cout << "2. Tampilkan tree" << endl;
    cout << "3. Tampilkan child" << endl;
    cout << "4. Tampilkan descendant" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> choice;

    while (choice!= 5) {
        switch (choice) {
            case 1: {
                int dill_2311110048;
                cout << "Masukkan data node: ";
                cin >> dill_2311110048;
                if (root == NULL) {
                    root = new TNode(dill_2311110048);
                } else {
                    TNode *temp = root;
                    while (true) {
                        if (dill_2311110048 < temp->data) {
                            if (temp->left == NULL) {
                                temp->left = new TNode(dill_2311110048);
                                break;
                            } else {
                                temp = temp->left;
                            }
                        } else {
                            if (temp->right == NULL) {
                                temp->right = new TNode(dill_2311110048);
                                break;
                            } else {
                                temp = temp->right;
                            }
                        }
                    }
                }
                break;
            }
            case 2: {
                cout << "Pre Order: ";
                preOrder(root);
                cout << endl;
                cout << "In Order: ";
                inOrder(root);
                cout << endl;
                cout << "Post Order: ";
                postOrder(root);
                cout << endl;
                break;
            }
            case 3: {
                int target;
                cout << "Masukkan node target: ";
                cin >> target;
                displayChild(root, target);
                break;
            }
            case 4: {
                int target;
                cout << "Masukkan node target: ";
                cin >> target;
                displayDescendant(root, target);
                cout << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid" << endl;
        }
        cout << "Menu:" << endl;
        cout << "1. Tambah node" << endl;
        cout << "2. Tampilkan tree" << endl;
        cout << "3. Tampilkan child" << endl;
        cout << "4. Tampilkan descendant" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;
    }

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

[1] Shofwan H., Wayan J. Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Edisi I. Yogyakarta:Andi. 2020.
