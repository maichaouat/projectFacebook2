#include "Facebook.h"
#include "GlobalFun.h"
#include <string.h>
#define MAX_LEN 20

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

void Facebook::start(Friend& friend1)
{
	int input = 1;
	
	while (input != 12)
	{
		cout << endl;
		printMenu();
		cin >> input;

		//add new friend to facebook
		if (input == 1)
		{
			option1();
			cout << "friend added succesfully" << endl;
		} 
		//add new fanPage to facebook
		else if (input == 2)
		{
			option2();
			cout << "fan page add succesfully" << endl;
		}
		//add status to fan page or friend
		else if (input == 3)
		{
			option3();
			cout << "status add succesfully" << endl;
		}
		else if (input == 4)
		{
			option4();
		}
		else if (input == 5)
		{
			option5();
		}
		else if (input == 6)
		{
			//to do - add is friend or fan page connected to fan page
			option6();
		}
		else if (input == 7)
		{
			option7();
		}
		else if (input == 8)
		{
			option8();
		}
		else if (input == 9)
		{
			option9();
		}
		else if (input == 10)
		{
			option10();
		}
		else if (input == 11)
		{
			option11();
		}

	}
}

//print all friends in facebook
void Facebook::showAllFriends() const
{
	
	for (int i = 0; i < numOfFriends; i++)
	{
		cout << "friend num #" << i+1 << " ";
		friends[i]->show();
	}
		
}

//print all fan pages in facebook
void Facebook::showAllFanPages() const
{

	for (int i = 0; i < numOfFanPages; i++)
	{
		cout << "fan page num #" << i + 1 << " ";
		cout<<fanPages[i]->getName()<<endl;
	}

}

//connect fan page with friend
void Facebook::connectFanPage(Friend& f1, FanPage& fanPage)
{
	f1.addFanPage(fanPage);
	fanPage.addFriend(f1);
}

//inital first data for facebook
void Facebook::initial()
{
	friends = new Friend*[3];
	fanPages = new FanPage * [3];
	friends[0] = new Friend("Mai Chaouat", 19, 8, 1998);
	friends[1] = new Friend("Amit Naory", 20, 1, 1997);
	friends[2] = new Friend("Ran Danker", 1, 1, 1980);

	connect(*friends[0], *friends[2]);
	connect(*friends[1], *friends[0]);

	fanPages[0] = new FanPage("Please give us A");
	fanPages[1] = new FanPage("We love Ran Danker");
	fanPages[2] = new FanPage("Hapshuta");

	numOfFriends = numOfFanPages = 3;

	connectFanPage(*friends[0], *fanPages[0]);
	connectFanPage(*friends[1], *fanPages[0]);
	connectFanPage(*friends[0], *fanPages[2]);
	connectFanPage(*friends[2], *fanPages[1]);
	connectFanPage(*friends[2], *fanPages[2]);


	friends[0]->addStatus("please give us good grade");
	friends[1]->addStatus("we are good students");
	friends[2]->addStatus("give them good graders");
	friends[2]->addStatus("I love my new dress");

	friends[0]->showFanPagesNames();
	friends[0]->show10Status();

}

//add new friend to facebook
void Facebook::option1() 
{
	int day, month, year;
	char name[MAX_LEN];

	cout << "Please enter your name " << endl;
	cin >> name;
	cout << "Please enter date of birth. format:DD MM YYYY" << endl;
	cin >> day >> month >> year;

	Friend* newFriend = new Friend(name, day, year, month);
	addFriend(*newFriend);
}

//add new fanPage to facebook
void Facebook::option2() 
{
	char name[20];
	cout << "Please enter fan page name " << endl;
	cin >> name;
	FanPage* newFanPage = new FanPage(name);
	addFanPage(*newFanPage);
}

//add status to fan page or friend
void Facebook::option3()
{

	char answer;
	char text[256];
	int option;
	cout << "Please enter your status" << endl;
	cin >> text;


	cout << "Do you want to add status to a friend? Y/N (if choose N we will add to fan page)" << endl;
	cin >> answer;
	if (answer == 'Y')
	{
		cout << "Please enter index of the friend you want to add status from the following friends" << endl;
		showAllFriends();
		cin >> option;
		if (option > 0 )
			friends[option - 1]->addStatus(text);

	}
	else //answer is N (add ststus to a fan page
	{
		cout << "Please enter index of the fan page you want to add status from the following fan pages" << endl;
		showAllFanPages();
		cin >> option;
		if (option >0)
			fanPages[option - 1]->addStatus(text);
	}
}

