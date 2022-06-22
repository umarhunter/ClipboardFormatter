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
    std::vector<std::string> retrievedVec = retrieveInput();
    if(emptystatus)
        std::vector<std::string> checkedEmptyVec = noEmptyElements(retrievedVec);

    std::vector<std::string> checkedDuplicatesVec = noMatchingElements(checkedEmptyVec);
    printResults(checkedDuplicatesVec);
}

std::vector<std::string> CFormat::retrieveInput() {
    std::string currentline;
    std::vector<std::string> retrievedVec;
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

std::vector<std::string> CFormat::noEmptyElements(std::vector<std::string> vec) {
    std::vector<std::string> vec2;
    for(int index = 0; index < vec.size(); index++){
        if(!(vec[index].size() < 2)) // if the line is empty then omit this
            vec2.push_back(vec[index]);
    }
    return vec2;
}

std::vector<std::string> CFormat::noMatchingElements(std::vector<std::string> vec) {
    if(sortstatus)
        sort(vec.begin(), vec.end()); // if user changed settings to sort alphabetically
    if(duplicatestatus)
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
    return vec;
}

void CFormat::printResults(std::vector<std::string> result) {
    std::cout << "Clipboard Formatter has compiled successfully. Here are the results:" << std::endl;
    std::cout << "Number of errors found: " << foundErrorN << std::endl;
    size_t size = result.size();
    for(int index = 0; index < size; index++){
        std::cout << result[index] << std::endl;
    }
}



