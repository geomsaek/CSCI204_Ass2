/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Task 2 Main File
Descript:	Demonstrates use of Date class

**/

#include<iostream>
#include "Date.h"
#include<string>

using namespace MyLib;

int main(){
    
    Date test;
    std::string userDate = "";
    int day = 0, month = 0, year = 0;

    std::cout << "Input date (DD/MM/YYYY): ";
    test.setDate("29/02/2014");
    test.toString();

    std::cout << "Input date (DD/MM/YYYY): ";
    std::getline(std::cin, userDate);

    test.setDate(userDate);
    test.toString();

    std::cout << "Input day: ";
    std::cin >> day;
    std::cout << "Enter month: ";
    std::cin >>  month;
    std::cout << "Enter year: ";
    std::cin >> year;

    test.setDate(day, month, year);
    test.toString();
    return 0;
}
