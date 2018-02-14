/*
	reTRIEval - linked trie ����
	
	Ž�� ���� ������ ���ڿ��� ���̿� ����Ѵ�.

	insert : O(length)
	remove : O(length)
	find : O(length)
	REFERENCE: http://jason9319.tistory.com/129
*/

// TODO: �κй��ڿ��� ���� Longest Common String List Ž�� �߰��ϱ�

#if 0

#include<iostream>
using namespace std;

#define ALPHABET 26
#define MAX_WORD_LENGTH 10
#define MAX_WORDLIST 100

inline int toInt(char& c) { return c - 'a'; }

class Node
{
public:
	bool terminal; // is terminal node? �ܾ��� ��� �͹̳� ��� true
	Node* child[ALPHABET];
	Node() : terminal(false)
	{ 
		for (int i = 0; i < ALPHABET; i++) 
			child[i] = nullptr; 
	}
	~Node() 
	{
		for (int i = 0; i < ALPHABET; i++) if (child[i] != nullptr)
		{
			delete child[i];
			child[i] = nullptr;
		}
	}

	void insert(char* c)
	{
		if (*c == 0)
		{
			terminal = true;
			return;
		}

		int idx = toInt(*c);
		if (child[idx] == nullptr)
			child[idx] = new Node;
		
		child[idx]->insert(c + 1);
	}

	bool remove(char* word)
	{
		Node* n = find(word);
		if (n == nullptr) 
			return false; // ���� ���ڿ��� �����Ϸ� �õ���.

		n->terminal = false; // �̹� �Ҵ�� ������ ������ �ʿ�� ����. (����/������ ����� ��� ���ɺ�� �ּ�ȭ)
		return true;
	}
	
	Node* find(char* c)
	{
		// word�� ���� ������ ��� ã�� ���� ������ ����.
		if (*c == 0) return nullptr;
		int idx = toInt(*c);
		if (child[idx] == nullptr)
			return nullptr;
		else
		{
			// ���� ��尡 terminal�̰� ���ÿ� ������ ������ ��� find
			if (child[idx]->terminal && *(c+1) == 0) 
				return child[idx];
			return child[idx]->find(c + 1);
		}
	}

	// search dfs (ascending dictionary)
	void search()
	{
		char buffer[MAX_WORD_LENGTH] = { 0, };
		_search(buffer - 1, buffer);
	}

	void _search(char* word, char* root)
	{
		if (word - root == MAX_WORD_LENGTH) // ���ڿ��� ������ ��� �����δ� ��尡 ���������Ƿ� �߻��� �� �ִ� case
			return;
			
		if (terminal)
		{
			cout << root << endl;
			return;
		}

		for (int i = 0; i < ALPHABET; i++)
		{
			if (child[i] != nullptr)
			{
				*(word + 1) = i+'a';
				child[i]->_search(word+1, root);
				*(word + 1) = 0;
			}
		}
	}
};

enum Operation { ADD=1, REMOVE, FIND, SEARCH };

int main(void)
{
	// Ʈ������ ��Ʈ�� �ƹ� ���ĺ��� �������� ����.
	Node trie;
	while (true)
	{
		int choice = 0;
		char buffer[MAX_WORD_LENGTH] = { 0, }; // �Է� ���ڿ� ���� ���ѿ� ���� ����ó���� ���� �ʾ���
		printf("1. ADD\n2. REMOVE\n3. FIND\n4.SEARCH\n>> ");
		cin >> choice;
		switch (choice)
		{
		case ADD: // add
			cin >> buffer;
			trie.insert(buffer);
			break;
		case REMOVE: // remove
			cin >> buffer;
			cout << trie.remove(buffer) << endl;
			break;
		case FIND: // find
			cin >> buffer;
			cout << trie.find(buffer) << endl;
			break;
		case SEARCH: // show result
			trie.search();
			break;
		default:
			exit(0);
		}
	}
	return 0;
}

#endif