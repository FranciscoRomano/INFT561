/** Dependencies **********************************************************************************/

#include "DepthBuffer.h"

/** Declarations **********************************************************************************/

Depthbuffer::~Depthbuffer()
{
    // free float buffer
    delete[] data;
};

Depthbuffer::Depthbuffer(const unsigned int& w, const unsigned int& h)
{
    // allocate float buffer
    data = new float[(long long)w * h];
};

void Depthbuffer::write(const unsigned int& i, const float& z)
{
    // write to buffer
    data[i] = z;
};

Depthbuffer::operator float* ()
{
    // return data
    return data;
};

/**************************************************************************************************/