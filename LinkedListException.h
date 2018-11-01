/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef LINKEDLISTEXCEPTION_H
#define LINKEDLISTEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class LinkedListException : public RuntimeException
{
public:
    /*
     * Default constructor
     */
    LinkedListException();
    /**
     * Variable Constructor
     * @param message - the error message
     */
    explicit LinkedListException(const std::string& message);
    /**
     * Copy constructor
     * @param exception - the exception to copy over
     */
    LinkedListException(const LinkedListException& exception);
    /**
     * Destructor
     * NOTES: is trivial
     */
    ~LinkedListException() override;
};

#endif // LINKEDLISTEXCEPTION_H