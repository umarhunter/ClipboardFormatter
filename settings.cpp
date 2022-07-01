//
// Created by umarhunter on 6/17/2022.
//

#include "CFormat.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

void CFormat::askUserSettings() { // ask the user a variety of questions to suit their needs
    int loop;
    do {
        loop = 0;
        int operation;
        std::cout << "LOADING USER SETTINGS....\n"
                     "1. Symbols\n"
                     "2. Characters\n"
                     "3. Duplicate\n"
                     "4. Empty\n"
                     "5. Sort\n"
                     "Enter the number of which setting you'd like to configure (to end program, enter any char):"
                  << std::endl;
        std::cin >> operation;
        switch (operation) {
            case 1: { // symbol filter
                char symbolinput;
                std::cout << "LOADING SYMBOL FILTER SETTINGS...\nElements currently in symbols filter list: "
                          << std::endl;
                for (int index = 0; index < symbolfilter.size(); index++) {
                    std::cout << index + 1 << ". " << "| " << symbolfilter[index] << " |" << std::endl;
                }
                std::cout << "Would you like to add/remove symbols? Enter y/n: ";
                std::cin >> symbolinput;
                if (symbolinput == 'y')
                    adjustsymbolfilter();
                else
                    std::cout << "EXITING SYMBOLS SETTING..." << std::endl;
            }
                break;
            case 2: { // character filter
                char characterinput;
                std::cout << "LOADING CHARACTER FILTER SETTINGS...\nElements currently in character filter list:\n";
                for (int index = 0; index < characterfilter.size(); index++) {
                    std::cout << index + 1 << ". " << "| " << characterfilter[index] << " |" << std::endl;
                }
                std::cout << "Would you like to add/remove characters?\nEnter y/n: ";
                std::cin >> characterinput;
                if (characterinput == 'y')
                    adjustcharfilter();
                else
                    std::cout << "EXITING CHARACTER SETTING..." << std::endl;
            }
                break;
            case 3: { // duplicate settings
                char dupe;
                std::cout << "FILTER DUPLICATE ELEMENTS IS CURRENTLY SET TO: " << (duplicatestatus) ? std::cout << " - ON\n" : std::cout << "OFF\n";
                std::cout << "Would you like to switch the status?\n"
                             "Enter y/n: ";
                std::cin >> dupe;
                if (dupe == 'y') {
                    duplicateswitch(duplicatestatus);
                    std::cout << "DUPLICATE STATUS IS CURRENTLY SET TO: " << (duplicatestatus) ? std::cout << " - ON\n" : std::cout << "OFF\n";
                } else {
                    std::cout << "EXITING DUPLICATE ELEMENTS SETTING..." << std::endl;
                }
            }
                break;
            case 4: { // filter empty status
                char check;
                std::cout << "FILTER EMPTY ELEMENTS IS CURRENTLY SET TO: " << (emptystatus) ? std::cout << " - ON\n" : std::cout << "OFF\n";
                std::cout << "\nWould you like to switch the status?\n"
                             "Enter y/n:";
                std::cin >> check;
                if (check == 'y') {
                    emptyswitch(emptystatus);
                    std::cout << "EMPTY STATUS IS CURRENTLY SET TO: " << (emptystatus) ? std::cout << " - OFF\n" : std::cout << "ON\n";
                } else {
                    std::cout << "EXITING EMPTY ELEMENTS SETTING..." << std::endl;
                }
            }
                break;
            case 5: { // sort status
                char check;
                std::cout << "SORTING IS CURRENTLY SET TO: " << (sortstatus) ? std::cout << " - OFF\n" : std::cout << "ON\n";
                std::cout << "Would you like to switch the status? Enter y/n: ";
                std::cin >> check;
                if (check == 'y') {
                    sortswitch(sortstatus);
                    std::cout << "SORT STATUS IS CURRENTLY SET TO: " << (sortstatus) ? std::cout << " - ON\n" : std::cout << "OFF\n";
                } else {
                    std::cout << "EXITING SORTING SETTING..." << std::endl;
                }
            }
                break;
            default: { // no valid input, assume user wants to exit settings
                std::cout << "SAVING AND EXITING SETTINGS....\n";
            }
        }
        char input;
        std::cout << "ADJUST MORE SETTINGS? y/n: ";
        std::cin >> input;
        if (input == 'y' || input == 'Y')
            loop = 1;
    } while (loop == 1);
}

/* SOME OF THESE FUNCTIONS WILL BE REMOVED IF FOUND UNNECESSARY DURING FINAL STAGE */

