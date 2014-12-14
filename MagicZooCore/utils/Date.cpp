#include "Date.h"


Date::Date() :
_dateTime(0)
{

	
}

Date::~Date()
{
}

uint64 Date::getTime()
{
	return _dateTime;
}