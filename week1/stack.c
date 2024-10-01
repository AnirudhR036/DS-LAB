#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
# define max 3

int s[10], item, ch, top=-1,i;

void Push(){

  if(top==max-1){
    printf("Stack Overflow \n");
    return;

  }
  top=top+1;
  printf("Enter the element to be pushed \t");
  scanf("%d",&item);
  s[top]=item;


}

int Pop(){

 if (top==-1){
    printf("Stack Underflow\n");
    return -1;
 }

 item=s[top];
 top=top-1;
 return(item);


}

void display(){

 if (top==-1){
    printf("The Stack is empty\n");
    return;
 }
 printf("The contents of the stack are:\n");
 for(i=top;i>=0;i--){
    printf("%d\n",s[i]);
 }

}

void main(){

  while(1){
    printf("1:PUSH\n2:POP\n3:DISPLAY\n4:EXIT\n");
    scanf("%d",&ch);
    switch(ch){
     case 1: Push();
              break;
     case 2: item=Pop();
              if (item!=-1){
                printf("Popped Element is = %d\n",item);
              }
              break;
     case 3: display();
             break;
     case 4: exit(0);


    }
  }
  getch();


}
