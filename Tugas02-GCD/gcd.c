#include <stdio.h>
#include <string.h>

// Fungsi untuk menghitung GCD
int gcd(int a,int b){
        if(b ==0)
       return a;
       return gcd(b,a % b);
}

int main(){
    char nama[1][100];
    char tanggal[100];
    int num1,num2;

    printf("Masukkan nama:\n");
    for (int i = 0;i < 1;i++){
    scanf("%d[^\n]",nama[i]);
    }
    printf("Masukkan tanggal:\n");
    scanf("%d[^\n]",tanggal);
    
    printf("Masukkan dua bilangan:");
    scanf("%d %d",&num1,&num2);

    int result = gcd(num1,num2);

    printf("Nama:\n");
    for(int i = 0;i < 1;i++){
        printf("%d.%s\n",i + 1,nama[i]);
    }
    printf("tanggal:%s\n",tanggal);
    printf("GCD dari %d dan %d adalah %d\n",num1,num2,result);

}