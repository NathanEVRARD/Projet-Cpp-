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
	PasswordException(string, int);
	PasswordException(PasswordException&);

	~PasswordException();

	void setCode(int);

	int getCode() const;

	static const int INVALID_LENGTH;
	static const int DIGIT_MISSING;
	static const int ALPHA_MISSING;
	static const int NO_PASSWORD;
};

#endif
