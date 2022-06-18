//
// Created by umarhunter on 6/17/2022.
//
#include "CFormat.hpp"
#include <iostream>
enum class defaultS{Symbols,Characters,Duplicate,Empty};

void CFormat::askUserSettings(){ // ask the user a variety of questions to suit their needs
    defaultS operation;

    switch(operation) {
        case defaultS::Symbols: {
            std::cout<< "Your current list of symbols is: " << ;
        } break;
        case defaultS::Subtract: {
            return a - b;
        }
        case defaultS::Multiply: {
            return a * b;
        } break;
        case defaultS::Divide: {
            return a / b;
        } break;
    }
}

*/