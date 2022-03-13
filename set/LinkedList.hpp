#pragma once
#include "Node.hpp"

using namespace std;

template <typename T>
class LinkedList
{
    private:
        Node<T>* head;
        int size;
        Node<T>* currentIterand;
    public:
        LinkedList()
        {
            this->size = 0;
            this->head = nullptr;
        }
        ~LinkedList()
        {
            Node<T>* temp = this->head;
            while (temp != nullptr)
            {
                Node<T>* next = temp->next;
                delete temp;
                temp = next;
            }
        }

        Node<T>* nextNode()
        {
            if(this->currentIterand == nullptr)
            {
                this->currentIterand = this->head;
                return this->head;
            }
            if(currentIterand->next != nullptr)
            {
                currentIterand = currentIterand->next;
                return currentIterand;
            }
            return nullptr;
        }

        bool add(T element)
        {
            Node<T>* newNode = new Node<T>(element);
            if(this->head == nullptr)
            {
                this->head = newNode;
                this->size++;
                return true;
            }
            else
            {
                Node<T>* temp = this->head;
                Node<T> *prev = nullptr;
                if(temp->value >= element)
                {
                    newNode->next = temp;
                    this->head = newNode;
                    this->size++;
                    return true;
                }
                while(temp->value < element)
                {
                    if(temp->next == nullptr)
                    {
                        temp->next = newNode;
                        this->size++;
                        return true;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = newNode;
                newNode->next = temp;
                this->size++;
            }
            return false;
        }

        int getSize()
        {
            return this->size;
        }

        bool remove(int index)
        {
            if(index < 0 || index >= this->size)
            {
                return false;
            }
            else
            {
                if(index == 0)
                {
                    Node<T>* temp = this->head;
                    this->head = this->head->next;
                    delete temp;
                }
                else
                {
                    Node<T>* temp = this->head;
                    for(int i = 0; i < index - 1; i++)
                    {
                        temp = temp->next;
                    }
                    Node<T>* tempToDelete = temp->next;
                    temp->next = tempToDelete->next;
                    delete tempToDelete;
                }
                this->size--;
                return true;
            }
            return true;
        }

        int locate(T element)
        {
            Node<T> *current = this->head;
            for(int i = 0; i < this->size; i++)
            {
                if(current->value == element)
                {
                    // cout << "Element " << element << " found at: "<< i << endl;
                    return i;
                }
                current = current->next;
            }
            // cout << "Element " << element << "not found" << endl;
            return -1;
        }

        bool removeElement(T element)
        {
            return this->remove(this->locate(element));
        }

        T retrieve(int index)
        {
            if(index < 0 || index >= this->size)
            {
                cout << "Out of bounds" << endl;
                exit(1);
                return -1;
            }
            else
            {
                Node<T>* temp = this->head;
                for(int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }
                return temp->value;
            }
        }

        bool contains(T element)
        {
            return this->locate(element) != -1;
        }

        bool push_front(T element)
        {
            if(this->head == nullptr)
            {
                this->head = new Node<T>(element);
                this->size++;
                return true;
            }
            else
            {
                Node<T>* temp = new Node<T>(element);
                temp->next = this->head;
                this->head = temp;
                this->size++;
                return true;
            }
            return true;
        }

        bool operator==(LinkedList& l2)
        {
            if(getSize() != l2.getSize())
            {
                return false;
            }
            else
            {
                Node<T>* temp1;
                Node<T>* temp2;
                temp1 = nextNode();
                temp2 = l2.nextNode();
                while(temp1 != nullptr && temp2 != nullptr)
                {
                    if(temp1->value != temp2->value)
                    {
                        return false;
                    }
                    temp1 = nextNode();
                    temp2 = l2.nextNode();
                }
                return true;
            }
        }

        void print()
        {
            Node<T> *current = this->head;
            int counter = 0;
            while(current != nullptr)
            {
                cout <<  current->value << "--->";
                current = current->next;
                counter++;
            }
            cout<<"nullptr";
            cout << endl;
        }
};