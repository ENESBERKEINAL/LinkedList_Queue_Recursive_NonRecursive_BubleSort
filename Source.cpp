#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int item;
	struct Node *next;
}QUEUE;

QUEUE *head = NULL;
QUEUE *tail = NULL;

void enQueue(int m) {
	QUEUE *p = (QUEUE*)malloc(sizeof(QUEUE));
	if (head == NULL && tail == NULL) {
		head = tail = p;	
		p->item = m;
		p->next = NULL;
	}
	else {
		tail->next = p;
		p->item = m;
		p->next = NULL;
		tail = p;
	}
}

int RecursiveBubbleSort(QUEUE *p, QUEUE *px) {
	if (px == NULL) {             //base case
		return 0;
	}
	else if (p->next == NULL) {
		p = head;
		return RecursiveBubbleSort(p, px->next);
	}
	else if (p->item > p->next->item) {
		QUEUE *temp = (QUEUE*)malloc(sizeof(QUEUE));
		temp->item = p->item;
		p->item = p->next->item;
		p->next->item = temp->item;
		return RecursiveBubbleSort(p->next, px);
	}
	else {
		return RecursiveBubbleSort(p->next, px);
	}
}

void IterativeBubbleSort(QUEUE *p, int n) {
	QUEUE *temp = (QUEUE*)malloc(sizeof(QUEUE)), *px = head;
	while (px != NULL) {
		while (p->next != NULL) {
			if (p->item > p->next->item) {
				temp->item = p->item;
				p->item = p->next->item;
				p->next->item = temp->item;
			}
			p = p->next;
		}
		px = px->next;
		p = head;
	}
}

void printList() {
	QUEUE *p = head;
	printf("\nSorted list: ");
	while (p) {
		printf("%d ", p->item);
		p = p->next;
	}
}

void main() {
	QUEUE *p, *px;
	int n, m, choice;
	bool exit = false;
	printf("How many elements are there in the queue: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("\n%d. number: ", i + 1);
		scanf("%d", &m);
		enQueue(m);
	}
	while (!exit) {
		printf("\n1--Recursive Bubble Sort\n2--Non-Recursive Bubble Sort\n0--For EXIT\n");
		printf("Enter a number: ");
		scanf("%d", &choice);
		p = px = head;
		switch (choice) {
		case 1:
			RecursiveBubbleSort(p, px);
			printList();
			break;
		case 2:
			IterativeBubbleSort(p, n);
			printList();
			break;
		case 0:
			exit = true;
			break;
		default:
			printf("You entered a wrong number..!\n");
			break;
		}
	}
}