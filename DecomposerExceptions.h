#pragma once
#include <exception>

class inputOutputException : public std::exception{
	const char * what() const throw(){
		return "File error\n";
	}
};

class unsupportedTypeException : public std::exception{
	const char * what() const throw(){
		return "This number has unsupported type\n";
	}
};

class symbolConvertionException : public std::exception{
	const char * what() const throw(){
		return "Wrong parametrs. Unable to convert to int\n";
	}
};

class inappropriateSymbolsException : public std::exception{
	const char * what() const throw(){
		return "String includes extra symbols\n";
	}
};

class valueException : public std::exception{
	const char * what() const throw(){
		return "This value is too big\n";
	}
};