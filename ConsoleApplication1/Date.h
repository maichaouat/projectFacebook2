#ifndef _DATE_H
#define _DATE_H
#include <iostream>

using namespace std;

//This h file does not have source file beacuse all funcs are short and described in here

class Date {
private:
	const int day;
	const int month;
	const int year;
public:
	Date() :day(0), month(0), year(0) {}
	Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}


	int GetDay() {
		return day;
	}
	int GetMonth() {
		return month;
	}
	int GetYear() {
		return year;
	}

};

#endif

