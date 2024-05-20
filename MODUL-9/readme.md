# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>
<p align="center">Dill Thafa Jausha</p>
<p align="center">2311110048</p>
<p align="center">SD04-A</p>

## Dasar Teori

Priority queue merupakan struktur data yang menyimpan elemen dengan nilai prioritas. Elemen dengan prioritas lebih tinggi akan dihapus terlebih dahulu. Priority queue digunakan untuk menyimpan node yang akan dikunjungi dalam algoritma pencarian terbaik. Node dengan nilai heuristik yang lebih tinggi diprioritaskan [1]. 

Heap adalah struktur data yang paling umum digunakan untuk priority queue. Heap memiliki kompleksitas waktu rata-rata O(log n) untuk operasi enqueue dan dequeue [2]. Binary search trees adalah struktur data yang memungkinkan operasi enqueue dan dequeue dalam O(log n) waktu rata-rata, tetapi membutuhkan lebih banyak memori dibandingkan heap [2].


## Guided 

### Guided 1

Source code:
```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1)/2;
}

int leftChild(int i) {
    return ((2 * 1) + 1);
}

int rightChild (int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 &&H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[1] > H [maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H [maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std :: swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }  
} 

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize -1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main () {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std :: cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std:: cout << H[i] << "";
    }
    std::cout << "\n";

    std:: cout << "Node with maximum priority : " << extractMax() << "\n";

    std:: cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std :: cout << H[i] << " ";
    }
    std :: cout << "\n";

    changePriority(2, 49);
    std :: cout << "Priority queue after priority change :";
    for (int i = 0; i <= heapSize; ++i) {
        std :: cout << H[i] << " ";
    }
    std :: cout << "\n";

    remove(3);
    std :: cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std :: cout << H[i] << " ";
    }
    return 0;
}

```

Program ini mengimplementasikan struktur data Priority Queue menggunakan Max Heap untuk memastikan bahwa setiap elemen dalam priority queue memiliki properti di mana elemen dengan prioritas tertinggi selalu berada di root (indeks 0). Operasi seperti insert, extractMax, changePriority, dan remove dilakukan dengan memindahkan elemen sesuai kebutuhan untuk menjaga properti heap.


###### Output 

![Screenshot 2024-05-19 225400](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/1b8ad6d1-1e12-4d52-948d-ae2d2c44ab6b)


## Unguided

Modifikasi guided diatas yang mana heap dikonstruksi secara manual
berdasarkan user.

#### Kode Program

``` C++
#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n, value;
    cout << "Masukkan jumlah elemen untuk dimasukkan ke heap: ";
    cin >> n;

    cout << "Masukkan elemen-elemen:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insert(value);
    }

    cout << "Queue Prioritas: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node dengan prioritas maksimum: " << extractMax() << "\n";

    cout << "Queue prioritas setelah mengekstrak maksimum: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Masukkan indeks dan prioritas baru untuk changePriority: ";
    int index, newPriority;
    cin >> index >> newPriority;
    changePriority(index, newPriority);
    cout << "Queue prioritas setelah perubahan prioritas: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Masukkan indeks untuk dihapus: ";
    cin >> index;
    remove(index);
    cout << "Queue prioritas setelah menghapus elemen: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}


```

Program berjalan hampir sama dengan kode program pada guided, yaitu dengan mendeklarasikan array dengan nama H untuk menyimpan elemen heap dan "heapSize" untuk melacak ukuran heap. Untuk mendapatkan indeks parent dari elemen, program menggunakan fungsi "int parent(int i)". Untuk mendapatkan indeks anak kiri dari elemen, menggunakan fungsi "int leftChild(int i). Begitupun sebaliknya, untuk mendapatkan indeks anak kanan elemen, menggunakan fungsi "int rightChild(int i)".

