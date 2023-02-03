#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Node;

typedef struct cell {
	int hashCode;
	struct node * list;
	struct cell * next;
} Cell;

Cell * createTable(Cell *, int);

Cell * addNode(Cell *, int);

void display(Cell *);

int main() {
	int range;
	printf("Enter the range of the cell: ");
	scanf("%d", &range);
	Cell * base = createTable(base, range);
	
	display(base);
	return 0;
}

Cell * createTable(Cell * base, int range) {
	Cell * temp = base;
	for(int i = 0; i < range; i++) {
		temp->hashCode = i;
		temp->list = (Node *) malloc(sizeof(Node));
		temp->next = (Cell *) malloc(sizeof(Cell));
		temp = temp->next;
	}
	return base;
}

Cell * addNode(Cell * base, int data, int range) {
	if(base == NULL) {
		base = createTable(range);
	}
	Cell * curr = base;
	while(curr->hashCode != data % range) {
		curr = curr->next;	
	}
	curr->list = insertRear(curr->list, data);
	return base;
}

void display(Cell * base) {
	Cell * curr = base;
	while(curr->next != NULL) {
		printf("\n(%d) -> ", curr->hashCode);
		if(curr->list == NULL) {
			printf("[]\n");
		} else{
			while(base->list != NULL) {
				if(base->list->next == NULL){
					printf("%d", base->list->data);
					break;
				}
				printf("%d -> ", base->list->data);
				base->list = list->next;
			}
		}
	}
}
