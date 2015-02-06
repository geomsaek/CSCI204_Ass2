/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Date Class Func Defs
Descript:	Contains the Date class function declarations

**/


#include<iostream>
#include<cstdlib>
#include "Date.h"

using namespace std;
using namespace MyLib;

Date::Date(){
    
    day = 0;
    month = 0;
    year = 0;
    
}

Date::Date(const Date & existDate){
        
    day = existDate.day;
    month = existDate.month;
    year = existDate.year;
    
}

Date::Date(int userDay, int userMonth, int userYear){
    
    day = userDay;
    month = userMonth;
    year = userYear;
    
    try{
       
       validateDate(*this);
    }
    catch(string err){
       
       cout << err << endl;
        
    }
}

Date::~Date(){
    
    day = 0;
    month = 0;
    year = 0;
}

void Date::setDate(int userDay, int userMonth, int userYear){
    
    day = userDay;
    month = userMonth;
    year = userYear;
    
    try{
        validateDate(*this);
    }catch(string err){
        cout << err << endl;
        day = 0;
        month = 0;
        year = 0;
    }
}

void Date::setDate(const std::string & date){

    
    int tempDay = 0, tempMonth = 0, tempYear = 0;
    string tempValue = "";
    
    int separatorCount = 0, dateTrack = 0;
    bool change = false;
    int dateLength = date.length();
    
    for(int i = 0; i < dateLength; i++){
        
        if(!isdigit(date[i]) && date[i] != '/' && date[i] != ' '){
            
            i = date.length();
            cout << "Invalid Date String" << endl;
            return;
            
        }else {
            if(date[i] != ' '){
                if(date[i] == '/'){
                    separatorCount++;
                    change = true;
                }
                if(change){
                    switch(dateTrack){
                        case 0:
                            tempDay = atoi(tempValue.c_str());
                            
                            
                        break;
                    
                        case 1:
                            tempMonth = atoi(tempValue.c_str());
                        break;
                    }
                    tempValue = "";
                    change = false;
                    dateTrack = dateTrack + 1;
                }else {
                    tempValue = tempValue + date[i];
                }
                if(i == (date.length() - 1)){
                    tempYear = atoi(tempValue.c_str());
                }
            }
        }
    }

    
    this->setDate(tempDay, tempMonth, tempYear);
}

void Date::validateDate(const Date & existDate){

    switch(existDate.month){
        
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(existDate.day > 31){
                throw(string("Invalid Day. Day should be between 1 and 31."));
            }
        break;
        
        case 4:
        case 6:
        case 9:
        case 11:
            if(existDate.day > 30){
                throw(string("Invalid Day. Day should be between 1 and 30."));
            }
        break;
            
        case 2:
            if(existDate.year % 4 > 0){
                if(existDate.day > 28){
                    throw(string("Invalid Day. Day should be between 1 and 28."));
                }
            }else if(existDate.year % 4 == 0){
                if(existDate.day > 29){
                    throw(string("Invalid Day. Day should be Between 1 and 29."));
                }
            }
        break;
    
     }
     if(existDate.month > 12 || existDate.month <= 0){
        
        cout << "existDate Month: " << existDate.month << endl;
        throw(string("Invalid month"));
        
     }

     if(existDate.year < 0){
        throw(string("Invalid year"));
        
     }
    
}

void Date::toString(){
    
    if(day != 0){
	    if(day < 10){
		cout << "0";
	    }
	    cout << day << "/";
	    
	    if(month < 10){
		cout << "0";
	    }
	    cout << month << "/" << year << endl;
    }
}

int Date::getDay(){ return day; }
int Date::getMonth(){ return month; };
int Date::getYear() { return year; };

