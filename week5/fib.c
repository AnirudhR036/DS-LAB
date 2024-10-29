#include<stdio.h>
int fib(int n){
if (n==1){
    return 0;
}
if (n==2){
    return 1;
}

return(fib(n-1)+fib(n-2));
}

void main(){
    int x,res;
    printf("Enter the term ");
    scanf("%d",&x);
    res=fib(x);
    printf("The %d term of fibbonacci series is %d",x,res);
}
