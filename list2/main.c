#include "list.h"

int main(void)
{
	List list;
	initList(&list);
	
	insertFirstNode(&list, 4);		// [4]
	insertFirstNode(&list, 3);		// [3, 4]
	insertFirstNode(&list, 1);		// [1, 3, 4]
	
	insertNode(&list, 3, 10);		// [1, 2, 3, 4] (insert 2 after searching 1)
	
	printList(&list);
	
	deleteNode(&list, 3);
	
	printList(&list);				// 1, 2, 4
	
	cleanupList(&list);
	return 0;
}
