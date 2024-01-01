#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lihatBarang();
void beliBarang();
// void strukBelanja();
// void history();
void helpdesk();
void logout();
struct{
    char nama[30]; char kategori[30];
    }beli;

struct {
    char nama[30], kategori[30];
    int harga;
}barang;

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
            // strukBelanja();
            break;
        case 4:
            // history();
            break;
        case 5:
            helpdesk();
            break;
        case 6:
            logout();
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
        printf("Nama barang\t:%s\n", barang.nama);
        printf("Kategori\t:%s\n", barang.kategori);
        printf("Harga Barang\t:%d\n", barang.harga);
    }

    fclose(f_barang);
    main();
}

void beliBarang(){
    fflush(stdin);
    FILE *f_barang;
    FILE *f_barang2;
    FILE *f_barang3;

    char dipilih[50];

    f_barang = fopen("Daftarbarang.dat","rb");
    f_barang2 = fopen("Daftarbarang2.dat","wb");
    f_barang3 = fopen("struct.dat","ab");
    printf("Masukkan barang yang ingin dibeli :");
    gets(dipilih);

    while (fread(&beli, sizeof(beli), 1, f_barang) == 1){
        if (strcmp(beli.nama, dipilih) != 0) 
        {
            fwrite(&beli, sizeof(beli), 1, f_barang2);
        }
        if (strcmp(beli.nama, dipilih) == 0 && strcmp(beli.kategori, dipilih) == 0)
        {
            strcpy(beli.kategori, barang.kategori);
        }
    }
    fclose(f_barang);
    fclose(f_barang2);
    fclose(f_barang3);
    remove("Daftarbarang.dat");
    rename("Daftarbarang2.dat", "Daftarbarang.dat");
    

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
            printf("Silahkan hubungi admin");
            break;
        case 2:
            printf("Silahkan hubungi admin");
            break;
        case 3:
            printf("Silahkan hubungi admin");
            break;
        default:
            printf("Pertanyaan tidak tersedia");
            system("pause");
            main();
    }
}

void logout(){
    printf("Anda akan keluar dari WDB");
    exit(0);
}