#if 1
/*

Tree의 순회
https://blog.naver.com/kyaryunha/221084287377 (백준)

입력 횟수 n이 입력되고 
각 입력마다 부모노드, 왼쪽자식, 오른쪽자식이 순서대로 주어지며 이로서 트리를 생성한다.
이 후 트리의 전/후/레벨 순회를 구현하고 출력하시오.

*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
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

	void pushLeft(int data)
	{
		if (left != nullptr)
		{
			left = new Node;
			left->data = data;
		}
	}

	void pushRight(int data)
	{
		if (right != nullptr)
		{
			right = new Node;
			right->data = data;
		}
	}
};

Node* find(int data);

// 순회
void dfs();
void bfs();
void levelOrder();

int main(void)
{
	Node root;
	int n = 0;
	cin >> n;
	

	return 0;
}

#endif