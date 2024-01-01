#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;
    char kalimat[1000];

    // Membuka file untuk penulisan (mode "w" akan membuat file baru atau menimpa file yang sudah ada)
    filePointer = fopen("output.txt", "w");
    if (filePointer == NULL) {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    // Meminta pengguna untuk memasukkan kalimat
    printf("Masukkan Teks : ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menulis kalimat ke dalam file
    fprintf(filePointer, "%s", kalimat);

    // Menutup file
    fclose(filePointer);

    // Menampilkan output yang dibaca dari file
    printf("\n===OUTPUT===\n");
    filePointer = fopen("output.txt", "r");
    if (filePointer == NULL) {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    // Membaca dan menampilkan isi file
    while (fgets(kalimat, sizeof(kalimat), filePointer) != NULL) {
        printf("%s", kalimat);
    }

    // Menutup file setelah selesai membaca
    fclose(filePointer);

    return 0;
}
