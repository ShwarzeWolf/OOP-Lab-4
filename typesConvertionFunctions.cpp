#include "typesConvertionFunctions.h"
#include "typesConvertionFunctionsException.h"
using namespace std;

uint64_t charToDigit(char symbol){
	switch (symbol){
	case '0': return 0; break;
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	default: throw symbolConvertionException();
	}
}

uint64_t stringToUint64_t(const string & number){
	uint64_t result = 0;

	for (auto i = number.begin(); i < number.end(); ++i)
		result = result * 10 + charToDigit(*i);

	return result;
};