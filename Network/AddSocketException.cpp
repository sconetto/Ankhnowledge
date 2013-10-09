#include <iostream>
#include "NetWorkExceptions.h"

using namespace std;

AddSocketException::AddSocketException(int code, const string& details)
: errCode(code), errDetails(details)
{}

AddSocketException::~AddSocketException ()throw(){}

int AddSocketException::getErrorCode()
{
	return errCode;
}

string AddSocketException::getErrorReport()
{
	return errDetails;
}
