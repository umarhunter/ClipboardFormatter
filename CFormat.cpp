//
// Created by Mark on 6/11/2022.
//

#include "CFormat.hpp"
#include <iostream>
#include <cstddef>
#include <vector>
#include <string>

CFormat::CFormat() {
    parseVec = retrieveInput();
    std::vector<std::string>checkDuplicateVec = noMatchingElements(parseVec);
    for(int i =0; i < checkDuplicateVec.size();i++){
        std::cout << checkDuplicateVec[i] << std::endl;
    }
    std::cout << "Number of errors found: " << foundError1.size() << std::endl;
    for(int index = 0; index < parseVec.size(); index++){
        if(!(parseVec[index].size() < 2)) // if the line is empty then omit this
            parseEmpty.push_back(parseVec[index]);
    }

    size_t size = parseEmpty.size();
    for(int index = 0; index < size; index++){ // print out the elements of vector
        std::cout << parseEmpty[index] << std::endl;
    }


}

std::vector<std::string> CFormat::retrieveInput() {
    std::string currentline;
    while(getline(std::cin,currentline)){
        loadedVec.push_back(removeSpaces(currentline)); // store this in a vector so that we can save it in the user clipboard at the completion of the program
    }
    return loadedVec;
}

std::vector<std::string> CFormat::noMatchingElements(std::vector<std::string> checkVector) { // ensure that there aren't identical emails, prevent spam mail being sent
    std::vector<std::string> comparisonVec = checkVector; // was kinda surprised C++ allows this -- otherwise I would've needed to manually push_back the elements in a loop
    std::vector<std::string> returnVec; // final vector that we return
    std::vector<std::string> testVec;
    int *data = new int[checkVector.size()];
    size_t size = checkVector.size(); // we don't know how big these vectors may be, standard int may not be a good idea
    //for(int index = 0; index < size; index++){
    for(int index2 = 1; index2 < size; index2++){
        if(checkVector[index2] == checkVector[index2+1]){

        }
    }
    for(int index = 0; index < size; index++){
        if(index != )
            returnVec.push_back(checkVector[index]);
    }
    return returnVec;
}

std::string CFormat::removeSpaces(std::string line) { //
    std::string stringwospace;
    for(int index = 0; index < line.size(); index++){
        if(!isspace(line[index]) && line[index] != '"')
        {
            stringwospace += line[index];
        }
        else{
            foundError.push_back(line); // copies string with errors in vector
            foundError1.push_back(index); // contains total number of errors found
        }
    }
    return stringwospace;
}


