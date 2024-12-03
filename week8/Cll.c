#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (!newNode) {
printf("Memory allocation failed\n");
return NULL;
    }
newNode->data = data;
newNode->next = NULL;
return newNode;
}


void insertEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data);


if (*head == NULL) {
*head = newNode;
newNode->next = *head;
} else {
struct Node* temp = *head;

while (temp->next != *head) {
temp = temp->next;
    }


temp->next = newNode;
newNode->next = *head;
    }
}


void displayList(struct Node* head) {
if (head == NULL) {
printf("List is empty.\n");
return;
}

struct Node* temp = head;
do {
printf("%d -> ", temp->data);
temp = temp->next;
} while (temp != head);

printf("(head)\n");
}

void deleteNode(struct Node** head, int data) {
if (*head == NULL) {
printf("List is empty.\n");
return;
    }

struct Node* temp = *head;
struct Node* prev = NULL;

if (temp->data == data) {
if (temp->next == *head) {
free(temp);
*head = NULL;
return;
} else {

while (temp->next != *head) {
temp = temp->next;
            }

temp->next = (*head)->next;
free(*head);
*head = temp->next;
return;
        }
    }


prev = temp;
temp = temp->next;
while (temp != *head && temp->data != data) {
prev = temp;
temp = temp->next;
    }

if (temp == *head) {
printf("Node with data %d not found in the list.\n", data);
return;
    }

prev->next = temp->next;
free(temp);
}

int main() {
struct Node* head = NULL;


insertEnd(&head, 30);
insertEnd(&head, 20);
insertEnd(&head, 10);
insertEnd(&head, 50);

    printf("Circular Linked List: \n");
    displayList(head);

    deleteNode(&head, 20);

    printf("Circular Linked List after deletion: \n");
    displayList(head);

    return 0;
}
