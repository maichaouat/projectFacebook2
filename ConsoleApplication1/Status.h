#ifndef _STATUS_H
#define _STATUS_H

#include <iostream>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#pragma warning(disable: 4996)
//This h file does not have source file beacuse all funcs are short and described in here


class Status {

private:
	char* text;
	time_t time_posted;

public:
	Status() : text(nullptr), time_posted(time(0)) {} 
	Status(const char* data) : text(_strdup(data)), time_posted(time(0)) {}
	Status(const Status& s)
	{
		time_posted = s.time_posted;
		if (this != &s)
			text = _strdup(s.text);
	}

	
	void set(char* data, time_t time) {
		text = _strdup(data);
		time_posted = time;
	}
	 
	const char* getText() const
	{
		return text;
	}

	const char* getDate() const
	{
		return (const char*)ctime(&time_posted);
	}


	void show() const
	{
		cout << text << endl<<"posted on date: " << ctime(&time_posted) << endl;
	}
	
	Status& operator=(const Status& newStatus)
	{
		if (this != &newStatus)
		{
			delete[] text;
			text = strdup(newStatus.getText());
			time_posted = time(0);
		}
		return *this;
	}
	

	~Status() { delete text; }


};


#endif // !_STATUS_H_
