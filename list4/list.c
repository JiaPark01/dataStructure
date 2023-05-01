#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initList(List *pList, int eleSize)
{
	pList->ptr = malloc(sizeof(Node)/* + eleSize*/);	// dummy node doesn't need data space
	//pList->ptr->data = dummy
	pList->ptr->next = NULL;
	pList->eleSize = eleSize;
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

void printList(const List *pList, void (*print)(const void *))
{
	Node *p = pList->ptr->next;
	printf("[");
	while(p) {
		//printf("%d", p->data);
		(*print)(p + 1);		// or... print(p + 1);
		printf((p->next) ? ", " : "]");
		
		p = p->next;
	}
	printf("\n");
}

void insertFirstNode(List *pList, const void *pData)
{
	Node *p = malloc(sizeof(Node) + pList->eleSize);
	//p->data = data;	// 치환은 memcpy
	memcpy(p + 1, pData, pList->eleSize);
	p->next = pList->ptr->next;		// after dummy node
	pList->ptr->next = p;
}

void insertNode(List *pList, const void *pPrevData, const void *pData)
{
	Node *p = pList->ptr->next;
	while(p) {
		//if (p->data == prevData) {
		if (memcmp(p + 1, pPrevData, pList->eleSize) == 0) {	// 크기만큼 비교
			break;
		}
		p = p->next;
	}
	
	if (p) {	// found the prevData
		Node *temp = malloc(sizeof(Node) + pList->eleSize);
		//temp->data = data;
		memcpy(temp + 1, pData, pList->eleSize);
		temp-> next = p->next;
		p->next = temp;
	}	// doesn't do anything if value not found
}

void deleteNode(List *pList, const void *pData)
{
	Node *p = pList->ptr->next;
	Node *temp = pList->ptr;
	
	while(p) {
		//if (p->data == data) {
		if (memcmp(p + 1, pData, pList->eleSize) == 0) {
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
