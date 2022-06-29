//
// Created by umarhunter on 6/17/2022.
//

#include "CFormat.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

void CFormat::askUserSettings() { // ask the user a variety of questions to suit their needs
    int operation;
    char exit;
    std::cout << "LOADING USER SETTINGS....\n"
                 "1. Symbols\n"
                 "2. Characters\n"
                 "3. Duplicate\n"
                 "4. Empty\n"
                 "5. Sort\n"
                 "Enter the number of which setting you'd like to configure (to end program, enter any char):" << std::endl;
    switch (operation) {
        case 1: { // symbol filter
            char symbolinput;
            std::cout << "LOADING SYMBOL FILTER SETTINGS...\nElements currently in symbols filter list: " << std::endl;
            for (int index = 0; index < symbolfilter.size(); index++) {
                std::cout << index+1 << ". "<< "| " << symbolfilter[index] << " |" << std::endl;
            }
            std::cout << "Would you like to add/remove symbols? Enter y/n: ";
            std::cin >> symbolinput;
            if (symbolinput == 'y')
                adjustsymbolfilter();
            else
                std::cout << "EXITING SYMBOLS SETTING..." << std::endl;
        } break;
        case 2: { // character filter
            char characterinput;
            std::cout << "LOADING CHARACTER FILTER SETTING...\nElements currently in character filter list:\n";
            for (int index = 0; index < characterfilter.size(); index++) {
                std::cout << index+1 << ". "<< "| " << characterfilter[index] << " |" << std::endl;
            }
            std::cout << "Would you like to add/remove characters?\nEnter y/n: ";
            std::cin >> characterinput;
            if (characterinput == 'y')
                adjustcharfilter();
            else
                std::cout << "EXITING CHARACTER SETTING..." << std::endl;
        } break;
        case 3: { // duplicate settings
            char dupe;
            std::cout << "FILTER DUPLICATE ELEMENTS IS CURRENTLY SET TO:" << duplicatestatus << std::endl;
            std::cout << "Would you like to switch the status?\nEnter y/n: ";
            std::cin >> dupe;
            if (dupe == 'y'){
                duplicateswitch(duplicatestatus);
            }
            else {
                std::cout << "EXITING DUPLICATE ELEMENTS SETTING..." << std::endl;
            }
        } break;
        case 4: { // filter empty status
            char check;
            std::cout << "FILTER EMPTY ELEMENTS IS CURRENTLY SET TO: " << emptystatus << std::endl;
            std::cout << "Would you like to switch the status?\nEnter y/n: ";
            std::cin >> check;
            if(check == 'y'){
                emptyswitch(emptystatus);
            }
            else{
                std::cout << "EXITING EMPTY ELEMENTS SETTING..." << std::endl;
            }
        } break;
        case 5: { // sort status
            char check;
            std::cout << "SORTING IS CURRENTLY SET TO: " << sortstatus << std::endl;
            std::cout << "Would you like to switch the status? Enter y/n: ";
            std::cin >> check;
            if(check == 'y'){
                sortswitch(sortstatus);
            }
            else{
                std::cout << "EXITING SORTING SETTING..." << std::endl;
            }
        } break;
        default: { // no valid input, assume user wants to exit settings
            std::cout << "SAVING AND EXITING SETTINGS....\n";
        }
    }
}

/* SOME OF THESE FUNCTIONS WILL BE REMOVED IF FOUND UNNECESSARY DURING FINAL STAGE */
void CFormat::emptyswitch(bool emptystatus) {
    (emptystatus) ? emptystatus = false : emptystatus = true;
}

void CFormat::sortswitch(bool sortstatus) {
    (sortstatus) ? sortstatus = false : sortstatus = true;
}

void CFormat::duplicateswitch(bool duplicatestatus) {
    (duplicatestatus) ? duplicatestatus = false : duplicatestatus = true;
}

void CFormat::adjustcharfilter() {
    int intinput;
    char charinput;
    bool complete = true;
    do{
        std::cout << "\nPlease enter a valid action:\n"
                     "1. Add new character to filter\n"
                     "2. Remove a character from the filter\n"
                     "3. Exit\n"
                     "Enter a number: ";
        std::cin >> intinput;
    }while(intinput != 1 && intinput != 2 && intinput != 3);
    if(intinput == 1){
        do{
            std::cout << "Please enter a character you would like to add:\n";
            std::cin >> charinput;
            while (!(isalpha(charinput))) {
                std::cout << "Invalid input!\nPlease enter a character:\n";
                std::cin >> charinput;
            }
            if(std::find(std::begin(characterfilter), std::end(characterfilter), charinput) == std::end(characterfilter)){
                std::cout << "ERROR: This character already exists.\n";
                complete = false; // confirm that a matching element has been found within vector
            }
        }while(complete == false);
        characterfilter.push_back(charinput);
        complete = true;
    }
    else if(intinput == 2){
        do{
            std::cout << "Please enter a character you would like to remove:\n";
            std::cin >> charinput;
            while (!(isalpha(charinput))) {
                std::cout << "Invalid input!\nPlease enter a character:\n";
                std::cin >> charinput;
            }
            if(!(std::find(std::begin(characterfilter), std::end(characterfilter), charinput) == std::end(characterfilter))){
                std::cout << "ERROR: This character does not exist!\n";
                complete = false; // confirm that a matching element has been found within vector
            }
        }while(complete == false);
        characterfilter.push_back(charinput);
    }
    else{
        std::cout << "EXITING....\n";
    }
}

void CFormat::adjustsymbolfilter() {
    int intinput;
    char symbolinput;
    bool complete = true;
    do{
        std::cout << "\nPlease enter a valid action:\n"
                     "1. Add new character to filter\n"
                     "2. Remove a character from the filter\n"
                     "3. Exit\n"
                     "Enter a number: ";
        std::cin >> intinput;
    }while(intinput != 1 && intinput != 2 && intinput != 3);
    if(intinput == 1){
        do{
            std::cout << "Please enter a symbol you would like to add:\n";
            std::cin >> symbolinput;
            while (!(isalpha(symbolinput))) {
                std::cout << "Invalid input!\nPlease enter a character:\n";
                std::cin >> symbolinput;
            }
            if(std::find(std::begin(characterfilter), std::end(characterfilter), symbolinput) == std::end(characterfilter)){
                std::cout << "ERROR: This character already exists.\n";
                complete = false; // confirm that a matching element has been found within vector
            }
        }while(complete == false);
        symbolfilter.push_back(symbolinput);
        complete = true;
    }
    else if(intinput == 2){
        do{
            std::cout << "Please enter a character you would like to remove:\n";
            std::cin >> symbolinput;
            while (!(isalpha(symbolinput))) {
                std::cout << "Invalid input!\nPlease enter a character:\n";
                std::cin >> symbolinput;
            }
            if(!(std::find(std::begin(symbolfilter), std::end(symbolfilter), symbolinput) == std::end(symbolfilter))){
                std::cout << "ERROR: This character does not exist!\n";
                complete = false; // confirm that a matching element has been found within vector
            }
        }while(complete == false);
        symbolfilter.push_back(symbolinput);
    }
    else{
        std::cout << "EXITING....\n";
    }
}

