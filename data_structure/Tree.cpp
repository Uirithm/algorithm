#if 1
/*

Tree의 순회
https://blog.naver.com/kyaryunha/221084287377 (백준)

입력 횟수 n이 입력되고 
각 입력마다 부모노드, 왼쪽자식, 오른쪽자식이 순서대로 주어지며 이로서 트리를 생성한다.
이 후 트리의 전/중/후/레벨 순회를 구현하고 출력하시오.

입력의 예)

7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

전,중,후위 모두 각각 VLR, LVR, LRV로 기억하여 재귀로 짜면 쉽고 오래 기억할 수 있다.

참고
순회는 모든 노드를 방문하는 것이며, 탐색은 특정 원소를 찾는 것이다.
*/
#include<iostream>
using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;
	Node() : data(0), left(nullptr), right(nullptr) {}

	~Node() {
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
		left = right = nullptr;
	}

	bool pushLeft(char data)
	{
		if (left)
			return false;
		
		left = new Node;
		left->data = data;
		return true;
	}

	bool pushRight(char data)
	{
		if (right)
			return false;

		right = new Node;
		right->data = data;
		return true;
	}

	Node* findDFS(char target)
	{
		if (data == target)
			return this;
		else
		{
			Node* ret = nullptr;
			if(left)
				ret = left->findDFS(target);
			if(!ret && right)
				ret = right->findDFS(target);
			return ret;
		}
	}

	bool traversePreOrder();
	bool traverseInOrder();
	bool traversePostOrder(); // DFS
	bool traverseLevelOrder(); // BFS
};

class Queue
{
public:
	int size;
	Node** q;
	int front;
	int rear;
	Queue(int _size) :size(_size) { q = new Node*[size]; }
	~Queue() { delete[] q; }
	void push(Node* n) { q[++front %= size] = n; }
	Node* peek() { return q[(rear + 1) % size]; }
	Node* pop() { return q[++rear %= size]; }
	bool isEmpty() { return front == rear ? true : false; }
	bool isFull() { return ((rear + 1) % size) == front ? true : false; }
};

// 전위 중위 후위 레벨
bool Node::traversePreOrder()
{ // VLR
	cout << data << " ";
	left && left->traversePreOrder();
	right && right->traversePreOrder();
	return true;
}
bool Node::traverseInOrder()
{ // LVR
	left && left->traverseInOrder();
	cout << data << " ";
	right && right->traverseInOrder();
	return true;
}

bool Node::traversePostOrder() // DFS
{ // LRV
	left && left->traversePostOrder();
	right && right->traversePostOrder();
	cout << data << " ";
	return true;
}

bool Node::traverseLevelOrder()
{
	Queue q(1000);
	q.push(this);
	while (!q.isEmpty())
	{
		Node* n = q.pop();
		if (n->left)
			q.push(n->left);
		if (n->right)
			q.push(n->right);
		cout << n->data << " ";
	}
	return true;
}

int main(void)
{
	Node root;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char p = 0;
		char l = 0;
		char r = 0;
		cin >> p >> l >> r;

		if (i == 0)
		{
			root.data = p;
			if(l != '.')
				root.pushLeft(l);
			if(r != '.')
				root.pushRight(r);
			continue;
		}
		
		Node* n = root.findDFS(p);

		if (l != '.')
			n->pushLeft(l) || cout << "abnormal operation";
		if (r != '.')
			n->pushRight(r) || cout << "abnormal operation";
	}
	
	cout << "Traverse pre, in, post, level order\n";
	root.traversePreOrder(); cout << endl;
	root.traverseInOrder(); cout << endl;
	root.traversePostOrder(); cout << endl;
	root.traverseLevelOrder(); cout << endl;

	return 0;
}

#endif