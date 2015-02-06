/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Main Task file
Descript:	Demonstrates the user of the EmployeeManagement Class

**/

#include<iostream>
#include "EmployeeManagement.h"

int main(int argc, char*argv[]){
    
	EmployeeManagement selection;
	selection.loadEmployees(argv[1]);
	

	selection.manageEmployees();
	//selection.displayEmployees();
	selection.saveEmployees();
	return 0;
}
