/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "ListInterface.h"
#include "DoublyLinkedListNode.h"
#include "LinkedListException.h"

template <class T>
class DoublyLinkedList : public ListInterface<T>
{
public:
    /**
     * Default Constructor
     */
    DoublyLinkedList();
    /**
     * Variable constructor
     * @param data - the data of the first node in the doubly linked list
     */
    explicit DoublyLinkedList(T data);
    /**
     * Copy constructor
     * @param list - the doubly linked list to copy over
     */
    DoublyLinkedList(const DoublyLinkedList& list);
    /**
     * Destructor
     */
    ~DoublyLinkedList() override;

    // unique methods
    // back operations
    /**
     * Insert node with data in the back of the doubly linked list
     * @param data - data to be inserted
     */
    void insertBack(T data);
    /**
     * Delete back node
     * @return - the data of the deleted node
     */
    T removeBack();
    /**
     * Returns the data in the node at the back
     * @return - the data of the back node
     */
    T peekBack();

    // overridden operations
    // front operations
    /**
     * Insert node with data in the front of the list
     * @param data - data to be inserted
     */
    void insertFront(T data) override;
    /**
     * Delete front node
     * @return - the data of the deleted node
     */
    T removeFront() override;
    /**
     * Returns the data in the node at the front
     * @return - the data of the front node
     */
    T peekFront() override;

    // miscellaneous operations
    /**
     * Removes node at the specified position
     * @param pos - the position of the node to remove
     * @return - the removed node
     */
    T remove(unsigned int pos) override;
    /**
     * Searches for a specific value in the list
     * @param val - the value to search for
     * @return - the position the value is at (-1 if it is not in the list)
     */
    int search(T val) override;
    /**
     * Prints the list
     */
    void printList() override;
    /**
     * Returns the date of the node at the specified position
     * @param pos - the position to check at
     * @return - the data at the specified node
     */
    T peekPos(unsigned int pos) override;
    /**
     * Checks if the list is empty
     * @return - a boolean value that returns true if the list is empty false otherwise
     */
    bool isEmpty() override;
    /**
     * Gets the size of the linked list
     * @return - the size of the linked list
     */
    unsigned int getSize() override;

private:
    unsigned int size;
    DoublyLinkedListNode<T>* front;
    DoublyLinkedListNode<T>* back;
};

// default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
: size(0), front(nullptr), back(nullptr)
{
}

// variable constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T data)
: size(1)
{
    auto* node = new DoublyLinkedListNode<T>(data);
    node->next = nullptr;
    node->prev = nullptr;
    front = node;
    back = node;
}

// copy constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& list)
{
// this implementation is left as an exercise for the reader
}

// destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (!isEmpty())
    {
        removeFront();
    }
}

// unique methods
// inserts node of data in the back of the linked list
template<class T>
void DoublyLinkedList<T>::insertBack(T data)
{
    auto* node = new DoublyLinkedListNode<T>(data);
    if (isEmpty()) // empty list
    {
        front = node;
    }
    else // not an empty list
    {
        back->next = node;
        node->prev = back;
    }
    back = node;
    ++size;
}

// removes the back node
template<class T>
T DoublyLinkedList<T>::removeBack()
{
    DoublyLinkedListNode<T>* oldNode = back;
    if (isEmpty()) // empty list
    {
        throw LinkedListException("Remove operation attempted on empty list");
    }
    if (back->prev == nullptr) // only node in the list
    {
       front = nullptr;
    }
    else // not the only node in the list
    {
        back->prev->next = nullptr;
    }
    back = back->prev;
    oldNode->prev = nullptr;
    T delData = oldNode->data;
    delete oldNode;
    --size;

    return delData;
}

// returns the data of the back node
template<class T>
T DoublyLinkedList<T>::peekBack()
{
    return back->data;
}

