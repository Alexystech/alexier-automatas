//
// Created by alexier& on 10/16/2020.
//

#ifndef AUTOMATAS_VARIABLES_H
#define AUTOMATAS_VARIABLES_H
#include <string>

using namespace std;

class Variables {

private:const string TOKEN_INT = "int";
private:const string TOKEN_CHAR = "char";
private:const string TOKEN_FLOAT = "float";
private:const string TOKEN_DOUBLE = "double";

public:Variables() {}

public:string getTokenInt() {
    return this->TOKEN_INT;
}

public:string getTokenChar() {
    return this->TOKEN_CHAR;
}

public:string getTokenFloat() {
    return this->TOKEN_FLOAT;
}

public:string getTokenDouble() {
    return this->TOKEN_DOUBLE;
}

};


#endif //AUTOMATAS_VARIABLES_H
