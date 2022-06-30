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
    void printResults(std::vector<std::string> result); // prints results at the termination of the program
private:
    std::vector<std::string> retrieveInput(std::vector<std::string> emptyvec); // this vector retrieves the users input
    std::vector<std::string> noMatchingElements(std::vector<std::string> vec); // this vector ensures that there are no matching emails
    std::vector<std::string> noEmptyElements(std::vector<std::string> vector); // this function returns a vector without empty elements
    std::string removeSpaces(std::string line); // this function returns a vector without spaces
    void askUserSettings(); // ask the user to select from a variety of settings based off their need
    std::vector<std::string> foundErrorS; // contains the string that had errors
    std::vector<char> symbolfilter; // vector containing filter for symbols
    std::vector<char> characterfilter; // vector containing filter for characters
    size_t foundErrorN = 0; // contains the number of space errors in string
    bool duplicatestatus; // states if duplicates need to be filtered or not
    bool emptystatus; // states if empty cells need to be filtered or not
    bool sortstatus; // states if input should be sorted alphabetically
    void startprogram();
    void emptyswitch(bool &emptystatus);
    void sortswitch(bool &sortstatus);
    void duplicateswitch(bool &duplicatestatus);
    void adjustcharfilter();
    void adjustsymbolfilter();
};

#endif
