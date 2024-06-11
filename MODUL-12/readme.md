# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
 A. Graf
Graf adalah kumpulan simpul (nodes) yang dihubungkan satu sama lain melalui sisi/busur (edges) [1]. Suatu graf G terdiri dari dua himpunan yaitu himpunan V (simpul) dan himpunan E (busur). Busur dapat menunjukkan hubungan (relasi) sembarang seperti rute penerbangan, jalan raya, sambungan telepon, ikatan kimia, dan lain-lain. Notasi graf: G (V, E) artinya graf G memiliki simpul V dan busur E. 

 Menurut arah dan bobotnya, graf dibagi menjadi empat bagian, yaitu [2]: 
    a. Graf berarah dan berbobot: tiap busur mempunyai anak panah dan bobot. 
    b. Graf tidak berarah dan berbobot: tiap busur tidak mempunyai anak panah tetapi mempunyai bobot. 
    c. Graf berarah dan tidak berbobot: tiap busur mempunyai anak panah yang tidak berbobot. 
    d. Graf tidak berarah dan tidak berbobot: tiap busur tidak mempunyai anak panah dan tidak berbobot. 

Suatu graf dapat direpresentasikan ke beberapa bentuk. Representasi graf dapat digunakan untuk mengimplementasikan graf tersebut ke dalam bentuk tertentu, sehingga dapat digunakan pada berbagai kasus yang berbeda [3]. Representasi graf yang sering digunakan diantaranya: 
    a. Matriks Kedekatan (Adjacency Matrix) 
    Untuk suatu graf dengan jumlah simpul sebanyak n, maka matriks kedekatan mempunyai ukuran n x n (n baris dan n kolom) [1].  
    (gambar)

    b. Senarai Kedekatan (Adjacency List)
    Pada simpul x dapat dianggap sebagai suatu senarai yang terdiri dari simpul pada graf yang berdekatan dengan x [1].
    (gambar)

B. Tree atau Pohon
Hierarki pada struktur tree dapat diibaratkan seperti sebuah pohon keluarga di mana terdapat hubungan antara orang tua dan anak. Titik yang lebih atas disebut simpul induk sedangkan simpul di bawahnya adalah simpul anak. Struktur data tree terdiri atas kumpulan simpul atau node dimana tiap-tiap simpul dari tree digunakan untuk menyimpan nilai dan sebuah list rujukan ke simpul lain yang disebut simpul anak atau child node [4]. Tiap-tiap simpul dari tree akan dihubungkan oleh sebuah garis hubung yang dalam istilah teknis disebut edge. Biasanya diimplementasikan menggunakan pointer. Simpul pada tree bisa memiliki beberapa simpul anak (child node). Namun, jalan menuju sebuah child node hanya bisa dicapai melalui maksimal 1 node [5]. Apabila sebuah node atau simpul tidak memiliki child node sama sekali maka dinamakan leaf node [4]. Struktur data ini adalah metode khusus untuk mengatur dan menyimpan data di komputer agar dapat digunakan secara lebih efektif.

Layaknya sebuah pohon yang memiliki akar, cabang, dan daun yang terhubung satu sama lain, pada struktur data tree terdapat beberapa istilah penting yang mirip seperti istilah di dunia nyata, antara lain [6]:
    1. Node
    Node atau simpul adalah entitas pada struktur data tree yang mengandung sebuah nilai dan pointer yang menunjuk simpul di bawahnya (child node).

    2. Child node   
    Child node atau simpul anak adalah simpul turunan dari simpul di atasnya.

    3. Leaf Node
    Leaf node atau simpul daun adalah simpul yang tidak memiliki child node dan merupakan node yang paling bawah dalam struktur data tree. Simpul ini biasa disebut juga sebagai external node

    3. Root
    Root atau akar adalah simpul teratas dari sebuah tree.

    4. Internal node
    Internal node adalah istilah untuk menyebut simpul yang memiliki minimal satu child node.

    5. Edge
    Edge merujuk pada garis yang menghubungkan antara dua buah simpul dalam tree. Jika sebuah tree memiliki N node maka tree tersebut akan memiliki (N-1) edge. Hanya ada satu jalur dari setiap simpul ke simpul lainnya.

    6. Height of node
    Height of node adalah jumlah edge dari sebuah node ke leaf node yang paling dalam.

    7. Depth of node
    Depth of node adalah banyaknya edge dari root ke sebuah node.

    8. Height of tree
    Height of tree dapat diartikan sebagai panjang jalur terpanjang dari simpul akar ke simpul daun dari seuah tree.

    9. Degree of node
    Jumlah cabang yang melekat pada simpul disebut Degree of node atau derajat simpul. Derajat simpul pada sebuah leaf node adalah 0. Selain Degree of node, terdapat juga Degree of tree yaitu derajat maksimum simpul di antara semua simpul pada tree.

    10. Subtree
    Subtree adalah setiap simpul dari tree beserta turunannya.

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
