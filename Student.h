/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <iostream>

class Student
{
public:
    /**
     * Default constructor
     */
    Student();
    /**
     * Variable constructor
     * @param windowTime - the time the student needs at the window
     */
    Student(int windowTime, int arrivalTime);
    /**
     * Copy constructor
     * @param student - the student to copy over
     */
    Student(const Student& student);
    /**
     * Destructor
     * NOTE: is trivial
     */
    ~Student();

    /**
     * Increments the wait time by 1
     */
    void wait();
    /**
     * Gets the window time the student needs
     * @return - the window time
     */
    int getWindowTime();
    /**
     * Gets the wait time of the student
     * @return - the wait time
     */
    unsigned int getWaitTime();
    /**
     * Gets the boolean value to determine if the student is waiting
     * @return - the boolean value waiting
     */
    bool isWaiting();
    /**
     * Sets the boolean value waiting to the passed in value
     * @param waiting - the passed in boolean value
     */
    void setWaiting(bool waiting);
    /**
     * Gets the student's arrival time
     * @return - the student's arrival time
     */
    int getArrivalTime();

    // Operator overloading
    /**
     * Overloads the = operator
     * @param student - the student to set this student equal to
     * @return - our student with the copied over values
     */
    Student& operator=(const Student& student);
    /**
     * Overloads the != operator
     * @param student - the student to check != for
     * @return - a boolean value that is true if they don't equal each other, false other wise
     */
    bool operator!=(const Student& student);
    /**
     * Overloads the << operator
     * @param os - the ostream object
     * @param student - the student for the ostream
     * @return - the ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
    int windowTime;
    unsigned int waitTime;
    bool waiting;
    int arrivalTime;
};

#endif // STUDENT_H