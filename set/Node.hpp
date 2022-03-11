#pragma once

template <typename T>
class Node
{
public:
    T value;
    Node<T>* next;

    Node(T value, Node<T>* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};
