#include<stdio.h>

int main(){
    int nilaiTugas, nilaiQuiz, nilaiUts, nilaiUas;
    float nilaiAkhir;
    char hurufMutu;

    // Pengulangan untuk menghitung nilai akhir dan huruf mutu untuk 3 mahasiswa
    for (int i = 1; i <= 3; i++) {
        // Input nilai dari pengguna
        printf("Masukkan nilai Tugas Mahasiswa %d: ", i);
        scanf("%f", &nilaiTugas);

        printf("Masukkan nilai Quiz Mahasiswa %d: ", i);
        scanf("%f", &nilaiQuiz);

        printf("Masukkan nilai UTS Mahasiswa %d: ", i);
        scanf("%f", &nilaiUTS);

        printf("Masukkan nilai UAS Mahasiswa %d: ", i);
        scanf("%f", &nilaiUAS);

        // Menghitung nilai akhir
        nilaiAkhir = 0.1 * nilaiTugas + 0.2 * nilaiQuiz + 0.3 * nilaiUTS + 0.4 * nilaiUAS;

        // Menentukan huruf mutu
        if (nilaiAkhir > 90) {
            hurufMutu = 'A';
        } else if (nilaiAkhir >= 86 && nilaiAkhir <= 90) {
            hurufMutu = 'AB';
        } else if (nilaiAkhir >= 81 && nilaiAkhir <= 85) {
            hurufMutu = 'BB';
        } else if (nilaiAkhir >= 76 && nilaiAkhir <= 80) {
            hurufMutu = 'B';
        } else if (nilaiAkhir >= 71 && nilaiAkhir <= 75) {
            hurufMutu = 'BA';
        } else if (nilaiAkhir >= 66 && nilaiAkhir <= 70) {
            hurufMutu = 'C';
        } else if (nilaiAkhir >= 61 && nilaiAkhir <= 65) {
            hurufMutu = 'CB';
        } else if (nilaiAkhir >= 56 && nilaiAkhir <= 60) {
            hurufMutu = 'CA';
        } else if (nilaiAkhir >= 46 && nilaiAkhir <= 55) {
            hurufMutu = 'D';
        } else {
            hurufMutu = 'E';
        }

        // Menampilkan hasil
        printf("Nilai Akhir Mahasiswa %d: %.2f\n", i, nilaiAkhir);
        printf("Huruf Mutu Mahasiswa %d: %c\n", i, hurufMutu);
    }

    return 0;
}
