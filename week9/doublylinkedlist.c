#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct Node node;

node *new1, *curr, *temp, *start = NULL;
char cho;
int ele, ch;

void create() {
    new1 = (node *)malloc(sizeof(node));
    printf("Enter value: ");
    scanf("%d", &new1->data);
    new1->prev = NULL;
    start = new1;
    curr = new1;

    while (1) {
        printf("Do you want to add another element? (Y/N): ");
        scanf(" %c", &cho);
        if (cho == 'Y' || cho == 'y') {
            new1 = (node *)malloc(sizeof(node));
            printf("Enter value: ");
            scanf("%d", &new1->data);
            new1->prev = curr;
            curr->next = new1;
            curr = new1;
        } else {
            curr->next = NULL;
            return;
        }
    }
}

void insert_left() {
    new1 = (node *)malloc(sizeof(node));
    printf("Enter value: ");
    scanf("%d", &new1->data);
    if (start == NULL) {
        new1->prev = NULL;
        new1->next = NULL;
        start = new1;
        return;
    }
    new1->prev = NULL;
    new1->next = start;
    start->prev = new1;
    start = new1;
}

void delete_sf() {
    if (start == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("Enter ele: ");
    scanf("%d", &ele);

    if (start->data == ele) {
        temp = start;
        start = start->next;
        if (start != NULL) start->prev = NULL;
        free(temp);
        return;
    }

    temp = start;
    while (temp != NULL && temp->data != ele) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    while (1) {
        printf("1. Create\t2. Insert left\n3. Delete specific\t4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: insert_left(); break;
            case 3: delete_sf(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
