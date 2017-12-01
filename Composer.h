#pragma once

#include <string>
#include <stdint.h>

//this class's functionality checks decomposer working type
class Composer{
public:
	void start(const char * inputFileName, const char * outputFileName);
	uint64_t composition(const std::string & stroka);

private:
	uint64_t charToDigit(char symbol);

};