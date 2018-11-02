/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include <fstream>
#include "GenQueue.h"
#include "DoublyLinkedList.h"
#include "Student.h"
#include "SimulationException.h"
#include "QueueException.h"
#include "LinkedListException.h"

class Simulation
{
public:
    /**
     * Variable Constructor
     */
    explicit Simulation(const std::string& registrarFileName);
    /**
     * Destructor
     */
    ~Simulation();
    /**
     * Runs the simulation
     */
    void run();
private:
    std::ifstream registrarFile;
    int numWindows;
    int numStudents;
    GenQueue<Student*>* studentLine;
    DoublyLinkedList<Student*>* students;
    bool* availableWindows;

    /**
     * Checks the registrar file to make sure it's in the right format
     * @return - a boolean value that returns true if the file is ok to use, false otherwise
     */
    bool check();
    /**
     * Checks if a string is numeric
     * @param string - the string to check
     * @return - a boolean value that is true if the string is numeric, false otherwise
     */
    bool isUnsignedNumeric(const std::string& string);
    /**
     * Initialize all of the variables for use in our queue
     */
    void initialize();
};


#endif // SIMULATION_H
