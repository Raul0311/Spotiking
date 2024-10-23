//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#ifndef ARTISTA_H
#define ARTISTA_H

#include <iostream>
#include <string>
#include "cancion.h"
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

class Cancion;

class Artista {
    private:
        unsigned int id;
        string nombre;
        Cancion** canciones;
        int util_canciones;
        int total_inclusiones;
        double media_valoracion;
        bool test;
        /*--------MÉTODO ADICIONAL--------*/
        void resize(int tamanio_nuevo);
    public:
        Artista();
        Artista(const Artista &a);
        ~Artista();
        /*--------GETS--------*/
        unsigned int getId() const;
        string getNombre() const;
        Cancion* getCanciones(int i) const;
        int getUtilCanciones() const;
        int getTotalInclusiones() const;
        double getMediaValoracion() const;
        bool getTest() const;
        /*--------SETS--------*/
        void setId(const int id);
        void setNombre(const string nombre);
        void setCanciones(const int i, Cancion *c);
        void eliminarCanciones(const int i);
        void setUtilCanciones(const int util);
        void setTotalInclusiones(const int inclusiones);
        void setMediaValoracion(const double val);
        /*--------SOBRECARGA DE OPERADORES--------*/
        Artista& operator=(const Artista &a);
        friend ostream& operator<<(ostream $flujo, const Artista &a);
        friend istream& operator>>(istream $flujo, Artista &a);
};

#endif