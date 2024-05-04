#include <iostream>
#include <stack>

using namespace std;

string balikKalimat(string kalimat) { // Fungsi untuk membalikkan kalimat didefinisikan sebagai balikKalimat
    stack<char> terbalikKalimat; // meginisialisasi stack berisi karakter dengan nama terbalikKalimat
    string balikKalimat = ""; // deklarasi variabel balikKalimat yang bertipe string

    // perulangan untuk tiap karakter dalam string kalimat
    for (char ch : kalimat) {
        if (ch == ' ') {
           
            while (!terbalikKalimat.empty()) { //jika stack kosong, maka perulangan akan terus dimulai
                balikKalimat += terbalikKalimat.top(); // menambahkan karakter teratas dari stack ke string
                terbalikKalimat.pop(); // menghapus karakter teratas dari stack
            }
            balikKalimat += ' '; // menambahkan spasi untuk memisahkan kalimat yang sudah dibalik
        } else {
            terbalikKalimat.push(ch); // memasukkan karakter baru ke dalam stack terbalikKalimat
        }
    } //penutup perulangan for yang sebelumnya

    while (!terbalikKalimat.empty()) { // perulangan selama stack tidak kosong
        balikKalimat += terbalikKalimat.top(); // menambahkan karakter teratas dari stack
        terbalikKalimat.pop(); // menghapus karakter teratas
    }

    return balikKalimat;
}

int main() {
    string objek;

    // pengguna memasukkan kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, objek);

    // memanggil fungsi untuk membalikkan kalimat
    string dibalik = balikKalimat(objek);

    // menampilkan kalimat 
    cout << "Kalimat Asli: " << objek << endl;
    cout << "Kalimat Terbalik: " << dibalik << endl;

    return 0;
}
