/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template <class T>
class ListInterface
{
public:
    /**
     * Destructor
     * NOTE: is trivial
     */
    virtual ~ListInterface();

    // front operations
    /**
     * Insert node with data in the front of the list
     * @param data - data to be inserted
     */
    virtual void insertFront(T data) = 0;
    /**
     * Delete front node
     * @return - the data of the deleted node
     */
    virtual T removeFront() = 0;
    /**
     * Returns the data in the node at the front
     * @return - the data of the front node
     */
    virtual T peekFront() = 0;

    // miscellaneous operations
    /**
     * Removes node at the specified position
     * @param pos - the position of the node to remove
     * @return - the removed node
     */
    virtual T remove(unsigned int pos) = 0;
    /**
     * Searches for a specific value in the list
     * @param val - the value to search for
     * @return - the position the value is at (-1 if it is not in the list)
     */
    virtual int search(T val) = 0;
    /**
     * Prints the list
     */
    virtual void printList() = 0;
    /**
     * Checks if the list is empty
     * @return - a boolean value that returns true if the list is empty false otherwise
     */
    virtual bool isEmpty() = 0;
    /**
     * Gets the size of the linked list
     * @return - the size of the linked list
     */
    virtual unsigned int getSize() = 0;
};

// destructor (is trivial)
template<class T>
ListInterface<T>::~ListInterface()
= default;

#endif // LISTINTERFACE_H