/*****************************************************************************/
/**
 * @file DLL.c, DLL.h
 * @brief Driver code to test doubly linked list functions in DLL.c
 *
 * This file tests all defined functions operabilities by printing the DLL's data.
 * Functions don't catch errors if the user passes wrong arguments, 
 * so program may crash in those cases.
 * 
 * @author Berk Topbas
 * @date 24.01.2023
 *
 */

#include <stdio.h>
#include <stdlib.h> 
#include "DLL.h"
 
int main()
{
	int A[] = {3, 5, 7, 10, 15, 18}; // a random int array
	int data = A[3];
	
	puts("Create a doubly linked list(DLL) from an array:");
	Node* list1 = create(A,6); // create a doubly linked list with desired number of elements from a previously initialized array
	display(list1);

	printf("Number of nodes in DLL = %d\n", count(list1));
	printf("Sum of DLL data = %d\n", add(list1));
	printf("Greatest number of DLL = %d\n", max(list1));
	printf("Search data(%d) in DLL. '%d' is found in %dth node of DLL.\n",data, data, search(list1, data));

	puts("\nDisplay DLL data:");
	display(list1);
	
	data = Delete(&list1,4);
	printf("Delete a node in DLL. Deleted node's data = %d\n", data);
	display(list1);
	
	puts("Reverse display DLL data:");
	reverse_display(list1);

	data = insert(&list1,0,11);
	printf("Insert a node in DLL. Inserted node's data = %d\n", data);
	display(list1);
	
	puts("Reverse the DLL:");
	reverse_list(&list1);
	display(list1);
	
	return 0;
}
