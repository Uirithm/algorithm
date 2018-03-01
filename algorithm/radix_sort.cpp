#if 1
/*

radix_sort의 알고리즘 특성 상 문자열을 사전순 정렬하는 경우에 응용될 수 있다.
정렬에 대한 큰 성능요구가 필요하지 않다면 퀵정렬이나 선택/버블 정렬 등을 구현하는 것을 고려하도록 하자.
정렬비용: O(dn), d는 가장 큰 숫자의 최대자릿수
REFERENCE : https://ko.wikipedia.org/wiki/%EA%B8%B0%EC%88%98_%EC%A0%95%EB%A0%AC

자릿수 만큼 for loop를 돌면서 전체 데이터를 정렬한다.
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
	// 입력되는 숫자의 수 n
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
	// 입력된 최대값의 자릿수 파악
	while (max_value >= max_exp) max_exp *= 10; 
	
	Queue q[10];
	
	for (int i = 1; i < max_exp; i *= 10) /* 매 자릿수마다 정렬 */
	{
		for (int j = 0; j < n; j++) /* 전체 원소들을 큐에 입력 */
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