// created by wahyu abdil afif_23343085

#include <stdio.h>
#include <string.h>

// Mendefinisikan struct Mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

int main() {
    // Mendeklarasikan variabel mahasiswa1 dengan tipe struct Mahasiswa
    struct Mahasiswa mahasiswa1;

    // Mengisi nilai untuk variabel mahasiswa1
    mahasiswa1.NIM = 23343085;
    strcpy(mahasiswa1.Nama, "Wahyu Abdil Afif");
    strcpy(mahasiswa1.TanggalLahir, "19-03-2002");
    mahasiswa1.IPK = 3.75;

    // Menampilkan informasi mahasiswa1
    printf("Informasi Mahasiswa:\n");
    printf("\nNIM: %d\n", mahasiswa1.NIM);
    printf("Nama: %s\n", mahasiswa1.Nama);
    printf("Tanggal Lahir: %s\n", mahasiswa1.TanggalLahir);
    printf("IPK: %.2f\n", mahasiswa1.IPK);

    return 0;
}
