#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
#include <fstream>
#include "Decomposer.h"
#include "DecomposerExceptions.h"
using namespace std;

void Decomposer::start(const char * inputFileName, const char * outputFileName){
	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);
	if (!inputFile.good())
		throw inputOutputException();

	uint64_t number = 0;
	while (!inputFile.eof()){
		//check number validity
		inputFile >> number;
		outputFile << decomposition(number) << endl;
	};

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
}
