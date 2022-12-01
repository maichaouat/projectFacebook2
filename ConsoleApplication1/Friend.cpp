#include "Friend.h"
#include "GlobalFun.h"


//This function add to friends pointers array a pointer to a new friend
void Friend::addFriend(Friend& newFriend)
{
	if (isFriendsConnected(newFriend) == false)
	{
		friends = myRealloc(friends, friendsSize, friendsSize + 1);
		friends[friendsSize] = &newFriend;
		friendsSize++;
	}
	else
		cout << "friends already connected" << endl;
	
}

//cheack if friends already connected
bool Friend::isFriendsConnected(Friend& newFriend)
{
	bool flag = false;
	for (int i = 0; i < friendsSize && !flag; i++)
	{
		if (friends[i] == &newFriend)
			flag = true;
	}

	return flag;
}

//This function add to fanpage pointers array a pointer to a new friend
void Friend::addFanPage(FanPage& newFanPage)
{
	if (isFanPageAndFriendsConnected(newFanPage) == false)
	{
		pages = myRealloc(pages, pagesSize, pagesSize + 1);
		pages[pagesSize] = &newFanPage;
		pagesSize++;
	}
	else
		cout << "friend already likes this fan page" << endl;
	
}
//cheack if fan page already connected
bool Friend::isFanPageAndFriendsConnected(FanPage& newFanPage)
{
	bool flag = false;
	for (int i = 0; i < pagesSize && !flag; i++)
	{
		if (pages[i] == &newFanPage)
			flag = true;
	}

	return flag;
}
//This function allocates new ptr friends array and copies the data  from the original friends array whithout the i' friend 
void Friend::removeFriend(int ind)
{
	Friend** tmp = new Friend * [friendsSize - 1];
	for (int i = 0; i < ind; i++)
	{
		tmp[i] = friends[i];
	}
	for (int i = ind + 1, j = ind; i < friendsSize; i++, j++)
	{
		tmp[j] = friends[i];
	}
	friendsSize--;
	delete[] friends;
	friends = tmp;
}

//Print friend's name
void Friend::show()
{
	cout << name << endl;
}

//show 10 recent status of a friend
void Friend::show10Status()
{
	Mboard.show10RecentStatus();
}

//This function Print's all the statuses of the friend
void Friend::showMboard()
{
	Mboard.printAllStatus();
}

//show the names of fan pages 
void Friend::showFanPagesNames()
{
	for (int i = 0; i < pagesSize; i++)
	{
		cout << "fan page #" << i + 1 << " name: " << pages[i]->getName() << endl;
	}
}

void Friend::showMyFriends10RecentStatuses()
{
	for (int i = 0; i < friendsSize; i++)
	{
		cout << "10 recent stastuses of: ";
		friends[i]->show();
		cout << endl;
		friends[i]->show10Status();
	}
}

void Friend::showAllFriends()
{
	for (int i = 0; i < friendsSize; i++)
	{
		cout << "friend num #" << i + 1 << " ";
		friends[i]->show();
	}
}

//free name pointer, friends arr and fanpages arr
Friend::~Friend()
{
	delete[] name;
	delete[] friends;
	delete[] pages;
}