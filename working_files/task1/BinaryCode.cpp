/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Binary Code Func Defs
Descript:	Contains function definitions for binary code class

**/

#include<iostream>
#include<sstream>
#include<cstdlib>
#include "BinaryCode.h"

BinaryCode::BinaryCode(){
    
    binaryCode = NULL;
    codeLength = 0;
}

BinaryCode::BinaryCode(const BinaryCode & exist){

    if(codeLength > 0 || binaryCode != NULL){
        codeLength = 0;
        delete [] binaryCode;
        binaryCode = NULL;
    }
    
    binaryCode = new short int[exist.codeLength];
    
    for(int i = 0; i < exist.codeLength; i++){
       binaryCode[i] = exist.binaryCode[i];    
    }
    
}

BinaryCode::~BinaryCode(){
	
	if(codeLength > 0){
		delete [] binaryCode;
		codeLength = 0;
	}

}

BinaryCode & BinaryCode::operator=(const BinaryCode & exist){
	
	if(this == &exist){
		return *this;
	}

	if(this->binaryCode != NULL){
		delete [] this->binaryCode;
		this->binaryCode = NULL;
	}

	codeLength = exist.codeLength;
	binaryCode = new short int[exist.codeLength];
	
	for(int i = 0; i < exist.codeLength; i++){
		this->binaryCode[i] = exist.binaryCode[i];
	}

	return *this;
}



std::istream &operator >> (std::istream& in, BinaryCode & currentObject){
    
	std::string tempString = "";
	int counter =0;
	long int number = 0;
	bool negative = false, notBin = false, binPositive = true;

	std::cout << "Enter Number: ";
	getline(std::cin, tempString);

	int numLength = tempString.length();
	short int * tempArray = NULL;
	int count = 0;

	currentObject.checkBinary(tempString, numLength, notBin, binPositive);

	number = atoi(tempString.c_str());

	if(number != 0 && notBin){
		currentObject.createNumber(number, negative, tempArray, count, counter, tempString);
		currentObject.copyArrayToBin(currentObject, tempArray, count);

		if(negative){
		    ~currentObject;
		    checkSign(currentObject, false);
		}else {
		    checkSign(currentObject, true);
		}
	}else if(number == 0){
		currentObject.codeLength = 0;
		currentObject.binaryCode = new short int[1];
		currentObject.binaryCode[0] = 0;
	}else{
		currentObject.createBinaryArray(currentObject, binPositive, numLength, tempString);
		
		if(!binPositive){
		    ~currentObject;
		    checkSign(currentObject, false);
		}else {
		    checkSign(currentObject, true);
		}
		
	}
	return in;
    
}

void BinaryCode::createNumber(int number, bool & negative, short int *& tempArray, int & count, int &counter, std::string tempString){

	bool finish = false;
	int mod = 0;
	if(number < 0){
	    number = number * -1;
	    negative = true;
	}
	
	tempArray = new short int[tempString.length()];

	while(finish == false){
	    
	    if(number / 2 != 0){
		mod = number % 2;
		tempArray[count] = mod;
		count = count + 1; 
		number = number /2;
	    }else {
		finish = true;
	    }
	    counter = counter + 1;
	}

	tempArray[count] = number;
	count = count + 1;

	if(count < 5){
	    tempArray[count] = 0;
	    count = count + 1;
	}
}

void BinaryCode::createBinaryArray(BinaryCode & currentObject, bool & binPositive, int numLength, std::string tempString){

	int arrayCount = 0;
	int k = 0;

	if(!binPositive){
		currentObject.binaryCode = new short int[numLength -1];
		currentObject.codeLength = numLength -1;	
		k = 1;		
	}else {
		currentObject.binaryCode = new short int[numLength];
		currentObject.codeLength = numLength;
		k = 0;
	}

	for(; k < numLength; k++){
		std::stringstream ss;
		ss << tempString[k];
		ss >> currentObject.binaryCode[arrayCount];
		arrayCount = arrayCount + 1;
	}

}

