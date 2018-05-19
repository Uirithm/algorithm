#include <stdio.h>

#define MAXN (10)

int parent[MAXN];

int Find(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	
	parent[y] = x;
}

int main(void) 
{
	for (int i = 0; i < MAXN; ++i)
		parent[i] = i;

	printf("NodeIdx: ");
	for (int i = 0; i < MAXN; ++i)
		printf("%d ", parent[i]);
	printf("\n");

	Union(1, 2);
	Union(1, 8);

	Union(4, 9);
	Union(1, 9);

	printf("Parent : ");
	for (int i = 0; i < MAXN; ++i)
		printf("%d ", parent[i]);

	printf("\n");

	printf("Top parent of the node %d: %d\n", 9, Find(9));

	return 0;
}
