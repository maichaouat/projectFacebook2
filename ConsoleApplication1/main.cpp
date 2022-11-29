#include <iostream>
using namespace std;


char* getStringFromUser();
char* myrealloc(char* str, int size, int newSize);
int main()
{
	return 0;
}

//get string with unkown size
char* getStringFromUser()
{
	char c;
	char* str = new char[2], *tmp;
	int logSize = 0, phySize = 2;
	c = getchar();
	while (c != '\n')
	{

		if (logSize == phySize)
		{
			phySize *= 2;
			tmp= myrealloc(str, logSize, phySize);
			str = tmp;
		}
		str[logSize] = c;
		logSize++;
		c = getchar();
	}
	if (logSize == phySize)
	{
		str = myrealloc(str, logSize, logSize + 1);

	}
	else if (logSize < phySize)
	{
		str = myrealloc(str, phySize, logSize + 1);
	}
	str[logSize] = '\0';
	return str;
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

