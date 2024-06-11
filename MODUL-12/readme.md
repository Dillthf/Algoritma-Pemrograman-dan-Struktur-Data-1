# <h1 align="center">Laporan Praktikum Modul Graph and Tree</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori
 A. Graf
Graf adalah kumpulan simpul (nodes) yang dihubungkan satu sama lain melalui sisi/busur (edges) [1]. Suatu graf G terdiri dari dua himpunan yaitu himpunan V (simpul) dan himpunan E (busur). Busur dapat menunjukkan hubungan (relasi) sembarang seperti rute penerbangan, jalan raya, sambungan telepon, ikatan kimia, dan lain-lain. Notasi graf: G (V, E) artinya graf G memiliki simpul V dan busur E. 

![Screenshot 2024-06-11 083923](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/b5c2c86c-d951-4202-a95e-f9a14a6da9f2)

 Menurut arah dan bobotnya, graf dibagi menjadi empat bagian, yaitu [2]: 
    a. Graf berarah dan berbobot: tiap busur mempunyai anak panah dan bobot. 
    b. Graf tidak berarah dan berbobot: tiap busur tidak mempunyai anak panah tetapi mempunyai bobot. 
    c. Graf berarah dan tidak berbobot: tiap busur mempunyai anak panah yang tidak berbobot. 
    d. Graf tidak berarah dan tidak berbobot: tiap busur tidak mempunyai anak panah dan tidak berbobot. 

Suatu graf dapat direpresentasikan ke beberapa bentuk. Representasi graf dapat digunakan untuk mengimplementasikan graf tersebut ke dalam bentuk tertentu, sehingga dapat digunakan pada berbagai kasus yang berbeda [3]. Representasi graf yang sering digunakan diantaranya: 

    a. Matriks Kedekatan (Adjacency Matrix) 
    Untuk suatu graf dengan jumlah simpul sebanyak n, maka matriks kedekatan mempunyai ukuran n x n (n baris dan n kolom) [1].  
    
   ![Screenshot 2024-06-11 085539](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/617b7812-e870-4e25-97dc-13b1bcf20a6b)

    b. Senarai Kedekatan (Adjacency List)
    Pada simpul x dapat dianggap sebagai suatu senarai yang terdiri dari simpul pada graf yang berdekatan dengan x [1].
    
   ![Screenshot 2024-06-11 085630](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/752c9bf3-7239-41d3-a960-b175126cd527)

B. Tree atau Pohon
Hierarki pada struktur tree dapat diibaratkan seperti sebuah pohon keluarga di mana terdapat hubungan antara orang tua dan anak. Titik yang lebih atas disebut simpul induk sedangkan simpul di bawahnya adalah simpul anak. Struktur data tree terdiri atas kumpulan simpul atau node dimana tiap-tiap simpul dari tree digunakan untuk menyimpan nilai dan sebuah list rujukan ke simpul lain yang disebut simpul anak atau child node [4]. Tiap-tiap simpul dari tree akan dihubungkan oleh sebuah garis hubung yang dalam istilah teknis disebut edge. Biasanya diimplementasikan menggunakan pointer. Simpul pada tree bisa memiliki beberapa simpul anak (child node). Namun, jalan menuju sebuah child node hanya bisa dicapai melalui maksimal 1 node [5]. Apabila sebuah node atau simpul tidak memiliki child node sama sekali maka dinamakan leaf node [4]. Struktur data ini adalah metode khusus untuk mengatur dan menyimpan data di komputer agar dapat digunakan secara lebih efektif.

![Screenshot 2024-06-11 090554](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/faa5964c-d773-4e18-a994-6b1e9a2c5750)

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

### Guided 1

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
Secara keseluruhan, program ini merepresentasikan graf dengan simpul-simpul dan busur-busur berbobot, lalu menampilkan informasi tersebut dalam format yang terstruktur.

### Output
![Z(guided1)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/3f64adb2-0965-4be3-ac27-a98782ed1245)

### Guided 2 

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

Kode di atas membuat dan mengelola sebuah struktur data tree biner, lalu melakukan tiga jenis traversal (pre-order, in-order, dan post-order) untuk menampilkan isi tree tersebut

