#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

using namespace std;

class Exception
{
protected:
	string message;
public:
	Exception();
	Exception(string);
	Exception(Exception&);

	~Exception();

	void setMessage(string);

	string getMessage() const;
};

#endif