void BinaryCode::copyArrayToBin(BinaryCode & currentObject, short int *& tempArray, int count){

	int nativeCount = 0;
	currentObject.binaryCode = new short int[count];

	int countDown = count-1;

	for(int k = 0; k < count; k++){

		currentObject.binaryCode[k] = tempArray[countDown];	
		nativeCount  = nativeCount + 1;
		countDown = countDown-1;
	}

	delete [] tempArray;
	tempArray = NULL;

	currentObject.codeLength = nativeCount;
}


void BinaryCode::checkBinary(std::string tempString, int numLength, bool & notBin, bool & binPositive){
	for(int i = 0; i < numLength; i++){
		if(!(tempString[i] == '1' || tempString[i] == '0' || tempString[i] == '-')){
			notBin = true;
		}
		if(tempString[i] == '-'){
			binPositive = false;
		}
	}
}

std::ostream&operator<<(std::ostream &out, BinaryCode & object){
    
    if(object.codeLength > 0){
        for(int i =  0; i < object.codeLength;i++){
            out << object.binaryCode[i];
        }
    }else {
        out << 0;
    }
    
    return out;
}

BinaryCode & BinaryCode::operator~(){
 
    bool initial = true;
    bool carry = true;
    
    flipGeneral(initial, carry);
    
    return *this;
}

BinaryCode & BinaryCode::operator!(){

	bool initial = false;
	bool carry = false;
	
	flipGeneral(initial, carry);
	
	return *this;
}

void BinaryCode::flipGeneral(bool initial, bool carry){
	
	
    for(int i = codeLength; i >= 0; i--){

        if(binaryCode[i] == 0){
            binaryCode[i] = 1;
        }else {
            binaryCode[i] = 0;
        }
        
        if(carry){
            if(binaryCode[i] == 1){
                binaryCode[i] = 0;
                carry = true;
            }else {
                binaryCode[i] = 1;
                carry = false;
            }
        }
        
        if(initial){
            
            if(binaryCode[i] == 1){
                binaryCode[i] = 0;
                carry = true;
            }else if(binaryCode[i] == 0){
                binaryCode[i] = 1;
            }
            initial = false;
        }
    }
}

BinaryCode & BinaryCode::operator+(const BinaryCode & exist){
    
   int longLength = 0, shortLength = 0;
    short int * longPtr= NULL, * shortPtr = NULL, * tempArray = NULL;
	
    int valOne = 0, valTwo = 0, sum = 0;
    bool carry = false, positive = false;
    
    arrangeData(exist, longLength, shortLength, longPtr, shortPtr);
    
    tempArray = new short int[longLength];
    int shortCount = 0;
    int shortPointCount = shortLength-1;

    for(int i = longLength-1; i >= 0 ; i--){

		valOne = longPtr[i];
		
		if(shortCount < shortLength){
			valTwo = shortPtr[shortPointCount];
		}else{
			valTwo = 0;
		}
		
		sum = valOne + valTwo;
		
		if(carry){
			sum = sum + 1;
			carry = false;
		}
		

		if(sum > 1){
			carry = true;
			switch(sum){
				
				case 2:
					sum = 0;
				break;
				
				case 3:
					sum = 1;
				break;
			}
		}
		
		
		tempArray[i] = sum;
		
		shortCount = shortCount + 1;
		shortPointCount = shortPointCount-1;

		if(carry && i == 0){
			sum = 1;
		}
    }
    
    delete [] binaryCode;
    binaryCode = NULL;
    
    if(carry){
    	longLength = longLength + 1;
    }
    else if(longPtr[0] == 0 && shortPtr[0] == 0){
		longLength = longLength + 1;
		positive = true;
    }
    
    
    int tempCounter = 0;
    binaryCode = new short int[longLength];
    for(int k = 0; k < longLength;k++){
    	
    	if(carry){
    		if(k==0){
    			binaryCode[k]= 1;
    		}else {
    			binaryCode[k] = tempArray[tempCounter];
	    		tempCounter++;
    		}
    	}
    	else if(positive){
    		if(k == 0){
	    		binaryCode[k]= 0;
	    	}else{
	    		 binaryCode[k] = tempArray[tempCounter];
	    		 tempCounter++;
	    	}
    	}
    	else{
		    binaryCode[k] = tempArray[k];
		}
	    
    }
    
    delete [] tempArray;
    tempArray = NULL;
    codeLength = longLength;
    
    return *this;
    
}

