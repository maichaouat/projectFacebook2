#include "FanPage.h"

Friend** myRealloc(Friend** arr, int size, int newSize);

//return fan page name
const char* FanPage::getName() { return name; }

//Return message board
BoardMessage FanPage::getMessageBoard() { return board; }

//Returns fan page friends array and puts in given integer the number of fans (size of array)
Friend** FanPage::getFriends(int& size) {
	size = fansSize;
	return fans;
}

//This function add to fans pointers array a pointer to a new fan
void FanPage::addFriend(Friend& newFriend)
{
	fans = myRealloc(fans, fansSize, fansSize + 1);
	fans[fansSize] = &newFriend;
	fansSize++;
}

//This function allocates new ptr fans array and copies the data  from the original fans array whithout the i' fan 
void FanPage::removeFriend(int ind)
{
	Friend** tmp = new Friend * [fansSize - 1];
	for (int i = 0; i < ind; i++)
	{
		tmp[i] = fans[i];
	}
	for (int i = ind + 1, j = ind; i < fansSize; i++, j++)
	{
		tmp[j] = fans[i];
	}
	fansSize--;
	delete[] fans;
	fans = tmp;

}

//Print all fans of fan page
void FanPage::showFans()
{
	cout << "All friends of " << name << ": " << endl;
	for (int i = 0; i < fansSize; i++)
	{
		cout << i + 1 << ":";
		fans[i]->show();
		cout << endl;
	}
}

//This function Print's all the statuses of the fan page
void FanPage::showAllStatuses()
{
	board.printAllStatus();
}