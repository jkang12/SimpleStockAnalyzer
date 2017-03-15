//AppleStock.cpp

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
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include "Stock.h"
#include "AppleStock.h"
using namespace std;

		AppleStock::AppleStock(){} //didn't see a reason for a specific constructor

		
		void AppleStock::myMethod(string date, double opening, double closing, double high, double low, double volume, size_t j){
			Stock stock;
			stock.setOpeningValue(opening);
				stock.setDate(date);
				stock.setHighValue(high);
				stock.setLowValue(low);
				stock.setClosingValue(closing);
				stock.setVolume(volume);
				stock.setYearAndMonth();
				stockV.push_back(stock);
			}
		
		void AppleStock::openFile(){
			
			bool flag = false;
			
			while (flag == false){ //loop until user enters correct file name
			cout << "Please enter the name of the file to open:		" << endl;
			cin >> myStr;
			
			ifstream inFile (myStr, ios::in);			
			
			if (!inFile)
			{
				cout << "Bad file name. Try again." << endl;
				flag = false; //just to ensure that the flag is still false
			}
			else
				flag = true; //exit the while loop
				
			}
		}
		
		
		void AppleStock::get_data_list(){
			ifstream inFile (myStr, ios::in);
			double opening;
			double closing;
			double high;
			double low;
			double volume;
			string date;
			size_t j = 0;
			
			inFile.seekg( 40, ios::cur );
			while(!inFile.eof()){
				inFile >> date >> opening >> high >> low >> closing >> volume;
				Stock stock;
				myMethod(date, opening, closing, high, low, volume, j);
				++j;
			}
			
		}
		
		void AppleStock::average_data(){
			int year;
			bool flag = false;
			while (flag == false ){
			cout << "What year do you want averaged?  " << endl;
			cin >> year;
			if (year >= 1984 && year <= 2013){
				flag = true;
			}
			else{
				cout << "That is not a valid year; please enter a valid year.";
				cin.clear();
				cin.ignore(1000, '\n');
				flag = false; //to ensure that the flag is still false
			}
		}
		
		//the below code will divide the user's input year into the necessary components
		int bottomYear = year % 10;
		year -= bottomYear;
		year = year / 10;
		int topYear = year % 10;
		
		
			size_t myInt = stockV.size();
			size_t j = 0;
			double sumOpen, sumClose, sumHigh, sumLow, sumVol;
			int count = 0;
			size_t openTracker, closeTracker; //used to track the special month
			double theOpen = 0.0;
			double theClose = 1000.0; //also used to track the special month's actual value
			char openM1, openM2, closeM1, closeM2;
			int openMonth1, openMonth2, closeMonth1, closeMonth2;
			double myOpenV, myCloseV;
			
			while (j < myInt){
				
				Stock myStock = stockV[j];
				myStock.setYearAndMonth();
					char y1 = myStock.getYear1();
					char y2 = myStock.getYear2();
					char m1 = myStock.getMonth1();
					char m2 = myStock.getMonth2();
					int iY1 = y1 - 48;
					int iY2 = y2 - 48;
					int iM1 = m1 - 48;
					int iM2 = m2 - 48;
						if ( topYear == iY1 && bottomYear == iY2 ){
							
							count++;
							double myOpen = myStock.getOpeningValue();
							sumOpen += myOpen;
							double myClose = myStock.getClosingValue();
							sumClose += myClose;
							double myHigh = myStock.getHighValue();
							sumHigh += myHigh;
							double myLow = myStock.getLowValue();
							sumLow += myLow;
							double myVol = myStock.getVolume();
							sumVol += myVol;
							
								if (myOpen > theOpen){
								openM1 = myStock.getMonth1();
								openM2 = myStock.getMonth2();
								openMonth1 = openM1 - 48;
								openMonth2 = openM2 - 48;
								myOpenV = myStock.getOpeningValue();
								theOpen = myOpen;
								}
							if (myClose < theClose){
								closeM1 = myStock.getMonth1();
								closeM2 = myStock.getMonth2();
								closeMonth1 = closeM1 - 48;
								closeMonth2 = closeM2 - 48;
								myCloseV = myStock.getClosingValue();
								theClose = myClose;
							}
							}
						j++;
					}
					
			
			double averageOpen = sumOpen/count;
			double averageClose = sumClose/count;
			double averageHigh = sumHigh/count;
			double averageLow = sumLow/count;
			double averageVolume = sumVol/count;
			int avgVolume = averageVolume;
			
			
			cout << endl << left << setw(10) << "Opening" << setw(10) << "Closing" << setw(10) << "High" << setw(10) << "Low" << setw(10) << "Volume"
			<< endl << setw(10) << averageOpen << setw(10) << averageClose << setw(10) << averageHigh << setw(10) << averageLow << setw(10) << avgVolume << endl;
			
			cout << endl << "The month with the highest opening value was " << openMonth1 << openMonth2 << " with " << myOpenV << endl;
			cout << endl << "The month with the lowest closing value was " << closeMonth1 << closeMonth2 << " with " << myCloseV << endl;
			
		}