### Output
![Z(guided2)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/3396a5d9-be37-4859-bfe8-cc818b5e4fa9)



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
Program ini memungkinkan pengguna untuk memasukkan graf berbobot dengan jumlah simpul yang ditentukan. Program ini meminta pengguna untuk memberikan nama setiap simpul dan bobot (berat) antara setiap pasangan simpul, kemudian menampilkan matriks bobot tersebut. 
Program akan meminta pengguna untuk memasukkan jumlah simpul  yang akan ada dalam graf dan menyimpannya dalam variabel dill_2311110048. Dengan perulangan, pengguna akan memasukkan nama setiap simpul dan menympannya dalam vektor namaSimpul. Alur berikutnya adalah menggunakan perulangan bersarang untuk meminta pengguna memasukkan bobot untuk setiap pasangan simpul (i, j) dan menyimpannya dalam matriks 2D yang diberi nama horanghae. Di akhir, program menampilkan nama-nama simpul di baris pertama dan dengan perulangan menampilkan setiap baris dari matriks bobot, dengan nama simpul di kolom pertama dan bobot yang sesuai.


###### Output 
![Z(output unguided 1)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/874d4bb1-6da7-4735-bc53-5ec671bcdde0)

###### Full screenshot 

![Z(fs unguided 2)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/ae0c7e96-10d6-4a88-8c3f-3f1df7b0cc48)

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
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void displayChild(TNode *node, int target) {
    if (node != NULL) {
        if (node->data == target) {
            if (node->left != NULL) {
                cout << "Child: " << node->left->data << endl;
            }
            if (node->right != NULL) {
                cout << "Child: " << node->right->data << endl;
            }
        } else {
            displayChild(node->left, target);
            displayChild(node->right, target);
        }
    }
}

void displayDescendant(TNode *node, int target) {
    if (node != NULL) {
        if (node->data == target) {
            preOrder(node);
        } else {
            displayDescendant(node->left, target);
            displayDescendant(node->right, target);
        }
    }
}

TNode* findNode(TNode* node, int target) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == target) {
        return node;
    }
    TNode* leftResult = findNode(node->left, target);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(node->right, target);
}

void addNode(TNode*& root) {
    int parentData, childData;
    char position;
    cout << "Masukkan data parent node: ";
    cin >> parentData;
    cout << "Masukkan data child node: ";
    cin >> childData;
    cout << "Masukkan posisi child (L/R): ";
    cin >> position;

    if (root == NULL) {
        root = new TNode(childData);
        cout << "Root node created with data: " << childData << endl;
        return;
    }

    TNode* parentNode = findNode(root, parentData);
    if (parentNode != NULL) {
        if (position == 'L' || position == 'l') {
            if (parentNode->left == NULL) {
                parentNode->left = new TNode(childData);
            } else {
                cout << "Left child already exists for node " << parentData << endl;
            }
        } else if (position == 'R' || position == 'r') {
            if (parentNode->right == NULL) {
                parentNode->right = new TNode(childData);
            } else {
                cout << "Right child already exists for node " << parentData << endl;
            }
        } else {
            cout << "Invalid position. Use 'L' for left or 'R' for right." << endl;
        }
    } else {
        cout << "Parent node with data " << parentData << " not found." << endl;
    }
}

int main() {
    TNode* root = NULL;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah node" << endl;
        cout << "2. Tampilkan tree" << endl;
        cout << "3. Tampilkan child" << endl;
        cout << "4. Tampilkan descendant" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNode(root);
                break;
            case 2:
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
            case 5:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 5);

    return 0;
}

