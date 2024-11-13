#include <stdio.h>
#include <stdlib.h>
struct node {
         int value;
         struct node *next;
};
typedef struct node *NODE;
NODE getnode() {
 NODE x;
 x = (NODE)malloc(sizeof(struct node));
 if (x == NULL){
 printf("No memory");
 exit(0);
 }
return (x);
}
NODE insert_first(NODE first, int item) {
         NODE new_node;
         new_node = getnode();
         new_node->value = item;
         new_node->next = first;
         return new_node;
}
NODE insert_end(NODE first, int item) {
         NODE new_node, temp;
         new_node = getnode();
         new_node->value = item;
         new_node->next = NULL;
         if (first == NULL) {
         return new_node;
         }
         temp = first;
         while (temp->next != NULL) {
         temp = temp->next;
          }
         temp->next = new_node;
        return first;
}
NODE insert_anyposition(NODE first, int item, int pos) {
 int count = 1;
 NODE new_node, temp;
 new_node = getnode();
 new_node->value = item;
 new_node->next = NULL;
 if (pos == 1) {
 new_node->next = first;
 return new_node;
 }
 temp = first;
 while (temp != NULL && count < pos - 1) {
 temp = temp->next;
 count++;
 }
 if (temp == NULL) {
 printf("Invalid position\n");
 return first;
 }
 new_node->next = temp->next;
 temp->next = new_node;
 return first;
}
NODE delete_first(NODE first) {
 if (first == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 NODE temp = first;
 first = first->next;
 free(temp);
 return first;
}
NODE delete_element(NODE first, int key) {
 if (first == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 NODE temp = first;
 NODE prev = NULL;
 if (temp != NULL && temp->value == key) {
 first = temp->next;
 free(temp);
 return first;
 }
 while (temp != NULL && temp->value != key) {
 prev = temp;
 temp = temp->next;
 }
 if (temp == NULL) {
 printf("Element not found\n");
 return first;
 }
 prev->next = temp->next;
 free(temp);
 return first;
}
NODE delete_last(NODE first) {
 if (first == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (first->next == NULL) {
     free(first);
     return NULL;
  }
 NODE temp = first;
 while (temp->next->next != NULL) {
    temp = temp->next;
 }
 free(temp->next);
 temp->next = NULL;
 return first;
}
void display(NODE first) {
 if (first == NULL) {
 printf("List is empty\n");
 return;
 }
 while (first != NULL) {
 printf("%d ", first->value);
 first = first->next;
 }
 printf("\n");
}
int main() {
 NODE first = NULL;
 int choice, item, pos, key;
 while (1) {
     printf("\n1. Insert at beginning\n");
     printf("2. Insert at end\n");
     printf("3. Insert at any position\n");
     printf("4. Delete first element\n");
     printf("5. Delete specified element\n");
     printf("6. Delete last element\n");
     printf("7. Display\n");
     printf("8. Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &choice);
    switch (choice) {
         case 1:
         printf("Enter the value to insert at beginning: ");
         scanf("%d", &item);
         first = insert_first(first, item);
         break;
         case 2:
         printf("Enter the value to insert at end: ");
         scanf("%d", &item);
         first = insert_end(first, item);
         break;
         case 3:
         printf("Enter the value to insert: ");
         scanf("%d", &item);
         printf("Enter the position: ");
         scanf("%d", &pos);
         first = insert_anyposition(first, item, pos);
         break;
         case 4:
         first = delete_first(first);
         break;
         case 5:
         printf("Enter the element to delete: ");
         scanf("%d", &key);
         first = delete_element(first, key);
         break;
         case 6:
         first = delete_last(first);
         break;
         case 7:
         printf("The linked list is: ");
         display(first);
         break;
         case 8:
         exit(0);
         default:
         printf("Invalid choice\n");
 }
 }
 return 0;
 }
