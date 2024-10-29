#include<stdio.h>
int factorial(int n){
    if (n==1 || n==0){
        return 1;
    }
    return(n*factorial(n-1));
}

void main(){
    int x,res;
    printf("Enter a number");
    scanf("%d",&x);
    res=factorial(x);
    printf("The factorial of %d is %d",x,res);
}
