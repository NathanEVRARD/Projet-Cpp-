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

PasswordException::PasswordException(int c) : Exception()
{
	#ifdef DEBUG
	  cout << "Constructeur d'initialisation ! (PasswordException)" << endl << endl;
	#endif

	setCode(c);
}

PasswordException::PasswordException(PasswordException& p)
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
}

int PasswordException::getCode() const
{
	return code;
}