/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#include "Student.h"

//default constructor
Student::Student()
: windowTime(0), waitTime(0)
{
}

// variable constructor
Student::Student(unsigned int windowTime)
: windowTime(windowTime), waitTime(0)
{
}

// copy constructor
Student::Student(const Student& student)
: windowTime(student.windowTime), waitTime(student.waitTime)
{
}

// destructor (is trivial)
Student::~Student()
= default;

// increments the student's wait time
void Student::wait()
{
    ++waitTime;
}

// returns the window time
unsigned int Student::getWindowTime()
{
    return windowTime;
}

// returns the wait time
unsigned int Student::getWaitTime()
{
    return waitTime;
}

// gets the boolean value to determine if the student is waiting
bool Student::isWaiting()
{
    return waiting;
}

// sets the boolean value waiting to the passed in value
void Student::setWaiting(bool waiting)
{
    this->waiting = waiting;
}
