#if 1
/*

Tree�� ��ȸ
https://blog.naver.com/kyaryunha/221084287377 (����)

�Է� Ƚ�� n�� �Էµǰ� 
�� �Է¸��� �θ���, �����ڽ�, �������ڽ��� ������� �־����� �̷μ� Ʈ���� �����Ѵ�.
�� �� Ʈ���� ��/��/���� ��ȸ�� �����ϰ� ����Ͻÿ�.

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

// ��ȸ
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