#include "OptionException.h"
#include "Exception.h"

//-----------------  CONSTRUCTEURS  --------------------------------

OptionException::OptionException() : Exception()
{
	#ifdef DEBUG
	  cout << "Constructeur par defaut ! (OptionException)" << endl << endl;
	#endif
}

OptionException::OptionException(string m) : Exception(m)
{
	#ifdef DEBUG
	  cout << "Constructeur par defaut ! (OptionException)" << endl << endl;
	#endif
}

OptionException::OptionException(OptionException& o) : Exception(o)
{
	#ifdef DEBUG
	  cout << "Constructeur par defaut ! (OptionException)" << endl << endl;
	#endif
}

//-----------------  DESTRUCTEUR  ----------------------------

OptionException::~OptionException()
{
	#ifdef DEBUG
	  cout << "Constructeur par defaut ! (Exception)" << endl << endl;
	#endif
}