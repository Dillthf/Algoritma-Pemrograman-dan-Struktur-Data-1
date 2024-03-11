#include <iostream>
#include <vector>

using namespace std;

// Struct untuk menyimpan data alamat
struct Alamat {
  string Jalan;
  string Kecamatan;
  string Kabupaten;
};

// Class untuk menyimpan data mahasiswa
class Student {
public:
  string name;
  Alamat alamat; // Menggunakan struct Address
  vector<int> nilai; // Vektor untuk menyimpan nilai

  // Fungsi untuk menghitung rata-rata nilai
  double calculateAverage() {
    double total = 0;
    for (int grade : nilai) {
      total += grade;
    }
    return total / nilai.size();
  }
};

int main() {
  // Deklarasi objek Student
  Student siswa1;

  // Mengisi data siswa
  siswa1.name = "Avny";
  siswa1.alamat.Jalan = "Jalan Komak";
  siswa1.alamat.Kecamatan = "Nubatukan";
  siswa1.alamat.Kabupaten = "Lembata";
  siswa1.nilai.push_back(87);
  siswa1.nilai.push_back(93);
  siswa1.nilai.push_back(85);

  // Menampilkan data siswa
  cout << "Nama: " << siswa1.name << endl;
  cout << "Alamat: " << siswa1.alamat.Jalan << ", " << siswa1.alamat.Kecamatan << ", " << siswa1.alamat.Kabupaten << endl;

  // Menampilkan rata-rata nilai
  double average = siswa1.calculateAverage();
  cout << "Rata-rata nilai: " << average << endl;

  return 0;
}


