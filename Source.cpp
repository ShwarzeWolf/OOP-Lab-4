#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
#include "Decomposer.h"
using namespace std;

int main(/*int argc, char * argv[]*/){
	char * inputFileName = "testIn.txt";
	char * outputFileName = "testOut.txt";
	Decomposer decomposer;
	try{
		decomposer.start(inputFileName, outputFileName);
	}
	catch (exception &error){
		cout << error.what() << endl;
	}
	
	system("pause");
	return 0;
}