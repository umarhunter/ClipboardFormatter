//
// Created by umarhunter on 6/11/2022.
//
#include "CFormat.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include <vector>
#include <algorithm>
// we need to include the header file, or else none of these functions will be defined
// we also need all these libraries for our program, some of these must be transferred to other .cpp files


CFormat::CFormat() {
    // constructor will set initial boolean values and automatically load up initial filters.
    // the user will be able to change the settings after program runs
    duplicatestatus = true;
    emptystatus = true;
    sortstatus = false;
    symbolfilter.push_back('"');
    symbolfilter.push_back(' ');
    startprogram(); // starts the rest of the program
}

void CFormat::startprogram() {
    askUserSettings(); // user will be prompted to change conditions in this function
    std::vector<std::string> emptyvec; // just an empty vector which will be used to load input
    std::cout << "\n\n\nPROGRAM HAS INITIALIZED. PLEASE BEGIN ENTERING INPUTS. TYPE 'END' TO TERMINATE OR FEED THE "
    "PROGRAM A TEXT FILE (SAMPLE ALREADY GIVEN) AND IT WILL AUTOMATICALLY TERMINATE." << std::endl;
    std::vector<std::string> retrievedVec = retrieveInput(emptyvec);
    if(emptystatus)
        // if user set this status to true, it will filter out the empty elements/inputs
        retrievedVec = noEmptyElements(retrievedVec);
    if(duplicatestatus)
        // if user set this status to true, it will filter out the duplicate elements/inputs
        retrievedVec = noMatchingElements(retrievedVec);
    printResults(retrievedVec);
    saveFile(retrievedVec);
}

std::vector<std::string> CFormat::retrieveInput(std::vector<std::string> emptyvec) {
    // retrieves the user input and loads corrected version into vector
    std::string currentline;
    while(getline(std::cin,currentline)){
        if (currentline == "end")
            break;
        emptyvec.push_back(removeSpaces(currentline));
        // store this in a vector so that we can save it in the user clipboard at the completion of the program
    }
    return emptyvec;
}

std::string CFormat::removeSpaces(std::string line) { // primary function that actually sorts through the strings
    // instead of "removing" the said element, it just loads the non-targeted elements into a new vector
    size_t size = line.size(); // size of the string
    std::string stringwospace; // string without spaces
    for(int index = 0; index < size; index++){
        if(std::find(symbolfilter.begin(), symbolfilter.end(), line[index]) != symbolfilter.end()){
            foundErrorS.push_back(line); // copies string with errors in vector
            foundErrorN++; // add to total number of errors found
        }
        else if(std::find(symbolfilter.begin(), symbolfilter.end(), line[index]) != symbolfilter.end()){
            foundErrorS.push_back(line); // copies string with errors in vector
            foundErrorN++; // add to total number of errors found
        }
        else{
            stringwospace += line[index];
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
    if(sortstatus) // if user set this to true then it will sort the contents alphabetically
        sort(vec.begin(), vec.end());
    if(duplicatestatus)
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
    return vec;
}

void CFormat::printResults(std::vector<std::string> result) {
    std::cout << "Clipboard Formatter has compiled successfully. Here are the results:" << std::endl;
    std::cout << "Number of errors found: " << foundErrorN << std::endl;
    //size_t size = result.size();
    for(auto index : result){
        std::cout << index << std::endl;
    }
}

void CFormat::saveFile(std::vector<std::string> finalresultVec) {
    std::ofstream outputFile("result.txt");
    for(const auto &index : finalresultVec)
        outputFile << index << "\n";
    std::cout << "SUCCESS. New .txt file has been created in the local directory.";
}

