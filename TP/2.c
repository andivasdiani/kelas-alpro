#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan data asisten praktikum
struct Asisten {
    char nama[100];
    char nim[20];
    char kelas[10];
    int angkatan;
};

int main() {
    int jumlahData;

    // Meminta pengguna untuk memasukkan jumlah data
    printf("Masukkan banyak data : ");
    scanf("%d", &jumlahData);

    // Membuka file biner untuk penulisan
    FILE *filePointer = fopen("data_asisten.bin", "wb");
    if (filePointer == NULL) {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    // Memasukkan data ke dalam file
    for (int i = 0; i < jumlahData; i++) {
        struct Asisten asisten;

        printf("Data %d\n", i + 1);
        printf("Nama\t\t: ");
        scanf(" %[^\n]s", asisten.nama);

        printf("NIM\t\t: ");
        scanf("%s", asisten.nim);

        printf("Kelas\t\t: ");
        scanf("%s", asisten.kelas);

        printf("Angkatan\t: ");
        scanf("%d", &asisten.angkatan);

        // Menulis data ke dalam file
        fwrite(&asisten, sizeof(struct Asisten), 1, filePointer);
    }

    // Menutup file setelah selesai penulisan
    fclose(filePointer);

    // Membuka file biner untuk membaca
    filePointer = fopen("data_asisten.bin", "rb");
    if (filePointer == NULL) {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    printf("\n===OUTPUT===\n");

    // Membaca dan menampilkan data dari file
    struct Asisten asisten;
    while (fread(&asisten, sizeof(struct Asisten), 1, filePointer) == 1) {
        printf("\nNama\t\t: %s\n", asisten.nama);
        printf("NIM\t\t: %s\n", asisten.nim);
        printf("Kelas\t\t: %s\n", asisten.kelas);
        printf("Angkatan\t: %d\n", asisten.angkatan);
    }

    // Menutup file setelah selesai membaca
    fclose(filePointer);

    return 0;
}
