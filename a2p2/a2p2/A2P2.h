#pragma once 
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
        : size{ sz }, ptr{ new ET[sz]() }
    {
        for (int i = 0; i != size; ++i) ptr[i] = other[i];
    }
    VecT(VecT && other) noexcept
        : size{ sz }, ptr{ new ET[sz]() }
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
            ptr = new ET[sz]();
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
            ptr = new ET[sz]();
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
    ET& operator[](int) 
    { 
        return ptr[i]; 
    }
    ET const& operator[](int i) const 
    { 
        return ptr[i] 
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