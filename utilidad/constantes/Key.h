//
// Created by alexier& on 10/16/2020.
//

#ifndef AUTOMATAS_KEY_H
#define AUTOMATAS_KEY_H
#include <iostream>

class Key {

private:const int KEY_INT = 31;
private:const int KEY_CHAR = 32;
private:const int KEY_FLOAT = 33;
private:const int KEY_DOUBLE = 34;

private:const int KEY_SUMA = 1;
private:const int KEY_RESTA = 2;
private:const int KEY_MULTIPLICACION = 3;
private:const int KEY_DIVISION = 4;

private:const int KEY_PARENTESIS_ABRE    = 11;
private:const int KEY_PARENTESIS_CIERRE  = 12;
private:const int KEY_MENOR_QUE          = 13;
private:const int KEY_MAYOR_QUE          = 14;
private:const int KEY_IGUAL              = 15;
private:const int KEY_PUNTO_COMA         = 16;
private:const int KEY_COMA               = 17;
private:const int KEY_LLAVE              = 18;
private:const int KEY_LLAVE_CIERRE       = 19;
private:const int KEY_HASHTAG            = 20;
private:const int KEY_COMILLA_DOBLE      = 21;
private:const int KEY_ESPACIO            = 22;
private:const int KEY_COMILLA_SIMPLE     = 23;

private:const int KEY_RANDOM = 61;

public:Key(){}

public:int getKeyComillaSimple() const {
    return KEY_COMILLA_SIMPLE;
}

public:int getKeyEspacio() const {
    return KEY_ESPACIO;
}

public:int getKeyInt() const {
    return KEY_INT;
}

public:int getKeyChar() const {
    return KEY_CHAR;
}

public:int getKeyFloat() const {
    return KEY_FLOAT;
}

public:int getKeyDouble() const {
    return KEY_DOUBLE;
}

public:int getKeySuma() const {
    return KEY_SUMA;
}

public:int getKeyResta() const {
    return KEY_RESTA;
}

public:int getKeyMultiplicacion() const {
    return KEY_MULTIPLICACION;
}

public:int getKeyDivision() const {
    return KEY_DIVISION;
}

public:int getKeyParentesisAbre() const {
    return KEY_PARENTESIS_ABRE;
}

public:int getKeyParentesisCierre() const {
    return KEY_PARENTESIS_CIERRE;
}

public:int getKeyMenorQue() const {
    return KEY_MENOR_QUE;
}

public:int getKeyMayorQue() const {
    return KEY_MAYOR_QUE;
}

public:int getKeyIgual() const {
    return KEY_IGUAL;
}

public:int getKeyPuntoComa() const {
    return KEY_PUNTO_COMA;
}

public:int getKeyComa() const {
    return KEY_COMA;
}

public:int getKeyLlave() const {
    return KEY_LLAVE;
}

public:int getKeyLlaveCierre() const {
    return KEY_LLAVE_CIERRE;
}

public:int getKeyHashtag() const {
    return KEY_HASHTAG;
}

public:int getKeyComillaDoble() const {
    return KEY_COMILLA_DOBLE;
}

public:int getKeyRandom() const {
    return KEY_RANDOM;
}
};


#endif //AUTOMATAS_KEY_H
