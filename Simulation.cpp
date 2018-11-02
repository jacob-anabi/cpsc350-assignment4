/**
 * @author Jacob Anabi
 * @date 2018-10-30
 * @version 1.0
 * 2294644
 * CPSC 350
 * Assignment 4 - Registrar Office Simulation
 */

#include <string>
#include <fstream>
#include <algorithm>
#include "Simulation.h"
#include "Student.h"
#include "SimulationException.h"

// variable constructor
Simulation::Simulation(const std::string& registrarFileName)
{
    registrarFile.open(registrarFileName);
}

// destructor
Simulation::~Simulation()
{
    delete studentLine;
    delete students;
    delete[] availableWindows;
    registrarFile.close();
}

// runs the simulation
void Simulation::run()
{
    if (!registrarFile || !check()) // if the registrar file is not usable
    {
        throw SimulationException("Registrar file contains invalid input");
    }
    else // if we can use the registrar, let's begin the simulation
    {

        bool keepGoing = true;
        unsigned timeTick = 0;
        int studentsDequeue = 0;
        int windowsAvailable = 0;

        availableWindows = new bool[numWindows];
        int* idleTimes = new int[numWindows];
        int* windowUseTime = new int[numWindows];
        int* windowTimeUsed = new int[numWindows];
        for (int i = 0; i < numWindows; ++i)
        {
            idleTimes[i] = 0;
            windowUseTime[i] = 0;
            windowTimeUsed[i] = 0;
        }

        int* waitTimes = new int[numStudents];
        students = new DoublyLinkedList<Student*>();
        studentLine = new GenQueue<Student*>();
        initialize();

        try
        {
            while (keepGoing)
            {
                // students arriving
                for (unsigned int i = 0; i < numStudents; ++i)
                {
                    if (students->peekPos(i)->getArrivalTime() == timeTick) // when a student arrive
                    {
                        studentLine->enqueue(students->peekPos(i)); // add them to the queue
                    }
                }
                // moving students to windows
                for (int i = 0; i < numWindows; ++i)
                {
                    if (availableWindows[i] && !studentLine->isEmpty()) // if there is an available window and there is still at least one student in line
                    {
                        windowUseTime[i] += studentLine->peek()->getWindowTime(); // setting the time the window will be used for
                        studentLine->dequeue(); // dequeue student from line
                        ++studentsDequeue; // increments the amount of students that dequeue
                        availableWindows[i] = false; // that window is no longer available
                    }
                }
                // increment wait times for students
                for (unsigned int i = 0; i < studentLine->getSize(); ++i)
                {
                    studentLine->peekPos(i)->wait(); // students in queue wait
                }
                // increment idle times for windows
                for (int i = 0; i < numWindows; ++i)
                {
                    if (availableWindows[i])
                    {
                        ++idleTimes[i];
                    }
                    else
                    {
                        ++windowTimeUsed[i];
                    }
                    if (windowTimeUsed[i] == windowUseTime[i])
                    {
                        availableWindows[i] = true;
                    }
                }
                // check if the simulation is finished
                if (studentsDequeue == numStudents)
                {
                    for (int i = 0; i < numWindows; ++i)
                    {
                        if (availableWindows[i])
                        {
                            ++windowsAvailable;
                        }
                    }
                    if (windowsAvailable == numWindows)
                    {
                        keepGoing = false;
                    }
                }
                windowsAvailable = 0;
                ++timeTick;
            }
        }
        catch (RuntimeException& err)
        {
            throw SimulationException("Registrar file contains invalid input");
        }

        for (unsigned int i = 0; i < numStudents; ++i)
        {
            waitTimes[i] = students->peekPos(i)->getWaitTime(); // added wait times to array
        }

        double meanWait = 0.0;
        int longestWait = 0;
        double medianWait = 0;
        int over10Wait = 0;
        double meanIdle = 0.0;
        int longestIdle = 0;
        int over5Idle = 0;

        std::sort(waitTimes, waitTimes + numStudents); // sorting wait times
        for (int i = 0; i < numStudents; ++i)
        {
            if (waitTimes[i] > longestWait)
            {
                longestWait = waitTimes[i];
            }
            if (waitTimes[i] > 10)
            {
                ++over10Wait;
            }
            meanWait += waitTimes[i];
        }

        if ((numStudents % 2) != 0) // odd number of students
        {
            medianWait = waitTimes[(numStudents)/2];
        }
        else // even number of students
        {
            medianWait = (static_cast<double>(waitTimes[(numStudents)/2] + waitTimes[(numStudents)/2-1])/2);
        }
        meanWait /= numStudents;

        for (int i = 0; i < numWindows; ++i)
        {
            if (idleTimes[i] > longestIdle)
            {
                longestIdle = idleTimes[i];
            }
            if (idleTimes[i] > 5)
            {
                ++over5Idle;
            }
            meanIdle += idleTimes[i];
        }

        std::cout << "Student Wait Times:\n"
        << "Mean wait, Median wait, Longest wait, Waits over 10 minutes, respectively: "
        << meanWait << ", " << medianWait << ", " << longestWait << ", " << over10Wait << "\n"
        << "Window Idle Times:\n"
        << "Mean Idle, Longest Idle, Idles Over 5 minutes, respectively: "
        << meanIdle << ", " << longestIdle << ", " << over5Idle << std::endl;

        delete[] idleTimes;
        delete[] windowUseTime;
        delete[] windowTimeUsed;
    }
}