// overridden operations
// insert node of data in the front of the linked list
template<class T>
void DoublyLinkedList<T>::insertFront(T data)
{
    auto* node = new DoublyLinkedListNode<T>(data);
    if (isEmpty()) // if the linked list is empty
    {
        back = node;
    }
    else // it's not empty
    {
        front->prev = node;
        node->next = front;
    }
    front = node;
    ++size;
}

// remove front node from the linked list
template<class T>
T DoublyLinkedList<T>::removeFront()
{
    DoublyLinkedListNode<T>* oldNode = front;
    if (isEmpty()) // if the linked list is empty
    {
        throw LinkedListException("Remove operation attempted on empty list");
    }
    if (front->next == nullptr) // only node in the list
    {
        back = nullptr;
    }
    else // more than one node in the list
    {
        front->next->prev = nullptr;
    }
    front = front->next;
    oldNode->next = nullptr;
    T delData = oldNode->data;
    delete oldNode;
    --size;

    return  delData;
}

// returns the data of the front node
template<class T>
T DoublyLinkedList<T>::peekFront()
{
    return front->data;
}

// removes node at specified position
template<class T>
T DoublyLinkedList<T>::remove(unsigned int pos)
{
    if (pos >= size) // remove at position greater than the size of the list
    {
        throw  LinkedListException("Linked List index out of bounds error");
    }
    // position < size
    int currentPos = 0;
    DoublyLinkedListNode<T>* currentNode = front;
    while (currentPos != pos)
    {
        currentNode = currentNode->next;
        ++currentPos;
    }
    // we found it
    // front
    if (currentNode == front)
    {
        front = currentNode->next;
    }
    else
    {
        currentNode->prev->next = currentNode->next;
    }
    // back
    if (currentNode == back)
    {
        back = currentNode->prev;
    }
    else
    {
        currentNode->next->prev = currentNode->prev;
    }
    currentNode->next = nullptr;
    currentNode->prev = nullptr;
    T delData = currentNode->data;
    delete currentNode;
    --size;

    return delData;
}

// searches for the position of some specified value (-1 if not found)
template<class T>
int DoublyLinkedList<T>::search(T val)
{
    int currentPos = 0;
    DoublyLinkedListNode<T>* currentNode = front;
    while (currentNode->data != val)
    {
        currentNode = currentNode->next;
        ++currentPos;
        if (currentNode == nullptr) // value not found
        {
            return -1;
        }
    }
    return currentPos;
}

// prints each node in the list
template<class T>
void DoublyLinkedList<T>::printList()
{
    DoublyLinkedListNode<T>* currentNode = front;
    while (currentNode != nullptr)
    {
        // this part is not necessary, you can just print out the data, but I want to make the printing look nice
        if (currentNode->next == nullptr && currentNode->prev == nullptr) // only node in the list
        {
            std::cout << "||--" << "(" << currentNode->data << ")" << "--||";
        }
        else if (currentNode->next == nullptr) // last node in the list
        {
            std::cout << "(" << currentNode->data << ")" << "--||";
        }
        else if (currentNode->prev == nullptr) // first node in the list
        {
            std::cout << "||--" << "(" << currentNode->data << ")" << "<-->";
        }
        else // some node that isn't first and/or last
        {
            std::cout << "(" << currentNode->data << ")" << "<-->";
        }
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

// returns the data of the node at the specified position
template<class T>
T DoublyLinkedList<T>::peekPos(unsigned int pos)
{
    if (pos >= size) // remove at position greater than the size of the list
    {
        throw  LinkedListException("Linked List index out of bounds error");
    }
    // position < size
    int currentPos = 0;
    DoublyLinkedListNode<T>* currentNode = front;
    while (currentPos != pos)
    {
        currentNode = currentNode->next;
        ++currentPos;
    }

    // we found it
    return currentNode->data;
}

// determines if the list is empty or not
template<class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (size == 0);
}

// gets the size of the linked list
template<class T>
unsigned int DoublyLinkedList<T>::getSize()
{
    return size;
}

#endif // DOUBLYLINKEDLIST_H