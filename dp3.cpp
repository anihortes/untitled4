// dp3.cpp
// A. Harrison Owen
// Started: 2021-09-17
// Last edit: 2021-09-21
// dp3 (i do not know what dp3 means)
//      function didItThrow checks if function throws an error
//      function gcd finds the greatest common factor of two numbers

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;

// error handling function :
// takes a function or object and if it throws an error, threw = true
void didItThrow(const function<void()> & ff,
                bool & threw) {
    try {
        ff();
    }
    catch(...){
        threw = true;
        throw;
    }
    threw = false;
}

// finds the greatest common factor between two ints using recursion
int gcd(int a, int b) {
    // base case
    if(a == 0) return b;
    // recursive cases
    else if(a > b)
        return gcd(b,a);
    else{
        return gcd(b%a,a);
    }
}