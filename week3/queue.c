#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[10],rear=-1,front=-1,ch,element,item;

void insert();
int deletion();
void display();

void main(){
    while(1){
        printf("1:INSERTION\n2:DELETION\n3:DISPLAY\n4:EXIT\n");
        scanf("%d",&ch);
            switch(ch){
                case 1:insert();break;
                case 2:item=deletion();
                       if(item!=-1){
                        printf("The deleted element is=%d\n",item);
                       }
                       break;
                case 3:display();break;
                case 4:exit(0);
            }

    }
}
void insert(){
   if(rear==MAX-1){
    printf("The Queue is full\n");
    return;
   }
    printf("Enter element to insert\n");
    scanf("%d",&element);

   if (rear==-1 && front==-1){
    rear=0;
    front=0;
   }
   else{
    rear=rear+1;
   }
   queue[rear]=element;
   return;
}

int deletion(){
    if(rear==-1 && front==-1){
        printf("The Queue is empty\n");
        return -1;
    }
    element=queue[front];
    if (rear==front){
        rear=-1;
        front=-1;
        return element;
    }
    front=front+1;
    return element;
}

void display(){
 if(front==-1 && rear==-1){
    printf("Queue is empty\n");
    return;
 }
 printf("The Contents of the queue are\n");
 for(int i=front;i<=rear;i++){
    printf("%d\n",queue[i]);
 }
}
