/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Employee Management Function def file
Descript:	Contains function defs for EmployeeManagement class

**/

#include <iostream>
#include <fstream>
#include<sstream>
#include<cctype>
#include<cstring>
#include "EmployeeManagement.h"

EmployeeManagement::EmployeeManagement(){
	
}

void EmployeeManagement::loadEmployees(const char * fileName){
	
	bool good = true;
	try{
		openFile(fileName);
	}catch(std::string err){
		std::ofstream file;
		good = false;
		file.open("log.txt", std::ofstream::out | std::ofstream::app);
		file << "Failed to open file: " << err;
		file << '\n';
		file << "File Name: " << fileName;
		file << '\n';
		file << '\n';
		file.close();
	}
	if(good){
		displayEmployees();
	}
}

void EmployeeManagement::openFile(const char * fileName){
	
	std::ifstream file;
	file.open(fileName);
	std::string tempValue;

	if(file.good()){
		file.close();
		countStudents(fileName);
		try{
			breakApartData(fileName);
		}catch(std::string error){
			writeErrorToLog(error);
		}
	}else {
		throw(std::string("Bad File Name"));
	}
	file.close();
}

void EmployeeManagement::countStudents(const char * fileName){

	std::ifstream file;

	std::string tempString;
	file.open(fileName);
	std::string type;
	int counter = 0;


	while(!file.eof()){
		std::getline(file, tempString);
		type = tempString[0];
		if(type == "A" || type == "T" || type == "D"){
			counter =counter + 1;
		}
	}
	file.close();

	totalEmployees = counter;

}

void EmployeeManagement::breakApartData(const char * fileName){

	char separator = ',';
	std::ifstream file;
	std::string tempString, subTemp,error = "";
	
	this->employeeList = new Employee * [totalEmployees];
	int employeeCount = 0, lineCount = 1, comFind = 0;
	bool errorFound = false, dateError = false,initial = true;

	for(int i = 0; i < 3; i++){
		file.open(fileName);
		while(!file.eof()){
			std::getline(file, tempString);
			if(tempString.length() > 20){
				comFind = searchIndex(tempString, separator);
				subTemp = tempString.substr(0, comFind);

				if(initial){
					if(!(subTemp == "A" || subTemp == "D" || subTemp == "T")){

						std::stringstream out;
						out << lineCount;
						if(error == ""){					
							error = "In text file line " + out.str() + " has an error: '" + subTemp + "' is a wrong employee type";
						}else {
							error = error + "In text file line " + out.str() + " has an error: '" + subTemp + "' is a wrong employee type";
						}
						errorFound = true;
					}
				}
				if(i == 0 && subTemp == "A"){
					dateError = checkDateString(tempString, lineCount, error);
					if(!dateError){
						this->employeeList[employeeCount] = new Administrator;
						std::stringstream out;
						out << tempString;
						out >> *(employeeList[employeeCount]);
						employeeCount++;
					}
				}
				if(i == 1 && subTemp == "T"){
					dateError = checkDateString(tempString, lineCount, error);
					if(!dateError){
						this->employeeList[employeeCount] = new Technician;
						std::stringstream out;
					
						out << tempString;
						out >> *(employeeList[employeeCount]);

						employeeCount++;
					}
				}
				if(i == 2 && subTemp == "D"){
					dateError = checkDateString(tempString, lineCount, error);
					if(!dateError){
						this->employeeList[employeeCount] = new Driver;
						std::stringstream out;
						out << tempString;
						out >> *(employeeList[employeeCount]);
						employeeCount++;
					}
				}
			}
			
			lineCount = lineCount + 1;
		}
		lineCount = 0;
		initial = false;
		file.close();
	}
	totalEmployees= employeeCount;
	if(errorFound){
		throw(std::string(error));
	}
	
}

int EmployeeManagement::searchIndex(std::string value, char searchChar){
	return value.find(searchChar);
}

bool EmployeeManagement::checkDateString(std::string tempString, int lineCount, std::string & curErrorString){
	
	char separator = ',';
	int comFind = 0; //foundEmployees = 0,
	int counter = 0;
	//bool employeeType = true, copyData = false;
	std::ifstream file;
	std::string subTemp;	
	bool dateError = false;

	while(tempString != subTemp){
		
		comFind = searchIndex(tempString, separator);
		subTemp = tempString.substr(0, comFind);
		if(counter == 3){
			Date find;
			try{
				find.setDate(subTemp);
				find.validateDate(find);
			}catch(std::string err){
				std::stringstream out;
				out << lineCount;
				dateError = true;
				curErrorString = curErrorString + "In text file line " + out.str() + " has error: " + err + '\n';
			}
			
			
		}
		tempString = createSubString(tempString, comFind + 1, tempString.length());
		counter = counter + 1;
	}
	return dateError;

}

