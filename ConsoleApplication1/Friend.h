#ifndef _FRIEND_H
#define _FRIEND_H
#include <iostream>
#include "Date.h"
#include "Status.h"
#include "BoardMessage.h"
#include "FanPage.h"
#define RECENT 10

using namespace std;
class FanPage;

class Friend {
private:
	char* name;
	Date date;
	Friend** friends;
	int friendsSize;
	BoardMessage Mboard;
	FanPage** pages;
	int pagesSize;

public:
	Friend() : name(nullptr), friends(nullptr), friendsSize(0), pages(nullptr), pagesSize(0) {}
	Friend(char* Name, int day, int month, int year)
		: name(Name), date(day, month, year), friends(nullptr), friendsSize(0), pages(nullptr), pagesSize(0) {}

	char* getFriendName() { return name; }
	void addFriend(Friend& newFriend);
	void removeFriend(int ind);
	void addFanPage(FanPage& newFanPage);
	void removeFanPage(int ind);
	void show();
	void show10Status();
	void showFanPagesNames();
	void addStatus(char* status) { Mboard.addStatus(status); }
	~Friend();
};
#endif