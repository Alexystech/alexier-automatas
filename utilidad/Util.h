
#ifndef AUTOMATAS_UTIL_H
#define AUTOMATAS_UTIL_H

#include <iostream>
#include <list>
#include <string>

#include "constantes/Variables.h"
#include "constantes/Caracteres.h"
#include "constantes/Key.h"

using namespace std;

class Util {

private:Variables *misVariables = new Variables();
private:Caracteres *misCaracteres = new Caracteres();
private:Key *misKeys = new Key();

public:Util(){}
/**
 * agregar espacios al texto
 * */
public:string agregarEspacios(string textoArchivo) {
    string textEdit = "";
    for (int x = 0; x < textoArchivo.size(); x++) {
        if (textoArchivo.at(x) == '(' || textoArchivo.at(x) == ')' ||
        textoArchivo.at(x) == '+' || textoArchivo.at(x) == '-' ||
        textoArchivo.at(x) == '*' || textoArchivo.at(x) == '/' ||
        textoArchivo.at(x) == '<' || textoArchivo.at(x) == '>' ||
        textoArchivo.at(x) == '=' || textoArchivo.at(x) == ';' ||
        textoArchivo.at(x) == ',' || textoArchivo.at(x) == '{' ||
        textoArchivo.at(x) == '}' || textoArchivo.at(x) == '#' ||
        textoArchivo.at(x) == '"') {
            textEdit = textEdit + " ";
            textEdit = textEdit + textoArchivo.at(x);
            textEdit = textEdit + " ";
            //variable = variable2 + variable3 - variable4 ;
        } else {
            textEdit = textEdit + textoArchivo.at(x);
        }
    }
    return textEdit;
}

/**
 * obtener los tokens
 * */
public:list<string>*tokens(string editText) {
    list<string>*tokens = new list<string>;
    string textoTemporal = "";

        for (int x = 0; x < editText.size(); x++) {
            if (editText.at(x) == '(' || editText.at(x) == ')' ||
                editText.at(x) == '+' || editText.at(x) == '-' ||
                editText.at(x) == '*' || editText.at(x) == '/' ||
                editText.at(x) == '<' || editText.at(x) == '>' ||
                editText.at(x) == '=' || editText.at(x) == ';' ||
                editText.at(x) == ',' || editText.at(x) == '{' ||
                editText.at(x) == '}' || editText.at(x) == '#' ||
                editText.at(x) == '"' || editText.at(x) == ' ') {

                tokens->push_back(textoTemporal);
                textoTemporal = editText.at(x);
                tokens->push_back(textoTemporal);
                textoTemporal = "";

            } else {
                textoTemporal = textoTemporal + editText.at(x);
            }
        }

    return tokens;
}

/**
 * tokens en condiciones para sacar keys
 * */
public:list<string>*subLineTokens(string tokenText) {
    list<string>*newTokens = new list<string>;
    string textoTemporal = "";
    bool firstCharacter = true;
    bool finalInconcluso = false;
    int hitsSaltosLinea = 0;

        for (int x = 0; x < tokenText.size(); x++) {
            if (tokenText.at(x) == '(' || tokenText.at(x) == ')' ||
                tokenText.at(x) == '+' || tokenText.at(x) == '-' ||
                tokenText.at(x) == '*' || tokenText.at(x) == '/' ||
                tokenText.at(x) == '<' || tokenText.at(x) == '>' ||
                tokenText.at(x) == '=' || tokenText.at(x) == ';' ||
                tokenText.at(x) == ',' || tokenText.at(x) == '{' ||
                tokenText.at(x) == '}' || tokenText.at(x) == '#' ||
                tokenText.at(x) == '"' || tokenText.at(x) == ' ' ||
                tokenText.at(x) == misCaracteres->getTokenComillaSimpleChar()) {
                hitsSaltosLinea++;
                if (hitsSaltosLinea > 1) {
                    textoTemporal = tokenText.at(x);
                    newTokens->push_back(textoTemporal);
                    textoTemporal = "";
                } else {
                    if (firstCharacter) {
                        textoTemporal = tokenText.at(x);
                        newTokens->push_back(textoTemporal);
                        textoTemporal = "";
                        firstCharacter = false;
                    } else {
                        newTokens->push_back(textoTemporal);
                        textoTemporal = tokenText.at(x);
                        newTokens->push_back(textoTemporal);
                        textoTemporal = "";
                    }
                }
                finalInconcluso = false;

            } else if (tokenText.at(x) == ' ') {

            } else if (tokenText.at(x) == '\n') {
                hitsSaltosLinea++;
            } else {
                textoTemporal = textoTemporal + tokenText.at(x);
                hitsSaltosLinea = 0;
                firstCharacter = false;
                finalInconcluso = true;
            }
        }
        if (finalInconcluso) {
            newTokens->push_back(textoTemporal);
        }
    return newTokens;
}

/**
 * sacar lineas de codigo independientes
 * */
public:list<string>*lineasCodigo(string textoArchivo) {
    list<string>*lineasCodigo = new list<string>;
    string textoTemporal = "";

        for (int x = 0; x < textoArchivo.size(); x++) {
            if (textoArchivo.at(x) == '\n') {
                lineasCodigo->push_back(textoTemporal);
                textoTemporal = "";
            } else {
                textoTemporal = textoTemporal + textoArchivo.at(x);
            }
        }

    return lineasCodigo;
}

public:list<int>*keyList(string lineaCodigo) {
    list<string>*tokensTemporal = subLineTokens(lineaCodigo);
    list<int>*keys = new list<int>;

    for (string token : *tokensTemporal) {
        if (token == misVariables->getTokenInt()) {
            keys->push_back(misKeys->getKeyInt());
        } else if (token == misVariables->getTokenChar()) {
            keys->push_back(misKeys->getKeyChar());
        } else if (token == misVariables->getTokenFloat()) {
            keys->push_back(misKeys->getKeyFloat());
        } else if (token == misVariables->getTokenDouble()) {
            keys->push_back(misKeys->getKeyDouble());
        } else if (token == misCaracteres->getTokenComillaDoble()) {
            keys->push_back(misKeys->getKeyComillaDoble());
        } else if (token == misCaracteres->getTokenDivicion()) {
            keys->push_back(misKeys->getKeyDivision());
        } else if (token == misCaracteres->getTokenEspacio()) {
            keys->push_back(misKeys->getKeyEspacio());
        } else if (token == misCaracteres->getTokenIgual()) {
            keys->push_back(misKeys->getKeyIgual());
        } else if (token == misCaracteres->getTokenParentesisAbre()) {
            keys->push_back(misKeys->getKeyParentesisAbre());
        } else if (token == misCaracteres->getTokenParentesisCierra()) {
            keys->push_back(misKeys->getKeyParentesisCierre());
        } else if (token == misCaracteres->getTokenPuntoComa()) {
            keys->push_back(misKeys->getKeyPuntoComa());
        } else if (token == misCaracteres->getTokenSuma()) {
            keys->push_back(misKeys->getKeySuma());
        } else if (token == misCaracteres->getTokenResta()) {
            keys->push_back(misKeys->getKeyResta());
        } else if (token == misCaracteres->getTokenMultiplicacion()) {
            keys->push_back(misKeys->getKeyMultiplicacion());
        } else if (token ==misCaracteres->getTokenComillaSimple()) {
            keys->push_back(misKeys->getKeyComillaSimple());
        } else {
            keys->push_back(misKeys->getKeyRandom());
        }

    }

    return keys;
}

public:bool veredictoFinal(list<int>*keyList) {
    bool tieneError = false;

    if (keyList!=NULL)
        tieneError = evaluarLinea(keyList);

    return tieneError;
}

public:bool evaluarLinea(list<int>*keyList) {
    if (keyList->size() < 4)
        return true;
    else if (keyList->size() == 4) {

    }

    return false;
}

};


#endif //AUTOMATAS_UTIL_H
