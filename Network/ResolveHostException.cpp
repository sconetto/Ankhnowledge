#include <iostream>
#include "NetWorkExceptions.h"

using namespace std;

/*const char* what() const throw();
{
	return "Impossible to resolve SDL host";
}*/

ResolveHostException::ResolveHostException(int code, const string& details)
: errCode(code), errDetails(details)
{}

ResolveHostException::~ResolveHostException ()throw(){}

int ResolveHostException::getErrorCode()
{
	return errCode;
}

string ResolveHostException::getErrorReport()
{
	return errDetails;
}
