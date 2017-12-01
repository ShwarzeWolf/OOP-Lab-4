#pragma once

#include <string>
#include <stdint.h>

class Decomposer{
public:
	void start(const std::string & inputFileName, const std::string & outputFileName);
	std::string decomposition(uint64_t number);
	//void setWorkingMode(int mode);? think about this idea

private:
	enum workingMode{
		WMDecomposing = 0,
		WMCheckingResult
	};

	// here should be structure for number saving
	bool checkNumber( const std::string & number);
	uint64_t stringToUint64_t(const std::string & number);
	uint64_t charToDigit(char symbol);

	const std::string MAX_UINT64_T = "18446744073709551615";
	const size_t MAX_UINT64_T_LENGTH = 20;
};