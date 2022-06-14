//
// Created by Mark on 6/11/2022.
//

#include "CFormat.hpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

CFormat::CFormat() {
    parseVec = retrieveInput();
    std::cout << "Number of errors found: " << foundError1.size();
    for(int index = 0; index < parseVec.size(); index++){
        if(!parseVec[index].size() < 2) // if the line is empty then omit this
            parseEmpty.push_back(parseVec[index]);
    }
    size_t size = parseEmpty.size();
    for(int index = 0; index < size; index++){ // print out the elements of vector
        std::cout << parseEmpty[index] << std::endl;
    }
}

std::vector<std::string> CFormat::retrieveInput() {
    //std::cout << numCells;
    std::string currentline;
    while(getline(std::cin,currentline)){
        //std::cout << "What the string looks like without spaces and '' character: " << removeSpaces(currentline) << std::endl;
        //std::cout << "What the string looks like without special characters: " << removeSpecialCharacters(currentline) << std::endl; // not needed yet
        loadedVec.push_back(removeSpaces(currentline)); // store this in a vector so that we can save it in the user clipboard at the completion of the program
    }
    return loadedVec;
}

std::string CFormat::removeSpaces(std::string line) {
    std::string stringwospace;
    for(int index = 0; index < line.size(); index++){
        if(!isspace(line[index]) && line[index] != '"')
        {
            foundError.push_back(line);
            foundError1.push_back(index); // contains index of error in first line
            stringwospace += line[index];
        }
    }
    return stringwospace;
}
