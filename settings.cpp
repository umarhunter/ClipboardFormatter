//
// Created by umarhunter on 6/17/2022.
//
#include "CFormat.hpp"
#include <iostream>

void CFormat::askUserSettings() { // ask the user a variety of questions to suit their needs
    int operation;
    std::cout << "LOADING USER SETTINGS....\n"
                 "1. Symbols\n"
                 "2. Characters\n"
                 "3. Duplicate\n"
                 "4. Empty\n"
                 "5. Sort\n"
                 "Enter the number of which setting you'd like to configure (if none, enter a non-setting): ";
    std::cin >> operation;
    switch (operation) {
        case 1: {
            int num = 1;
            char symbolinput;
            std::cout << "LOADING SYMBOL FILTER SETTINGS...\nElements currently in symbols filter list: " << std::endl;
            for (int index = 0; index < symbolfilter.size(); index++) {
                std::cout << index+1 << ". "<< "| " << symbolfilter[index] << " |" << std::endl;
            }
            std::cout << "Would you like to add/remove symbols? Enter y/n: ";
            std::cin >> symbolinput;
            if (symbolinput == 'y')
                config(num);
            else
                std::cout << "EXITING SYMBOLS SETTINGS..." << std::endl;
        } break;
        case 2: {
            int num = 2;
            char characterinput;
            std::cout << "LOADING CHARACTER FILTER SETTINGS...\nElements currently in character filter list: " << std::endl;
            for (int index = 0; index < characterfilter.size(); index++) {
                std::cout << index+1 << ". "<< "| " << characterfilter[index] << " |" << std::endl;
            }
            std::cout << "Would you like to add/remove characters? Enter y/n: ";
            std::cin >> characterinput;
            if (characterinput == 'y')
                config(num);
            else
                std::cout << "EXITING CHARACTER SETTINGS..." << std::endl;
        } break;
        case 3: {
            char dupe;
            std::cout << "FILTER DUPLICATE ELEMENTS IS CURRENTLY SET TO: "; //<< duplicatestatus << std::endl;
            std::cout << "Would you like to switch the status? Enter y/n: ";
            std::cin >> dupe;
            if (dupe == 'y')
                config();
            else
                std::cout << "EXITING CHARACTER SETTINGS..." << std::endl;
        } break;
        case 4: {
            std::cout << "FILTER EMPTY ELEMENTS IS CURRENTLY SET TO: "; //emptystatus << std::endl;
        } break;
        default: {
            std::cout << "EXITING SETTINGS....";
        }
    }
}

void CFormat::config(int s1){ // overloaded function, if this function takes an input it must mean that its
                              // changing either the symbol or character filter
    std::string getinput;
    if(s1 == 1){ // symbols
        std::cout << " ";
    }
    else{ // characters
        std::cout << " ";
    }
}

void CFormat::config(bool s3){ // the other overloaded function
    std::cout << "config bool ran" << std::endl;
}