#pragma once

#include <string>
#include <stdint.h>

class Decomposer{
public:
	void start(const char * inputFileName, const char * outputFileName);
	std::string decomposition(uint64_t number);

private:
	//structure for number saving
	bool checkNumber(uint64_t number);
};
