#ifndef LIST_H
#define LIST_H

typedef struct node {
	struct node *next;
} Node;

typedef struct {
	Node *ptr;
	int eleSize;
} List;

void initList(List *pList, int eleSize);
void cleanupList(List *pList);

void printList(const List *pList, void (*print)(const void * ));	// 반환형이 void, 인자값이 void *, 여기서 사용할 함수 이름을 *print로

void insertFirstNode(List *pList, const void *pData);
void insertNode(List *pList, const void *pPrevData, const void *pData);
void deleteNode(List *pList, const void *pData);


#endif
