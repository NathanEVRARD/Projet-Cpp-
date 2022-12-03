#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H

#include "Exception.h"
#include <iostream>

using namespace std;

class PasswordException : public Exception
{
private:
	int code;
public:
	PasswordException();
	PasswordException(int);
	PasswordException(PasswordException&);

	~PasswordException();

	void setCode(int);

	int getCode() const;
};

#endif
