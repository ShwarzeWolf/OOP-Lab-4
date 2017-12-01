#pragma once

#include <string>
#include <stdint.h>

//this class checks corectness of decomposer working
class Composer{
public:
	void start(const char * inputFileName, const char * outputFileName);

private:
	uint64_t composition(const std::string & stroka);
	uint64_t charToDigit(char symbol);

};