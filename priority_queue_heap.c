#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertNodeAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int removeNode(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        exit(1);
    }
    struct Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

void printLinkedList(struct Node* head) {
    printf("LINKED LIST (order list):\n");
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    struct Node* head = NULL;
    int orderNumber;
    int orderCount = 0;

    printf("order(0) / exit(1) : ");

    while (1) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            break;
        } else if (choice == 0) {
            printf("enter order #: ");
            scanf("%d", &orderNumber);
            insertNodeAtFront(&head, orderNumber);
            orderCount++;
            printLinkedList(head);
        } else {
            printf("Invalid choice. Please enter 0 for order or 1 to exit.\n");
        }
    }

    if (orderCount == 0) {
        printf("No orders were placed. Exiting program.\n");
    } else {
        printf("linked list after all orders:\n[ ");
        while (head != NULL) {
            int order = removeNode(&head);
            printf("%d ", order);
        }
        printf("]\n");
    }

    return 0;
}