#include <stdio.h>
#include "list.h"

void printInt(const void *pData)		// 넘길 때 void *로 넘기므로 여기서 받는 것도 동일하게
{
	printf("%d", *(int *)pData);		// void ptr (바로 *pData) 역참조 불가하므로 타입캐스트
}

void printDouble(const void *pData)
{
	printf("%f", *(double *)pData);
}

int main(void)
{
	List list1, list2;
	initList(&list1, sizeof(int));
	initList(&list2, sizeof(double));
	
	int i;
	i = 4;		insertFirstNode(&list1, &i);		// [4]
	i = 3;		insertFirstNode(&list1, &i);		// [3, 4]
	i = 1;		insertFirstNode(&list1, &i);		// [1, 3, 4]
	
	int j = 1;
	i = 2;		insertNode(&list1, &j, &i);		// [1, 2, 3, 4] (insert 2 after searching 1)
	
	i = 3;		deleteNode(&list1, &i);
	
	printList(&list1, printInt);
	
	double d;
	d = 4.4;	insertFirstNode(&list2, &d);
	d = 3.3;	insertFirstNode(&list2, &d);
	d = 1.1;	insertFirstNode(&list2, &d);
	
	double f = 1.1;
	d = 2.2;	insertNode(&list2, &f, &d);
	
	d = 3.3;	deleteNode(&list2, &d);
	
	printList(&list2, printDouble);
	
	cleanupList(&list1);
	cleanupList(&list2);
	return 0;
}
