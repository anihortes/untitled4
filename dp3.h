// dp3.h
// A. Harrison Owen
// Started: 2021-09-17
// Last edit: 2021-09-21
// dp3 header (i do not know what dp3 means)
//      function lookup returns data in array
//      function uniqueCount returns number of unique items in array


#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <algorithm>   // For std::sort, std::unique, std::distance
#include <iostream>
// if iostream is not included,
// "'out_of_range' may be undeclared or unknown" warning is thrown
// on lines 32 and 42

// linked list template
// is given pointer in array and an index to look for
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index) {
    auto ptr = head;
    auto count = 0;
    // checks if the index is not in range
    if(index < 0)
        throw std::out_of_range("bad index. index < array size.");

    // get size of the array
    while(ptr != nullptr){
        count++;
        ptr = ptr->_next;
    }

// with the size known, checks again if the index is not in range
    if(index >= count)
        throw std::out_of_range("bad index. index > array size.");

    ptr = head; // return iter to point to head
    count = 0;  // reset count now that we know the index is safe

    // iterate through array, return data that iter points to
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

// returns number of unique items in an array
// first and last points to indices in an array
template <typename RAIter>
std::size_t uniqueCount(const RAIter & first,
                        const RAIter & last) {
    // after std::sort, std::unique removes all repeated items
    std::sort(first, last);
    // lst points to the last item not removed
    auto lastUnique = std::unique(first, last);
    return lastUnique-first;
}

// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

