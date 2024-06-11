// created by wahyu abdil afif_23343085

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur dari simpul buku
struct NodeBuku {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct NodeBuku *next;
    struct NodeBuku *prev;
};

// Fungsi untuk membuat simpul buku baru
struct NodeBuku *buatNodeBuku(char judul[], char pengarang[], int tahun) {
    struct NodeBuku *nodeBaru = (struct NodeBuku*)malloc(sizeof(struct NodeBuku));
    if (nodeBaru == NULL) {
        printf("Pengalokasian memori gagal\n");
        exit(1);
    }
    strcpy(nodeBaru->judul, judul);
    strcpy(nodeBaru->pengarang, pengarang);
    nodeBaru->tahun = tahun;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    return nodeBaru;
}

// Fungsi untuk menyisipkan simpul buku di akhir daftar
void sisipkanAkhir(struct NodeBuku **head, char judul[], char pengarang[], int tahun) {
    struct NodeBuku *nodeBaru = buatNodeBuku(judul, pengarang, tahun);
    if (*head == NULL) {
        *head = nodeBaru;
        return;
    }
    struct NodeBuku *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    nodeBaru->prev = temp;
}

// Fungsi untuk menghapus simpul berdasarkan judul buku
void hapusBerdasarkanJudul(struct NodeBuku **head, char judul[]) {
    if (*head == NULL) {
        printf("Daftar kosong\n");
        return;
    }
    struct NodeBuku *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->judul, judul) == 0) {
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
            printf("\nBuku dengan judul '%s' berhasil dihapus\n", judul);
            return;
        }
        temp = temp->next;
    }
    printf("\nBuku dengan judul '%s' tidak ditemukan\n", judul);
}

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku(struct NodeBuku *head) {
    if (head == NULL) {
        printf("Daftar kosong\n");
        return;
    }
    printf("\nDaftar Buku:\n");
    while (head != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", head->judul, head->pengarang, head->tahun);
        head = head->next;
    }
}

int main() {
    struct NodeBuku *head = NULL;

    // Menyisipkan beberapa buku
    sisipkanAkhir(&head, "How to make ice cream", "Gema", 2000);
    sisipkanAkhir(&head, "How to make cake", "Asep", 2005);
    sisipkanAkhir(&head, "How to make ramen", "Aziz", 2010);
    sisipkanAkhir(&head, "How to make pizza", "Herman", 2015);

    // Menampilkan daftar buku
    tampilkanBuku(head);

    // Menghapus sebuah buku berdasarkan judul
    hapusBerdasarkanJudul(&head, "How to make ramen");

    // Menampilkan daftar buku yang telah diperbarui
    tampilkanBuku(head);

    return 0;
}
