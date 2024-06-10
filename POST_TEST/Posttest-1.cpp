#include <iostream>

using namespace std;

int main (){
    int n = 6;
    int data[n] = {1,2,3,4,5,5};
    int cari = 5;
    int i;
    bool ketemu = false;

    for ( i == 0; i<n ; i++) {
        if (data[i] == cari){
            ketemu = true;
            break;
        }
        
        else {
            ketemu = false;
        }
    }
    
    if (ketemu = true){
        cout << "Angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }
    else {
        cout << "Data tidak ditemukan" << endl;
    }
    return 0;
}
