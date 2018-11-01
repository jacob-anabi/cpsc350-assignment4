/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef DOUBLYLINKEDLISTNODE_H
#define DOUBLYLINKEDLISTNODE_H

template <class T>
class DoublyLinkedListNode
{
public:
    /**
     * Default constructor
     */
    DoublyLinkedListNode();
    /**
     * Variable constructor
     * @param data - the node's data
     */
    explicit DoublyLinkedListNode(T data);
    /**
     * Copy constructor
     * @param node - the node to copy over
     */
    DoublyLinkedListNode(const DoublyLinkedListNode& node);
    /**
     * Destructor
     */
    ~DoublyLinkedListNode();

    // Attributes
    DoublyLinkedListNode<T>* next; // next pointer
    DoublyLinkedListNode<T>* prev; // prev pointer
    T data; // node's data
};

// default constructor
template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode()
: data(nullptr), next(nullptr), prev(nullptr)
{
}

// variable constructor
template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(T data)
: data(data), next(nullptr), prev(nullptr)
{
}

// copy constructor
template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(const DoublyLinkedListNode& node)
: data(node.data), next(node.next), prev(node.prev)
{
}

// destructor
template<class T>
DoublyLinkedListNode<T>::~DoublyLinkedListNode()
{
    next = nullptr;
    prev = nullptr;
}

#endif // DOUBLYLINKEDLISTNODE_H