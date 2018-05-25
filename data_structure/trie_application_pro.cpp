//https://www.acmicpc.net/problem/9367

#include <stdio.h>
#include <malloc.h>

typedef struct
{
	int p;
	int q;
	int k;
}CAR;

typedef struct
{
	int inconsistency;
	int sum;
	CAR* car;
}SPY;

typedef struct node
{
	struct node* next[26];
	void* data;
}NODE;

#define GETIDX(X) ((X)-'a')

NODE* Insert_Data(NODE* root, char* str, void* data)
{
	int i;
	NODE* node = root;
	for (i = 0; str[i] != 0;i++)
	{
		if (node->next[GETIDX(str[i])] == (NODE*)0)
		{
			node->next[GETIDX(str[i])] = (NODE*)calloc(1, sizeof(NODE));
		}

		node = node->next[GETIDX(str[i])];
	}
	node->data = data;
	return node;
}
NODE* Search_Data(NODE* root, char* str)
{
	int i;
	NODE* node = root;

	for (i = 0; str[i] != 0;i++)
	{
		if (node->next[GETIDX(str[i])] == (NODE*)0) return (NODE*)0;
		node = node->next[GETIDX(str[i])];
	}
	
	if (node->data == (void*)0) return (NODE*)0;
	else return node;
}

NODE root_spy, root_car;
int N,M,T;

void Insert_Car_Data(void)
{
	int i;
	CAR* car;
	char name[41];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N;i++)
	{
		car = (CAR*)calloc(1, sizeof(CAR));
		scanf("%s %d %d %d", name, &car->p, &car->q, &car->k);
		Insert_Data(&root_car, name, (void*)car);
	}
}

void Process_Event(void)
{
	int i;
	int t;
	int dist,perc;
	char name_spy[41];
	char name_car[41];
	char event_type;
	NODE* node;
	SPY* spy;
	for (i = 0; i < M;i++)
	{
		scanf("%d %s %c", &t, name_spy, &event_type);
		node = Search_Data(&root_spy, name_spy);
		if (node == (NODE*)0)
		{
			spy = (SPY*)calloc(1, sizeof(SPY));
			node = Insert_Data(&root_spy, name_spy, (void*)spy);
		}
		else
		{
			spy = (SPY*)node->data;
		}

		switch (event_type)
		{
		case 'p':
			scanf("%s", name_car);
			if (spy->inconsistency) break;
			if (spy->car)
			{
				spy->inconsistency = 1;
				break;
			}
			node = Search_Data(&root_car, name_car);
			spy->car = (CAR*)node->data;
			spy->sum += spy->car->q;
			break;
		case 'r':
			scanf("%d", &dist);
			if (spy->inconsistency) break;
			if (spy->car == (CAR*)0)
			{
				spy->inconsistency = 1;
				break;
			}
			spy->sum += spy->car->k * dist;
			spy->car = (CAR*)0;
			break;
		case 'a':
			scanf("%d", &perc);
			if (spy->inconsistency) break;
			if (spy->car == (CAR*)0)
			{
				spy->inconsistency = 1;
				break;
			}
			spy->sum += (spy->car->p * perc + 99)/ 100;
			break;
		}
	}
}

char searched_name[41];
int name_idx;

void Print_All_Spy(NODE* node)
{
	int i;

	if (node->data)
	{
		printf("%s ", searched_name);
		SPY* spy = (SPY*)node->data;
		if (spy->inconsistency || spy->car)
		{
			printf("INCONSISTENT\n");
		}
		else
		{
			printf("%d\n",spy->sum);
		}
		free(spy);
	}


	for (i = 0; i < 26;i++)
	{
		if (node->next[i])
		{
			searched_name[name_idx++] = i + 'a';
			Print_All_Spy(node->next[i]);
			searched_name[--name_idx] = 0;

			free(node->next[i]);
			node->next[i] = (NODE*)0;
		}
	}
}

void Delete_All_Car_Node(NODE* node)
{
	int i;

	for (i = 0; i < 26; i++)
	{
		if (node->next[i])
		{
			Delete_All_Car_Node(node->next[i]);
			free(node->next[i]);
			node->next[i] = (NODE*)0;
		}
	}
}


int main(void)
{
	scanf("%d",&T);

	while (T--)
	{
		Insert_Car_Data();

		Process_Event();

		Print_All_Spy(&root_spy);

		Delete_All_Car_Node(&root_car);
	}
	return 0;
}
