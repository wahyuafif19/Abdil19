// created by wahyu abdil afif_23343085
#include <stdio.h>
#include <string.h>

//Struktur data untuk mahasiswa
struct Mahasiswa 
{
    int nim;
    char nama[50];
    char ttl[50];
    float ipk;
};

//Fungsi sequential search
int sequentialSearch(struct Mahasiswa arr[], int n, int key) 
{
    for (int i = 0; i < n; i++) 
	{
        if (arr[i].nim == key) 
		{
            return i; //Mengembalikan indeks jika ditemukan
        }
    }
    return -1; //Mengembalikan -1 jika tidak ditemukan
}

//Fungsi untuk melakukan binary search pada array yang telah diurutkan
int binarySearch(struct Mahasiswa arr[], int l, int r, int key) 
{
    while (l <= r) 
	{
        int mid = l + (r - l) / 2;

        //Check jika nim di tengah adalah kunci
        if (arr[mid].nim == key)
            return mid;

        //Jika nim di tengah lebih besar, abaikan bagian kanan
        if (arr[mid].nim > key)
            r = mid - 1;

        //Jika nim di tengah lebih kecil, abaikan bagian kiri
        else
            l = mid + 1;
    }
    return -1; //Mengembalikan -1 jika tidak ditemukan
}

//Fungsi untuk output data mahasiswa
void printMahasiswa(struct Mahasiswa mhs) 
{
    printf("\nNIM : %d\n", mhs.nim);
    printf("Nama : %s\n", mhs.nama);
    printf("TTL : %s\n", mhs.ttl);
    printf("IPK : %.2f\n", mhs.ipk);
    printf("\n");
}

int main() 
{
    //Inisialisasi data mahasiswa
    struct Mahasiswa mahasiswa[] = 
	{
        {101, "Afif", "Payakumbuh, 19 Maret 2002", 3.71},
        {102, "Gilang", "Pasaman, 2 September 2005", 3.75},
        {103, "Fauzan", "Bukittinggi,  15 Juli 2005", 3.69},
        {104, "Serly", "Pesisir Selatan, 20 Febuari 2004", 3.45}
    };

    int n = sizeof(mahasiswa) / sizeof(mahasiswa[0]);
    int key;

    printf("\nMasukkan NIM yang ingin dicari (101-104) : ");
    scanf("%d", &key);

    //Pencarian dengan sequential search
    int seqResult = sequentialSearch(mahasiswa, n, key);
    if (seqResult != -1) 
	{
        printf("\nData ditemukan dengan sequential search :\n");
        printMahasiswa(mahasiswa[seqResult]);
    } 
	else 
	{
        printf("Data tidak ditemukan dengan sequential search\n");
    }

    //Mengurutkan array mahasiswa berdasarkan NIM
    //Diperlukan karena binary search memerlukan array yang terurut
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mahasiswa[j].nim > mahasiswa[j + 1].nim) {
                struct Mahasiswa temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j + 1];
                mahasiswa[j + 1] = temp;
            }
        }
    }

    //Pencarian dengan binary search
    int binaryResult = binarySearch(mahasiswa, 0, n - 1, key);
    if (binaryResult != -1) 
	{
        printf("\nData ditemukan dengan binary search :\n");
        printMahasiswa(mahasiswa[binaryResult]);
    } 
	else 
	{
        printf("Data tidak ditemukan dengan binary search\n");
    }

    return 0;
}