std::string EmployeeManagement::createSubString(std::string & value, int startIndex, int finish){

	value = value.substr(startIndex, finish);
	return value;
}

void EmployeeManagement::writeErrorToLog(std::string errorMessage){
	
	std::ofstream file;
	file.open("log.txt", std::ofstream::out | std::ofstream::app);
	file << errorMessage;
	file << '\n';
	file.close();
}

int EmployeeManagement::getTotalEmployees(){
	return totalEmployees;
}

void EmployeeManagement::manageEmployees(){
	
	bool end = false; // correct= true;
	char userInput;
	
	while(end == false){
		std::cout << "/********* MANAGE EMPLOYEES - MAIN MENU *********/" << std::endl;
		std::cout << "1. Display employees" << std::endl;
		std::cout << "2. Update an employee" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Your choice: ";
		
		std::cin >> userInput;
			switch(userInput){
				case '0':
					std::cout << "Bye" << std::endl;
					end = true;
				break;

				case '1':
					displayEmpByVal();
				break;

				case '2':
					updateEmployee();
				break;
				
				default:
					std::cout << std::endl;
					std::cout << "Invalid selection!! Please try again!" << std::endl;
					std::cin.clear();
					std::cin.ignore(1000,'\n');
				break;
			}

	}
}


void EmployeeManagement::displayEmpByVal(){
	
	bool end = false;
	char userInput;

	while(end == false){
		std::cout << "/********* SEARCH EMPLOYEES - MAIN MENU *********/" << std::endl;
		std::cout << "1. Find an employee by a number" << std::endl;
		std::cout << "2. Find all employees by a type" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> userInput;
		switch(userInput){
			case '0':
				end = true;
			break;
				
			case '1':
			case '2':
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				findEmployeeByNum(userInput);
			break;
		}
	}
}

void EmployeeManagement::findEmployeeByNum(char select){
	
	int userNumber = 0, count = 0; // num = 0;
	char value;
	
	if(select == '1'){
		std::cout << "Input an employee number: ";
		std::cin >> userNumber;
	}else {
		std::cout << "Input employee type: ";
		std::cin >> value;
	}

	for(int i = 0; i < totalEmployees; i++){
		if(select == '1'){
			if(userNumber == (*employeeList[i]).getEmpNumber()){
				std::cout << (*employeeList[i]);
				count = count + 1;
			}
		}else {
			if(value == (*employeeList[i]).getEmpType()){
				std::cout << (*employeeList[i]);
				count = count + 1;
			}
		}
	
	}
	if(count == 0){
		std::cout << "Sorry! Your number did not match any employee" << std::endl;
		std::cout << std::endl;
	}else {
		std::cout << std::endl;
	}
}


void EmployeeManagement::displayEmployees(){
	for(int i = 0; i < totalEmployees; i++){
		std::cout << *employeeList[i];
	}
}

void EmployeeManagement::updateEmployee(){

	int userEmpNum = 0;
	bool end = false;
	std::string newAddress = "";
	char empType;
	int newRoom = 0;
	int newSkill = 0;

	while(end == false){
		std::cout << "Employee number: ";
		std::cin >> userEmpNum;

		for(int i = 0; i < totalEmployees; i++){
			if(userEmpNum == (*employeeList[i]).getEmpNumber()){
				std::cout << (*employeeList[i]);
				empType = (*employeeList[i]).getEmpType();
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				std::cout << "Input new address (Directly Enter for no change): ";
				std::getline(std::cin, newAddress);
				if(newAddress != ""){
					(*employeeList[i]).setAddress(newAddress);
				}

				switch(empType){
					case 'A':
						{
							std::cout << "New office (0 for no change): ";
							std::cin >> newRoom;
							Administrator * temp = NULL;
						
							if(newRoom != 0){
								temp = dynamic_cast<Administrator *>((employeeList[i]));
								temp->updateRoomNum(newRoom);
							}
						}
					break;

					case 'T':
						{
							std::cout << "New skill level (0 for no change): ";
							std::cin >> newSkill;
							Technician * tempPtr = NULL;
						
							if(newSkill != 0){
								tempPtr = dynamic_cast<Technician *>((employeeList[i]));
								tempPtr->updateSkillLevel(newSkill);
								std::cout << (*employeeList[i]);
							}
						}
					break;
				}
				
				end = true;

			}
		}
	}

	std::cout << std::endl;
}

void EmployeeManagement::saveEmployees(){
	
	std::ofstream file;
	char * fileName;
	fileName = new char[100];
	std::cout << "Input the name to save the data: ";
	std::cin.clear();
	std::cin.ignore(1000,'\n');
	std::cin.getline(fileName, 100, '\n');

	file.open(fileName, std::ofstream::out | std::ofstream::app);
	for(int i = 0;i < totalEmployees; i++){
		file << (*employeeList[i]);
	}
	file.close();
	
}
