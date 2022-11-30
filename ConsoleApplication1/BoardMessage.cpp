#include "BoardMessage.h"

//print all statuses in board message
void BoardMessage::printAllStatus()
{
	cout << "all board messages: " << endl;
	for (int i = 0; i < logSize; i++)
	{
		messages[i].show();
	}
}

//This function add new given status to the status array in board message
void BoardMessage::addStatus(const char* message)
{
	Status newStatus(message);
	if (logSize == phySize) {
		phySize *= 2;
		messages = myRealloc(messages, logSize, phySize);
	}
	messages[logSize] = newStatus;
	logSize++;
}

//show 10 recent status
void BoardMessage::show10RecentStatus()
{
	for (int i = 0; i < RECENT && i <logSize; i++)
	{
		messages[i].show();
	}
}


