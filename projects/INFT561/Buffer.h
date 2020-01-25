#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

template<typename T>
class Buffer
{
    float* data;
public:
    // destructor
    virtual ~Buffer() { delete[] data; };
    // constructor
    Buffer(const unsigned int& length) { data = new T[length]; };
    // T* cast operator
    operator T* () { return data; };
};

/**************************************************************************************************/