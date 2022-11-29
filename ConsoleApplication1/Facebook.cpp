#include "Facebook.h"
#include "GlobalFun.h"
//connect with two friends
void Facebook::connect(Friend& f1, Friend& f2)
{
	f1.addFriend(f2);
	f2.addFriend(f1);
}

//add friend to fanPage
void Facebook::addFriendToFanPage(Friend& friend1, FanPage& page)
{
	friend1.addFanPage(page);
	page.addFriend(friend1);
}

//show names of all fanpages that friend likes
void Facebook::showFanPagesNameOfFriend(Friend& friend1)
{
	friend1.showFanPagesNames();
}
//add pointer to new friend to facebook
void Facebook::addFriend(Friend& newFriend)
{
	friends = myRealloc(friends, numOfFriends, numOfFriends + 1);
	friends[numOfFriends] = &newFriend;
	numOfFriends++;
}
//add pointer to new page to facebook
void Facebook::addFanPage(FanPage& newPage)
{
	fanPages = myRealloc(fanPages, numOfFanPages, numOfFanPages + 1);
	fanPages[numOfFanPages] = &newPage;
	numOfFanPages++;
}
//free all pointers friends and friends array
void Facebook::freeFriends()
{
	for (int i = 0; i < numOfFriends; i++)
	{
		delete friends[i];
	}
	delete[] friends;
}

//free all pointers fanPages and fanPage array
void Facebook::freeFanPages()
{
	for (int i = 0; i < numOfFanPages; i++)
	{
		delete fanPages[i];
	}
	delete[] fanPages;
}

//print all options in the menu
void Facebook::printMenu() const
{
	cout << "Please choose option from menu: " << endl;
	cout << "1) add friend " << endl;
	cout << "2) add fan page" << endl;
	cout << "3) add status to friend / fanpage" << endl;
	cout << "4) show all status of friend/fan page" << endl;
	cout << "5) show 10 recents status of a friend" << endl;
	cout << "6) connect two friends" << endl;
	cout << "7) delete connection with two friends" << endl;
	cout << "8) add fan to page" << endl;
	cout << "9) remove friend from page" << endl;
	cout << "10) show all friends on Facebook" << endl;
	cout << "11) show friends of friend/fan page" << endl;
	cout << "12) exit" << endl;
}

void Facebook::start()
{
	int input = 1;
	
	while (input != 12)
	{
		printMenu();
		cin >> input;

		
			

	}
}