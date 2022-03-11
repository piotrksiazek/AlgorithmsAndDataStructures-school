using namespace std;
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Node.h"


LinkedList::LinkedList()
{
	this->size = 0;
	this->head = nullptr;
}

LinkedList::~LinkedList()
{
	Node* temp = this->head;
	while (temp != nullptr)
	{
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
}

bool LinkedList::insert(int index, int element)
{
	if(index < 0 || index > this->size)
	{
		return false;
	}
	else
	{
		Node* newNode = new Node(element);
		if(index == 0)
		{
			newNode->next = this->head;
			this->head = newNode;
		}
		else
		{
			Node* temp = this->head;
			for(int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		this->size++;
		return true;
	}
	return true;
}

bool LinkedList::remove(int index)
{
	if(index < 0 || index >= this->size)
	{
		return false;
	}
	else
	{
		if(index == 0)
		{
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
		else
		{
			Node* temp = this->head;
			for(int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			Node* tempToDelete = temp->next;
			temp->next = tempToDelete->next;
			delete tempToDelete;
		}
		this->size--;
		return true;
	}
	return true;
}

int LinkedList::retrieve(int index)
{
	if(index < 0 || index >= this->size)
	{
		cout << "Out of bounds" << endl;
		exit(1);
		return -1;
	}
	else
	{
		Node* temp = this->head;
		for(int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}
}

int LinkedList::locate(int element)
{
	Node *current = this->head;
	for(int i = 0; i < this->size; i++)
	{
		if(current->value == element)
		{
			return i;
		}
		current = current->next;
	}
	cout << "Element " << element << "not found" << endl;
	return -1;
}

int LinkedList::end()
{
	return 1;
}

Node * LinkedList::first()
{
	if(this->head == nullptr)
	{
		return nullptr;
	}
	else
	{
		return this->head;
	}
}

int LinkedList::front()
{
	if(this->head == nullptr)
	{
		cout << "List is empty" << endl;
		return -1;
	}
	else
	{
		cout << "Front element: " << this->head->value << endl;
		return this->head->value;
	}
}

int LinkedList::next(int index)
{
	return 1;
}

int LinkedList::previous(int index)
{
	return 1;
}

Node* LinkedList::last()
{
	if(this->head == nullptr)
	{
		cout<<"List is empty"<<endl;
		return nullptr;
	}
	else
	{
		Node* temp = this->head;
		for(int i = 0; i < this->size - 1; i++)
		{
			temp = temp->next;
		}
		return temp;
	}
}

int LinkedList::back()
{
	if(this->head == nullptr)
	{
		cout << "List is empty" << endl;
		return -1;
	}
	else
	{
		return this->last()->value;
	}
	return 1;
}

bool LinkedList::push_front(int element)
{
	if(this->head == nullptr)
	{
		this->head = new Node(element);
		this->size++;
		return true;
	}
	else
	{
		Node* temp = new Node(element);
		temp->next = this->head;
		this->head = temp;
		this->size++;
		return true;
	}
	return true;
}

bool LinkedList::push_back(int element)
{
	Node * newNode = new Node(element);
	if(this->head == nullptr)
	{
		this->head = newNode;
		this->size++;
		return true;
	}
	else
	{
		Node *current = this->head;
		while(current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
		this->size++;
		return true;
	}
	return false;
}

void LinkedList::pop_front()
{
	if(this->head == nullptr)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
		this->size--;
	}
}

void LinkedList::pop_back()
{
	if(this->head == nullptr)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node* current = this->head;
		while(current->next->next != nullptr)
		{
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
		this->size--;
	}
}

void LinkedList::delete_all_occurencies(int element)
{
	if(this->head == nullptr)
	{
		cout << "List empty" << endl;
	}
	else
	{
		Node* current = this->head;
		while(current->next != nullptr)
		{
			if(current->next->value == element)
			{
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				this->size--;
			}
			else
			{
				current = current->next;
			}
		}

		if(this->head->value == element)
		{
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
			this->size--;
		}
	}
}

void LinkedList::delete_duplicates()
{
	if(this->head == nullptr)
	{
		cout << "List empty" << endl;
	}
	else
	{
		Node* current = this->head;
		while(current->next != nullptr)
		{
			current = current->next;

			Node* current2 = current;
			while(current2->next != nullptr)
			{
				if(current->value == current2->next->value)
				{
					Node* temp = current2->next;
					current2->next = current2->next->next;
					delete temp;
					this->size--;
				}
				else
				{
					current2 = current2->next;
				}
			}
		}
	}
}

void LinkedList::reverse()
{
	if(this->head == nullptr)
	{
		cout << "List empty" << endl;
	}
	else
	{
		Node* current = this->head;
		Node* previous = nullptr;
		Node* next = nullptr;
		while(current != nullptr)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		this->head = previous;
	}
}

void LinkedList::print()
{
	Node *current = this->head;
	int counter = 0;
	while(current != nullptr)
	{
		cout << counter << ": " <<  current->value << endl;
		current = current->next;
		counter++;
	}
}


void LinkedList::deleteEverySecond()
{
	if(this->head == nullptr)
	{
		cout << "List empty" << endl;
	}
	else
	{
		Node* oldHead = this->head;
		this->head = oldHead->next;
		delete oldHead;

		Node* current = this->head;
		while(current->next != nullptr)
		{
			Node *temp = current->next;
			current->next = current->next->next;
			this->size--;
			current = current->next;
			delete temp;
		}
	}
}

bool LinkedList::arrayContains(int* arr, int element)
{
	return true;
}

