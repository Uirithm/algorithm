#include <iostream>

#define HEAP_MAX (5000)

using namespace std;

int N;
int heap[HEAP_MAX + 1];
int lastnode;

int Heap_Push(int d)
{
	if (lastnode == HEAP_MAX) return 0;
	int n, p, temp;

	heap[++lastnode] = d;

	n = lastnode; p = n / 2;

	while (p > 0)
	{
		if (heap[n] < heap[p])
		{
			temp = heap[n];
			heap[n] = heap[p];
			heap[p] = temp;

			n = p; p = n / 2;
		}
		else break;
	}

	return 1;
}

int Heap_Pop(int *d) // Call by reference
{
	if (lastnode == 0) return 0;

	int n, c, lc, rc, temp;

	*d = heap[1];
	heap[1] = heap[lastnode--];

	n = 1; lc = 2; rc = 3;

	while (lc <= lastnode) // 자식이 존재하는 동안 (왼쪽 자식 존재하는 경우 동안)
	{
		if (lc == lastnode) c = lc; // 자식이 하나밖에 없는 경우는 항상 왼쪽 자식 & 마지막 노드
		else c = (heap[lc] < heap[rc]) ? (lc) : (rc);

		if (heap[n] > heap[c])
		{
			temp = heap[n];
			heap[n] = heap[c];
			heap[c] = temp;

			n = c; lc = 2 * n; rc = lc + 1;
		}
		else break;
	}

	return 1;
}

int main(void)
{
	int i;
	Heap_Push(-77);
	Heap_Push(10);
	Heap_Push(-1);
	Heap_Push(-2);
	Heap_Push(10);
	Heap_Push(40);
	Heap_Push(0);
	Heap_Push(1);
	Heap_Push(-2);

	int d;
	for (i = 0; i < 11; ++i)
	{
		if (Heap_Pop(&d) == 1)
			cout << d << endl;
	}

	return 0;
}