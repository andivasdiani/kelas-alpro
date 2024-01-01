#include<stdio.h>

void displayGaji(char nama[100], char golongan, int jam_kerja, int gaji_total) {
    printf("Nama: %s\n", nama);
    printf("Golongan: %c\n", golongan);
    printf("Gaji: Rp %d\n", gaji_total);
}

int calcGaji(int jam_kerja, int gaji_pokok_perjam, int gaji_perjam, int gaji_lembur) {
    if (jam_kerja > 150) {
        return gaji_pokok_perjam + gaji_perjam + gaji_lembur;
    } else {
        return gaji_pokok_perjam + gaji_perjam;
    }
}

int main() {
    char nama[100], golongan;
    int jam_kerja, gaji_total, gaji_pokok, gaji_perjam, gaji_lembur;

    printf("Nama:\n");
    fgets(nama, sizeof(nama), stdin);

    printf("Golongan:\n");
    scanf("%c", &golongan);

 switch(golongan) {
        case '1':
            printf("Masukan jam kerja:\n");
            scanf("%d", &jam_kerja);
            gaji_pokok = 500000;
            gaji_perjam = jam_kerja * 5000;
            gaji_lembur = (jam_kerja - 150) * 100;
            gaji_total = calcGaji(jam_kerja, gaji_pokok, gaji_perjam, gaji_lembur);
            displayGaji(nama, golongan, jam_kerja, gaji_total);
            break;

        case '2':
             printf("Masukan jam kerja:\n");
            scanf("%d", &jam_kerja);
            gaji_pokok = 300000;
            gaji_perjam = jam_kerja * 3000;
            gaji_lembur = (jam_kerja - 150) * 100;
            gaji_total = calcGaji(jam_kerja, gaji_pokok, gaji_perjam, gaji_lembur);
            displayGaji(nama, golongan, jam_kerja, gaji_total);
            break;

        case '3':
             printf("Masukan jam kerja:\n");
            scanf("%d", &jam_kerja);
            gaji_pokok = 250000;
            gaji_perjam = jam_kerja * 2000;
            gaji_lembur = (jam_kerja - 150) * 100;
            gaji_total = calcGaji(jam_kerja, gaji_pokok, gaji_perjam, gaji_lembur);
            displayGaji(nama, golongan, jam_kerja, gaji_total);
            break;

        case '4':
            printf("Masukan jam kerja:\n");
            scanf("%d", &jam_kerja);
            gaji_pokok = 100000;
            gaji_perjam = jam_kerja * 1500;
            gaji_lembur = (jam_kerja - 150) * 100;
            gaji_total = calcGaji(jam_kerja, gaji_pokok, gaji_perjam, gaji_lembur);
            displayGaji(nama, golongan, jam_kerja, gaji_total);
            break;

        case '5':
            printf("Masukan jam kerja:\n");
            scanf("%d", &jam_kerja);
            gaji_pokok = 50000;
            gaji_perjam = jam_kerja * 1000;
            gaji_lembur = (jam_kerja - 150) * 100;
            gaji_total = calcGaji(jam_kerja, gaji_pokok, gaji_perjam, gaji_lembur);
            displayGaji(nama, golongan, jam_kerja, gaji_total);
            break;

        default:
            printf("Golongan Tersebut Tidak ada\n");
            printf("Silahkan Coba Kembali\n");
            return 1; 
    }

    return 0; 
}


