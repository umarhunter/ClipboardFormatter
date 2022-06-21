//
// Created by umarhunter on 6/11/2022.
//
#include "CFormat.hpp"
#include <iostream>
#include <cstddef>
#include <vector>
#include <string>
#include <algorithm>

CFormat::CFormat() {
    duplicatestatus = true;
    emptystatus = true;
    sortstatus = false;
    symbolfilter.push_back('"');
    symbolfilter.push_back(' ');
    startprogram();
}

void CFormat::startprogram() {
    askUserSettings(); // user can select from a variety of options to change from
    retrievedVec = retrieveInput();
    checkedEmptyVec = noEmptyElements();
    checkedDuplicatesVec = noMatchingElements();
    printResults();
}

std::vector<std::string> CFormat::retrieveInput() {
    std::string currentline;
    while(getline(std::cin,currentline)){
        if (currentline == "end")
            break;
        retrievedVec.push_back(removeSpaces(currentline)); // store this in a vector so that we can save it in the user clipboard at the completion of the program
    }
    return retrievedVec;
}

std::string CFormat::removeSpaces(std::string line) {
    size_t size = line.size();
    std::string stringwospace; // string without spaces
    for(int index = 0; index < size; index++){
        if(!isspace(line[index]) && line[index] != '"'){
            stringwospace += line[index];
        }
        else{
            foundErrorS.push_back(line); // copies string with errors in vector
            foundErrorN++; // add to total number of errors found
        }
    }
    return stringwospace;
}

std::vector<std::string> CFormat::noEmptyElements() {
    for(int index = 0; index < retrievedVec.size(); index++){
        if(!(retrievedVec[index].size() < 2)) // if the line is empty then omit this
            checkedEmptyVec.push_back(retrievedVec[index]);
    }
    return checkedEmptyVec;
}

std::vector<std::string> CFormat::noMatchingElements() {
    //sort(checkedEmptyVec.begin(), checkedEmptyVec.end()); not really needed but it could be useful
    checkedEmptyVec.erase(unique(checkedEmptyVec.begin(),checkedEmptyVec.end()),checkedEmptyVec.end());
    return checkedEmptyVec;
}

void CFormat::printResults() {
    std::cout << "Clipboard Formatter has compiled successfully. Here are the results:" << std::endl;
    std::cout << "Number of errors found: " << foundErrorN << std::endl;
    for(int index = 0; index < checkedDuplicatesVec.size();index++){
        std::cout << checkedDuplicatesVec[index] << std::endl;
    }
}



