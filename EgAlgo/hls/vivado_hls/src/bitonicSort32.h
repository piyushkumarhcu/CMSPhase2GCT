#ifndef _BITONICSORTIO_H_
#define _BITONICSORTIO_H_


#include <iostream>
#include "ap_int.h"
#include "../../../../include/objects.h"
#define M 32

using namespace std;

typedef ap_uint<6> dloop_t;

class GreaterSmaller{
public:
    Tower greater, smaller;
};

void bitonicSort(Tower in[M], Tower out[M]);

#endif
