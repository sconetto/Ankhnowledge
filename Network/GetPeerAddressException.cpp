#include <iostream>
#include "NetWorkExceptions.h"

using namespace std;

GetPeerAddressException::GetPeerAddressException(int code, const string& details)
: errCode(code), errDetails(details)
{}

GetPeerAddressException::~GetPeerAddressException ()throw(){}

int GetPeerAddressException::getErrorCode()
{
	return errCode;
}

string GetPeerAddressException::getErrorReport()
{
	return errDetails;
}
