#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[10], rear=-1,front=-1,item,element,ch,size=MAX;
void insert();
int deletion();
void display();

void main(){

while(1){
    printf("1:INSERT\n2:DELETE\n3:DIPLAY\n4:EXIT\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:insert();break;
        case 2:element=deletion();
               if (element!=-1){
                printf("The popped element is %d\n",element);
               }
               break;
       case 3:display();break;
       case 4:exit(0);
    }
}
}

void insert(){
    if (front==(rear+1)%size){
        printf("The Queue is full\n");
        return;
    }
    if (front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%size;
    }
    printf("Enter the element to insert\n");
    scanf("%d",&item);
    queue[rear]=item;
}

int deletion(){
    if (rear==-1 && front==-1){
        printf("Queue is empty\n");
        return -1;
    }
    item=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
        return item;
    }
    front=(front+1)%size;
    return item;
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return;
    }
    if (front<=rear){
        for(int i= front; i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
    else{
        for(int i=front;i<MAX;i++){
            printf("%d\n",queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}
