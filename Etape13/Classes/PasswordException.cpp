#include "PasswordException.h"
#include "Exception.h"

//-------------------  CONSTRUCTEURS  ---------------------------------

PasswordException::PasswordException() : Exception()
{
	#ifdef DEBUG
	  cout << "Constructeur par defaut ! (PasswordException)" << endl << endl;
	#endif

	setCode(0);
}

PasswordException::PasswordException(string m, int c) : Exception(m)
{
	#ifdef DEBUG
	  cout << "Constructeur d'initialisation ! (PasswordException)" << endl << endl;
	#endif

	setCode(c);
}

PasswordException::PasswordException(PasswordException& p) : Exception(p)
{
	#ifdef DEBUG
	  cout << "Constructeur de copie ! (PasswordException)" << endl << endl;
	#endif

	setCode(p.getCode());
}

//---------------------  DESTRUCTEUR  -----------------------------------

PasswordException::~PasswordException()
{
	#ifdef DEBUG
	  cout << "Destructeur ! (PasswordException)" << endl << endl;
	#endif
}

//---------------------  SETTERS ET GETTERS  ----------------------------

void PasswordException::setCode(int c)
{
	code = c;

	switch(getCode())
    {
      case 1:
        message = "INVALID_LENGTH";
        break;
      case 2:
        message = "ALPHA_MISSING";
        break;
      case 3:
        message = "DIGIT_MISSING";
        break;
      case 4:
        message = "NO_PASSWORD";
        break;
      default:
        message = "UNKNOW_ERROR";
        break;
    }
}

int PasswordException::getCode() const
{
	return code;
}

const int PasswordException::INVALID_LENGTH = 1;
const int PasswordException::DIGIT_MISSING = 2;
const int PasswordException::ALPHA_MISSING = 3;
const int PasswordException::NO_PASSWORD = 4;