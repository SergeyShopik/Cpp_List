#include"List.h"
void initList(List& list)
{
	list.head = nullptr;
	list.tail = nullptr;
	list.size = 0;
}
void pushBack(List& list, int backKey)
{
	Node* temp = new Node;
	temp->data = backKey; //put backKey into empty node
	temp->next = nullptr;

	if (list.size != 0)
	{
		list.tail->next = temp;// reassign pointer to a new element
		list.tail = list.tail->next;// assign new element to the tail
	}
	else
	{
		list.head = temp;
		list.tail = list.head;
	}
	list.size++;

}
void pushFront(List& list, int frontKey)
{
	Node* temp = new Node; 
	temp->data = frontKey; 
	temp->next = list.head; // new element points to the head
	list.head = temp;// reassing head to a new element
	if (list.size == 0)
	{
		list.tail = list.head;
	}
	list.size++;
}
void pushPosition(List& list, int positionKey, size_t position)
{
	if (position <= list.size)
	{
		if (position == 0)
		{
			pushFront(list, positionKey);
			return;
		}

		Node* temp = new Node;
		temp->data = positionKey;

		Node* i = list.head;
		for (int count = 0; count < position - 1; count++)
		{
			i = i->next;
		}
		temp->next = i->next;// reassign temp pointer to the next element
		i->next = temp;// assign pointer i (previous element) to temp
		list.size++;
	}
	else
	{
		std::cout << "Cannot insert element.\n";
		return;
	}
}
int popFront(List& list)
{
	int key = -1;
	if (list.size > 1)
	{
		key = list.head->data;
		Node* temp = list.head->next;
		delete list.head;
		list.head = temp;
		list.size--;
	}
	else if (list.size == 1)
	{
		key = list.head->data;
		delete list.head;
		list.head = list.tail = nullptr;
		list.size--;
	}
	else
	{
		std::cout << "List is empty\n";
	}
	return key;
}
int popBack(List& list)
{
	int key = 0;
	if (list.size == 1)
	{
		key = list.head->data;
		delete list.head;
		list.head = list.tail = nullptr;
		list.size--;
	}
	else if (list.size > 1)
	{
		key = list.tail->data;
		Node* temp;
		for (temp = list.head; temp->next != list.tail; temp = temp->next);
		list.tail = temp;
		delete list.tail->next;
		list.tail->next = nullptr;
		list.size--;
	}
	else
	{
		std::cout << "List is empty\n";
	}
	return key;
}

void removeKey(List& list, int key)
{
	Node* prev = nullptr;
	for (Node* i = list.head; i != nullptr; prev = i, i = i->next)
	{
		if (i->data == key)
		{
			if (prev != nullptr)
			{
				prev->next = i->next; // previous element pointer points to the element next after the key
				delete i;
				list.size--;
			}
			else popFront(list);
			return;
		}
	}
	std::cout << "Element is not found.\n";
}
int removePosition(List& list, int pos)
{
	if (pos > list.size)
	{
		std::cout << "Cannot remove.\n";
		return -1;
	}
	Node* prev = nullptr;
	Node* i = list.head;
	int result, count = 0;
	for (i; count < pos - 1; prev = i, i = i->next, count++);

	if (prev)
	{
		result = i->data;
		prev->next = i->next;
		delete i;
		list.size--;
		return result;
	}
	else
	{
		result = popFront(list);
		return result;
	}
}

void printList(const List& list)
{
	for (Node* i = list.head; i != nullptr; i = i->next/*go to the next element*/)
	{
		std::cout << i->data << ' ';
	}
	std::cout << std::endl;
}

void addSort(List& list, int key)
{
	Node* temp = new Node;
	temp->data = key;

	if (list.size == 0)
	{
		list.head = temp;
		list.tail = temp;
		list.size++;
		return;
	}
	if (list.tail->data <= key)
	{
		pushBack(list, key);
		return;
	}
	if (list.head->data >= key)
	{
		pushFront(list, key);
		return;
	}

	temp->next = nullptr;
	Node* i = list.head;
	Node* prev = nullptr;
	for (i; i->data <= key; prev = i, i = i->next);
	temp->next = i;
	prev->next = temp;
	list.size++;
}

