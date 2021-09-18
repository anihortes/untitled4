// dp3.h  SKELETON
// Glenn G. Chappell
// 2021-09-16
//
// For CS 311 Fall 2021
// Header for Project 3 functions

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <algorithm>   // For std::sort
#include <iostream>
using std::cout;
using std::endl;


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    auto ptr = head;
    auto data = head;
    auto count=0;

    if(index < 0)
        throw std::out_of_range("bad index");

    while(ptr != nullptr){
        count++;
        ptr = ptr->_next;
    }
    if(index >= count)
        throw std::out_of_range("bad index");

    ptr = head;
    count = 0;
    while(ptr != nullptr){
        if(count == index) {
            return ptr->_data;
        }
        ptr = ptr->_next;
        count++;
    }
    return ptr->_data;
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);


template <typename RAIter>
std::size_t uniqueCount(RAIter & first,
                        RAIter & last)
{
    auto count = 0;
    auto iterOne = first;
    auto iterTwo = first;
    auto size = last - first;
    if(size == 0) return 0;
    if(size == 1) return 1;
    std::sort(first, last);
    auto lst = std::unique(first, last);
    count = std::distance(first, lst);
    return count;
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

