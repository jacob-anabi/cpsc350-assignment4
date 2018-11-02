/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#include <iostream>
#include "Student.h"

//default constructor
Student::Student()
: windowTime(0), waitTime(0), arrivalTime(0)
{
}

// variable constructor
Student::Student(int windowTime, int arrivalTime)
: windowTime(windowTime), waitTime(0), arrivalTime(arrivalTime)
{
}

// copy constructor
Student::Student(const Student& student)
: windowTime(student.windowTime), waitTime(student.waitTime), arrivalTime(student.arrivalTime)
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
int Student::getWindowTime()
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

// gets the student's arrival time
int Student::getArrivalTime()
{
    return arrivalTime;
}

// = operator
Student& Student::operator=(const Student& student) // https://en.cppreference.com/w/cpp/language/operators
{
    if (this != &student) // not the same students
    {
        this->windowTime = student.windowTime;
        this->waitTime = student.waitTime;
        this->waiting = student.waiting;
        this->arrivalTime = student.arrivalTime;
    }
    return *this;
}

// != operator
bool Student::operator!=(const Student& student)
{
    return (this->arrivalTime != student.arrivalTime);
}

// << operator
std::ostream& operator<<(std::ostream& os, const Student& student) // https://stackoverflow.com/a/22588202
{
    os << "Student Arrival Time, Wait Time, and Window Time: " << std::to_string(student.arrivalTime)  <<
    " " << std::to_string(student.waiting) << " " << std::to_string(student.windowTime) << std::endl;

    return os;
}