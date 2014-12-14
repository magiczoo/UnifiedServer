#ifndef DATE_H
#define DATE_H

#include "../Types.h"

class Date
{
protected:
    uint64 _dateTime;
 
public:
	Date();
	virtual ~Date();

	uint64 getTime();
};

#endif // DATE_H
