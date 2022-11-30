#ifndef  _FACEBOOK_H_
#define _FACEBOOK_H_
#include <iostream>
#include "Date.h"
#include "Status.h"
#include "BoardMessage.h"
#include "FanPage.h"
using namespace std;

class Facebook
{
private:
	Friend** friends;
	int numOfFriends;

	FanPage** fanPages;
	int numOfFanPages;

public:
	Facebook() : friends(nullptr), numOfFriends(0), fanPages(nullptr), numOfFanPages(0) {}
	Facebook(Friend** friends_array, int friends_size, FanPage** fanPage_array, int fanPage_size) : 
		friends(friends_array) , numOfFriends(friends_size), fanPages(fanPage_array), numOfFanPages(fanPage_size) {}
	void connect(Friend& f1, Friend& f2);
	void connectFanPage(Friend& f1, FanPage& fanPage);
	void addFriendToFanPage(Friend& friend1, FanPage& page);
	void showFanPagesNameOfFriend(Friend& friend1);
	void addFriend(Friend& newFriend);
	void addFanPage(FanPage& newPage);
	void showAllFriends() const;
	void showAllFanPages() const;
	void freeFriends();
	void freeFanPages();
	void printMenu() const;
	void start(Friend& friend1);
	void initial();

private:
	void option1();
	void option2();
	void option3();
	void option4();
	void option5();
	void option6();
	void option7();
	void option8();
	void option9();
	void option10();
	void option11();


public:
	~Facebook() { if (friends != nullptr) { delete[] friends; } if (fanPages != nullptr) { delete[] fanPages; } }


};
#endif // ! _FACEBOOK_H_

