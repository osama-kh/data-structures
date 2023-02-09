#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Linked_List.h"

int main()
{
	list* head = NULL;
	int num, index;
	head = BuildList();
	PrintList(head);


	printf("\nEnter a number for new head node: ");
	scanf("%d", &num);
	head = addToHead(head, num);
	PrintList(head);


	printf("\nEnter a number for new tail node: ");
	scanf("%d", &num);
	head = addToTail(head, num);
	PrintList(head);

	printf("\nEnter a number and an index for new node: ");
	scanf("%d%d", &num, &index);
	head = addToIndex(head, num, index);
	PrintList(head);

	printf("\nSorted List: ");
	SelectionSort(head);
	PrintList(head);

	printf("\nEnter a value for delete: ");
	scanf("%d", &num);
	head = Delete(head, num);
	PrintList(head);


	/////////////////////////////////////////////////////////////////////////////////////////////
	// home work functions

	printf("\nThe size of the list is: ");
	int x = Listcounter(head);
	printf("%d \n", x);

	printf("\nEnter a number for new node for sorted list: ");
	scanf("%d", &num);
	head = add_sorted_node(head, num);
	PrintList(head);

	printf("\nEnter a number to see if exist: ");
	scanf("%d", &num);
	Search_num(head, num);

	printf("\n the sum of List's data: %d .\n ", sum_List(head));

	printf("\n the sum of multibly the values in the even indexs in the List : %d .\n ", mul_even(head));
	
	printf("\nreverse list:\n");
	head = reverse_List(head);
	PrintList(head);

	head = FreeList(head);

	return 0;
}