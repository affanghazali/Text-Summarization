#ifndef EXCEPTION_H
#define EXCEPTION_H

#pragma once
#include<exception>

class Exception : public std::exception
{
private:
	const char* error_msg;

public:
	Exception(const char* msg) : error_msg(msg) {}
	virtual const char* what() { return this->error_msg; }
};

#endif