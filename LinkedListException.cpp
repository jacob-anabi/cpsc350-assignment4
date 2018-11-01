/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#include <string>
#include "LinkedListException.h"

// default constructor
LinkedListException::LinkedListException()
: RuntimeException()
{
}

// variable constructor
LinkedListException::LinkedListException(const std::string &message)
: RuntimeException(message)
{
}

// copy constructor
LinkedListException::LinkedListException(const LinkedListException& exception)
: RuntimeException(exception)
{
}

// destructor (is trivial)
LinkedListException::~LinkedListException()
= default;
