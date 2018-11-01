/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef GENQUEUEEXCEPTION_H
#define GENQUEUEEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class QueueException : public RuntimeException
{
public:
    /*
     * Default constructor
     */
    QueueException();
    /**
     * Variable Constructor
     * @param message - the error message
     */
    explicit QueueException(const std::string& message);
    /**
     * Copy constructor
     * @param exception - the exception to copy over
     */
    QueueException(const QueueException& exception);
    /**
     * Destructor
     * NOTES: is trivial
     */
    ~QueueException() override;
};

#endif // GENQUEUEEXCEPTION_H