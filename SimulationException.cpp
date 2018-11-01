/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */
#include <string>
#include "SimulationException.h"

// default constructor
SimulationException::SimulationException()
: RuntimeException()
{
}

// variable constructor
SimulationException::SimulationException(const std::string& message)
: RuntimeException(message)
{
}

// copy constructor
SimulationException::SimulationException(const SimulationException& exception)
: RuntimeException(exception)
{
}

// destructor
SimulationException::~SimulationException()
= default;
