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
#include <algorithm>   // For std::sort
#include <iostream>
using std::cout;
using std::endl;

// linked list template
// is given pointer in array and an index to look for
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index) {
    auto ptr = head;
    auto count = 0;
    // checks if the index is not in range
    if(index < 0)
        throw std::out_of_range("bad index");

    // get size of the array
    while(ptr != nullptr){
        count++;
        ptr = ptr->_next;
    }

// with the size known, checks again if the index is not in range
    if(index >= count)
        throw std::out_of_range("bad index");

    ptr = head; // return iter to point to head
    count = 0;  // reset count now that we know index is safe

    // iterate through array, return data iter points to
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
std::size_t uniqueCount(RAIter & first,
                        RAIter & last) {
    std::size_t count;
    // check for smallest array scenarios
    if((last - first) == 0) return 0;
    if((last - first) == 1) return 1;

    // after std::sort, std::unique removes all repeated items
    std::sort(first, last);
    // lst points to the last item not removed
    auto lst = std::unique(first, last);
    // returns distance between two iterators
    count = std::distance(first, lst);
    return count;
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

