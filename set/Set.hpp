#include "LinkedList.hpp"
#include "Node.hpp"
using namespace std;

template<typename T>
class Set
{
    public:
        Set()
        {
            this->list = new LinkedList<T>();
        }
        
        void insert(T value)
        {
            if(!this->contains(value))
                this->list->add(value);
        }

        void remove(T value)
        {
            this->list->removeElement(value);
        }

        bool contains(T value) const
        {
            return this->list->contains(value);
        }

        int size()
        {
            return this->list->getSize();
        }

        void Union(const Set &other)
        {
            Node<T> *currentNode;

            while((currentNode = other.list->nextNode()) != nullptr)
            {
                this->insert(currentNode->value);
            }
        }

        void intersection(const Set &other)
        {
            Node<T> *currentNode;
            while((currentNode = other.list->nextNode()) != nullptr)
            {
                T value = currentNode->value;
                if(!(this->contains(value) && other.contains(value)))
                {
                    this->remove(value);
                }
            }
        }

        void difference(const Set &other)
        {
            Node<T> *currentNode;
            while((currentNode = other.list->nextNode()) != nullptr)
            {
                T value = currentNode->value;
                if(this->contains(value))
                {
                    this->remove(value);
                }
            }
        }

        void print()
        {
            this->list->print();
        }
    private:
        LinkedList<T> *list;
};