// created by wahyu abdil afif_23343085

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data mahasiswa
struct Mahasiswa {
    char nim[15];
    char nama[50];
    float nilai;
};

// Struktur dari simpul stack
struct Node {
    struct Mahasiswa data;
    struct Node* next;
};

// Fungsi untuk membuat simpul stack baru
struct Node* createNode(struct Mahasiswa newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan data ke stack
void push(struct Node** top, struct Mahasiswa newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *top;
    *top = newNode;
}

// Fungsi untuk menghapus data dari stack
struct Mahasiswa pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack kosong\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = *top;
    struct Mahasiswa poppedData = temp->data;
    *top = temp->next;
    free(temp);
    return poppedData;
}

// Fungsi untuk menampilkan data stack
void display(struct Node* top) {
    printf("\nData Mahasiswa dalam Stack:\n");
    while (top != NULL) {
        printf("NIM : %s\n", top->data.nim);
        printf("Nama : %s\n", top->data.nama);
        printf("Nilai : %.2f\n", top->data.nilai);
        top = top->next;
    }
}

// Fungsi untuk membandingkan dua nilai float (untuk sorting)
int compare(float a, float b) {
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

// Fungsi untuk mengurutkan data dalam stack berdasarkan nilai mahasiswa
void sort(struct Node** top) {
    struct Node* current = *top;
    struct Node* index = NULL;
    struct Mahasiswa temp;

    if (*top == NULL) return;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (compare(current->data.nilai, index->data.nilai) == 1) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

int main() {
    struct Node* top = NULL;
    int choice;
    struct Mahasiswa newData;

    while (1) {
        printf("\nMenu Program Stack Mahasiswa\n");
        printf("\n1. Tambahkan Data Mahasiswa\n");
        printf("2. Hapus Data Mahasiswa\n");
        printf("3. Tampilkan Data Mahasiswa\n");
        printf("4. Urutkan Data Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMasukkan NIM: ");
                scanf("%s", newData.nim);
                printf("Masukkan Nama : ");
                scanf(" %[^\n]s", newData.nama);
                printf("Masukkan Nilai : ");
                scanf("%f", &newData.nilai);
                push(&top, newData);
                break;
            case 2:
                if (top == NULL) {
                    printf("\nStack kosong\n");
                } else {
                    printf("\nData yang dihapus:\n");
                    printf("NIM: %s\n", top->data.nim);
                    printf("Nama: %s\n", top->data.nama);
                    printf("Nilai: %.2f\n", top->data.nilai);
                    pop(&top);
                }
                break;
            case 3:
                if (top == NULL) {
                    printf("\nStack kosong\n");
                } else {
                    display(top);
                }
                break;
            case 4:
                if (top == NULL) {
                    printf("Stack kosong\n");
                } else {
                    sort(&top);
                    printf("\nData Mahasiswa telah diurutkan berdasarkan nilai\n");
                }
                break;
            case 5:
                printf("\nTerima kasih telah menggunakan program ini.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("\nPilihan tidak valid\n");
        }
    }

    return 0;
}
