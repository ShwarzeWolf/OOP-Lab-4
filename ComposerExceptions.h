#pragma once
#include <exception>

class symbolConvertionException : public std::exception{
	const char * what() const throw(){
		return "Wrong parametrs. Unable to convert to int\n";
	}
};