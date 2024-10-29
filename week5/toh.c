#include<stdio.h>
void toh(int n, char s, char t, char d);

void toh(int n, char s, char t, char d){
    if (n==1){
        printf("Move %d discs from %c to %c \n", n, s, d);
    }
    else{
        toh(n-1, s, d, t);
        printf("Move %d discs from %c to %c \n", n-1,t,s,d);
        toh(n-1, t, s, d);
    }
}
void main(){
    int num;
    char st='S', de='D', temp='T';
    printf("Enter the number of discs \t");
    scanf("%d", &num);
    toh(num, st, temp, de);
    }
