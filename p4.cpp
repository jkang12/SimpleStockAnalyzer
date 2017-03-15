//p4.cpp

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

#include <iostream>
#include "AppleStock.h"
using namespace std;

int main(){
	
	AppleStock a;
	a.openFile();
	a.get_data_list();
	a.average_data();
	
	return 0;
}


