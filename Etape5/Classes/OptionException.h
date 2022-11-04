#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H

#include <iostream>
#include "Exception.h"

using namespace std;

class OptionException : public Exception
{
public:
	OptionException();
	OptionException(string);
	OptionException(OptionException&);

	~OptionException();
};

#endif