/*
	reTRIEval - linked trie 구현
	
	탐색 삽입 삭제가 문자열의 길이에 비례한다.

	insert : O(length)
	remove : O(length)
	find : O(length)
	REFERENCE: http://jason9319.tistory.com/129
*/

// TODO: 부분문자열에 대한 Longest Common String List 탐색 추가하기

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
	bool terminal; // is terminal node? 단어인 경우 터미널 노드 true
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
			return false; // 없는 문자열을 삭제하려 시도함.

		n->terminal = false; // 이미 할당된 노드들을 삭제할 필요는 없다. (삭제/삽입이 빈번한 경우 성능비용 최소화)
		return true;
	}
	
	Node* find(char* c)
	{
		// word의 끝에 도달한 경우 찾지 못한 것으로 간주.
		if (*c == 0) return nullptr;
		int idx = toInt(*c);
		if (child[idx] == nullptr)
			return nullptr;
		else
		{
			// 현재 노드가 terminal이고 동시에 마지막 문자인 경우 find
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
		if (word - root == MAX_WORD_LENGTH) // 문자열을 삭제한 경우 실제로는 노드가 남아있으므로 발생할 수 있는 case
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
	// 트라이의 루트는 아무 알파벳을 포함하지 않음.
	Node trie;
	while (true)
	{
		int choice = 0;
		char buffer[MAX_WORD_LENGTH] = { 0, }; // 입력 문자열 길이 제한에 대한 예외처리는 하지 않았음
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