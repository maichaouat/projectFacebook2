#ifndef _GLOBAFUN_H_
#define _GLOBAFUN_H_
#include "Status.h"
#include"Date.h"
#include "BoardMessage.h"
#include "Friend.h"
#include "FanPage.h"
#include "Facebook.h"

Status* myRealloc(Status* arr, int size, int newSize);
char* myrealloc(char* str, int size, int newSize);
Friend** myRealloc(Friend** arr, int size, int newSize);
FanPage** myRealloc(FanPage** arr, int size, int newSize);

#endif // !_GLOBAFUN_H_