void BinaryCode::arrangeData(const BinaryCode & exist, int & longLength, int & shortLength, short int *& longPtr, short int *& shortPtr){
	
	int greater = 0;
	
	if(exist.codeLength > codeLength){
        longPtr = exist.binaryCode;
        shortPtr = binaryCode;
        
        longLength = exist.codeLength;
        shortLength = codeLength;

    }else if(exist.codeLength < codeLength){
        
        longPtr = binaryCode;
        shortPtr = exist.binaryCode;
        
        longLength = codeLength;
        shortLength = exist.codeLength;
        
    }else {
        
        greater = compareVals(exist);

		switch(greater){
			case 0:
			case 1:
				longLength = codeLength;
				shortLength = exist.codeLength;
				
        		longPtr = binaryCode;
		        shortPtr = exist.binaryCode;
				
			break;
			
			case 2:
				
				longPtr = exist.binaryCode;
				shortPtr = binaryCode;
		
				longLength = exist.codeLength;
		        shortLength = codeLength;
			break;
		}
    }
}

BinaryCode & BinaryCode::operator+=(const BinaryCode & exist){

	*this = *this + exist;

	return *this;
}

BinaryCode & BinaryCode::operator-(BinaryCode & exist){
	
	exist = ~exist;
	*this = *this + exist;
	
	return *this;
	
}

BinaryCode & BinaryCode::operator-=(BinaryCode & exist){

	exist = ~exist;
	*this = *this + exist;
	
	return *this;
}

BinaryCode & BinaryCode::operator*(const BinaryCode & exist){
	
	int mainLength = (codeLength + exist.codeLength);
	int diffNative = mainLength - codeLength;
	int diffExist = mainLength - exist.codeLength;
	
	short int * tempNative = new short int[mainLength];
	short int * tempExist = new short int[mainLength];
	
	nodePtr listMultiply = NULL;
	nodePtr mainHold = NULL;

	int valOne = 0, valTwo = 0, multiplyFinal = 0, zeroCount = 0;
	bool addStartZero = true;

	createTempArray(tempNative, diffNative, this->binaryCode, this->codeLength);
	createTempArray(tempExist, diffExist, exist.binaryCode, exist.codeLength);
	
	for(int i = mainLength-1; i >=0; i--){
		
		
		valOne = tempNative[i];
		
		for(int k = mainLength-1; k >= 0; k--){
			
			valTwo = tempExist[k];
			if(addStartZero){
				if(zeroCount > 0){
				
					for(int z = 0; z < zeroCount; z++){
						loopList(listMultiply, 0);
					}
				}
				addStartZero = false;
			}

			multiplyFinal = valOne * valTwo;
			loopList(listMultiply, multiplyFinal);
			
		}

		if(mainHold == NULL){
			copyList(mainHold, listMultiply);
		}else {
			addListVals(mainHold, listMultiply);
		}
		deleteList(listMultiply);

		addStartZero = true;
		
		zeroCount = zeroCount + 1;
		
	}


	copyListToArray(mainHold, mainLength);
	deleteList(mainHold);
	
	return *this;
}

BinaryCode & BinaryCode::operator*=(const BinaryCode & exist){
	
	*this = *this * exist;
	return *this;
}

