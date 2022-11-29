#ifndef _BOARDMESSAGE_H_
#define _BOARDMESSAGE_H_
#include "Status.h"


Status* myRealloc(Status* arr, int size, int newSize);

class BoardMessage
{
private:
	Status* messages;
	int logSize;
	int phySize;

public:
	BoardMessage() : logSize(0), phySize(2) { messages = new Status[2]; }

	void addStatus(const Status& message);
	void printAllStatus();


	~BoardMessage() { delete[] messages; }
};
#endif // !_BOARDMESSAGE_