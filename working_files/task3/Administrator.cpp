/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Administrator Func Def file
Descript:	Contains function definitions of Administrator sub class

**/


#include<iostream>
#include<fstream>
#include "Administrator.h"

void Administrator::writeToStream(std::istream & input){

	Employee::writeToStream(input);
	input >> roomNumber;
}

void Administrator::outputToStream(std::ostream & output){
	
	Employee::outputToStream(output);
	output << this->roomNumber;
	output << std::endl;
}

void Administrator::updateRoomNum(int newRoom){
	roomNumber = newRoom;
}

/*
int Administrator::searchIndex(std::string value, char searchChar){
	return value.find(searchChar);
}

std::string Administrator::createSubString(std::string & value, int startIndex, int finish){

	value = value.substr(startIndex, finish);
	return value;
}*/

void Administrator::outputOther(){

	std::ofstream file;
	file.open("log.txt", std::ofstream::out | std::ofstream::app);
	file << "Room Number: " << this->roomNumber;
	file << '\n';
	file << '\n';
	file.close();
}
