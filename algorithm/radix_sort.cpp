#if 1
/*

radix_sort�� �˰��� Ư�� �� ���ڿ��� ������ �����ϴ� ��쿡 ����� �� �ִ�.
���Ŀ� ���� ū ���ɿ䱸�� �ʿ����� �ʴٸ� �������̳� ����/���� ���� ���� �����ϴ� ���� ����ϵ��� ����.
���ĺ��: O(dn), d�� ���� ū ������ �ִ��ڸ���
REFERENCE : https://ko.wikipedia.org/wiki/%EA%B8%B0%EC%88%98_%EC%A0%95%EB%A0%AC

�ڸ��� ��ŭ for loop�� ���鼭 ��ü �����͸� �����Ѵ�.
*/

#include<iostream>
using namespace std;

struct Queue
{
	int *q;
	int front = -1;
	int rear = -1;
	int size = 0;
	Queue() { init(100); }
	~Queue() { destroy(); }

	void init(int _size) { size = _size; q = new int[size]; }
	void destroy() { delete[] q; q = nullptr; }

	void push(int data) { q[++front %= size] = data; }
	int peek() { return q[(rear + 1) % size]; }
	int pop() { return q[++rear %= size]; }
	bool isFull() { return (rear + 1) % size == front ? true : false; }
	bool isEmpty() { return rear == front ? true : false; }
	
};

int main(void)
{
	// �ԷµǴ� ������ �� n
	int n = 0;
	int *buffer = nullptr;
	int top = -1;
	
	cout << "input size : ";
	cin >> n;
	buffer = new int[n];

	int max_value = 0;
	int max_exp = 1;
	for (int i = 0; i < n; i++)
	{
		cout << "input number(" << i+1 << ") : ";
		cin >> buffer[i];
		max_value = max_value < buffer[i] ? buffer[i] : max_value;
	}
	// �Էµ� �ִ밪�� �ڸ��� �ľ�
	while (max_value >= max_exp) max_exp *= 10; 
	
	Queue q[10];
	
	for (int i = 1; i < max_exp; i *= 10) /* �� �ڸ������� ���� */
	{
		for (int j = 0; j < n; j++) /* ��ü ���ҵ��� ť�� �Է� */
		{
			int idx = (buffer[j] / i) % 10;
			q[idx].push(buffer[j]);
		}

		for (int j = 0; j < 10; j++)
		{
			while (!q[j].isEmpty())
			{
				cout << q[j].peek() << " ";
				buffer[++top] = q[j].pop();
			}
		}
		cout << endl;

		top = -1;
	}

	cout << endl << "result" << endl;
	for (int i = 0; i < n; i++)
		cout << buffer[i] << " ";
	cout << endl;
	delete[] buffer;
	buffer = 0;

	return 0;
}

#endif