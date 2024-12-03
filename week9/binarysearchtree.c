#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left;
    int data;
    struct Node *right;
};

typedef struct Node node;

node *new1, *ptr, *curr, *root = NULL;
char cho;

void create() {
    new1 = (node *)malloc(sizeof(node));
    printf("Enter value: ");
    scanf("%d", &new1->data);
    new1->left = NULL;
    new1->right = NULL;
    root = new1;

    while (1) {
        printf("Do you want to add another element? (Y/N): ");
        scanf(" %c", &cho);
        if (cho == 'Y' || cho == 'y') {
            new1 = (node *)malloc(sizeof(node));
            printf("Enter value: ");
            scanf("%d", &new1->data);
            int item = new1->data;
            new1->left = NULL;
            new1->right = NULL;
            curr = root;

            while (curr != NULL) {
                ptr = curr;
                curr = (item >= curr->data ? curr->right : curr->left);
            }

            if (item < ptr->data) {
                ptr->left = new1;
            } else {
                ptr->right = new1;
            }
        } else {
            return;
        }
    }
}

void preorder(node *ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void display() {
    if (root == NULL) {
        printf("Tree is empty\n");
    } 
    
}

int main() {
    int ch;
    while (1) {
        printf("1. Create\t2. Preorder\n3. Inorder\t4. Postorder\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: printf("Preorder Traversal: "); preorder(root); printf("\n"); break;
            case 3: printf("Inorder Traversal: "); inorder(root); printf("\n"); break;
            case 4: printf("Postorder Traversal: "); postorder(root); printf("\n"); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
