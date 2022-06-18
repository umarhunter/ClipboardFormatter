//
// Created by Mark on 6/11/2022.
//

#ifndef CLIPBOARDFORMATTER_CFORMAT_HPP  // include guards
#define CLIPBOARDFORMATTER_CFORMAT_HPP
#include <cstdio>
#include <vector>
#include <string>

class CFormat {
public:
    CFormat(); // default constructor
    std::vector<std::string> retrieveInput(); // this vector retrieves the users input
    std::vector<std::string> noMatchingElements(); // this vector ensures that there are no matching emails
    std::vector<std::string> noEmptyElements(); // this function returns a vector without empty elements
    std::string removeSpaces(std::string line); // this function returns a vector without spaces
    void printResults(); // prints all the results at the end
private:
    std::vector<std::string> retrievedVec; // resultant vector after
    std::vector<std::string> checkedDuplicatesVec; // resultant vector after checking for duplicates
    std::vector<std::string> checkedEmptyVec; // resultant vector after checking for empty lines
    std::vector<std::string> foundErrorS; // contains the string that had errors
    size_t foundErrorI; // contains the number of space errors in string
};

#endif
