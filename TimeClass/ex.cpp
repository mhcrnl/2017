/***
*
*	TIME AND DATE PROGRAM
*	  - Using a time and date class i designed
*	
*	Copyright 3/27/2002 By Matthew Guidry
*	
*	Direct questions/comments to: mattg2k4@yahoo.com
*
***/


#include <iostream.h>	//obvious why this is here
#include "string.h"		//a string class i use here
#include "time.h"		//the time class i made
#include <stdlib.h>		//here in order to use system("pause")

void main()
{
	//declare instance of my time and date class
	tdclass TimeDateClass;
		
	//Accesses the date function of the class
	cout<<"Today is "<<TimeDateClass.date()<<endl;

	//Accesses the time function in 24 hour format
	//NOTE: The bool value for time functions must be 
	//  true if you want it to display seconds
	cout<<"The 24hour time is: "<<TimeDateClass.time24(true)<<endl;	
	
	//Displays the time in 12 hour format
	cout<<"The 12hour time is: "<<TimeDateClass.time12(true)<<endl;
	
	//starts the stopwath
	TimeDateClass.SWStart();

	//pauses the program until a key is hit
	system("pause");
	
	//tells user how long it took them to hit enter or whatever
	cout<<"It has been "<<TimeDateClass.SWReading()<<" second(s) since the previous time has been displayed"<<endl;
	
	//Refreshes the time and date with current values
	TimeDateClass.reset();
	
	//Displays the new time
	cout<<"Now the time is: "<<TimeDateClass.time12(true)<<endl;
	
	//Pauses program at end
	system("pause");


	//If this program doesnt work, email me at mattg2k4@yahoo.com with your compiler
	//name and version, and anything relevant
	//Feel free to email me with questions or comments about this program
}