#include <iostream>
#include "NetWorkExceptions.h"

using namespace std;

CheckSocketException::CheckSocketException(int code, const string& details)
: errCode(code), errDetails(details)
{}

CheckSocketException::~CheckSocketException ()throw(){}

int CheckSocketException::getErrorCode()
{
	return errCode;
}

string CheckSocketException::getErrorReport()
{
	return errDetails;
}
