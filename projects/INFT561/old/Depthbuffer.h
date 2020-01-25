#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

class Depthbuffer
{
    float* data;
    unsigned int size;
public:

    // destructor
    virtual ~Depthbuffer();

    // constructor
    Depthbuffer(const unsigned int& length);

    // float* cast operator
    operator float* ();
};

/**************************************************************************************************/