```
 Program ini dibuatuntuk mengelola dan menampilkan sebuah pohon biner (binary tree) dinamis. Pengguna dapat menambahkan node ke dalam pohon, serta menampilkan pohon dengan berbagai urutan traversal (pre-order, in-order, post-order), menampilkan child node dari suatu node, dan menampilkan seluruh descendant dari suatu node.
Program menginisialisasi root pohon sebagai NULL lalu menampilkan menu berulang kali hingga pengguna memilih untuk keluar. 

 Saat pengguna memilih pilihan 1, maka alur program akan meminta data node parent, data node child, dan posisi child (kiri/kanan). Jika root NULL, membuat node root dengan data child. Jika parent ditemukan, menambah child pada posisi yang sesuai jika belum ada child di posisi tersebut.

 Jika pengguna memilih pilihan 2, maka program akan menampilkan tree dalam berbagai traversal: pre-order, in-order, dan post-order. 

 Sementara itu, jika pengguna memilih untuk menampilkan child maupun descendant, maka program akan meminta pengguna memasukkan nilai node target kemudian menampilkan child node dari target node atau menampilkan seluruh descendant dari target node menggunakan pre-order traversal.

##### Output

 1) membuat tree
    
![Z(unguided 2 output pil 1)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/88a3ed10-f2f5-4bb4-a1eb-9424d46acc7e)

![Z(unguided 2 output pil 1 b)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/075092a8-663e-40ae-bc8d-12002f482894)

![Z(unguided 2 output pil 1 c)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/df6a59c8-4b94-4984-a6a3-742feec2764f)
 
![Z(unguided 2 output pil 1d)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/06ba9511-934e-4a59-8567-db3101da1a08)

![Z(unguided 2 output pil 1 e)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f7ccd4bf-a973-481a-93bc-161d15f409f6)

![Z(unguided 2 output pil 1 f)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/561225ed-8b47-4f7d-a378-689fce31c578)

![Z(unguided 2 output pil 1 g)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/156a156e-d382-452f-808b-7fbbf14a1edf)

 2) menampilkan tree

![Z(unguided 2 output pil 2)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/b9cb66a1-c8d5-4adf-8a4d-b304acd2a7a9)

 3) menampilkan child

 ![Z(unguided 2 output pil 3)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/37f589c8-8a88-480b-a0cc-8d5d59a620ca)
 
![Z(unguided 2 output pil 3 b)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/f297666d-d5d9-40ad-96f4-f68f8a04b9cc)

![Z(unguided 2 output pil 3 c)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/6e2d8212-fd54-4f08-9bac-f0401c28900f) 

 4) menampilkan descendant

![Z(unguided 2 output pil 4)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/ebd9f7b3-02f1-4dc3-80b6-3a4e2702b4b9)

![Z(unguided 2 output pil 4 b)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/0772c651-ed32-4e2b-9456-fccc07039e5f)

![Z(unguided 2 output pil 4 c)](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/27ed3a0d-ab94-4295-b352-a1ba41aee9de)  

##### Full Screenshot
![Screenshot 2024-06-11 091419](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/279146d5-5ce8-4f00-8197-fca1ca94fa28)


## Kesimpulan

Graf dan tree adalah dua jenis struktur data yang digunakan untuk menyimpan dan mengatur data secara efisien. Graf terdiri dari simpul-simpul yang dihubungkan oleh busur, yang dapat berarah atau tidak, serta berbobot atau tidak berbobot. Representasi graf umum meliputi matriks kedekatan dan senarai kedekatan. Tree, seperti hierarki keluarga, memiliki simpul induk, simpul anak, dan simpul daun, dengan akar sebagai simpul teratas. Setiap simpul di tree dihubungkan oleh edge, dan struktur ini diimplementasikan menggunakan pointer. Konsep penting pada tree mencakup tinggi, kedalaman, dan derajat simpul, serta subtree.

## Referensi
[1] Zakaria, T. M. & Prijono, A. Konsep dan Implementasi Struktur Data. Bandung: Informatika. 2006. 

[2] N. Selma Karamy, “Pewarnaan Titik Pada Graf Dengan Menggunakan Algoritma Pewarnaan Barisan Sederhana Dalam Penataan Buku Perpustakaan,” in Conference on Research & Community Services, 2019, pp. 557–565. 

[3] T. S. N. Anggraini, Lana Aristya, Rosyida, Isnaini ,Asih, “Penyelesaian Masalah Pewarnaan Graf Dengan Algoritma Genetika,” vol. 8, no. 1, pp.30–39, 2019

[4] Oka S., Anak Agung K. Tree Structure Implementation Bebantenan. Journal of CSTID. Jimbaran : UNUD, 2019.

[5] Dewi R., Gilang K. IMPLEMENTASI ALGORITMA BINARY TREE PADA SISTEM INFORMASI MULTILEVEL MARKETING. Jurnal Informatika. No.3 ,  Vol.  3. 2021

[6] M. W. Saputra, A. A. K. O. Sudana, dan I. M. Sukarsa, “Implementasi Struktur Data tree pada
Sistem Informasi Upacara yadnya Berbasis Android”, MERPATI, vol. 2, no. 3, Des 2014.
