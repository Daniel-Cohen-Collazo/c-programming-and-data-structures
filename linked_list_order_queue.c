#include <stdio.h>
#include <stdlib.h>

// Define a structure for the order
typedef struct Order {
    int order_number;
    struct Order* next;
} Order;

// Function to add an order to the end of the linked list
void addOrder(Order** head, int order_number) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    newOrder->order_number = order_number;
    newOrder->next = NULL;

    if (*head == NULL) {
        *head = newOrder;
    } else {
        Order* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newOrder;
    }
}

// Function to remove the first order from the linked list (FIFO)
void removeOrder(Order** head) {
    if (*head == NULL) {
        printf("Linked List Empty: Exit\n");
        exit(0);
    } else {
        Order* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to print the orders in reverse order
void printOrders(Order* head) {
    if (head == NULL) {
        printf("Linked List Empty: Exit\n");
        exit(0);
    }
    
    Order* stack = NULL;
    while (head != NULL) {
        Order* temp = (Order*)malloc(sizeof(Order));
        temp->order_number = head->order_number;
        temp->next = stack;
        stack = temp;
        head = head->next;
    }
    
    printf("[ ");
    while (stack != NULL) {
        printf("%d ", stack->order_number);
        stack = stack->next;
    }
    printf("]\n");
}

int main() {
    Order* orderList = NULL;
    int order_number;
    int choice;

    while (1) {
        printf("Order (0) / Exit (1): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Linked List (order List):\n");
            printOrders(orderList);
            int orderCount = 0;

            while (orderList != NULL) {
                removeOrder(&orderList);
                orderCount++;
                printf("Linked List after order %d:\n", orderCount);
                printOrders(orderList);
            }
            exit(0);
        } else if (choice == 0) {
            printf("Enter Order #: ");
            scanf("%d", &order_number);
            addOrder(&orderList, order_number);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}