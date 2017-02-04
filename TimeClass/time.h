/***
*time.h - A class and struct for use with time and dates
*
* struct mtime contains various elements of time and date you can use
* Reset() will refresh the values in the mtime struct
* Time and Date will be returned as a string using their repective functions
*
*		copyright 3/25/2002 by Matthew Guidry
***/

#ifndef _MATTS_TIME_DATE_CLASS__
#define _MATTS_TIME_DATE_CLASS__

#include <time.h>
#include "string.h"
#include <sys\types.h>
#include <sys\timeb.h>

struct m_time {
	String day_week;//the day of the week
	String month;	//the month of the year
	int day_month;	//day of the month
	int year;		//the year
	int hour24;		//current hour in 24 hour time format
	int hour12;		//current hour in 12 hour time
	bool pm;		//in 12 hour time, if it is pm
	String ampm;	//the string representing am or pm
	int min;		//minutes after hour
	int sec;		//seconds after minute
};
//----------------------------------------------
class tdclass{
public:
	tdclass();

	void reset();

	String time12(bool);

	String time24(bool);

	String date();

	void SWStart(); //stop watch start timer, just call this again to reset

	double SWReading(); //gives a reading of the seconds since stopwatch last started

	struct _timeb sw;

	m_time mtime;
	
private:
	String IntToString(int);
};
//----------------------------------------------
tdclass::tdclass()
/*	Creates a tdclass object and resets it with current values from the system clock
	Post: Object created and reset														*/
{
	reset();
}
//----------------------------------------------
void tdclass::reset()
/*	Resets the mtime struct to contain up-to-date info according to the system clock
	Post: All time and date values refreshed from system clock							*/
{
	time_t mytime; //time_t is a typedef for long (in other words, time_t=long)
	tm *t; //tm is a struct declared in time.h which is similar to my m_time
	
	time(&mytime); //this make the value of mytime equal to the num of seconds after Jan 1 1970 
	t=localtime(&mytime); //this converts mytime to the already described struct

	//day_week, day of week
	switch(t->tm_wday){
	case 0: mtime.day_week="Sunday"; break;
	case 1: mtime.day_week="Monday"; break;
	case 2: mtime.day_week="Tuesday"; break;
	case 3: mtime.day_week="Wednesday"; break;
	case 4: mtime.day_week="Thursday"; break;
	case 5: mtime.day_week="Friday"; break;
	case 6: mtime.day_week="Saturday"; break;
	default: mtime.day_week="Error finding day"; break;
	}

	//month
	switch(t->tm_mon){
	case 0: mtime.month="January"; break;
	case 1: mtime.month="February"; break;
	case 2: mtime.month="March"; break;
	case 3: mtime.month="April"; break;
	case 4: mtime.month="May"; break;
	case 5: mtime.month="June"; break;
	case 6: mtime.month="July"; break;
	case 7: mtime.month="August"; break;
	case 8: mtime.month="September"; break;
	case 9: mtime.month="October"; break;
	case 10: mtime.month="November"; break;
	case 11: mtime.month="December"; break;
	}

	//year
	mtime.year=t->tm_year+1900;

	//day_month, day of the month
	mtime.day_month=t->tm_mday;

	//the hour
	mtime.hour24=t->tm_hour;
	if(mtime.hour24>12) //if its in the afternoon...
	{
		mtime.hour12=mtime.hour24-12;
		mtime.pm=true;
		mtime.ampm="PM";
	}
	else
	{
		mtime.pm=false;
		mtime.ampm="AM";
		mtime.hour12=mtime.hour24;
	}

	//the minute
	mtime.min=t->tm_min;

	//second
	mtime.sec=t->tm_sec;

}
//----------------------------------------------
String tdclass::time24(bool disp_sec)
/*	Returns the current (since last reset) time in HH:MM formate in 24hour time, and if 
		disp_sec is true, adds '.SS' to the end
	Post: current 24hour time returned as a string, optionally with seconds						*/
{
		
	String time;

	time=IntToString(mtime.hour24);
	time+=":";
	if(mtime.min<10)
		time+="0";
	time+=IntToString(mtime.min);
	if(disp_sec)
	{
		time+=".";
		if(mtime.sec<10)
			time+="0";
		time+=IntToString(mtime.sec);
	}
	
	return(time);
}
//----------------------------------------------
String tdclass::time12(bool disp_sec)
/*	Returns current (since last reset) 12hour time with seconds at end if disp_sec == true
	Post: Current 12hour time returned														*/
{
	String time;
	
	time=IntToString(mtime.hour12);
	time+=":";
	if(mtime.min<10)
		time+="0";
	time+=IntToString(mtime.min);
	
	if(disp_sec)
	{
		time+=".";
		if(mtime.sec<10)
			time+="0";
		time+=IntToString(mtime.sec);
	}

	return(time);
}
//----------------------------------------------
String tdclass::IntToString(int i)//only works for 1 and 2  and 4 digit numbers
/*	Converts a 1,2, or 4 digit number to a string, for time/date purposes
	Pre: i has 1,2 or 4 digits
	Post: String equivalent of i returned										*/
{
	String str;
	if(i<10)
		str=char(i+48);
	else if(i<100)
	{
		str=char(i/10+48);
		str+=char(i%10+48);
	}
	else if(i<1000)
	{

	}
	else
	{
		str=char(i/1000+48);
		str+=char((i%1000)/100+48);
		str+=char((i/10)%10+48);
		str+=char(i%10+48);
	}
	return(str);
}
//----------------------------------------------
String tdclass::date()
/*	Returns current date (as of last reset) in form day month date, year
	Post: Date returned as a string											*/
{
	return((mtime.day_week + " " + mtime.month + " " + IntToString(mtime.day_month) + ", " + IntToString(mtime.year)));
}
//copyright 3/25/2002 Matthew Guidry
//----------------------------------------------
void tdclass::SWStart()
{
	_ftime(&sw);
}
//----------------------------------------------
double tdclass::SWReading()
{
	struct _timeb t2;
	_ftime(&t2);
	double diff = (t2.time - sw.time)+
		(t2.millitm - sw.millitm)/1000.0;

	return diff;
}
#endif
