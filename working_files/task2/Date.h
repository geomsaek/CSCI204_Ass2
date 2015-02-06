/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Date header file
Descript:	Defines the prototypes for the functions in the Date class

**/


#include<iostream>
#include<string>

#ifndef DATE_H_
#define DATE_H_
namespace MyLib {
    
    class Date {
        
        public:
            
            // REQUIRED FUNCTIONS
            
            void setDate(const std::string &);
            void setDate(int, int, int);
            void validateDate(const Date &);
            void toString();
            
            /*******************/
            
	    int getDay();
	    int getMonth();
	    int getYear();

            Date();
            Date(const Date &);
            Date(int, int, int);
            ~Date();
        private:
            
           // check the inserted date values
           
           int day;
           int month;
           int year;
    };
    
}
#endif
