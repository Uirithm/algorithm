/*
�ּ� ����

�ּ� ���� root�� ������ Ʈ�� ������, ���� ���� �� O(logn)�� ����� �ʿ��ϴ�.
�̴� ���� ����� ���� �׻� �� ū ���� �����ϱ� ���� Ʈ���� ���� ����̴�.

pop ���꿡�� left, right child�� ���� ���ο� ���� ���� ó���� �����ؾ� �Ѵ�.
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
	int data[HEAP_SIZE]; // 0�� �ϰ����� ���� ������� �ʴ´�.
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

// Ʈ���� �������� ���� ���� ������� �� ���� ������ ���ϸ鼭 Ʈ���� �����Ѵ�.
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
		if (i * 2 > top) break; // �ڽ� ��尡 ���̻� ���� ��� ����

		int parent = i;
		int left = i * 2;
		int right = (i*2+1 > top) ? left: i * 2 + 1; // ������ �ڽ� ��尡 ������ ���� �ڽ��� target���� �Ѵ�.
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