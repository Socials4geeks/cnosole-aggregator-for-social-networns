#include "interfaces/interface_basic.h"

InterfaceBasic::InterfaceBasic(){

};

InterfaceBasic::~InterfaceBasic(){

};

void printLoginNecessity() {
    std::cout << termcolor::on_red << "Access violation:"
              << termcolor::reset << " Please, login. Print 'help' for help." << std::endl;
}

int InterfaceBasic::PrintMessages( Response data ){
    printLoginNecessity();
    return 1;
};

int InterfaceBasic::PrintWall( Response data ){
    printLoginNecessity();
    return 1;
};

int InterfaceBasic::PrintFriends( Response data ){
    printLoginNecessity();
    return 1;
};


