#ifndef _BOARDMESSAGE_H_
#define _BOARDMESSAGE_H_
#include "Status.h"
#define RECENT 10

Status* myRealloc(Status* arr, int size, int newSize);

class BoardMessage
{
private:
	Status* messages;
	int logSize;
	int phySize;

public:
	BoardMessage() : logSize(0), phySize(2) { messages = new Status[2]; }

	void addStatus(const char* message);
	void printAllStatus();
	void show10RecentStatus();

	~BoardMessage() { delete[] messages; }
};
#endif // !_BOARDMESSAGE_
