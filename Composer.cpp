#include <string>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include "Composer.h";
#include "ComposerExceptions.h"

using namespace std;

void Composer::start(const string & inputFileName, const string & outputFileName){
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);

	if (inputFile.bad())
		throw inputOutputException();
	cout << "File was opened sucessfully\n";

	string currentFileString("");

	while (!inputFile.eof()){

		try{
			inputFile >> currentFileString;
			outputFile << composition(currentFileString) << endl;
		}
		catch (exception & error){
			cout << error.what() << endl;
		}

	};

	cout << "Program was executed" << endl;
	inputFile.close();
	outputFile.close();
}

uint64_t Composer::composition(const string & stroka) const{
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