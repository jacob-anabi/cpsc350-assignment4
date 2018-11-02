/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#include <iostream>
#include "Simulation.h"
#include "SimulationException.h"
#include "LinkedListException.h"
#include "QueueException.h"

int main(int argc, char** argv)
{
    try
    {
        Simulation* simulation = new Simulation(argv[1]);
        simulation->run();
        delete simulation;
    }
    catch (RuntimeException& err)
    {
        std::cout << err.getErr() << std::endl;
    }
}