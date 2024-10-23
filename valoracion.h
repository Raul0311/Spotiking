//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#ifndef VALORACION_H
#define VALORACION_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define GREEN "\033[1;32m"      /* Green */
#define YELLOW "\033[1;33m"      /* Yellow */
#define BLUE "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define CYAN "\033[1;36m"      /* Cyan */
#define WHITE "\033[1;37m"      /* White */
#define RED "\033[1;31m"	/* Red */
#define DEBUG "\033[1;34m"

class Valoracion {
    private:
        string nombre;
        int valoracion;
        bool test;
    public:
        Valoracion();
        Valoracion(const Valoracion &v);

        string getNombre() const;
        int getValoracion() const;
        bool getTest() const;

        void setNombre(const string nombre);
        void setValoracion(const int val);
};

#endif