/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#include <string>
#include "QueueException.h"

// default constructor
QueueException::QueueException()
: RuntimeException()
{
}

// variable constructor
QueueException::QueueException(const std::string& message)
: RuntimeException(message)
{
}

// copy constructor
QueueException::QueueException(const QueueException& exception)
: RuntimeException(exception)
{
}

// destructor
QueueException::~QueueException()
= default;
