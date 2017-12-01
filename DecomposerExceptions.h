#include <exception>

class inputOutputException : public std::exception{
	const char * what() const throw(){
		return "File error\n";
	}
};

class unsupportedType : public std::exception{
	const char * what() const throw(){
		return "This number has unsupported type\n";
	}
};