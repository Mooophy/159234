// dVecType.cpp
// Member-function definitions for class VecType

#pragma once 
#include <iostream>
#include <iomanip>
#include <assert.h> 
#include"vect.h"
using namespace std;
void info(){
	cout << "*******************************************" << endl;
	cout << "*     159.234 Assignment 1 - Part 2       *" << endl;
	cout << "*     12086075 , Kuan Liu                 *" << endl;
	cout << "*     13158665 , Yuxiang Zhang            *" << endl;
	cout << "*******************************************" << endl;
}
void err(const char* s){
	cout << s << endl;
	exit(1);
}

ostream &operator<<(ostream &os, const VecType &vecType){//overloading operator "<<"

	for (int i = 0; i < vecType.size; i++){
		os << setw(10) << vecType[i];
		if ((i + 1) % 5 == 0){ os << endl; }
	}
	os << endl;
	return os;
}

istream &operator>>(istream &is, VecType &vecType){//overloading operator ">>"
	for (int i = 0; i < vecType.size; i++)
	{
		is >> vecType[i];
	}
	return is;
}

VecType::VecType(int size){
	if (size < 0){ this->size = 5; }//avoid invalid size
	else{
		this->size = size;
	}
	this->ptr = new ElemType[size];
}

VecType::VecType(const VecType &vecType){// copy constructor
	this->size = vecType.size;
	this->ptr = new ElemType[this->size];
	for (int i = 0; i<size; i++){//deep copy
		ptr[i] = vecType[i];
	}
}

VecType::~VecType(){// destructor
	delete[] ptr;
}

int VecType::getSize() const{// return size
	return this->size;
}

const VecType &VecType::operator=(const VecType &vecType){// assignment operator
	if (this != &vecType){//do nothing if assign to self
		delete[] ptr;
		this->size = vecType.size;
		ptr = new ElemType[this->size];
		for (int i = 0; i<this->size; ++i)
			ptr[i] = vecType[i];
	}
	return *this;
}

bool VecType::operator==(const VecType &vecType) const{// overloading equality operator
	if (this->size != vecType.size){//size equivalent
		return false;
	}
	else{
		for (int j = 0; j < this->size; j++){
			if (ptr[j] != vecType[j]){ return false; }//data equivalent
		}
	}
	return true;
}

bool VecType::operator!=(const VecType &right) const{// overloading non-equality operator
	return !( *this == right );
}

ElemType &VecType::operator[](int i){// subscript operator for non-const objects 
	if ((i >= 0) && (i < size)) return ptr[i];
	else err("ERROR! Out of range. ");
}

ElemType VecType::operator[](int i) const{// subscript operator for const objects 
	if ((i >= 0) && (i < size)) return ptr[i];
	else err("ERROR! Out of range. ");
}