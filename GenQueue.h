/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef GENQUEUE_H
#define GENQUEUE_H

#include "DoublyLinkedList.h"
#include "QueueException.h"

template <class T>
class GenQueue
{
public:
    /**
     * Default constructor
     */
    GenQueue();
    /**
     * Variable constructor
     * @param elem
     */
    explicit GenQueue(T elem);
    /**
     * Copy constructor
     * @param queue - the queue to copy over
     */
    GenQueue(const GenQueue& queue);
    /**
     * Destructor
     */
    ~GenQueue();

    /**
     * Enqueues an element in the back of the queue
     * @param elem - the element to enqueue
     */
    void enqueue(T elem);
    /**
     * Dequeues an element from the front of the queue
     * @return - the element dequeued
     */
    T dequeue();
    /**
     * Returns the element at the front of the queue
     * @return - the element at the front of the queue
     */
    T peek();
    /**
     * Returns the element at the specified position
     * @param pos - the specified position
     * @return - the element at that position
     */
    T peekPos(unsigned int pos);
    /**
     * Searches for an element in the queue
     * @param elem - the element to search for
     * @return - the position the element is in the queue (-1 if it's not in the queue)
     */
    int search(T elem);
    /**
     * Prints the elements of the queue
     */
    void printQueue();
    /**
     * Checks whether if the queue is empty
     * @return - a boolean value that is true if the queue is empty, false otherwise
     */
    bool isEmpty();
    /**
     * Gets the size of the queue
     * @return - the size of the queue
     */
    unsigned int getSize();

private:
    unsigned int size;
    DoublyLinkedList<T>* linkedList;
};

// default constructor
template<class T>
GenQueue<T>::GenQueue()
: size(0), linkedList(new DoublyLinkedList<T>())
{
}

// variable constructor
template<class T>
GenQueue<T>::GenQueue(T elem)
: size(1), linkedList(new DoublyLinkedList<T>(elem))
{
}

// copy constructor
template<class T>
GenQueue<T>::GenQueue(const GenQueue& queue)
: size(queue.size), linkedList(new DoublyLinkedList<T>(queue.linkedList))
{
}

// destructor
template<class T>
GenQueue<T>::~GenQueue()
{
    delete linkedList;
}

// enqueues an element at the back of the queue
template<class T>
void GenQueue<T>::enqueue(T elem)
{
    linkedList->insertBack(elem);
    ++size;
}

// dequeues an element from the front of the queue
template<class T>
T GenQueue<T>::dequeue()
{
    if (isEmpty())
    {
        throw QueueException("Dequeue operation attempted on empty queue");
    }
    --size;

    return linkedList->removeFront();
}

// returns the element at the front of the queue
template<class T>
T GenQueue<T>::peek()
{
    return linkedList->peekFront();
}

// returns the element at the specified position
template<class T>
T GenQueue<T>::peekPos(unsigned int pos)
{
    return linkedList->peekPos(pos);
}

// searches for an element in the queue
template<class T>
int GenQueue<T>::search(T elem)
{
    return linkedList->search(elem);
}

// prints the elements of the queue
template<class T>
void GenQueue<T>::printQueue()
{
    linkedList->printList();
}

// checks if the queue is empty
template<class T>
bool GenQueue<T>::isEmpty()
{
    return (size == 0);
}

// gets the size of the queue
template<class T>
unsigned int GenQueue<T>::getSize()
{
    return size;
}

#endif // GENQUEUE_H