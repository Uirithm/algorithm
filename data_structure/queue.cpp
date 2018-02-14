#if 0
#include<iostream>
using namespace std;

const int Q_SIZE = 10+1;
struct Queue
{
	int queue[Q_SIZE];
	int front = 0;
	int rear = 0;

	void push(int data) { queue[(++front %= Q_SIZE)] = data; }
	int pop() { return queue[++rear %= Q_SIZE]; }
	int peek() { return queue[(rear + 1) % Q_SIZE]; }
	bool isFull() { return (front + 1) % Q_SIZE == rear ? true : false; }
	bool isEmpty() { return front == rear ? true : false; }

	void show() {
		int _rear = rear;
		printf("queue > (rear:%d) ", rear);
		while (_rear != front)
		{
			++_rear %= Q_SIZE;
			printf("%d, ", queue[_rear]);
		}
		printf("(front:%d)\n", front);
	}
};

int main(void)
{
	Queue q;
	for (int i = 0; i < Q_SIZE; i++)
	{
		if (!q.isFull())
		{
			q.push(i);
			printf("pushed %d\n", i);
		}
		else
			printf("queue is full data(%d)\n", i);
	}
	q.show();

	for (int i = 0; i < Q_SIZE/2; i++)
	{
		if (!q.isEmpty()) 
		{
			printf("popping %d\n", q.peek());
			q.pop();
		}
		else
			printf("queue is empty tried(%d)\n", i);
	}
	q.show();

	for (int i = 0; i < Q_SIZE; i++)
	{
		printf("try push %d\n", i);
		if (!q.isFull())
			q.push(i);
		else
			printf("queue is full data(%d)\n", i);
	}
	q.show();
	
	return 0;
}

#endif