/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Technician header file
Descript:	Contains function prototypes for Technician class

**/

#include<iostream>
#include<string>
#include<sstream>
#include "Administrator.h"
#include "Driver.h"

class Technician : public Employee {
	public:
		Technician(){};
		Technician(std::string newSkill, int newLevel, int employeeNum, std::string employeeName, std::string birthdate, std::string address, char empType) : Employee(employeeNum, employeeName, birthdate, address, empType){
			skill = newSkill;
			skillLevel = newLevel;
		}

		void updateSkillLevel(int);
		virtual void writeToStream(std::istream &);
		virtual void outputToStream(std::ostream &);
		virtual void outputOther();
	private:
		std::string skill;
		int skillLevel;
};
