#pragma once

#include <string>
#include <stdint.h>
#include "typesConvertionFunctions.h"

class Decomposer{
public:
	void start(const std::string & inputFileName, const std::string & outputFileName);
	std::string decomposition(uint64_t number) const;

private:
	// here should be structure for number saving
	bool checkNumber(const std::string & number);

	const std::string MAX_UINT64_T = "18446744073709551615";
	const size_t MAX_UINT64_T_LENGTH = 20;
};