#pragma once
#include <iomanip>
#include <iostream>


template<typename ET>
class VecT
{
public:
	//
	// constructors
	//
	VecT(int sz = 5)
		: size{ sz }, ptr{ new ET[sz]() }
	{}
	VecT(VecT const& other)
		: size{ other.getSize() }, ptr{ new ET[other.getSize()]() }
	{
		for (int i = 0; i != size; ++i) ptr[i] = other[i];
	}
	VecT(VecT && other) noexcept
		: size{ other.getSize() }, ptr{ new ET[other.getSize()]() }
	{
		for (int i = 0; i != size; ++i) ptr[i] = std::move(other[i]);
		other.ptr = nullptr;
	}

	//
	// destructor
	//
	~VecT()
	{
		delete[] ptr;
	}

	//
	// operator overloading
	//
	VecT& operator=(VecT const& other)
	{
		if (this->ptr != other.ptr)
		{
			delete[] this->ptr;
			size = other.size();
			ptr = new ET[size]();
			for (int i = 0; i != size; ++i) ptr[i] = std::move(other[i]);
		}
		other.ptr = nullptr;
		return *this;
	}
	VecT& operator=(VecT && other)
	{
		if (this->ptr != other.ptr)
		{
			delete[] this->ptr;
			size = other.size();
			ptr = new ET[size]();
			for (int i = 0; i != size; ++i) ptr[i] = other[i];
		}
	}
	bool operator==(VecT const& other) const
	{
		if (this->size != other.size) return false;
		for (int i = 0; i != size; ++i) if (ptr[i] != other[i]) return false;
		return true;
	}
	bool operator!=(VecT const& other) const
	{
		return !(*this == other);
	}
	ET& operator[](int i) 
	{ 
		return ptr[i]; 
	}
	ET const& operator[](int i) const 
	{ 
		return ptr[i]; 
	};
	//
	// public interfaces
	//
	int getSize() const
	{
		return size;
	}
private:
	//
	// data members
	//
	int size;
	ET* ptr;
};

//
// non member functions 
//
template<typename T>
inline std::istream& operator>>(std::istream& is, VecT<T> & vec)
{
	for(int i = 0; i != vec.getSize(); ++i) is >> vec[i];
	return is;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, VecT<T> const& vec)
{	
	for(int i = 0; i != vec.getSize(); ++i) os << std::setw(10) << vec[i];
	return os << std::endl;
}

void info()
{
	std::cout << "*******************************************" << std::endl;
	std::cout << "*     159.234 Assignment 2 - Part 2       *" << std::endl;
	std::cout << "*     12086075 , Kuan Liu                 *" << std::endl;
	std::cout << "*     13158665 , Yuxiang Zhang            *" << std::endl;
	std::cout << "*******************************************" << std::endl;
}
