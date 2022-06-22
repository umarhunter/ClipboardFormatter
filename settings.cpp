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
                std::cout << "EXITING SYMBOLS SETTING..." << std::endl;
        } break;
        case 2: {
            int num = 2;
            char characterinput;
            std::cout << "LOADING CHARACTER FILTER SETTING...\nElements currently in character filter list: " << std::endl;
            for (int index = 0; index < characterfilter.size(); index++) {
                std::cout << index+1 << ". "<< "| " << characterfilter[index] << " |" << std::endl;
            }
            std::cout << "Would you like to add/remove characters? Enter y/n: ";
            std::cin >> characterinput;
            if (characterinput == 'y')
                config(num);
            else
                std::cout << "EXITING CHARACTER SETTING..." << std::endl;
        } break;
        case 3: {
            char dupe;
            std::cout << "FILTER DUPLICATE ELEMENTS IS CURRENTLY SET TO: " << duplicatestatus << std::endl;
            std::cout << "Would you like to switch the status? Enter y/n: ";
            std::cin >> dupe;
            if (dupe == 'y'){
                duplicateswitch(duplicatestatus);
            }
            else {
                std::cout << "EXITING DUPLICATE ELEMENTS SETTING..." << std::endl;
            }
        } break;
        case 4: {
            char check;
            std::cout << "FILTER EMPTY ELEMENTS IS CURRENTLY SET TO: " << emptystatus << std::endl;
            std::cout << "Would you like to switch the status? Enter y/n: ";
            std::cin >> check;
            if(check == 'y'){
                emptyswitch(emptystatus);
            }
            else{
                std::cout << "EXITING EMPTY ELEMENTS SETTING..." << std::endl;
            }

        } break;
        case 5: {
            char check;
            std::cout << "SORTING IS CURRENTLY SET TO: " << sortstatus << std::endl;
            std::cout << "Would you like to switch the status? Enter y/n: ";
            if(check == 'y'){
                sortswitch(sortstatus);
            }
            else{
                std::cout << "EXITING SORTING SETTING..." << std::endl;
            }
        }
        default: {
            std::cout << "SAVING AND EXITING SETTINGS....";
        }
    }
}

