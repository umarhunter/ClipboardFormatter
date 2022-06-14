//
// Created by Mark on 6/11/2022.
//

#ifndef CLIPBOARDFORMATTER_CFORMAT_HPP  // include guards - makes sure headeer
#define CLIPBOARDFORMATTER_CFORMAT_HPP
#include <cstdio>
#include <vector>
#include <string>

class CFormat {
public:
    CFormat(); // default constructor
    //~CFormat(); // destructor not needed since I decided not to go through with dynamic memory
    std::vector<std::string> retrieveInput();
    std::string removeSpaces(std::string line);
    //std::string removeSpecialCharacters(std::string line);

private:
    size_t numCells{0};
    int (*findIndex)[5];
    std::vector<std::string> loadedVec; // the initial loaded vector from user input
    std::vector<std::string> foundError; // contains the string that had errors
    std::vector<std::string> parseVec;
    std::vector<std::string> parseEmpty; // if the elements within parseVec are empty, skip it
    std::vector<size_t> foundError1; // contains the indices of space errors in string
    std::vector<size_t> foundError2; // contains the indices of special character errors in string

};


#endif //CLIPBOARDFORMATTER_CFORMAT_HPP
