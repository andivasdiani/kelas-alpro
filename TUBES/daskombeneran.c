#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lihatBarang();
void beliBarang();
void strukBelanja();
void history();
void helpdesk();
void logout();

struct {
    char nama[30], kategori[30];
    int harga;
}barang;

struct {
    char nama[30], kategori[30], opsibayar[30];
    int harga;
}struk;

int main(){
    int n;

    printf("========MENU========\n");
    printf("1. Melihat Barang\n2. Membeli Barang\n3. Melihat Struk Belanja\n4. Melihat History\n5. Log out\n");
    printf("Pilih menu\t: ");
    scanf("%d", &n);

    switch(n){
        case 1: 
            lihatBarang();
            break;
        case 2: 
            beliBarang();
            break;
        case 3: 
            strukBelanja();
            break;
        case 4:
            history();
            break;
        case 5:
            logout();
            break;
        case 6:
            helpdesk();
            break;
        default:
            printf("Pilihan anda tidak ada");
            system("pause");
            main();
    }
}

void lihatBarang(){
    FILE *f_barang;
    int n, i;
    
    f_barang = fopen("Daftar barang.dat","rb");

    while (fread(&barang, sizeof(barang), 1, f_barang) == 1) {
        printf("Nama barang\t: %s\n", barang.nama);
        printf("Kategori\t: %s\n", barang.kategori);
        printf("Harga Barang\t: %d\n", barang.harga);
    }

    fclose(f_barang);
    main();
}

void beliBarang(){
    FILE *f_barang;
    FILE *f_barang2;
    FILE *f_barang3;

    char dipilih[50];
    char dipilih2[50];

        f_barang = fopen("Daftar barang.dat","rb");
        f_barang2 = fopen("Daftar barang2.dat","wb");
        f_barang3 = fopen("Struk belanja.dat","ab");
        printf("Masukkan kategori yang ingin dibeli : ");
        gets(dipilih); getchar();
        printf("Masukkan nama barang yang ingin dibeli : ");
        gets(dipilih2);

        while (fread(&barang, sizeof(barang), 1, f_barang) == 1){
            if (strcmp(barang.nama, dipilih) != 0){
                fwrite(&barang, sizeof(barang), 1, f_barang2);
            }
            if (strcmp(barang.kategori, dipilih) == 0 && strcmp(barang.nama, dipilih2) == 0){
                strcpy(struk.kategori, barang.kategori);
                strcpy(struk.nama, barang.nama);
                strcpy(struk.harga, barang.harga);
            }
        }
            
        fclose(f_barang);
        fclose(f_barang2);
        fclose(f_barang3);
        remove("Daftar barang.dat");
        rename("Daftar barang2.dat", "Daftarbarang.dat"); 
        main();  
}

void strukBelanja(){
    FILE *f_barang;
    int n, i, j;
    
    f_barang = fopen("Struk belanja.dat","rb");

    while (fread(&barang, sizeof(barang), 1, f_barang) == 1) {
        printf("Nama barang\t: %s\n", struk.nama);
        printf("Kategori\t: %s\n", struk.kategori);
        printf("Harga Barang\t: %d\n", struk.harga);
    }

    fclose(f_barang);

    printf("====Opsi Pembayaran====\n");
    printf("1. Transfer\n2. COD\n");
    printf("Pilih opsi pembayaran : ");
    scanf("%d", &j);

    switch (j){
        case 1:
            printf("Silahkan transfer di nomor berikut : 123456789 a.n  kelompok 9");
            break;

        case 2:
            printf("Siapkan uang yang pas untuk pembayaran");
            break;
    
        default:
            printf("Opsi pembayaran tidak tersedia");
            break;
    }
    main();
}

void helpdesk(){
    int n;

    printf("===Pertanyaan===\n");
    printf("1. Bagaimana cara mengganti password ?\n");
    printf("2. Bagaimana cara menghapus akun ?\n");
    printf("3. Bagaimana cara menghapus history ?\n");
    printf("Pertanyaan : "); 
    scanf("%d", &n);

    switch(n){
        case 1:
            printf("Silahkan hubungi admin\n");
            break;
        case 2:
            printf("Silahkan hubungi admin\n");
            break;
        case 3:
            printf("Silahkan hubungi admin\n");
            break;
        default:
            printf("Pertanyaan tidak tersedia\n");
            system("pause");
            main();
    }
}

void logout(){
    printf("Anda keluar dari WDB\n");
    exit(0);
}