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

class AddSocketException : public exception
{
	public:
		AddSocketException(int code, const string& details);
		~AddSocketException() throw();
		int getErrorCode();
		string getErrorReport();

	private:
		int errCode;
		string errDetails;
};

class CheckSocketException : public exception
{
	public:
		CheckSocketException(int code, const string& details);
		~CheckSocketException() throw();
		int getErrorCode();
		string getErrorReport();

	private:
		int errCode;
		string errDetails;
};

class OpenSocketException : public exception
{
	public:
		OpenSocketException(int code, const string& details);
		~OpenSocketException() throw();
		int getErrorCode();
		string getErrorReport();

	private:
		int errCode;
		string errDetails;
};

class GetPeerAddressException : public exception
{
	public:
		GetPeerAddressException(int code, const string& details);
		~GetPeerAddressException() throw();
		int getErrorCode();
		string getErrorReport();

	private:
		int errCode;
		string errDetails;
};

#endif