#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data asisten praktikum
struct Asisten {
    char nama[100];
    char nim[20];
    char kelas[10];
    int angkatan;
};

// Fungsi untuk menampilkan data dari file
void tampilkanData() {
    FILE *filePointer = fopen("data_asisten.bin", "rb");
    if (filePointer == NULL) {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    printf("\n===DATA ASESTEN===\n");

    struct Asisten asisten;
    while (fread(&asisten, sizeof(struct Asisten), 1, filePointer) == 1) {
        printf("\nNama\t\t: %s\n", asisten.nama);
        printf("NIM\t\t: %s\n", asisten.nim);
        printf("Kelas\t\t: %s\n", asisten.kelas);
        printf("Angkatan\t: %d\n", asisten.angkatan);
    }

    fclose(filePointer);
}

// Fungsi untuk menghapus data asisten berdasarkan nama
void hapusData(char nama[]) {
    FILE *filePointer = fopen("data_asisten.bin", "r");
    if (filePointer == NULL) {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    FILE *tempFile = fopen("temp_data_asisten.bin", "w");
    if (tempFile == NULL) {
        perror("Gagal membuka file sementara");
        fclose(filePointer);
        exit(EXIT_FAILURE);
    }

    struct Asisten asisten;
    int dataDihapus = 0;

    // Membaca dan menulis ulang data, melewatkan data yang sesuai kriteria
    while (fread(&asisten, sizeof(struct Asisten), 1, filePointer) == 1) {
        if (strcmp(asisten.nama, nama) == 0) {
            // Data cocok dengan nama yang diinginkan, tidak ditulis ke file sementara
            dataDihapus++;
        } else {
            // Data tidak sesuai dengan kriteria, ditulis ke file sementara
            fwrite(&asisten, sizeof(struct Asisten), 1, tempFile);
        }
    }

    // Menutup file setelah selesai membaca dan menulis ulang
    fclose(filePointer);
    fclose(tempFile);

    // Menghapus file asli dan mengganti dengan file sementara
    remove("data_asisten.bin");
    rename("temp_data_asisten.bin", "data_asisten.bin");

    if (dataDihapus > 0) {
        printf("\n%d data berhasil dihapus.\n", dataDihapus);
    } else {
        printf("\nTidak ada data yang dihapus.\n");
    }
}

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

    // Menampilkan data yang sudah diinput
    tampilkanData();

    // Meminta pengguna untuk memasukkan nama yang ingin dihapus
    printf("\nMasukkan nama asisten yang ingin dihapus: ");
    char nama[100];
    scanf(" %[^\n]s", nama);

    // Menghapus data berdasarkan nama
    hapusData(nama);

    // Menampilkan data setelah penghapusan
    tampilkanData();

    return 0;
}
