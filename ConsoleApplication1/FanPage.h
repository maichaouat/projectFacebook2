#ifndef _FANPAGE_H_
#define _FANPAGE_H_
#include <iostream>
#include "Date.h"
#include "Status.h"
#include "BoardMessage.h"
#include "FanPage.h"
#include "Friend.h"

using namespace std;
class Friend;

class FanPage
{
private:
	char* name;
	BoardMessage board;
	Friend** fans;
	int fansSize;

public:
	FanPage() : name(nullptr), fans(nullptr), fansSize(0) {}
	FanPage(char* Name) :name(Name), fans(nullptr), fansSize(0) {}



	char* getName();
	BoardMessage getMessageBoard();
	Friend** getFriends(int& size);
	void addFriend(Friend& newFriend);
	void removeFriend(int ind);
	void showFans();

	~FanPage()
	{
		delete name;
		delete fans;
	}

};
#endif // _FRIEDN_H_