void BinaryCode::copyListToArray(nodePtr listToCopyFrom, int newSize){

	int innerCount = 0;
	int counter = 0;
	int storeVal = 0;

	int listLength = 0;
	int innerTrack = 0;

	this->codeLength = 10;
	delete [] this->binaryCode;
	this->binaryCode = NULL;
	int arrayIndex = 9;


	this->binaryCode = new short int [10];
	
	nodePtr curCount = listToCopyFrom;

	while(curCount->next != NULL){
		curCount = curCount->next;
		listLength = listLength + 1;
	}

	while(counter < 10){
		nodePtr cur = listToCopyFrom;

		while(cur->next != NULL){
			if(innerTrack == innerCount){
				storeVal = cur->value;
			}
			cur = cur->next;
			innerCount = innerCount +1;
		}
		innerTrack = innerTrack + 1;
		this->binaryCode[arrayIndex] = storeVal;
		arrayIndex = arrayIndex -1;
		innerCount = 0;
		counter = counter + 1;
	}
}

void BinaryCode::loopList(nodePtr & list, int addValue){
	
	nodePtr temp = new numList;
	temp->value = addValue;
	temp->next = NULL;

	if(list == NULL){
		list = temp;
	}else {
		nodePtr cur = list;
		while(cur->next != NULL){
			cur = cur->next;	
		}
		cur->next = temp;
		temp = list;
	}

}

void BinaryCode::deleteList(nodePtr & list){

	nodePtr tmp;

	while(list != NULL){
		tmp = list;
		list = list->next;
		delete tmp;
	}
	delete list;
	list = NULL;
}

void BinaryCode::addListVals(nodePtr & existStore, nodePtr & newValsToAdd){

	nodePtr curExist = existStore;
	nodePtr curNew = newValsToAdd;

	nodePtr tempStore = NULL;
	int existVal = 0, newVal = 0, sum = 0;
	bool carry = false, listLoopEnd = false, existEnd = false, newEnd = false;

	while(listLoopEnd == false){

		if(carry){
			sum = sum + 1;
			carry = false;
		}

		existVal = curExist->value;
		
		newVal = curNew->value;
		
		sum = sum + existVal + newVal;

		if(sum > 1){
			switch(sum){
				case 2:
					sum = 0;
				break;
	
				case 3:
					sum =1;
				break;
			}
			carry = true;
		}

		loopList(tempStore, sum);

		if(curExist->next == NULL){
			existEnd = true;
		}else {
			curExist = curExist->next;
		}

		if(curNew->next == NULL){
			newEnd = true;
		}else {
			curNew = curNew->next;
		}

		if(existEnd && newEnd){
			listLoopEnd = true;
		}
		if(listLoopEnd && carry){
			loopList(tempStore, sum);
		}
		sum = 0;
		
	}

	deleteList(existStore);
	copyList(existStore, tempStore);
	deleteList(tempStore);
}

void BinaryCode::copyList(nodePtr & mainList, nodePtr copyFrom){
	
	int copyVal = 0;

	while(copyFrom->next != NULL){
		copyVal = copyFrom->value;
		loopList(mainList, copyVal);
		copyFrom = copyFrom->next;
	}
}


void BinaryCode::createTempArray(short int *& tempPointer, int diffLength, short int * copyFrom, int copyFromLength){

	int shortCount = 0;
	bool initial = true;
	
	for(int i = 0; i < copyFromLength; i++){
		
		if(initial){
			for(int k = 0; k < diffLength; k++){
				tempPointer[shortCount] = copyFrom[0];
				shortCount = shortCount + 1;
			}
			initial = false;
		}
		tempPointer[shortCount] = copyFrom[i];
		shortCount = shortCount + 1;

	}
}

