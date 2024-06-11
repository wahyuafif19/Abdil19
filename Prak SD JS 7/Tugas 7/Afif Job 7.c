// created by wahyu abdil afif_23343085

#include <stdio.h>
#include <stdlib.h>

//Jumlah maksimal simpul (nodes)
#define MAX_NODES 100

//Struktur simpul (node)
typedef struct Node {
    int value;
    struct Node* next;
} Node;

//Struktur queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

//Inisialisasi queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

//Memeriksa apakah queue kosong
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

//Menambahkan elemen ke queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//Menghapus elemen dari queue dan mengembalikan nilainya
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Antrian kosong\n");
        return -1;
    } else {
        Node* temp = q->front;
        int value = temp->value;
        q->front = q->front->next;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
        return value;
    }
}

//Algoritma BFS
void BFS(int graph[][MAX_NODES], int nodes, int start) {
    //Array untuk menyimpan status kunjungan simpul
    int visited[MAX_NODES] = {0};

    //Buat queue untuk penelusuran BFS
    Queue* q = createQueue();

    //Tandai simpul awal sebagai telah dikunjungi
    visited[start] = 1;
    printf("Simpul %d ", start);

    //Tambahkan simpul awal ke queue
    enqueue(q, start);

    while (!isEmpty(q)) {
        //Ambil simpul dari depan queue
        int current = dequeue(q);

        //Lakukan penelusuran ke semua simpul yang terhubung dengan simpul saat ini
        for (int i = 0; i < nodes; i++) {
            if (graph[current][i] && !visited[i]) {
                //Tandai simpul yang terhubung sebagai telah dikunjungi
                visited[i] = 1;
                printf("-> %d ", i);
                //Tambahkan simpul yang terhubung ke queue
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int nodes, edges, start;
    int graph[MAX_NODES][MAX_NODES];

    printf("Masukkan jumlah simpul : ");
    scanf("%d", &nodes);

    printf("Masukkan jumlah sisi : ");
    scanf("%d", &edges);

    //Inisialisasi matriks adjacency
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }

    //Masukkan sisi
    printf("Masukkan sisi (format: simpul1 simpul2):\n");
    for (int i = 0; i < edges; i++) {
        int simpul1, simpul2;
        scanf("%d %d", &simpul1, &simpul2);
        graph[simpul1][simpul2] = 1;
        graph[simpul2][simpul1] = 1;
    }

    printf("Masukkan simpul awal untuk BFS : ");
    scanf("%d", &start);

    printf("Hasil Penelusuran BFS : ");
    BFS(graph, nodes, start);

    return 0;
}

