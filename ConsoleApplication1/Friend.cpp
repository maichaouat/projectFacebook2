#include "Friend.h"
#include "GlobalFun.h"


//This function add to friends pointers array a pointer to a new friend
void Friend::addFriend(Friend& newFriend)
{
	friends = myRealloc(friends, friendsSize, friendsSize + 1);
	friends[friendsSize] = &newFriend;
	friendsSize++;
}

//This function add to fanpage pointers array a pointer to a new friend
void Friend::addFanPage(FanPage& newFanPage)
{
	pages = myRealloc(pages, pagesSize, pagesSize + 1);
	pages[pagesSize] = &newFanPage;
	pagesSize++;
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

//show the names of fan pages 
void Friend::showFanPagesNames()
{
	for (int i = 0; i < pagesSize; i++)
	{
		cout << "fan page #" << i + 1 << " name: " << pages[i]->getName() << endl;
	}
}

//free name pointer, friends arr and fanpages arr
Friend::~Friend()
{
	delete[] name;
	delete[] friends;
	delete[] pages;
}