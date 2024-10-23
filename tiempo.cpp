//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#include "tiempo.h"

/*CONSTRUCTOR*/
Tiempo::Tiempo() {
    this->test = false;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Tiempo): Creando el Tiempo..." << DEFAULT << endl;
    }

    this->setMinutos(0);
    this->setSegundos(0);

    if(this->getTest() == true) {
        cout << DEBUG << "DEBUG(Tiempo): Tiempo creado correctamente..." << DEFAULT << endl;
	}
}
/*CONSTRUCTOR POR COPIA*/
Tiempo::Tiempo(const Tiempo &t) {
    this->test = t.test;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Tiempo): Creando el Tiempo por Copia..." << DEFAULT << endl;
    }

    this->setMinutos(t.getMinutos());
    this->setSegundos(t.getSegundos());

    if(this->getTest() == true) {
        cout << DEBUG << "DEBUG(Tiempo): Tiempo creado correctamente por Copia..." << DEFAULT << endl;
	}
}
/*DESTRUCTOR*/
Tiempo::~Tiempo() {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Tiempo): Eliminando el Tiempo..." << DEFAULT << endl;
    }

    this->setMinutos(0);
    this->setSegundos(0);

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Tiempo): Tiempo eliminado correctamente..." << DEFAULT << endl;
    }
}
/*GETS*/
int Tiempo::getMinutos() const {
    return this->minutos;
}

int Tiempo::getSegundos() const {
    return this->segundos;
}
bool Tiempo::getTest() const {
    return this->test;
}
/*SETS*/
void Tiempo::setMinutos(const int minutos) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setMinutos): Estableciendo los minutos..." << DEFAULT << endl;
    }
    this->minutos = minutos;
}

void Tiempo::setSegundos(const int segundos) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setSegundos): Estableciendo los segundos..." << DEFAULT << endl;
    }
    this->segundos = segundos;
}
/*SOBRECARGA DE OPERADORES*/
Tiempo Tiempo::operator+(const Tiempo &t) {
    this->test = t.getTest();
    if(this->getTest() == true) {
        cout << DEBUG <<  "Sumando Tiempos con Sobrecarga" << DEFAULT << endl;
    }
    
    int seg;
    seg = (t.getMinutos()*(60/1)) + t.getSegundos();
    seg += (this->getMinutos()*(60/1)) + this->getSegundos();
    this->setMinutos(0);
    this->setSegundos(0);
    this->minutos = seg / 60;
	this->minutos = this->minutos % 60;
	this->segundos = seg % 60;
    this->setMinutos(minutos);
    this->setSegundos(segundos);

    if(this->getTest() == true) {
        cout << DEBUG <<  "Tiempos sumados correctamente con Sobrecarga" << DEFAULT << endl;
    }

    return *this;
}

ostream& operator<<(ostream&flujo, Tiempo &t) {
    if(t.getTest() == true) {
        cout << DEBUG <<  "Imprimiendo Tiempo con Sobrecarga" << DEFAULT << endl;
    }

    flujo << GREEN << t.getMinutos() << ":" << t.getSegundos() << DEFAULT << endl;

    if(t.getTest() == true) {
        cout << DEBUG <<  "Tiempo imprimido correctamente con Sobrecarga" << DEFAULT << endl;
    }

    return flujo;
}
/*MÉTODO ADICIONAL*/
void Tiempo::convertiraMinutosySegundos(int minutos, int segundos) {
    int seg = 0;
    seg = (minutos*(60/1)) + segundos;
    minutos = 0;
    segundos = 0;
    minutos = seg / 60;
	minutos = minutos % 60;
	segundos = seg % 60;
    this->setMinutos(minutos);
    this->setSegundos(segundos);
}