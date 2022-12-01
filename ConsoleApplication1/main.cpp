#include <iostream>
#include "GlobalFun.h"
using namespace std;

Status* myRealloc(Status* arr, int size, int newSize);
char* myrealloc(char* str, int size, int newSize);
Friend** myRealloc(Friend** arr, int size, int newSize);
FanPage** myRealloc(FanPage** arr, int size, int newSize);
//amit
//love
int main() {
	
	Facebook network;
	network.initial();
	network.showAllFriends();
	network.showAllFanPages();
	Friend f;
	network.start(f);
	network.showAllFriends();
}

Status* myRealloc(Status* arr, int size, int newSize) {

	Status* tmp = new Status[newSize];

	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	return tmp;
}

char* myrealloc(char* str, int size, int newSize)
{
	char* tmp = new char[newSize];

	for (int i = 0; i < size; i++)
	{
		tmp[i] = str[i];
	}
	delete[] str;
	return tmp;
}

Friend** myRealloc(Friend** arr, int size, int newSize) {

	Friend** tmp = new Friend * [newSize];

	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	return tmp;
}

FanPage** myRealloc(FanPage** arr, int size, int newSize) {

	FanPage** tmp = new FanPage * [newSize];

	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	return tmp;
}



