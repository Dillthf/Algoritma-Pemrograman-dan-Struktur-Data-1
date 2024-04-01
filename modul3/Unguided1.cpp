#include <iostream>
using namespace std;

void selection_Sort(double arr[], int n) { // Deklarasi variable. Dimana variabel arr berisi Indeks Prestasi Semester, dan n berisi jumlah mahasiswa
    for (int i = 0; i < n - 1; ++i) { // Perulangan for ini memulai dari indeks i = 0 dan berhenti ketika indeks i menjadi sama dengan n-1.
        int elemen_terurut = i; // Variabel elemen_terurut berisi indeks elemen yang terurut terkecil hingga saat ini.
        for (int j = i + 1; j < n; ++j) { // Perulangan for ini memulai dari indeks i+1 dan berhenti ketika indeks j menjadi sama dengan n.
            if (arr[j] > arr[elemen_terurut]) { //Jika elemen arr[j] lebih besar dari elemen arr[elemen_terurut], maka indeks elemen_terurut diubah menjadi j
                elemen_terurut = j; 
            } // AKhir dari if
        } // Akhir dari perulangan for
        swap(arr[i], arr[elemen_terurut]); // Setelah mencari elemen yang terurut terkecil, elemen arr[i] diganti dengan elemen arr[elemen_terurut]
    } // Akhir dari perulangan for
} // Akhir dari selection_Sort

int main() { // Fungsi main merupakan fungsi utama program.
    double arr[] = {3.8, 2.9, 3.3, 4.0, 2.4}; // Deklarasi variabel array yang berisi tipe data double. Elemen dalam array tersebut adalah Indeks Prestasi Semester
    int n = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen dalam array arr dengan menggunakan fungsi sizeof

    cout << "Indeks Prestasi Semester Mahasiswa sebelum diurutkan : "; //Menampilkan teks "Indeks Prestasi Semester Mahasiswa sebelum diurutkan :" ke layar
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr.
        cout << arr[i] << " "; // Menampilkan setiap elemen dalam array arr ke layar.
    } // Akhir prulangan for
    cout << endl; 

    selection_Sort(arr, n); // Berupa fungsi selection_Sort dengan parameter arr (array yang akan diurutkan) dan n (jumlah elemen dalam array).

    cout << "Indeks Prestasi Semester Mahasiswa setelah diurutkan : "; // Menampilkan teks "Indeks Prestasi Semester Mahasiswa setelah diurutkan :" ke layar.
    for (int i = 0; i < n; ++i) { // Perulangan for yang berada dalam main mengulang setiap elemen dalam array arr setelah diurutkan.
        cout << arr[i] << " "; // Menampilkan setiap elemen dalam array arr setelah diurutkan ke layar.
    } // Akhir perulangan for
    cout << endl;

    return 0;
}// Akhir main
 