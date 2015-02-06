/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Employee Management header file
Descript:	Contains function prototypes for EmployeeManagement class

**/


#include <iostream>
#include "Technician.h"

class EmployeeManagement {
	
	public:
		EmployeeManagement();
		
		// REQUIRED FUNCTIONS

		void loadEmployees(const char *);
		void manageEmployees();
		void displayEmployees();
		void updateEmployee();
		void saveEmployees();

		/////////////////////
		
		int getTotalEmployees();
		


	private:
		void openFile(const char *);
		void countStudents(const char *);
		void breakApartData(const char *);
		int searchIndex(std::string value, char searchChar);
		std::string createSubString(std::string & value, int startIndex, int finish);
		
		void writeErrorToLog(std::string);
		
		
		bool checkDateString(std::string, int, std::string &);
		void displayEmpByVal();
		void findEmployeeByNum(char);


		Employee ** employeeList;
		int totalEmployees;
};