Untuk menggeser elemen, baik ke atas dan ke bawah agar heap property terpenuhi, program menggunakan fungsi shiftUp dan shiftDown. Fungsi shiftUp berjalan dengan memeriksa elemen parent dengan elemen saat ini. Jika elemen parent lebih kecil daripada elemen saat ini, elemen parent ditukar dengan elemen saat ini. Kemudian, indeks akan dipindahkan ke parent untuk memeriksa heap property berikutnya. Sedangkan, fungsi shiftDown berjalan dengan mendapatkan indeks anak kiri dan kanan melalui leftChild dan rightChild, lalu diperiksa apakah  anak kiri dan anak kanan lebih besar dari elemen saat ini. Jika  anak kiri dan kanan lebih besar dari elemen saat ini, set maxIndex ke anak kiri dan set maxIndex ke anak kanan. Jika maxIndex bukan elemen saat ini, elemen saat ini ditukar dengan elemen maxIndex. Pada baris berikutnya adalah rekursi untuk menggeser ke bawah pada maxIndexselan. Indeks dipindahkan ke parent untuk periksa heap property berikutnya. 

Untuk menyisipkan elemen ke dalam heap, menggunakan fungsi insert. Awalnya, ukuran heap aan ditambah. Kemudian elemen baru dimasukkan di akhir heap. Dan elemen tersebut digeser ke atas unutk menjaga heap property.

Untuk mengekstrak elemen maksimum dari heap, menggunakan fungsi extractMax. Elemen maksimum adalah elemen pada indeks 0 di array. Elemen terakhir dipindahkan ke posisi root. Setelah ukuran heap dikurangi, elemen digeser ke bawah untuk menjaga heap property.

Untuk mengubah prioritas elemen pad indeks i ke p, menggunakan fungsi changePriority. Elemen prioritas diubah. Jika prioritas baru lebih besar, maka elemen akan digeser ke atas. Namun, jika prioritas baru ebih kecil atau sama, elemen akan digeser ke bawah.

Untuk mendapatkan elemen maksimum dari heap tanpa menghapus, menggunakan getMax. Jika elemen maksimum adalah elemen di indeks 0. Dan untuk menghapus elemen pada indkes i dari heap, menggunakan fungsi remove. Dengan menaikkan prioritas elemen menjadi lebih tinggi dari maksimum dan elemen digeser ke atas. Kemudian ekstrak elemen maksimum (elemen yang dihapus).

Fungsi utama program, untuk memasukkan jumlah elemen yang dimasukkan ke heap, memasukkan elemen-elemen tersebut, menampilkan priority queue, menampilkan node dengan prioritas maksimum, menampilkan priority queue setelah mengekstarak maksimum, memasukkan indeks dan elemen baru untuk diubah, menampilkan priority queue setelah diubah, memasukkan indeks untuk dihapus, dan menampilkan priority queue setelah dihapus.


##### Output
![Screenshot 2024-05-19 225330](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/9880a861-2111-449e-b358-665f1a10dbef)

Modifikasi pada program dari guided  ini memungkinkan pengguna untuk menentukan banyak elemen (maksimum 50) dan memasukkan sendiri elemen heap. Program juga membebaskan pengguna untuk merubah dan menghapus prority queue sesuai indeks yang diinginkan.

##### Full Screenshot

![Screenshot 2024-05-19 231726](https://github.com/Dillthf/Algoritma-Pemrograman-dan-Struktur-Data-1/assets/161497877/228adc9b-031a-423d-a87d-04316cd20662)



## Kesimpulan

Priority queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritas mereka, dengan elemen nilai prioritas tinggi diambil lebih dahulu. Terdapat beberapa cara untuk mengimplementasikan priority queue, termasuk menggunakan array, linked list, heap, atau binary search tree, masing-masing dengan kelebihan dan kekurangannya. Heap, sebagai struktur data yang mendasari priority queue, memiliki sifat khas seperti being a complete binary tree dan memiliki aturan tertentu, baik sebagai max-heap atau min-heap, yang menentukan urutan nilai-nilai pada setiap node. Heap juga sering digunakan dalam algoritma sorting dan implementasi priority queue.

## Referensi

[1] T. Liu and X. Li, "Priority Queues in Machine Learning," arXiv preprint arXiv:2102.02015, 2021. [Online]

[2] Cheng, T., & Shang, Y., "A Survey of Priority Queues," ACM Computing Surveys, vol. 52, no. 6, 2020. [Online]. 

