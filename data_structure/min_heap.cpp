/*
최소 히프

최소 값을 root로 가지는 트리 구조로, 삽입 삭제 시 O(logn)의 비용이 필요하다.
이는 상위 노드의 값이 항상 더 큰 것을 보장하기 위한 트리의 연산 비용이다.

pop 연산에서 left, right child의 존재 여부에 대한 예외 처리를 조심해야 한다.
*/

#if 1

#include<iostream>
using namespace std;

inline void swap(int &a, int &b) 
{
	int tmp = a;
	a = b;
	b = tmp;
}

struct MinHeap
{
#define HEAP_SIZE 100
	int data[HEAP_SIZE]; // 0은 일관성을 위해 사용하지 않는다.
	int top = 0;
	
	void push(int d);
	int pop();
	void show()
	{
		for (int i = 1; i <= top; i++)
		{
			cout << data[i] << " ";
			int newLine = i;
			newLine++;
			while (newLine % 2 == 0) newLine /= 2;
			if (newLine == 1) cout << endl;
		}
	}
};

// 트리의 마지막에 값을 먼저 집어넣은 후 상위 노드들을 비교하면서 트리를 정렬한다.
void MinHeap::push(int d)
{
	data[++top] = d; 
	if (top == 1) return;

	for (int i = top; i != 1; )
	{
		if (d < data[i / 2])
		{
			swap(data[i / 2], data[i]);
			i /= 2; // go to parent
		}
		else break;
	}
}

int MinHeap::pop()
{
	
	int ret = data[1];
	swap(data[1], data[top--]);
	
	for (int i = 1; i < top;)
	{
		if (i * 2 > top) break; // 자식 노드가 더이상 없는 경우 종료

		int parent = i;
		int left = i * 2;
		int right = (i*2+1 > top) ? left: i * 2 + 1; // 오른쪽 자식 노드가 없으면 왼쪽 자식을 target으로 한다.
		int &target = data[left] < data[right] ? left : right;
		
		if (data[target] < data[parent])
		{
			swap(data[target], data[parent]);
			i = target;
		}
		else break;
	}
	return ret;
}

int main(void)
{
	MinHeap heap;
	while (true)
	{
		int choice;
		cout << "1. push\n2. pop\n> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int data;
			cin >> data;
			heap.push(data);
			break;
		case 2:
			if (heap.top == 0) break;
			cout << heap.pop();
			break;
		default:
			exit(0);
		}
		cout << endl << "Display Heap\n";
		heap.show();
		cout << endl;
	}
	return 0;
}

#endif