//Stock.cpp

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

#include <iomanip>
#include <iostream>
#include "Stock.h"
#include <string>
using namespace std;

ostream &operator<<( ostream &output, const Stock &stock ){
	output << left << setw(13) << "Opening" << setw(13) << "Closing" << setw(13) << "High" << setw(13) << "Low" << setw(13) << "Volume" << endl 
			<< setw(13) << stock.openingValue << setw(13) << stock.closingValue << setw(13) << stock.highValue << setw(13) << stock.lowValue << setw(13) << stock.volume << endl;
			
	return output;
	
}


Stock::Stock(){} // didn't see need for a specific constructor

double Stock::getOpeningValue(){
		return openingValue;
}

double Stock::getHighValue(){
	return highValue;
}

double Stock::getLowValue(){
	return lowValue;
}

double Stock::getClosingValue(){
	return closingValue;
}

double Stock::getVolume(){
	return volume;
}

void Stock::setOpeningValue(double myNum){
	openingValue = myNum;
}

void Stock::setHighValue(double myNum){
	highValue = myNum;
}

void Stock::setLowValue(double myNum){
	lowValue = myNum;
}

void Stock::setClosingValue(double myNum){
	closingValue = myNum;
}

void Stock::setVolume(double myNum){
	volume = myNum;
}


void Stock::setDate(string myStr){
	date = myStr;
}

void Stock::setYearAndMonth(){
	size_t j = date.size();
	j--;
	year2 = date[j];
	j--;
	year1 = date[j];
	j = 0;
	month1 = date[j];
	j++;
	if (date[j] != '/')
		month2 = date[j];
	else{
		month2 = month1;
		month1 = '0';
	}
}

char Stock::getYear1(){
	return year1;
}

char Stock::getYear2(){
	return year2;
}

char Stock::getMonth1(){
	return month1;
}

char Stock::getMonth2(){
	return month2;
}


