/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Employee Class header
Descript:	Contains function prototypes for Employee class

**/


#include<iostream>
#include<string>
#include<sstream>
#include "Date.h"

using namespace MyLib;


class Employee{

	public:
		Employee();
		Employee(int, std::string, std::string, std::string, char);
		~Employee();

		void setEmployeeNum(int);
		void setEmployeeName(std::string);
		void setDateBirth(std::string);
		void setAddress(std::string);
		void setType(char);
		std::string getBirthDate();

		int getEmpNumber();
		char getEmpType();

		virtual void writeToStream(std::istream &);
		virtual void outputToStream(std::ostream &);
		virtual void searchIndex(std::string, char, int &);

		
		friend std::istream& operator>>(std::istream & in, Employee &);
		std::string createSubString(std::string & value, int startIndex, int finish);
		friend std::ostream& operator<<(std::ostream & out, Employee &);
		
	private:
		
	    	int number;
	   	std::string employeeName;
		Date DOB;
	     	std::string address;
		char type;
};
