#pragma once

#include <string>
#include <stdint.h>
#include "typesConvertionFunctions.h"

//this class checks decomposer working type
class Composer{
public:
	void start(const std::string & inputFileName, const std::string & outputFileName);
	uint64_t composition(const std::string & stroka) const;
};