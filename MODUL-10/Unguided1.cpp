#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    if (n <= 1) {
        return 1; // Basis rekursi
    } else {
        return n * faktorial(n - 1); // Rekursi
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Bilangan harus positif." << endl;
    } else {
        int hasil = faktorial(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}
