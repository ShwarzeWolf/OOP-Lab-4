#include <iostream>
#include <stdint.h>
#include <string>
#include "Decomposer.h"
#include "DecomposerExceptions.h"
#include "Composer.h"
using namespace std;

int main(int argc, char * argv[]){
	try{
		if (argc < 2)
			throw inputOutputException();

		string inputFileName = argv[1];
		string outputFileName = argv[2];

		Decomposer decomposer;
		try{
			decomposer.start(inputFileName, outputFileName);
		}
		catch (exception & error){
			cout << error.what() << endl;
		}

	}
	catch (exception & error){
		cout << error.what() << endl;
	}
	
	system("pause");
	return 0;
}