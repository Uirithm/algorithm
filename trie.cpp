// reTRIEval
// search : O(length)
// insert : O(length)
// remove : O(length)
// REFERENCE: http://jason9319.tistory.com/129

#if 1


#include<iostream>
using namespace std;

#define ALPHABET 24
#define MAX_WORD_LENGTH 10
#define MAX_WORDLIST 100

inline int toInt(char& c) { return c - 'a'; }

// word stack
struct WordList
{
	char* words[MAX_WORDLIST];
	int top = -1;
	void push(char* c)
	{
		top++;
		if (words[top] == nullptr)
			words[top] = new char[MAX_WORD_LENGTH];
		int i = 0;
		while (c[i] != 0)
		{
			words[top][i] = c[i];
			i++;
		}
		words[top][i + 1] = 0;
	}
	bool isFull() { return (top+1) == MAX_WORDLIST; }
};

class Node
{
public:
	bool terminal; // is terminal node?
	Node* child[ALPHABET];
	Node() : terminal(false)
	{ 
		for (int i = 0; i < ALPHABET; i++) 
			child[i] = 0; 
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

		n->terminal = false;
		return true;
	}

	Node* find(char* c)
	{
		// word의 끝인 경우 찾지 못하였음.
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

	// get the node
	Node* getLastNodeOf(char *c)
	{
		if (c == 0) return this;

		int idx = toInt(*c);
		if (child[idx] != nullptr)
		{
			child[idx]->getLastNodeOf(c + 1);
		}
		else return nullptr;
	}

	// find all of terminal nodes by dfs
	void findAll(char* c, int length, WordList* wl)
	{
		for (int i = 0; i < ALPHABET; i++)
		{
			if (child[i] != nullptr)
			{
				char* word = new char[length+2];
				for (int i = 0; i < length; i++)
					word[i] = c[i];
				word[length] = i+'a';
				word[length+1] = 0;
				if (child[i]->terminal)
					wl->push(word);
				child[i]->findAll(word, length, wl);
				delete word;
				word = 0;
			}
		}
	}

	WordList* getWordList(char* c)
	{
		Node* current = getLastNodeOf(c);
		if (current == nullptr) return nullptr;

	}
};


int main(void)
{

	return 0;
}


#endif