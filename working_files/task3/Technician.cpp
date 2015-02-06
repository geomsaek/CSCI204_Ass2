/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Technician and Driver class func defs
Descript:	Contains function definitions for derived Technician and Driver classes

**/


#include<iostream>
#include<fstream>
#include "Technician.h"

/********** TECHNICIAN FUNCTIONS **********/
void Technician::writeToStream(std::istream & input){
	
	Employee::writeToStream(input);
	std::getline(input, skill, ',');
	input >> skillLevel;
}

void Technician::outputToStream(std::ostream & output){
	
	Employee::outputToStream(output);
	output << this->skill;
	output << ", ";
	output << this->skillLevel;
	output << std::endl;
}

void Technician::outputOther(){
	std::ofstream file;
	file.open("log.txt", std::ofstream::out | std::ofstream::app);
	file << "Skill: " << skill;
	file << '\n';
	file << "Skill Level: " << skillLevel;
	file << '\n';
	file << '\n';
	file.close();
}

void Technician::updateSkillLevel(int newLevel){
	skillLevel = newLevel;
}

/********** DRIVER FUNCTIONS **********/

void Driver::writeToStream(std::istream & input){

	Employee::writeToStream(input);
	std::getline(input, licenseNumber);
}

void Driver::outputToStream(std::ostream & output){

	Employee::outputToStream(output);
	output << this->licenseNumber;
	output << std::endl;	
}

void Driver::outputOther(){

	std::ofstream file;
	file.open("log.txt", std::ofstream::out | std::ofstream::app);
	file << "Driver License Number: " << this->licenseNumber;
	file << '\n';
	file << '\n';
	file.close();

}


