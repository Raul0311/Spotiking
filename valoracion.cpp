//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#include "valoracion.h"

Valoracion::Valoracion() {
    this->test = true;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Valoracion): Creando la Valoración..." << DEFAULT << endl;
    }

    this->setNombre("NULL");
    this->setValoracion(0);

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Valoracion): Valoración creada correctamente..." << DEFAULT << endl;
    }
}

Valoracion::Valoracion(const Valoracion &v) {
    this->test = v.getTest();
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Valoracion): Creando la Valoración..." << DEFAULT << endl;
    }

    this->setNombre(v.getNombre());
    this->setValoracion(v.getValoracion());

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Valoracion): Valoración creada correctamente..." << DEFAULT << endl;
    }
}

string Valoracion::getNombre() const {
    return this->nombre;
}

int Valoracion::getValoracion() const {
    return this->valoracion;
}

bool Valoracion::getTest() const {
    return this->test;
}

void Valoracion::setNombre(const string nombre) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setNombre): Estableciendo el nombre de la Valoración..." << DEFAULT << endl;
    }
    this->nombre = nombre;
}

void Valoracion::setValoracion(const int val) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setValoracion): Estableciendo la valoración de la Valoración..." << DEFAULT << endl;
    }
    this->valoracion = val;
}