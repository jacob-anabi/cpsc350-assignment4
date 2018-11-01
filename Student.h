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
    Student(unsigned int windowTime);
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
    unsigned int getWindowTime();
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

private:
    unsigned int windowTime;
    unsigned int waitTime;
    bool waiting;
};

#endif // STUDENT_H