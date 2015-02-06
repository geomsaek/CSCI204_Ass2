/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Administrator Header fle
Descript:	Contains function prototypes for Administrator class

**/


#include <iostream>
#include<string>
#include "Employee.h"

using namespace MyLib;

class Administrator: public Employee {

	public:

		Administrator(){}		
		Administrator(int newRoom, int employeeNum, std::string employeeName, std::string birthdate, std::string address, char empType) : Employee(employeeNum, employeeName, birthdate, address, empType){
			roomNumber = newRoom;
		}
		
		virtual void writeToStream(std::istream &);
		virtual void outputToStream(std::ostream &);
		void outputOther();
		void updateRoomNum(int);
	private:
		int roomNumber;

};
