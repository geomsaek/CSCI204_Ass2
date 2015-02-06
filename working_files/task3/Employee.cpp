/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Employee Class functions
Descript:	Contains function definitions for Employee class

**/


#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
#include "Employee.h"

using namespace MyLib;

Employee::Employee(){
	number = 0;
	employeeName = "";
	address = "";
}

Employee::Employee(int newNumber, std::string newName, std::string newDOB, std::string newAddress, char newType){
	
	number = newNumber;
	employeeName = newName;
	DOB.setDate(newDOB);
	address = newAddress;
	type = newType;
}

Employee::~Employee(){
	number = 0;
	employeeName = "";
	address = "";
}

void Employee::setEmployeeNum(int newNumber){
	number = newNumber;
}

void Employee::setEmployeeName(std::string newName){
	employeeName = newName;
}

void Employee::setDateBirth(std::string newDate){
	DOB.setDate(newDate);
}

void Employee::setAddress(std::string newAddress){
	address= newAddress;
}

void Employee::setType(char newType){
	type = newType;
}

std::string Employee::getBirthDate(){
	return DOB.returnDateString();
}

void Employee::writeToStream(std::istream & input){
	
	std::string subTemp;
	
	input >> type;
	input.ignore(3, ',');
	input >> number;
	input.ignore(3,',');
	std::getline(input, employeeName,',');
	std::getline(input, subTemp, ',');
	DOB.setDate(subTemp);
	std::getline(input,address,',');
}


void Employee::searchIndex(std::string value, char searchChar, int & indexFind){
	indexFind = value.find(searchChar);
}

std::string Employee::createSubString(std::string & value, int startIndex, int finish){

	value = value.substr(startIndex, finish);
	return value;
}

void Employee::outputToStream(std::ostream & output){
	
	output << this->type;
	output << ", ";
	output << this->number;
	output << ", ";
	output << this->employeeName;
	output << ", ";
	output << this->DOB.getDay();
	output << "/";
	output << this->DOB.getMonth();
	output << "/";
	output << this->DOB.getYear();
	output << ", ";
	output << this->address;
	output << ", ";
}



int Employee::getEmpNumber(){ return number; }
char Employee::getEmpType(){ return type; }

std::istream &operator >> (std::istream& in, Employee & object){
	
	object.writeToStream(in);
	return in;
}

std::ostream&operator<<(std::ostream &out, Employee & object){

	object.outputToStream(out);

	return out;
}

