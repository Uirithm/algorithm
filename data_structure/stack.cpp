#if 1

#include<iostream>
using namespace std;

// non-secure simple stack
const int SIZE = 20;
struct stack
{
	int top = -1;
	int s[SIZE];
	inline bool isEmpty() { return top == -1 ? true : false; }
	inline bool isFull() { return top == (SIZE-1) ? true : false; } // top은 SIZE-1 index 까지 허용된다.

	void push(int data) { s[++top] = data; }
	int peek() { return s[top]; }
	int pop() { return s[top--]; }
};

int main(void)
{
	stack s;
	// Usage
	for(int i = 0; !s.isFull();i++)
	{
		s.push(i);
	}

	while(!s.isEmpty())
	{
		cout << s.peek() << endl;
		s.pop();
	}
	
	return 0;
}

#endif
