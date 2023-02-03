#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
	Node *t;
	t = (Node*)malloc(sizeof(Node));
	if(t == NULL) // if heap is full
	printf("Queue is full\n");
	else
	{
		t->data = x;
		t->next = NULL;
		if(front == NULL)
			front = rear = t;
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

int dequeue()
{
	int x = -1;
	Node* t;
	if(front == NULL)
		printf("Queue is Empty\n");
	else
	{
		x = front->data;
		t = front;
		front = front->next;
		free(t); // Release the Node
	}
	return x;
}

void Display()
{
	Node *p = front;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}


int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	Display();
	printf("%d\n",dequeue());
	printf("%d\n",dequeue());
	return 0;
}