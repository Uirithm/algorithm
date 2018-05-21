#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}NODE;

NODE head;

int Insert_Node(int data)
{
	NODE* node = &head;
	NODE* p;
	while (node->next)
	{
		if (node->next->data > data) break;
		node = node->next;
	}

	p = (NODE*)calloc(1, sizeof(NODE));
	if (p == (NODE*)0) return 0;
	p->data = data;

	p->prev = node;
	p->next = node->next;

	p->prev->next = p;
	if (p->next) p->next->prev = p;

	return 1;
}


int Delete_Node(int data)
{
	NODE* node = &head;

	while (node->next)
	{
		if (node->next->data == data)
		{
			node = node->next;

			node->prev->next = node->next;
			if (node->next) node->next->prev = node->prev;
			free(node);

			return 1;
		}
		node = node->next;
	}
	return 0;
}


void Print_All_Node(NODE* node)
{
	if (node == (NODE*)0) return;
	printf("%d ", node->data);
	Print_All_Node(node->next);
}

void Delete_All_Node(NODE* node)
{
	if (node == (NODE*)0) return;
	Delete_All_Node(node->next);
	free(node);
}

int main(void)
{
	Insert_Node(5);
	Insert_Node(10);
	Insert_Node(2);
	Insert_Node(8);
	Insert_Node(15);
	Insert_Node(1);

	Print_All_Node(head.next);
	printf("\n");


	Delete_Node(8);
	Print_All_Node(head.next);
	printf("\n");

	Delete_Node(1);
	Print_All_Node(head.next);
	printf("\n");

	Delete_Node(15);
	Print_All_Node(head.next);
	printf("\n");

	Delete_Node(10);
	Print_All_Node(head.next);


	Delete_All_Node(head.next);
	head.next = (NODE*)0;
	printf("\n");

}