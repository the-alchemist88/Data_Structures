/*****************************************************************************/
/**
 * @file DLL.c
 * @brief  This file consists of function implementations that operates with Node structure defined in DLL.h
 *
 * @author Berk Topbas
 * @date 24.01.2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

Node* create(int arr[], unsigned int n) //, unsigned int n)
{
	Node* head = (Node*)malloc (sizeof(Node));

	Node* temp; // defined for just holding addresses, hence not allocated memory
	Node* tail;

	head->data = arr[0]; // initialize head node
	head->next = NULL;
	head->previous = NULL;
	tail = head; // for now only one allocated, so head and tail points to same node

// Create a Linked List
	for (unsigned int i=1; i<n; i++)
	{
		// Create a temporary Node
		temp = (Node*)malloc (sizeof(Node)); // Used to create temp to add at the end of the list

		// Populate temporary Node
		temp->data = arr[i];
		temp->next = NULL;
		temp->previous = NULL;

		// tail's next is pointing to temp
		tail->next = temp; // tail was set to head so it is used to set 'next' to point next Node in each loop
		temp->previous = tail; // since temp was set as next node, its 'previous' should point to tail(tail is not the last node yet)
		tail = temp; // Now 'tail' is set to last Node in list
	}
	return head;
}
	
void display(Node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	puts("\n");
}

void reverse_display(Node* p)
{
	while (p->next != NULL)
		p = p->next;
	
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->previous;
	}
	puts("\n");
}

int count(Node* p)
{
	int num = 0;
	while (p!= NULL)
	{
		num++;
		p = p->next;
	}
	return num;
}

int add(Node* p)
{
	int sum = 0;
		while (p!= NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int max(Node* p)
{
	int m = p->data;
		while (p!= NULL)
	{
		if(m < p->data)
			m = p->data;
		p = p->next;
	}
	return m;
}

int search(Node* p, int key)
{
	int order = 1;
	while(p != NULL)
	{
		if( key == p->data)
			return order;
		else
			order++;
		p = p->next;
	}
	return 0;
}

int insert(Node** p, unsigned int index, int data) // index '0' inserts before head, other numbers inserts after 'index'th node
{
	Node* first = *p;
	
	if(index>count(first) || index<0)
	{
		puts("Position is not correct in insert function\n");
		return -1;
	}
	
	else if(index == 0) // insert before head
	{
		Node* head = (Node*)malloc(sizeof(Node));
		head->data = data;
		head->previous = NULL;
		head->next = first;
		first->previous = head;
		*p = head; // move head to first node because it is inserted before head
	}
	
	else // insert after 'index'th node
	{
		Node* temp = (Node*)malloc(sizeof(Node)); 
		
		for(int i = 1; i<index;i++)
			first = first->next;
		
		temp->data = data;
		temp->previous = first;
		temp->next = first->next;
		
		if(first->next)
			first->next->previous = temp;
		first->next = temp;
	}
	return data;
}

int Delete(Node** p, unsigned int index) // deletes the 'index'th node. The head starts from 1
{
	Node* head = *p;

	int x = -1;
	
	if( index<1 || index>count(head))
		return -1;
		
	if(index == 1)
	{
		x = head->data;
		if(head->next)
			head->next->previous = NULL;
		*p = head->next;
		free(head);
	}
	else
	{
		for(int i = 0; i<index-1; i++)
			head = head->next;
		head->previous->next = head->next;
		if(head->next)
			head->next->previous = head->previous;
		x = head->data;
		free(head);
	}
	return x;
}

void reverse_list(Node** p)
{
	Node* temp = NULL;
	Node* head = *p;
	
	while(head)
	{
		temp = head->next;
		head->next = head->previous;
		head->previous = temp;
		head = head->previous;
		if(head != NULL && head->next == NULL)
			*p = head;
	}
}