#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Anusha Abdulla MUT366

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element *elements;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* initializePriorityQueue(int capacity);
void enqueue(PriorityQueue *queue, int data, int priority);
void displayPriorityQueue(PriorityQueue *queue);
void dequeue(PriorityQueue *queue);

PriorityQueue* initializePriorityQueue(int capacity) {
    PriorityQueue *queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->elements = (Element*)malloc(sizeof(Element) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(PriorityQueue *queue, int data, int priority) {
    if (priority <= 0){
	return;
    }	
    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = queue->size - 1;
    while (i >= 0 && queue->elements[i].priority < newElement.priority) {
        queue->elements[i + 1] = queue->elements[i];

        i--;
    }

    queue->elements[i + 1] = newElement;
    queue->size++;
}

void dequeue(PriorityQueue *queue) {
    int i = 0;
    while (i < queue->size && queue->elements[i].priority == 0) {
        i++;
    }

    if (i == queue->size) {
        printf("No valid elements to dequeue.\n");
        return;
    }

    for (i = 0; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }

    queue->size--;
}

void displayPriorityQueue(PriorityQueue *queue) {
    int i = 0;
    for (i = queue->size-1; i >= 0; i--) {
        printf("(%d, %d)\n", queue->elements[i].data, queue->elements[i].priority);
    }
    fflush(stdout);
}

int main(){
	int capacity;
	int numElements;
	printf("Enter P-Queue Length: ");
	scanf("%d", &capacity);
	int i = 0;
	PriorityQueue *queue = initializePriorityQueue(capacity);
	
	for(i = 0; i < capacity; i++){
		int data, priority;
		printf("Enter element %d: ", i + 1);
		scanf("%d", &data);
		printf("Enter priority of element %d: ", i + 1);
		scanf("%d", & priority);
		if(data != 0){
		enqueue(queue, data, priority);
	}
}
	int value = 1;
	printf("Priority Queue Before Dequeue :\n");
	
	displayPriorityQueue(queue);

	while(value != 0){
		printf("Dequeue (1 for yes, 0 for exit): ");
		scanf("%d", &value);
		if (value == 1){
			dequeue(queue);
			printf("Priority Queue After Dequeue :\n");
			displayPriorityQueue(queue);
		}
	}
}