//Show all statuses of a friend or a fan page 
void Facebook::option4()
{
	char answer;
	int option;

	cout << "Do you want to see all statuses of a friend? Y/N (if choose N we will show all statuses of a fan page)" << endl;
	cin >> answer;
	if (answer == 'Y')
	{
		cout << "Please enter index of the friend that you want to see his statuses from the following friends" << endl;
		showAllFriends();
		cin >> option;
		if (option > 0)
			friends[option - 1]->showMboard();
	}
	else //answer is N (show all statuses of a fan page
	{
		cout << "Please enter index of the fan page that you want to see it statuses from the following fan pages" << endl;
		showAllFanPages();
		cin >> option;
		if (option > 0)
			fanPages[option - 1]->showAllStatuses();
	}
}

//show 10 recent statuses of all of friend's friends
void Facebook::option5()
{
	int option;

	cout << "Please enter index from the following friends list of the friend that you want to see the 10 recent ststuses of his friends" << endl;
	showAllFriends();
	cin >> option;
	if (option > 0)
		friends[option - 1]->showMyFriends10RecentStatuses();
}

//connect with two friends
void Facebook::option6()
{
	int ind1, ind2;
	cout << "Please choose 2 friends from the following friends list that you want to connect friends as friends" << endl;
	showAllFriends();
	cout << "#1 friend: ";
	cin >> ind1;
	cout << endl << "#2 friend: ";
	cin >> ind2;
	connect(*friends[ind1 - 1], *friends[ind2 - 1]);
}

//cancel friendship with two friends
void Facebook::option7()
{
	int ind1, ind2;
	cout << "Please choose friend from the following friends list that you want to remove connection to" << endl;
	showAllFriends();
	cout << "#1 friend: ";
	cin >> ind1;
	cout << "please choose friend you want to remove from " << friends[ind1 - 1]->getFriendName() <<" friends "<< endl;
	friends[ind1 - 1]->showAllFriends();
	cin >> ind2;
	
	friends[ind1 - 1]->removeFriend(ind2);
	friends[ind2 - 1]->removeFriend(ind1);
}

//add fan to a page
void Facebook::option8()
{
	int ind1, ind2;
	cout << "Choose friend index " << endl;
	showAllFriends();
	cin >> ind1;

	cout << "Choose fan page you want the friend to like" << endl;
	showAllFanPages();
	cin >> ind2;

	friends[ind1 - 1]->addFanPage(*fanPages[ind2 - 1]);
	fanPages[ind2 - 1]->addFriend(*friends[ind1 - 1]);
}

//remove fan from fan page
void Facebook::option9()
{
	int ind1, ind2;
	 
	cout << "Please choose fan page index" << endl;
	showAllFanPages();
	cin >> ind1;

	cout << "Please choose friend you want to remove from fans of " << fanPages[ind1 - 1]->getName() << " fan page" << endl;
	fanPages[ind1 - 1]->showFans();
	cin >> ind2;

	fanPages[ind1 - 1]->addFriend(*friends[ind2 - 1]);
	friends[ind2 - 1]->addFanPage(*fanPages[ind1 - 1]);


}

//show all friends of facebook and fan pages
void Facebook::option10()
{
	cout << "All friends of facebook" << endl;
	showAllFriends();
	cout << "All fan pages of facebook" << endl;
	showAllFanPages();
}

//show all friends of page or friend
void Facebook::option11()
{
	int option;
	char answer;
	cout << "Do you want to add status to a friend? Y/N (if choose N we will add to fan page)" << endl;
	cin >> answer;
	if (answer == 'Y')
	{
		cout << "Please enter index of the friend you want to add status from the following friends" << endl;
		showAllFriends();
		cin >> option;
		friends[option - 1]->showAllFriends();

	}
	else //answer is N (add ststus to a fan page
	{
		cout << "Please enter index of the fan page you want to add status from the following fan pages" << endl;
		showAllFanPages();
		cin >> option;
		fanPages[option - 1]->showFans();
	}
}