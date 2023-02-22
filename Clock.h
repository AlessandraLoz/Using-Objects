/* File: Clock.h
 * Course: CS215-00x
 * Project: Lab 8
 * Purpose: Provide the delcaration of the class named Clock
 *			Note that it represents a 24-hour clock (or you can call it military time)
 * Author: Alessandra Lozano
 */
#ifndef CLOCK_H
#define CLOCK_H

 // define constants
const int HOUR_MIN_SEC = 60;
const int HOURS_TO_WRAP = 24;

class Clock {
public:
    //default constructor
    Clock();

    //alternative constructor
    Clock(int hh, int mm, int ss);

    //set time to hh:mm:ss
    void setClock(int hh, int mm, int ss);

    //increase time by sec seconds
    void incrementSeconds(int sec);

    //increase time by min minutes
    void incrementMinutes(int min);

    //increase time by hh hours, 
    //if hours reach 24, simply wrap around to 0.
    void incrementHours(int hh);

    //add C into the current clock time
    void addTime(Clock C);

    //print time in hours:minutes:seconds in 24-hour format
    void printTime() const;

    //compare with C, if it is earlier than C, return -1;
    // if it is the same time as C, return 0;
    // if it is later than C, return 1.
    int compareTime(Clock C) const;

private:
    //Declare data members of the class
    // 0 <= hours < 24, 0 <= minutes < 60, 0 <= seconds < 60
    int hours, minutes, seconds;

    //Helper function to validate the data members
    //it only serves the member functions of this class, hence private
    void adjustClock();
};

#endif		/* CLOCK_H*/
