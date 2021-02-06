//
// Created by alexer& on 10/16/2020.
//

#ifndef AUTOMATAS_CUSTOMFILE_H
#define AUTOMATAS_CUSTOMFILE_H
#include <iostream>
#include <fstream>

using namespace std;

class CustomFile {
private:fstream file;
private:string ruta;

public:CustomFile(string ruta){
    this->ruta = ruta;
}

public:string read() {
    string fullText = "";
    file.open(this->ruta,ios::in);
    if ( file.is_open() ) {
        string line;
        while ( getline(file,line) ) {
            fullText = fullText + line +"\n";
        }
        file.close();
    } else {
        cout<<"Archivo no encontrado, verifique la ruta"<<endl;
    }
    return fullText;
}

};


#endif //AUTOMATAS_CUSTOMFILE_H
