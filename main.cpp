//
//  main.cpp
//  ECInt
//
//  Created by Vincent on 15/1/9.
//  Copyright (c) 2015年 Vincent. All rights reserved.
//

#include <iostream>
#include "ECType.h"


int main(int argc, const char * argv[]) {
    
    
    ec_int16 _value1 = 100;
    ec_int32 _value2 = 0x7fffffff;
    ec_int32 _value3 = 200;
    
    printf("_value1 > _value2 = %d \n", _value1 > _value2);
    printf("_value1 < _value2 = %d \n", _value1 < _value2);
    printf("_value1 * _value3 = %d \n", _value1 * _value3);
    printf("_value1 / _value3 = %d \n", _value3 / _value1);
    
    ec_double _value5 = 0.05;
    printf("_value3 * _value5 = %f \n", _value3 / _value5);
    
    return 0;
}
