//Stock.h

/*
Course Number:  CSE 1342
Programmer:     JOSEPH KANG
Date:           11/09/2015
Program Number: Program 4
Purpose:        ANALYZES A SEQUENTIAL FILE OF STOCKS TO FIND HIGH AND LOW VALUES AND MORE  
Server:		 genuse30.lyle.smu.edu
Instructor: DONALD EVANS
TA:             SEAN

Sources Consulted: NONE
*/

#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>
using namespace std;

class Stock{
	
	friend ostream &operator<<( ostream &, const Stock & );
	
	public:
	
	Stock(); //didn't find need for a specific constructor
	string getDate();
	double getOpeningValue();
	double getHighValue();
	double getLowValue();
	double getClosingValue();
	double getVolume();
	int getMonth();
	int getYear();
	void setDate(string);
	void setOpeningValue(double);
	void setHighValue(double);
	void setLowValue(double);
	void setClosingValue(double);
	void setVolume(double);	
	char getYear1();
	char getYear2();
	char getMonth1();
	char getMonth2();
	void setYearAndMonth();
	
	private:
	
	string date;
	double openingValue;
	double highValue;
	double lowValue;
	double closingValue;
	double volume;
	char year1, year2;
	char month1, month2;
};

#endif

