#include <iostream>
#include <string>

void bubbleSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int elemen_terurut = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[elemen_terurut]) {
                elemen_terurut = j;
            }
        }
        std::swap(arr[i], arr[elemen_terurut]);
    }
}

int main() {
    std::string arr[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Nama warga sebelum diurutkan: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr, n);

    std::cout << "Nama warga setelah diurutkan: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}