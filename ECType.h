//
//  ECType.h
//  Encode Data
//
//  Created by vincent
//

#ifndef __ECType__
#define __ECType__

#include <stdio.h>
#include <iostream>

template <class T, class VT=int>
class ECType
{
private:
    T value;
    VT key;
private:
    void MakeKey(size_t size){
        switch (size) {
            case sizeof(int8_t):    key = rand() & 0xff; break;
            case sizeof(int16_t):   key = rand() & 0xffff; break;
            case sizeof(int32_t):   key = rand() & 0xffffffff; break;
            case sizeof(int64_t):   key = rand() & 0xffffffff; key *= 2; break;
            default: abort();
        }
    }
    void Set(T v){
        MakeKey(sizeof(T));
        VT intPtr = *(VT*)(&v) ^ key;
        this->value = *(T*)(&intPtr);
    }
public:
    T Get()  const{
        VT intPtr = *(VT*)(&value) ^ key;
        return *((T*)(&intPtr));
        
    }
    ECType(){
        
    }
    ECType(T value){
        Set(value);
    }
public:
    ECType<T, VT> operator++(){
        ECType<T> retVal = Get();
        Set(Get() + 1);
        return retVal;
    }
    ECType<T, VT> operator++(int v){
        Set(Get() + 1);
        return *this;
    }
    ECType<T, VT> operator--(){
        ECType<T> retVal = Get();
        Set(Get() - 1);
        return retVal;
    }
    ECType<T, VT> operator--(int v){
        Set(Get() - 1);
        return *this;
    }
    ECType<T, VT> operator+=(T i){
        Set(Get() + i);
        return *this;
    }
    template<class OQT>
    ECType<T, VT> operator-=(OQT i){
        Set(Get() - i);
        return *this;
    }
    
    
    template<class EQT>
    bool operator==(EQT i){
        return Get() == i;
    }
    
    template<class EQT>
    bool operator!=(EQT i){
        return Get() != i;
    }
    template<class EQT>
    bool operator<(EQT i){
        return Get() < i;
    }
    template<class EQT>
    bool operator>(EQT i){
        return Get() > i;
    }
    template<class EQT>
    bool operator<=(EQT i){
        return Get() <= i;
    }
    template<class EQT>
    bool operator>=(EQT i){
        return Get() >= i;
    }
    
    operator T() const{
        return Get();
    }
    
};


typedef ECType<int8_t, int8_t> ec_int8;
typedef ECType<int16_t, int16_t> ec_int16;
typedef ECType<int32_t, int32_t> ec_int32;
typedef ECType<int64_t, int64_t> ec_int64;
typedef ECType<float, int32_t> ec_float;
typedef ECType<double, int64_t> ec_double;

typedef ECType<uint8_t, uint8_t> ec_uint8;
typedef ECType<uint16_t, uint16_t> ec_uint16;
typedef ECType<uint32_t, uint32_t> ec_uint32;
typedef ECType<uint64_t, uint64_t> ec_uint64;


#endif
