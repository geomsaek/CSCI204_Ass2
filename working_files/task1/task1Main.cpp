/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Task 1 main cpp file
Descript:	File demos use of BinaryCode Class

**/

#include<iostream>
#include "BinaryCode.h"


int main(){
    
	BinaryCode bc1;
	BinaryCode bc2;
	BinaryCode bc3;
	BinaryCode bc4;

	std::cout << std::endl;
	std::cout << "Input a decimal number for bc1: ";
	std::cin >> bc1;
	
	std::cout << "bc1 = " << bc1 << std::endl;
	std::cout << "!bc1 = " << !bc1 << std::endl;
	!bc1;
	std::cout << "~bc1 = " << ~bc1 << std::endl;
	~bc1;

	bc3 = bc1;
	bc1 << 4;
	std::cout << "bc1 << 4 = " << bc1 << std::endl;
	bc1 >> 4;
	bc1 >> 2;
	std::cout << "bc1 >> 2 = " << bc1 << std::endl;

	std::cout << std::endl;

	std::cout << "Input a binary string for bc2: ";
	std::cin >> bc2;

	bc4 = bc2;
	std::cout << "bc2 = " << bc2 << std::endl;
	std::cout << "!bc2 = " << !bc2 << std::endl;
	!bc2;
	std::cout << "~bc2 = " << ~bc2 << std::endl;
	~bc2;
	bc2 << 3;
	std::cout << "bc2 << 3 = " << bc2 << std::endl;
	bc2 >> 3;
	bc2 >> 4;
	std::cout << "bc2 >> 4 = " << bc2 << std::endl;
	bc2 << 4;

	bc1 = bc3;
	bc2 = bc4;

	std::cout << "bc1 + bc2 = " << bc1 + bc2 << std::endl; 
	bc1 = bc3;
	bc2 = bc4;

	std::cout << "bc1 - bc2 = " << bc1 - bc2 << std::endl;
	bc1 = bc3;
	bc2 = bc4;
	std::cout << "bc1 * bc2 = " << bc1 * bc2 << std::endl;

	bc1 = bc3;
	bc2 = bc4;
	bc3 = bc1;
	std::cout << "bc3 = bc1 = " << bc3 << std::endl;
	bc3 += bc2;
	std::cout << "bc3 += bc2 = " << bc3 << std::endl;
	bc2 = bc4;
	bc3 = bc1;
	std::cout << "bc3 = bc1 = " << bc3 << std::endl;
	bc3 -= bc2;
	std::cout << "bc3 -= bc2 = " << bc3 << std::endl;
	bc2 = bc4;
	bc3 = bc1;
	std::cout << "bc3 = bc1 = " << bc3 << std::endl;
	bc3 *= bc2;
	std::cout << "bc3 *= bc2 = " << bc3 << std::endl;



    
    return 0;
}
