#include <iostream>
#include "BTOperator.h"
#include <exception>

int main(int argc, char **argv) {

	if(argc != 2){
		std::cout << "Incorrect number of arguments !!\n";
		std::cout << "Usage on Linux: ./binaryTree <input-filename>\n Usage on Windows: binaryTree.exe <input-filename>\n";
		std::cout << "Sample usage on Linux: ./binaryTree input.txt\n Sample usage on Windows: binaryTree.exe input.txt\n";
		exit(-1);
	}

	try{
		BTOperator btOps(argv[1]);
		btOps.run();
	}
	catch(const std::exception& excp){
		std::cout << excp.what() << "\n";
	}

	return 0;
}
