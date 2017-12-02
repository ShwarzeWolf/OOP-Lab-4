#pragma once
#include <exception>


class inputOutputException : public std::exception{
	const char * what() const throw(){
		return "File error\n";
	}
};