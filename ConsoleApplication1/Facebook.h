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
	void addFriendToFanPage(Friend& friend1, FanPage& page);
	void showFanPagesNameOfFriend(Friend& friend1);
	void addFriend(Friend& newFriend);
	void addFanPage(FanPage& newPage);

	void freeFriends();
	void freeFanPages();
	void printMenu() const;
	void start();

	~Facebook() { freeFriends(); freeFanPages(); }


};
#endif // ! _FACEBOOK_H_

