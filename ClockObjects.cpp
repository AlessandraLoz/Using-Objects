#include "Clock.h"
#include <iostream>
#include <iomanip>

using namespace std;

//default constructor
Clock::Clock()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Clock::Clock(int hh, int mm, int ss)
{
	hours = 0;
	minutes = 0;
	seconds = 0;
	setClock(hh, mm, ss);
}

//set time to hh:mm:ss
void Clock::setClock(int hh, int mm, int ss)
{
	if (hh < 0 || mm < 0 || ss < 0)
	{
		cout << "Invalid time!" << endl;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	else
	{
		hours = hh;
		minutes = mm;
		seconds = ss;
		adjustClock();
	}
}

//increase time by sec seconds
void Clock::incrementSeconds(int sec)
{
	seconds = seconds + sec;
	adjustClock();
}

//increase time by min minutes
void Clock::incrementMinutes(int min)
{
	minutes = minutes + min;
	adjustClock();
}

//increase time by hh hours, 
//if hours reach 24, simply wrap around to 0.
void Clock::incrementHours(int hh)
{
	hours = hours + hh;
	adjustClock();
}

//add C into the current clock time
void Clock::addTime(Clock C)
{
	hours = hours + C.hours;
	minutes = minutes + C.minutes;
	seconds = seconds + C.seconds;
	adjustClock();
}

//print time in hours:minutes:seconds in 24-hour format
void Clock::printTime() const
{
	cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << endl;
}

//compare with C, if it is earlier than C, return -1;
// if it is the same time as C, return 0;
// if it is later than C, return 1.
int Clock::compareTime(Clock C) const
{
	if (hours > C.hours)
	{
		return 1;
	}
	else if (hours < C.hours)
	{
		return -1;
	}
	else 
	{
		if (minutes > C.minutes)
		{
			return 1;
		}
		else if (minutes < C.minutes)
		{
			return -1;
		}
		else
		{
			if (seconds > C.seconds)
			{
				return 1;
			}
			else if (seconds < C.seconds)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}

//Helper function to validate the data members
//it only serves the member functions of this class, hence private
void Clock::adjustClock()
{
	int adjust = 0;
	if (seconds >= HOUR_MIN_SEC)
	{
		adjust = seconds / HOUR_MIN_SEC;
		seconds = seconds % HOUR_MIN_SEC;
		minutes = minutes + adjust;
	}
	if (minutes >= HOUR_MIN_SEC)
	{
		adjust = minutes / HOUR_MIN_SEC;
		minutes = minutes % HOUR_MIN_SEC;
		hours = hours + adjust;
	}
	if (hours >= 24)
	{
		hours = hours % HOURS_TO_WRAP ;
	}
}

int main()
{
	//write each statement for each operation below in ()
	Clock C1;
	C1.setClock(3, -5, 16);		//(set C1 with h : m:s = 3 : -5 : 16)
	C1.setClock(0, 0, 5);	//(set C1 with h : m:s = 0 : 0 : 5)
	Clock C2(12,35,59); //(create second Clock object C2 with h : m:s = 12 : 35 : 59)
	cout << "Clock 1 -- ";
	C1.printTime();		//(print C1)
	cout << "Clock 2 -- ";
	C2.printTime();		//(print C2)
	C1.compareTime(C2);		//compare C1 with C2
	
	if (C1.compareTime(C2) < 0)
	{
		cout << "C1 is earlier than C2" << endl;
	}
	else if (C1.compareTime(C2) > 0)
	{
		cout << "C1 is later than C2" << endl;
	}
	else
	{
		cout << "C1 is the same as C2" << endl;
	}

	C1.addTime(C2);		//(add C2 into C1)
	cout << "Clock 1 -- ";
	C1.printTime();		//(print C1)
	cout << "Clock 2 -- ";
	C2.printTime();		//(print C2)
	C1.compareTime(C2);	//(compare C1 with C2)

	if (C1.compareTime(C2) < 0)
	{
		cout << "C1 is earlier than C2" << endl;
	}
	else if (C1.compareTime(C2) > 0)
	{
		cout << "C1 is later than C2" << endl;
	}
	else
	{
		cout << "C1 is the same as C2" << endl;
	}

	C1.incrementSeconds(55);	//(increase clock C1 by 55 seconds)
	cout << "Clock 1 -- ";
	C1.printTime();		//(print C1)
	C1.incrementMinutes(119);	//(increase clock C1 by 119 minutes)
	cout << "Clock 1 -- ";
	C1.printTime();		//(print C1)
	C1.incrementHours(22);//(increase clock C1 by 22 hours)
	cout << "Clock 1 -- ";
	C1.printTime();	//(print C1)
	cout << "Clock 2 -- ";
	C2.printTime();	//(print C2)
	C2.compareTime(C1);	//compare C2 with C1
	
	if (C2.compareTime(C1) < 0)
	{
			cout << "C2 is earlier than C1" << endl;
	}
	else if (C2.compareTime(C1) > 0)
	{
		cout << "C2 is later than C1" << endl;
	}
	else
	{
		cout << "C2 is the same as C1" << endl;
	}
	return 0;
}
