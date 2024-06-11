// created by wahyu abdil afif_23343085

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur dari simpul mobil
struct NodeMobil {
    char no_plat[20];
    char merk[50];
    char nama_pemilik[100];
    struct NodeMobil *next;
    struct NodeMobil *prev;
};

// Fungsi untuk membuat simpul mobil baru
struct NodeMobil *buatNodeMobil(char no_plat[], char merk[], char nama_pemilik[]) {
    struct NodeMobil *nodeBaru = (struct NodeMobil*)malloc(sizeof(struct NodeMobil));
    if (nodeBaru == NULL) {
        printf("Pengalokasian memori gagal\n");
        exit(1);
    }
    strcpy(nodeBaru->no_plat, no_plat);
    strcpy(nodeBaru->merk, merk);
    strcpy(nodeBaru->nama_pemilik, nama_pemilik);
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    return nodeBaru;
}

// Fungsi untuk menyisipkan simpul mobil di akhir daftar
void sisipkanAkhir(struct NodeMobil **head, char no_plat[], char merk[], char nama_pemilik[]) {
    struct NodeMobil *nodeBaru = buatNodeMobil(no_plat, merk, nama_pemilik);
    if (*head == NULL) {
        *head = nodeBaru;
        return;
    }
    struct NodeMobil *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    nodeBaru->prev = temp;
}

// Fungsi untuk menghapus simpul berdasarkan nomor plat mobil
void hapusBerdasarkanPlat(struct NodeMobil **head, char no_plat[]) {
    if (*head == NULL) {
        printf("\nAntrian kosong\n");
        return;
    }
    struct NodeMobil *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->no_plat, no_plat) == 0) {
            if (temp->prev == NULL) { // Menghapus simpul pertama
                *head = temp->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            printf("\nMobil dengan nomor plat '%s' berhasil keluar\n", no_plat);
            return;
        }
        temp = temp->next;
    }
    printf("\nMobil dengan nomor plat '%s' tidak ditemukan\n", no_plat);
}

// Fungsi untuk menampilkan daftar mobil
void tampilkanAntrian(struct NodeMobil *head) {
    if (head == NULL) {
        printf("Antrian kosong\n");
        return;
    }
    printf("\nAntrian Mobil:\n");
    while (head != NULL) {
        printf("Nomor Plat: %s, Merk: %s, Pemilik: %s\n", head->no_plat, head->merk, head->nama_pemilik);
        head = head->next;
    }
}

int main() {
    struct NodeMobil *head = NULL;

    // Menyisipkan beberapa mobil ke dalam antrian
    sisipkanAkhir(&head, "AB 1264 CD", "Hyundai", "Afif");
    sisipkanAkhir(&head, "BA 4591 DC", "Honda", "Gilang");
    sisipkanAkhir(&head, "B 1057 CA", "Toyota", "Fauzan");

    // Menampilkan daftar mobil dalam antrian
    tampilkanAntrian(head);

    // Menghapus sebuah mobil dari antrian berdasarkan nomor plat
    hapusBerdasarkanPlat(&head, "B 1057 CA");

    // Menampilkan daftar mobil dalam antrian yang telah diperbarui
    tampilkanAntrian(head);

    return 0;
}
