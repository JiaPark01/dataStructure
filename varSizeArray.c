#include <stdio.h>

int main(void)
{
	int size;
	scanf("%d", &size);
	
	int array[size];
	
	for (int i = 0; i < size; ++i) {
		array[i] = i;
	}
	
	for (int i = 0; i < size; ++i) {
		printf("%d\n", array[i]);
	}
	
	return 0;
}
