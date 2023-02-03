/*****************************************************************************/
/**
 * @file DLL.c
 * @brief  This file consists of function declarations that operates with Node structure defined in DLL.h
 * and Node structure that forms the doubly linked list data structure.
 * 
 * @author Berk Topbas
 * @date 24.01.2023
 *
 */

#ifndef __DLL__
#define __DLL__

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
} Node;

void display(Node* p);
void reverse_display(Node* p);
int count(Node* p);
int add(Node* p);
int max(Node* p);
int search(Node* p, int key);
int  insert(Node** p, unsigned int pos, int data);
Node* create(int arr[], unsigned int n);
int Delete(Node** p, unsigned int index);
void reverse_list(Node** p);

#endif