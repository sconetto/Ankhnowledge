#include <iostream>
#include "NetWorkExceptions.h"

using namespace std;

OpenSocketException::OpenSocketException(int code, const string& details)
: errCode(code), errDetails(details)
{}

OpenSocketException::~OpenSocketException ()throw(){}

int OpenSocketException::getErrorCode()
{
	return errCode;
}

string OpenSocketException::getErrorReport()
{
	return errDetails;
}
