//AppleStock.h

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

#ifndef APPLESTOCK_H
#define APPLESTOCK_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include "Stock.h"
using namespace std;

class AppleStock{
	
	private:
		vector< Stock > stockV;
		ifstream inFile;
		
	public:
		
		AppleStock(); //don't see a reason for a specific constructor
			
		string myStr;
		
		void myMethod(string, double, double, double, double, double, size_t);
		
		void openFile();		
		
		void get_data_list();
		
		void average_data();
	};
	
#endif
