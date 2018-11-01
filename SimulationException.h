/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef SIMULATIONEXCEPTION_H
#define SIMULATIONEXCEPTION_H

#include <string>
#include "RuntimeException.h"

class SimulationException : public  RuntimeException
{
public:
    /*
     * Default constructor
     */
    SimulationException();
    /**
     * Variable Constructor
     * @param message - the error message
     */
    explicit SimulationException(const std::string& message);
    /**
     * Copy constructor
     * @param exception - the exception to copy over
     */
    SimulationException(const SimulationException& exception);
    /**
     * Destructor
     * NOTES: is trivial
     */
    ~SimulationException() override;
};


#endif //REGISTRAROFFICESIMULATION_SIMULATIONEXCEPTION_H
