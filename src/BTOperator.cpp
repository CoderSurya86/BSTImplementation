/*
 * BTOperator.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: surte
 */

#include "BTOperator.h"
#include "FileNotFoundException.h"
#include "EntryNotFoundException.h"
#include "BSTTester.h"
#include <exception>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <climits>

std::ofstream BTOperator::traversalOutFStream;

BTOperator::BTOperator() {
	copyCreated = false;
}

BTOperator::BTOperator(const std::string& iFileName){

	std::ifstream ifile(iFileName);

	if(ifile.is_open()){

		copyCreated=false;

		std::string tmpStr="";

		while(1){
			getline(ifile, tmpStr,'\r');
			ifile.ignore(1); // to ignore the '\n' after \r at end of line

			std::cout << "\ntmpStr: " << tmpStr << ", length: " << tmpStr.length() << "\n";

			try{
				if(!(tmpStr == ""))
					myBTree.add(tmpStr);
			}
			catch(const std::exception& e){
				throw;
			}

			if(ifile.eof() || tmpStr == "")
				break;

		}

		ifile.close();
	} // end of if(ifile.is_open())
	else{
		throw FileNotFoundException("Input file - "+iFileName+ " doesn't exist !!");
	}
}

void BTOperator::run(){

	int inpOpt=-1;

	while(inpOpt != 8){

		std::cout << "\nBinary tree operations:\n1) Add \n2) Remove \n3) Copy \n4) Traverse\n5) Get depth\n6) Get minimal subtree with deepest nodes\n7) Test\n8) Exit\n\nChoose an option:\n";
		std::cin >> inpOpt;

		while((std::cin.fail()) || (inpOpt < 1) || (inpOpt > 8)){

			if(std::cin.fail()){
				std::cout << "Invalid input !\nShould be a number in the range: 1-8(inclusive)\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if((inpOpt < 1) || (inpOpt > 8)){
				std::cout << "Invalid option " << inpOpt << " !\nShould be a number in the range: 1-8(inclusive)\n";
			}

			std::cout << "\nBinary tree operations:\n1) Add \n2) Remove \n3) Copy \n4) Traverse\n5) Get depth\n6) Get minimal subtree with deepest nodes\n7) Test\n8) Exit\n\nChoose an option:\n";
			std::cin >> inpOpt;

		}


		if(inpOpt == 1){ // add
			if(copyCreated){
				std::cout << "Enter the new character/string: ";

				std::string tmp="";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				getline(std::cin, tmp);

				try{
					if(copyBTree.add(tmp))
						std::cout << "\nSuccessfully added new entry - " << tmp << " to the copy !\n";
				}
				catch(const std::exception& e){
					std::cout << e.what();
				}
			}
			else
				std::cout << "Create a copy first !\n";
		}
		else if(inpOpt == 2){ // remove
			if(copyCreated){
				std::cout << "Enter the entry to remove: ";

				std::string tmp="";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(std::cin, tmp);

				try{
					if(copyBTree.remove(tmp))
						std::cout << "\nSuccessfully removed entry - " << tmp << " from the copy !\n";
				}
				catch(const std::exception& e){
					std::cout << e.what() << " Input entry " << tmp << " not found !\n";
				}
			}
			else
				std::cout << "Create a copy first !\n";
		}
		else if(inpOpt == 3){ // copy
			if(!copyCreated){
				copyBTree = myBTree;
				copyCreated = true;
				std::cout << "\nCopy has been created !\n";
			}
		}
		else if(inpOpt == 4){ // traverse
			int tMenuOpt=-1;
			int bstChoice=-1;

			while(tMenuOpt != 4){

				std::cout << "\nTraversal sub-menu (Binary Search Tree):\n1) pre-order \n2) in-order \n3) post-order \n4) Exit\nChoose a menu option[1-4(inclusive)]: ";
				std::cin >> tMenuOpt;

				while((std::cin.fail()) || (tMenuOpt < 1) || (tMenuOpt > 4)){

					if(std::cin.fail()){
						std::cout << "Invalid input !\nShould be a number in the range: 1-4(inclusive)\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else if((tMenuOpt < 1) || (tMenuOpt > 4)){
						std::cout << "Invalid option " << tMenuOpt << " !\nShould be a number in the range: 1-4(inclusive)\n";
					}

					std::cout << "\nTraversal sub-menu (Binary Search Tree):\n1) pre-order \n2) in-order \n3) post-order \n4) Exit\nChoose a menu option[1-4(inclusive)]: ";
					std::cin >> tMenuOpt;

				}

				if(tMenuOpt != 4){ // exit if == 4
					std::cout << "\nChoice of Binary Search Tree:\n1) Original \n2) Copy\nChoose a menu option[1 or 2]: ";
					std::cin >> bstChoice;

					while((std::cin.fail()) || (bstChoice < 1) || (bstChoice > 2)){

						if(std::cin.fail()){
							std::cout << "Invalid input !\nShould be a number(1 or 2)\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else if((bstChoice < 1) || (bstChoice > 2)){
							std::cout << "Invalid option " << bstChoice << " !\nShould be a number(1 or 2)\n";
						}

						std::cout << "\nChoice of Binary Search Tree:\n1) Original \n2) Copy\nChoose a menu option[1 or 2]: ";
						std::cin >> bstChoice;

					}


					if(!copyCreated && (bstChoice == 2))
						std::cout << "\nCreate a copy first !\n";
					else{

						std::string fname="";
						std::cout << "\nEnter the name of outfile:";
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::getline(std::cin, fname);

						traversalOutFStream.open(fname.c_str());

						if(tMenuOpt == 1){ // pre-order
							if(bstChoice == 1){ // original
								//myBTree.preorderTraversal(printDataEntry);
								myBTree.preorderTraversal(printDataToFile);
							}
							else{ // copy
								//copyBTree.preorderTraversal(printDataEntry);
								copyBTree.preorderTraversal(printDataToFile);
							}
						}
						else if(tMenuOpt == 2){ // in-order
							if(bstChoice == 1){ // original
								//myBTree.inorderTraversal(printDataEntry);
								myBTree.inorderTraversal(printDataToFile);
							}
							else{ // copy
								//copyBTree.inorderTraversal(printDataEntry);
								copyBTree.inorderTraversal(printDataToFile);
							}
						}
						else if(tMenuOpt == 3){ // post-order
							if(bstChoice == 1){ // original
								//myBTree.postorderTraversal(printDataEntry);
								myBTree.postorderTraversal(printDataToFile);
							}
							else{ // copy
								//copyBTree.postorderTraversal(printDataEntry);
								copyBTree.postorderTraversal(printDataToFile);
							}
						}

						traversalOutFStream.close();
						std::cout << "\nData successfully written to file " << fname << "\n";
					} // end of else-part of if(!copyCreated && (bstChoice == 2))
				} // end of if(tMenuOpt != 4)
			} // end of while(tMenuOpt != 4)

			std::cout << "\nExiting tree-traversal sub-menu ...\n";

		} // end of else if(inpOpt == 4)
		else if(inpOpt == 5){ // get depth

			int bstChoice = -1;

			while((std::cin.fail()) || ((bstChoice != 1) && (bstChoice != 2))){

				std::cout << "\nChoice of Binary Search Tree:\n1) Original \n2) Copy\nChoose a menu option[1 or 2]: ";
				std::cin >> bstChoice;

				if(std::cin.fail()){
					std::cout << "Invalid input !\nShould be a number(1 or 2)\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if((bstChoice != 1) && (bstChoice != 2)){
					std::cout << "Invalid option " << bstChoice << " !\nShould be a number(1 or 2)\n";
				}

			}

			if(bstChoice == 1)
				std::cout << "\nCurrent tree depth is: " << myBTree.getTreeDepth() << "\n";
			else
				std::cout << "\nCurrent tree depth is: " << copyBTree.getTreeDepth() << "\n";
		}
		else if(inpOpt == 6){ // minimal sub-tree with deepest nodes

			int bstChoice = -1;

			while((std::cin.fail()) || (bstChoice != 1) || (bstChoice != 2)){

				if(std::cin.fail()){
					std::cout << "Invalid input !\nShould be a number(1 or 2)\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if((bstChoice != 1) || (bstChoice != 2)){
					std::cout << "Invalid option " << bstChoice << " !\nShould be a number(1 or 2)\n";
				}

				std::cout << "\nChoice of Binary Search Tree:\n1) Original \n2) Copy\nChoose a menu option[1 or 2]: ";
				std::cin >> bstChoice;

			}

			try{
				if(bstChoice == 1)
					std::cout << "\nMinimal sub-tree root with deepest nodes: " << myBTree.getSmallestSubTreeAllDeepestNodes() << "\n";
				else
					std::cout << "\nMinimal sub-tree root with deepest nodes: " << copyBTree.getSmallestSubTreeAllDeepestNodes() << "\n";
			}
			catch(const std::exception& ex){
				std::cout << ex.what();
			}
		}
		else if(inpOpt == 7){ // test
			int menuChoice=-1;
			BSTTester tester;

			while(menuChoice != 4){

				std::cout << "\n__________________\n";
				std::cout << "|----Test Menu----|\n";
				std::cout << "__________________\n";
				std::cout << "1) Add\n 2) Remove\n 3) Traverse\n 4) Exit\n";
				std::cin >> menuChoice;

				while(std::cin.fail() || (menuChoice < 1) || (menuChoice > 4)){

					std::cout << "\nInvalid input !\n Should be a number in the range: 1-4(inclusive)\n";

					if(std::cin.fail()){
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					}

					std::cout << "1) Add\n 2) Remove\n 3) Traverse\n 4) Exit\n";
					std::cin >> menuChoice;
				}

				if(menuChoice == 1){ // add
					try{
						tester.testAdd(myBTree);
					}
					catch(const std::exception& exc){
						std::cout << exc.what() << "\n";
					}
				}
				else if(menuChoice == 2){ // remove
					try{
						tester.testRemove(myBTree);
					}
					catch(const std::exception& exc){
						std::cout << exc.what() << "\n";
					}
				}
				else if(menuChoice == 3){ // traverse
					tester.testTraverse(myBTree);
				}
			} // end of while(menuChoice != 4)
		}
	} // end of while(inpOpt != 8)

	// Input option is 7 and control exits loop.
	std::cout << "\nExiting application ...\n\n";

}

BTOperator::~BTOperator() {

}


void BTOperator::printDataEntry(std::string& dEntry){
	std::cout << dEntry << "\n";
}

void BTOperator::printDataToFile(std::string& dEntry){
	traversalOutFStream << dEntry << "\n";
}
