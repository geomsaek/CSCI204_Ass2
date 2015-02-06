/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Driver Class header file
Descript:	Contains function prototypes for Driver class

**/


#include<iostream>
#include<string>

using namespace MyLib;

class Driver : public Employee {
	
	public:
		Driver(){};
		Driver(std::string newLicense, int employeeNum, std::string employeeName, std::string birthdate, std::string address, char empType) : Employee(employeeNum, employeeName, birthdate, address, empType){
			licenseNumber = newLicense;
		}
		virtual void writeToStream(std::istream &);
		virtual void outputToStream(std::ostream &);
		void outputOther();

	private:
		std::string licenseNumber;

};
