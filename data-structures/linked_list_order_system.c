#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int element;
    int priority;
} PriorityQueueElement;

void swap(PriorityQueueElement *a, PriorityQueueElement *b) {
    PriorityQueueElement temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueueElement *queue, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (queue[index].priority > queue[parentIndex].priority) {
            swap(&queue[index], &queue[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void enqueue(PriorityQueueElement *queue, int *size) {
    int element, priority;
    printf("Enter element: ");
    scanf("%d", &element);
    printf("Enter priority (1-5): ");
    scanf("%d", &priority);

    if (*size < 100) {
        queue[*size].element = element;
        queue[*size].priority = priority;
        (*size)++;
        heapifyUp(queue, *size - 1);
        printf("Element added to the priority queue.\n");
    } else {
        printf("Priority queue is full.\n");
    }
}

void heapifyDown(PriorityQueueElement *queue, int size, int index) {
    int leftc = 2 * index + 1;
    int rightc = 2 * index + 2;
    int highestPriority = index;

    if (leftc < size && queue[leftc].priority > queue[highestPriority].priority) {
        highestPriority = leftc;
    }
    if (rightc < size && queue[rightc].priority > queue[highestPriority].priority) {
        highestPriority = rightc;
    }

    if (highestPriority != index) {
        swap(&queue[index], &queue[highestPriority]);
        heapifyDown(queue, size, highestPriority);
    }
}

void dequeue(PriorityQueueElement *queue, int *size) {
    if (*size > 0) {
        printf("Dequeued element: (%d, %d)\n", queue[0].element, queue[0].priority);
        *size -= 1;
        if (*size > 0) {
            queue[0] = queue[*size];
            heapifyDown(queue, *size, 0);
        }
    } else {
        printf("Priority queue is empty.\n");
    }
}

int main() {
    int size = 0;
    PriorityQueueElement queue[100];

    printf("Enter P-queue length: ");
    int length;
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        int element;
        scanf("%d", &element);
        printf("Enter priority of element %d (1-5): ", i + 1);
        int priority;
        scanf("%d", &priority);

        if (priority < 1 || priority > 5) {
            printf("Invalid priority. Please enter a priority between 1 and 5.\n");
            i--;
            continue;
        }

        queue[i].element = element;
        queue[i].priority = priority;
        size++;
    }

    printf("Priority before dequeue:\n");
    for (int i = 0; i < size; i++) {
        printf("(%d, %d)\n", queue[i].element, queue[i].priority);
    }

    int choice;
    do {
        printf("Dequeue (1 for yes, 0 for quit): ");
        scanf("%d", &choice);
        if (choice == 1) {
            dequeue(queue, &size);
            printf("Priority after dequeue:\n");
            for (int i = 0; i < size; i++) {
                printf("(%d, %d)\n", queue[i].element, queue[i].priority);
            }
        } else if (choice != 0) {
            printf("Invalid choice. Please enter 1 for yes or 0 for quit.\n");
        }
    } while (choice != 0);

    return 0;
}
