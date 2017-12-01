#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
#include <fstream>
#include "Decomposer.h"
#include "DecomposerExceptions.h"

using namespace std;

void Decomposer::start(const string & inputFileName, const string & outputFileName){
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);

	if (inputFile.bad())
		throw inputOutputException();
	cout << "File was opened sucessfully\n";

	uint64_t number = 0;
	string currentFileString("");

	while (!inputFile.eof()){

		try{
			inputFile >> currentFileString;

			if (checkNumber(currentFileString))
				outputFile << decomposition(stringToUint64_t(currentFileString)) << endl;
		}
		catch (exception & error){
			cout << error.what() << endl;
		}

	};

	cout << "Program was executed" << endl;
	inputFile.close();
	outputFile.close();
}

string Decomposer::decomposition(uint64_t number){

	string decompositionResult = "";
	int rightBorder = ceil(number / 2);

	//simple version of decomposition
	for (uint64_t leftBorder = 2; leftBorder <= rightBorder; ++leftBorder)
		while (number % leftBorder == 0){
			decompositionResult = decompositionResult + to_string(leftBorder) + '*';
			number = number / leftBorder;
		};

	if (decompositionResult == "")
		decompositionResult = to_string(number);
	else
		decompositionResult.erase(decompositionResult.end() - 1, decompositionResult.end());

	return decompositionResult;
};

bool Decomposer::checkNumber(const string & number){
	// checking for inappropriate symbols
	try{
		for (size_t i = 0; i < number.length(); ++i)
			if (!(number[i] >= '0' && number[i] <= '9'))
				throw inappropriateSymbolsException();

		//checking for length
		if (number.length() > MAX_UINT64_T_LENGTH)
			throw valueException();
		else if (number.length() == MAX_UINT64_T_LENGTH)
			if (number > MAX_UINT64_T)
				throw valueException();
	}
	catch (exception & error){
		cout << error.what() << "\n";
		return false;
	};

	return true;
}

uint64_t Decomposer::charToDigit(char symbol){
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

uint64_t Decomposer::stringToUint64_t(const string & number){
	uint64_t result = 0;

	for (auto i = number.begin(); i < number.end(); ++i)
		result = result * 10 + charToDigit(*i);

	return result;
};