


#include "stdafx.h"


template <typename obj>
std::istream& operator>>(std::istream& in, myVector<obj> vec)
{
    
}

template <typename obj>
std::ostream& operator<<(std::ostream& out, myVector<obj>& vec)
{
    out << "vector: ";
    for (uint16_t i = 0; i < vec.size; ++i) { out << vec.vec[i] << " "; }
    out << endl;
    return out;
}
