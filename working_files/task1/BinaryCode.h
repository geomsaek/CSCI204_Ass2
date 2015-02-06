/**

Name:		Matthew Saliba
Subject:	CSCI204
Student Num:	3284165
Title:		Binary Code Header file
Descript:	Contains function prototypes used for binary code class

**/

#include<iostream>

struct numList;
typedef numList * nodePtr;

struct numList {
	short int value;
	nodePtr next;	
};

class BinaryCode{
    
    ///////// public functions /////////
    
    public:
    
	BinaryCode();
	BinaryCode(const BinaryCode &);
	BinaryCode(short int, int);
	~BinaryCode();
	
	BinaryCode &operator=(const BinaryCode &);
	BinaryCode &operator~();
	BinaryCode &operator+(const BinaryCode &);
	BinaryCode &operator+=(const BinaryCode &);
	BinaryCode &operator-(BinaryCode &);
	BinaryCode &operator-=(BinaryCode &);
	BinaryCode &operator!();
	BinaryCode &operator*(const BinaryCode &);
	BinaryCode &operator*=(const BinaryCode &);
	
	BinaryCode &operator>>(int);
	BinaryCode &operator<<(int);
        
	friend std::istream& operator>>(std::istream & in, BinaryCode &);
	friend std::ostream& operator<<(std::ostream & out, BinaryCode &);
	friend void checkSign(BinaryCode &, bool);
	
	friend void addVals(bool changeSign, short int *& temp, int loopLength, const BinaryCode &);


	///////// PRIVATE FUNCTIONS /////////
	
    private:
    
	void createNumber(int number, bool & negative, short int *& tempArray, int & count, int &counter, std::string);
	void checkBinary(std::string, int, bool &, bool &);
	void copyArrayToBin(BinaryCode &, short int *& tempArray, int);

	void createBinaryArray(BinaryCode &, bool &, int, std::string);
	void arrangeData(const BinaryCode &, int &, int &, short int *&, short int *&);
	int compareVals(const BinaryCode &);
	void flipGeneral(bool initial, bool carry);

	void createTempArray(short int *&, int, short int *, int );

	void loopList(nodePtr &, int);

	void deleteList(nodePtr &);
	void addListVals(nodePtr &, nodePtr &);
	void copyList(nodePtr &, nodePtr);
	void copyListToArray(nodePtr, int);


	// PRIVATE VALUES
		
	short int * binaryCode;
	int codeLength;
    
};