// checks the registrar file to make sure it's in the right format
bool Simulation::check()
{
    std::string line; // file line
    unsigned int fileLineNum = 0; // file line number
    unsigned int numStudents = 0; // number of students total
    unsigned int numStudentGroup = 0; // number of groups of students
    int individualNumStudents = 0; // number of students in each group
    int individualNumStudentsGroup = 0; // number of students in each group
    bool inTimeCheck = true; // if we are checking arrival time
    bool inGroupCheck = false; // if we are checking groups

    while (getline(registrarFile, line))
    {
        if (line[0] == '\n') // ignore blank lines
        {
            continue;
        }
        else if (!isUnsignedNumeric(line)) // the file is bad if it contains anything other than a number
        {
            if (line.empty())
            {
                continue;
            }
            return false;
        }
        if (fileLineNum == 0)
        {
            numWindows = std::stoi(line);
        }
        else if (fileLineNum > 0) // information below the window numbers
        {
            if (inTimeCheck) // in arrival time check
            {
                inTimeCheck = false; // switch boolean value (number of students comes after arrival time)
            }
            else if (inGroupCheck) // in group check
            {
                ++individualNumStudentsGroup; // increment number of students in each group
                if (individualNumStudentsGroup == individualNumStudents) // if number of students specified corresponds to proper number of students in group
                {
                    individualNumStudentsGroup = 0; // reset students in group
                    ++numStudentGroup; // increment number of student groups
                    inGroupCheck = false; // switch boolean value
                    inTimeCheck = true; // switch boolean value (arrival time comes after group)
                }
            }
            else // checking number of students
            {
                numStudents += std::stoi(line); // add number of students
                individualNumStudents = std::stoi(line); // set number of students
                inGroupCheck = true; // switch boolean value (group comes after number of students)
            }
        }
        ++fileLineNum;
    }
    this->numStudents = numStudents;
    return ((numStudents + numStudentGroup * 2 + 1) == fileLineNum);
}

// checks if a string is numeric
bool Simulation::isUnsignedNumeric(const std::string& string)
{
    return (!string.empty() && string.find_first_not_of("0123456789") == std::string::npos); // https://stackoverflow.com/a/23661936
}

// initialize all of our variables
void Simulation::initialize()
{
    std::string line;
    unsigned int fileLineNum = 0; // file line number
    unsigned int numStudentGroup = 0; // number of groups of students
    int arrivalTime = 0; // each student's arrival time
    int individualNumStudents = 0; // number of students in each group
    int individualNumStudentsGroup = 0; // number of students in each group
    bool inTimeCheck = true; // if we are checking arrival time
    bool inGroupCheck = false; // if we are checking groups
    registrarFile.clear();
    registrarFile.seekg(0, std::ios::beg); // resetting file to beginning after checking it

    for (int i = 0; i < numWindows; ++i) // creating our windows
    {
        availableWindows[i] = true;
    }

    while (getline(registrarFile, line))
    {
        if (fileLineNum > 0) // information below the window numbers
        {
            if (inTimeCheck) // in arrival time check
            {
                arrivalTime = std::stoi(line);
                inTimeCheck = false; // switch boolean value (number of students comes after arrival time)
            }
            else if (inGroupCheck) // in group check
            {
                ++individualNumStudentsGroup; // increment number of students in each group
                students->insertBack(new Student(std::stoi(line), arrivalTime));
                if (individualNumStudentsGroup == individualNumStudents) // if number of students specified corresponds to proper number of students in group
                {
                    arrivalTime = 0;
                    individualNumStudentsGroup = 0; // reset students in group
                    ++numStudentGroup; // increment number of student groups
                    inGroupCheck = false; // switch boolean value
                    inTimeCheck = true; // switch boolean value (arrival time comes after group)
                }
            }
            else // checking number of students
            {
                individualNumStudents = std::stoi(line); // set number of students
                inGroupCheck = true; // switch boolean value (group comes after number of students)
            }
        }
        ++fileLineNum;
    }
}