#ifndef NETWORKEXCEPTION_H_
#define NETWORKEXCEPTION_H_

#include <iostream>
#include <exception>

using namespace std;

class ResolveHostException : public exception
{
	public:
		ResolveHostException(int code, const string& details);
		~ResolveHostException() throw();
		int getErrorCode();
		string getErrorReport();

	private:
		int errCode;
		string errDetails;
};

#endif