int BinaryCode::compareVals(const BinaryCode & exist){
    
    int counter = 0;
    bool finish = false;
    
    int valOne = 0, valTwo = 0;
    
    int valOneCount = 0, valTwoCount = 0;
    bool oneFinish = false, twoFinish = false;
    
    
    while(finish == false){
        
        if(counter < codeLength){
            valOne = binaryCode[counter];
        }else {
		oneFinish = true;
        }
        
        if(counter < exist.codeLength){
            valTwo = exist.binaryCode[counter];
        }else {
		twoFinish = true;
        }
        
        if(!(oneFinish && twoFinish)){

        	if(valOne > valTwo){
        		valOneCount = valOneCount + 1;
        	}else if(valOne < valTwo){
        		valTwoCount = valTwoCount + 1;
        	}else{
        		valOneCount = valOneCount + 1;
        		valTwoCount = valTwoCount + 1;
        	}
        }else {
        	if(oneFinish){
        		valTwoCount = valTwoCount + 1;
			}
			if(twoFinish){
				valOneCount = valOneCount + 1;
			}
        }
        
        if(oneFinish && twoFinish){
        	finish = true;
        }
        counter= counter + 1;
    }
    
	if(valOneCount > valTwoCount){
		return 1;
	}else if(valTwoCount > valOneCount){
		return 2;
	}else {
		return 0;
	}
	
	return 0;
}


BinaryCode & BinaryCode::operator<<(int shift){
	
	if(shift > 0){

		int tempLength = this->codeLength + shift;
		short int * temp = new short int[tempLength];

		for(int k = 0; k < tempLength; k++){
			if(k >= codeLength){
				temp[k] = 0;
			}else {
				temp[k] = binaryCode[k];
			}
		}
		codeLength = tempLength;
		delete [] this->binaryCode;
		binaryCode = NULL;
	
		binaryCode = new short int[tempLength];

		for(int i = 0; i < codeLength; i++){
			binaryCode[i] = temp[i];
		}
	}
	
		return *this;
}

BinaryCode & BinaryCode::operator>>(int shift){
	
	int shiftCount = 0;
	int reduceCount = this->codeLength;
	short int * temp = NULL;

	if(shift > 0){
		for(int i = this->codeLength -1;i >= 0; i--){
			
			if(shiftCount < shift){
				this->binaryCode[i] = 5;
				reduceCount = reduceCount -1;
				
			}
			shiftCount = shiftCount + 1;
		}

		if(reduceCount != this->codeLength){
			temp = new short int[reduceCount];
			int startTempCount = reduceCount -1;

			for(int k = this->codeLength -1;k >= 0; k--){
				if(this->binaryCode[k] != 5){
					temp[startTempCount] = this->binaryCode[k];
					startTempCount = startTempCount - 1;
				}
			}

			delete [] this->binaryCode;
			this->binaryCode = NULL;
			this->binaryCode = new short int[reduceCount];
			for(int c = 0; c < reduceCount; c++){
				this->binaryCode[c] = temp[c];
			}
			this->codeLength = reduceCount;
		}else {
			delete [] this->binaryCode;
			this->codeLength = 0;
		}
		
	}

	return *this;
}

void checkSign(BinaryCode & currentObject, bool sign){
	
	short int * temp = NULL;
	int loopLength = currentObject.codeLength + 1;
	bool changeSign = false;

	if(sign == false){
		if(currentObject.binaryCode[0] != 1){
			temp = new short int[loopLength];
			addVals(false, temp, loopLength, currentObject);
			changeSign = true;
		}
	}else {
		if(currentObject.binaryCode[0] != 0){
			temp = new short int[loopLength];
			addVals(true, temp, loopLength, currentObject);
			changeSign = true;
		}
	}
	
	if(changeSign){
		delete [] currentObject.binaryCode;
		currentObject.binaryCode = NULL;
		currentObject.binaryCode = new short int[loopLength];

		for(int i = 0; i < loopLength;i++){
			currentObject.binaryCode[i] = temp[i];
		}
		currentObject.codeLength = loopLength;
	}
	
}



void addVals(bool changeSign, short int *& temp, int loopLength, const BinaryCode & currentObject){

	int indexCount = 0;

	for(int i = 0; i < loopLength; i ++){
		if(i == 0){
			if(changeSign == false){
				temp[i] = 1;
			}else {
				temp[i] = 0;
			}
		}else {
			temp[i] = currentObject.binaryCode[indexCount];
			indexCount = indexCount + 1;
		}
	}
}

