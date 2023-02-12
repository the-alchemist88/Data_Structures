#include <stdio.h>
#include <stdlib.h>

// Functions are NOT implemented in FIFO fashion, which a typical queue structure follows
// i.e. -- front_enqueue, rear_dequeue
struct Node
{
	int data;
	struct Node *next;
	struct Node *previous;
}*front=NULL,*rear=NULL; // front points to the first, and rear points to last element of the queue

void enqueue(int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	if(t==NULL)
		printf("Queue is FUll\n");
	else
	{
		t->data=x;
		t->next=NULL;
		if(front==NULL)
		{
			t->previous=NULL;
			front=rear=t;
		}
		else
		{
			rear->next=t;
			t->previous=rear;
			rear=t;
		}
	}
}

void front_enqueue(int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	if(t==NULL)
		printf("Queue is FUll\n");
	else
	{
		t->data=x;
		t->previous=NULL;
		if(front==NULL)
		{
			t->next=NULL;
			front=rear=t;
		}
		else
		{
			front->previous=t;
			t->next=front;
			front=t;
		}
	}
}


int dequeue()
{
	int x=-1;
	struct Node* t;
	if(front==NULL)
		printf("Queue is Empty\n");
	else
	{
		x=front->data;
		t=front;
		front=front->next;
		front->previous = NULL;
		free(t);
	}
	return x;
}

int rear_dequeue()
{
	int x=-1;
	struct Node* t;
	if(front==NULL)
		printf("Queue is Empty\n");
	else
	{
		x=rear->data;
		t=rear;
		rear=rear->previous;
		rear->next = NULL;
		free(t);
	}
	return x;
}

void Display()
{
	printf("Forward display:\n");
	struct Node *p=front;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void Reverse_Display()
{
	printf("Reverse display:\n");
	struct Node *p=rear;
	while(p)
	{
		printf("%d ",p->data);
		p=p->previous;
	}
	printf("\n");
}


int main()
{
	int val;
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	puts("Inintial queue");
	Display();
	Reverse_Display();
	puts("Enqueue the data '60' to rear");
	enqueue(60);
	Display();
	puts("Dequeue from front");
	val = dequeue();
	printf("dequeued Node's data = %d\n",val);
	Display();
	puts("Enqueue the data '90' to front");
	front_enqueue(90);
	Display();
	puts("Dequeue from rear");
	val = rear_dequeue();
	printf("dequeued Node's data = %d\n",val);
	Display();
	Reverse_Display();
	return 0;
}