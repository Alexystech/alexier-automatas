//
// Created by alexier& on 10/16/2020.
//

#ifndef AUTOMATAS_CARACTERES_H
#define AUTOMATAS_CARACTERES_H
#include <string>

using namespace std;

class Caracteres {

private:const string TOKEN_IGUAL = "=";
private:const string TOKEN_SUMA = "+";
private:const string TOKEN_RESTA = "-";
private:const string TOKEN_MULTIPLICACION = "*";
private:const string TOKEN_DIVICION = "/";
private:const string TOKEN_PUNTO_COMA = ";";
private:const string TOKEN_PARENTESIS_ABRE = "(";
private:const string TOKEN_PARENTESIS_CIERRA = ")";
private:const string TOKEN_ESPACIO = " ";
private:const string TOKEN_COMILLA_SIMPLE = "'";
    //componer esta parte
private:const char comillaDoble = '"';
private:const string TOKEN_COMILLA_DOBLE = TOKEN_COMILLA_SIMPLE + comillaDoble;

private:const char COMILLA_SIMPLE_CHAR = TOKEN_COMILLA_SIMPLE[0];

public:Caracteres(){}

public:char getTokenComillaSimpleChar() {
    return COMILLA_SIMPLE_CHAR;
}

public:string getTokenComillaSimple() const {
    return TOKEN_COMILLA_SIMPLE;
}

public:string getTokenComillaDoble() const {
    return TOKEN_COMILLA_DOBLE;
}

public:string getTokenIgual() const {
    return TOKEN_IGUAL;
}

public:string getTokenSuma() const {
    return TOKEN_SUMA;
}

public:string getTokenResta() const {
    return TOKEN_RESTA;
}

public:string getTokenMultiplicacion() const {
    return TOKEN_MULTIPLICACION;
}

public:string getTokenDivicion() const {
    return TOKEN_DIVICION;
}

public:string getTokenPuntoComa() const {
    return TOKEN_PUNTO_COMA;
}

public:string getTokenParentesisAbre() const {
    return TOKEN_PARENTESIS_ABRE;
}

public:string getTokenParentesisCierra() const {
    return TOKEN_PARENTESIS_CIERRA;
}

public:string getTokenEspacio() const {
    return TOKEN_ESPACIO;
}

};


#endif //AUTOMATAS_CARACTERES_H
