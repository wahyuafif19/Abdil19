// created by wahyu abdil afif_23343085

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Struktur dari simpul stack
struct Node {
    char data;
    struct Node* next;
};

// Fungsi untuk membuat simpul stack baru
struct Node* createNode(char newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan karakter ke dalam stack
void push(struct Node** top, char newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *top;
    *top = newNode;
}

// Fungsi untuk menghapus karakter dari stack
char pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack kosong\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = *top;
    char poppedData = temp->data;
    *top = temp->next;
    free(temp);
    return poppedData;
}

// Fungsi untuk membalik kata menggunakan stack
void reverseWord(char word[]) {
    struct Node* stackTop = NULL;
    int length = strlen(word);
    int i;

    // Push setiap karakter dari kata ke dalam stack
    for (i = 0; i < length; i++) {
        push(&stackTop, word[i]);
    }

    // Pop setiap karakter dari stack untuk membalikkan kata
    printf("\nKata yang dibalik :\n");
    while (stackTop != NULL) {
        printf("%c", pop(&stackTop));
    }
    printf("\n");
}

int main() {
    int choice;
    char word[MAX_LENGTH];

    while (1) {
        printf("\nMenu Program Pembalik Kata\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMasukkan kata: ");
                scanf("%s", word);
                break;
            case 2:
                if (strlen(word) == 0) {
                    printf("\nAnda belum memasukkan kata\n");
                } else {
                    reverseWord(word);
                }
                break;
            case 3:
                printf("\nTerima kasih telah menggunakan program ini.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("\nPilihan tidak valid\n");
        }
    }

    return 0;
}
