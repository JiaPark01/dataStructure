#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

static Node *createNode(int data, Node *next)
{
	Node *p = malloc(sizeof(Node));
	assert(p);
	p->data = data;
	p->next = next;
	
	return p;	// return the address of the node created (reason for Node type func)
}

void initList(List *pList)
{
	//pList->ptr = malloc(sizeof(Node));
	// //pList->ptr->data = dummy
	//pList->ptr->next = NULL;
	
	pList->ptr = createNode(-1, NULL);

}

void cleanupList(List *pList)
{
	Node *p = pList->ptr;
	while(p) {
		Node *temp = p;
		p = p->next;
		free(temp);
	}
}

void printList(const List *pList)
{
	Node *p = pList->ptr->next;
	printf("[");
	
	while(p) {
		printf("%d", p->data);
		printf((p->next) ? ", " : "]");
		p = p->next;
	}
	printf("\n");
}

void insertFirstNode(List *pList, int data)
{
	//Node *p = malloc(sizeof(Node));
	//p->data = data;
	//p->next = pList->ptr->next;		// after dummy node
	//pList->ptr->next = p;
	pList->ptr->next = createNode(data, pList->ptr->next);
}

void insertNode(List *pList, int prevData, int data)
{
	Node *p = pList->ptr->next;
	while(p) {
		if (p->data == prevData) {
			break;
		}
		p = p->next;
	}
	
	if (p) {	// found the prevData
		//Node *temp = malloc(sizeof(Node));
		//temp->data = data;
		//temp-> next = p->next;
		//p->next = temp;
		p->next = createNode(data, p->next);
	}	// doesn't do anything if value not found
}

void deleteNode(List *pList, int data)
{
	Node *p = pList->ptr->next;
	Node *temp = pList->ptr;
	
	while(p) {
	if (p->data == data) {
		break;
	}
		p = p->next;
		temp = temp->next;
	}
	
	if (p) {
		temp->next = p->next;
		free(p);
	}
}
