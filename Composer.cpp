#include <string>
#include <stdint.h>
#include "Composer.h";
#include "ComposerExceptions.h"

using namespace std;

uint64_t Composer::charToDigit(char symbol){
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

uint64_t Composer::composition(const string & stroka){
	uint64_t result = 1;
	uint64_t currentNumber = 0;

	for (auto i = stroka.begin(); i < stroka.end(); ++i)
		if (*i == '*'){
			result = result * currentNumber;
			currentNumber = 0;
		}
		else{
			currentNumber = currentNumber * 10 + charToDigit(*i);
		};

		return result*currentNumber;
};