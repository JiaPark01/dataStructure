#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

int main(void)
{
	Node *ptr;
	ptr = malloc(sizeof(Node));
	
	ptr->data = 1;
	ptr->next = malloc(sizeof(Node));
	
	ptr->next->data = 3;
	ptr->next->next = malloc(sizeof(Node));
	
	ptr->next->next->data = 4;
	ptr->next->next->next = NULL;
	
	
	// insert node 2
	Node *p;
	p = malloc(sizeof(Node));
	p->data = 2;
	p->next = ptr->next;
	ptr->next = p;
	
	// delete node 3
	p = ptr->next->next;
	ptr->next->next = p->next; // ptr->next->next = ptr->next->next->next
	free(p);
	
	p = ptr;
	
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	
	while (p) {
		Node *temp = p;
		p = p->next;
		free(temp);
	}
	
	return 0;
}
