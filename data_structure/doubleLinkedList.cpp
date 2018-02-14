#if 0
/*
	연결리스트의 설계
	연결리스트는 여러가지 방식으로 구현이 가능하다.
	그러나 코드 길이가 길고 실수하기 쉽기 때문에, 설계를 어느정도 기억해두고 가야 편하다.

	1. head와 tail을 더미 노드로 생성하면 알고리즘을 좀더 간략하게 구현할 수 있다.
	2. 삽입/삭제등의 연산 시 [새로운 노드] [전][후] 노드들의 연결을 빠트리지 않도록 한다.
 
	성능 비용
	앞/뒤 삽입: O(1)
	앞/뒤 삭제: O(1)
	임의의 위치 삽입/삭제: O(n)
	탐색: O(n)
	전탐색: O(n)
*/


#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node() :next(nullptr), prev(nullptr) {}
	Node(int _data) : next(nullptr), prev(nullptr), data(_data) {}
};

class DLinkList
{
public:
	Node* head;
	Node* tail;

	DLinkList();
	~DLinkList();

	void push_front(int data);
	void push_back(int data);
	
	void pop_front();
	void pop_back();

	bool append_at(int data, int idx); 
	bool pop_at(int idx); // delete
	
	int find_front(int data);
	int find_back(int data);

	void dpy();
	void dpyReverse();
};

DLinkList::DLinkList()
{
	head = new Node;
	tail = new Node;
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
}

DLinkList::~DLinkList()
{
	Node* node = head->next;
	while (node != tail)
	{
		Node* deleteNode = node;
		node = node->next;
		delete deleteNode;
	}
	delete head;
	delete tail;
}

void DLinkList::push_front(int data)
{
	Node* newNode = new Node(data);
	newNode->next = head->next;
	newNode->prev = head;

	head->next->prev = newNode;
	head->next = newNode;
}

void DLinkList::push_back(int data)
{
	Node* newNode = new Node(data);
	newNode->next = tail;
	newNode->prev = tail->prev;
	
	tail->prev->next = newNode;
	tail->prev = newNode;
}

void DLinkList::pop_front()
{
	Node* target = head->next;
	target->next->prev = head;
	head->next = target->next;

	delete target;
	target = nullptr;
}

void DLinkList::pop_back()
{
	Node* target = tail->prev;
	target->prev->next = tail;
	tail->prev = target->prev;

	delete target;
	target = nullptr;
}

bool DLinkList::append_at(int data, int idx)
{
	Node* current = head->next;
	if (current == tail) return false;

	for (int i = 0; i < idx; i++)
		if (current->next != nullptr)
			current = current->next;
		else return false;

	Node* newNode = new Node(data);
	newNode->next = current->next;
	newNode->prev = current;

	current->next->prev = newNode;
	current->next = newNode;

	return true;
}

bool DLinkList::pop_at(int idx)
{
	Node* target = head->next;
	if (target == tail) return false;

	for (int i = 0; i < idx; i++)
		target = target->next;

	target->prev->next = target->next;
	target->next->prev = target->prev;
	delete target;
	target = nullptr;
	return true;
}

int DLinkList::find_front(int data)
{
	Node* current = head->next;
	int i = 0;
	while (current != tail)
	{
		if (current->data == data)
			return i;
		current = current->next;
		i++;
	}
	return -1;
}

int DLinkList::find_back(int data)
{
	Node* current = tail->prev;
	int i = 0; 
	while (current != head)
	{
		if (current->data == data)
			return i;
		current = current->prev;
		i++;
	}
	return -1;
}

void DLinkList::dpy()
{
	Node* current = head->next;
	cout << "head - ";
	while (current != tail)
	{
		std::cout << current->data << " - ";
		current = current->next;
	}
	cout << "tail\n";
}
void DLinkList::dpyReverse()
{
	Node* current = tail->prev;
	cout << "tail - ";
	while (current != head)
	{
		std::cout << current->data << " - ";
		current = current->prev;
	}
	cout << "head\n";
}

enum Operation { PUSH_FRONT=1, PUSH_BACK, POP_FRONT, POP_BACK, PUSH_AT, POP_AT, FIND_FRONT, FIND_BACK, DPY, DPY_REVERSE, CLEAR};

int main(void)
{
	DLinkList *list = new DLinkList;
	while (true)
	{
		cout << "\n1. push_front \n2. push_back \n3. pop_front\n4. pop_back\n5. append_at\n6. pop_at\n7. "
			"find_front\n8. find_back\n9. display\n10. display reverse\n11. clear list\n>> ";
		int choice;
		int data;
		int index;
		cin >> choice;
		switch (choice)
		{
		case PUSH_FRONT:
			cout << "data > "; cin >> data;
			list->push_front(data);
			break;
		case PUSH_BACK:
			cout << "data > "; cin >> data;
			list->push_back(data);
			break;
		case POP_FRONT:
			list->pop_front();
			break;
		case POP_BACK:
			list->pop_back();
			break;
		case PUSH_AT:
			cout << "data and idx > "; cin >> data >> index;
			list->append_at(data, index);
			break;
		case POP_AT:
			cout << "idx > "; cin >> index;
			list->pop_at(index);
			break;
		case FIND_FRONT:
			cout << "data > "; cin >> data;
			cout << "index from front " << list->find_front(data) << endl;
			break;
		case FIND_BACK:
			cout << "data > "; cin >> data;
			cout << "index from front " << list->find_back(data) << endl;
			break;
		case DPY:
			list->dpy();
			break;
		case DPY_REVERSE:
			list->dpyReverse();
			break;
		case CLEAR:
			delete list;
			list = new DLinkList;
			break;
		default:
			exit(0);
		}

		if(choice < FIND_FRONT)
			list->dpy();
	}
	return 0;
}

#endif