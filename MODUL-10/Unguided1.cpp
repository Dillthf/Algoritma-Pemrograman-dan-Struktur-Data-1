#include <iostream>

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
    std::cout << "Masukkan bilangan bulat positif: ";
    std::cin >> num;
    
    if (num < 0) {
        std::cout << "Bilangan harus positif." << std::endl;
    } else {
        int hasil = faktorial(num);
        std::cout << "Faktorial dari " << num << " adalah: " << hasil << std::endl;
    }

    return 0;
}