void CFormat::adjustsymbolfilter() {
    int intinput;
    char symbolinput;
    bool complete = true;
    do{
        std::cout << "\nPlease enter a valid action:\n"
                     "1. Add new symbol to filter\n"
                     "2. Remove a symbol from the filter\n"
                     "3. Exit\n"
                     "Enter a number: ";
        std::cin >> intinput;
    }while(intinput != 1 && intinput != 2 && intinput != 3);
    if(intinput == 1){
        do{
            std::cout << "Please enter a symbol you would like to add:\n";
            std::cin >> symbolinput;
            while(isalpha(symbolinput)) {
                std::cerr << "INVALID INPUT\n";
                std::cout << "Please enter a symbol: " << std::endl;
                std::cin >> symbolinput;
            }
            complete = true;
            if(std::find(symbolfilter.begin(), symbolfilter.end(), symbolinput) != symbolfilter.end()){ // if vector contains symbolinput
                std::cerr << "ERROR: THIS SYMBOL ALREADY EXISTS\n";
                complete = false; // confirm that a matching element has NOT been found within vector
            }
        }while(complete == false);
        symbolfilter.push_back(symbolinput);
        std::cout << "SUCCESS. " << symbolinput << " HAS BEEN SUCCESSFULLY ADDED TO THE FILTER LIST." << std::endl;
        complete = true;
    }
    else if(intinput == 2){
        do{
            std::cout << "Please enter a symbol you would like to remove:\n";
            std::cin >> symbolinput;
            while ((isalpha(symbolinput)) || isdigit(symbolinput)) {
                std::cerr << "ERROR: INVALID INPUT\n";
                std::cout << "Please enter a symbol:\n";
                std::cin >> symbolinput;
            }
            if(std::find(symbolfilter.begin(), symbolfilter.end(), symbolinput) != symbolfilter.end()){ // if vector contains symbolinput
                size_t size = symbolfilter.size();
                std::vector<char> backupsymbolfilter = symbolfilter;
                symbolfilter.clear();
                for(int index = 0; index < size; index++){
                    if(backupsymbolfilter[index] != symbolinput){
                        symbolfilter.push_back(backupsymbolfilter[index]);
                    }
                }
                std::cout << "SUCCESS. " << symbolinput << " HAS BEEN SUCCESSFULLY REMOVED FROM THE FILTER LIST." << std::endl;
                complete = true; // confirm that a matching element has been found and successfully removed within vector
            }
            else{
                std::cerr << "ERROR: THE FILTER DOES NOT CONTAIN SELECTED INPUT\n";
                complete = false;
            }
        }while(complete == false);
    }
    else{
        std::cout << "EXITING....\n";
    }
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
            while(!(isalpha(charinput))) {
                std::cerr << "INVALID INPUT\n";
                std::cout << "Please enter a character: " << std::endl;
                std::cin >> charinput;
            }
            complete = true;
            if(std::find(characterfilter.begin(), characterfilter.end(), charinput) != characterfilter.end()){ // if vector contains charinput
                std::cerr << "ERROR: THIS CHARACTER ALREADY EXISTS\n";
                complete = false; // confirm that a matching element has NOT been found within vector
            }
        }while(complete == false);
        characterfilter.push_back(charinput);
        std::cout << "SUCCESS. " << charinput << " HAS BEEN SUCCESSFULLY ADDED TO THE FILTER LIST." << std::endl;
        complete = true;
    }
    else if(intinput == 2){
        do{
            std::cout << "Please enter a character you would like to remove:\n";
            std::cin >> charinput;
            while (!(isalpha(charinput)) || isdigit(charinput)) {
                std::cerr << "ERROR: INVALID INPUT\n";
                std::cout << "Please enter a character:\n";
                std::cin >> charinput;
            }
            if(std::find(characterfilter.begin(), characterfilter.end(), charinput) != characterfilter.end()){ // if vector contains charinput
                size_t size = characterfilter.size();
                std::vector<char> backupcharfilter = characterfilter;
                characterfilter.clear();
                for(int index = 0; index < size; index++){
                    if(backupcharfilter[index] != charinput){
                        characterfilter.push_back(backupcharfilter[index]);
                    }
                }
                std::cout << "SUCCESS. " << charinput << " HAS BEEN SUCCESSFULLY REMOVED FROM THE FILTER LIST." << std::endl;
                complete = true; // confirm that a matching element has been found and successfully removed within vector
            }
            else{
                std::cerr << "ERROR: THE FILTER DOES NOT CONTAIN SELECTED INPUT\n";
                complete = false;
            }
        }while(complete == false);
    }
    else{
        std::cout << "EXITING....\n";
    }
}

void CFormat::emptyswitch(bool &emptystatus) {
    (emptystatus) ? emptystatus = false : emptystatus = true;
}

void CFormat::sortswitch(bool &sortstatus) {
    (sortstatus) ? sortstatus = false : sortstatus = true;
}

void CFormat::duplicateswitch(bool &duplicatestatus) {
    (duplicatestatus) ? duplicatestatus = false : duplicatestatus = true;
}


